/*
  UTF-8 Wrapper Library for Windows

  Released under the MIT license

  Copyright (C) 2014 SASAKI Nobuyuki

  Permission is hereby granted, free of charge, to any person obtaining a
  copy of this software and associated documentation files (the "Software"),
  to deal in the Software without restriction, including without limitation
  the rights to use, copy, modify, merge, publish, distribute, sublicense,
  and/or sell copies of the Software, and to permit persons to whom the
  Software is furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
  DEALINGS IN THE SOFTWARE.
*/

#include <stdlib.h>
#include <windows.h>

#define lu8wlib_c
#define LUA_LIB

#include "lua.h"

#include "lauxlib.h"
#include "lualib.h"

#include "lu8w.h"

static int u8w_getacp (lua_State *L) {
  int codepage = GetACP();
  lua_pushinteger(L, codepage);
  return 1;
}

/* from ansi code page to utf-8 */
static int u8w_acptoutf8 (lua_State *L) {
  int res = 0;
  const char *acp = luaL_checkstring(L, 1);
  int codepage = (int)luaL_optinteger(L, 2, CP_ACP);
  const wchar_t *utf16 = u8lmbtolwc(acp, codepage);
  const char *utf8 = u8wstos(utf16);
  if (utf8) res = 1;
  lua_pushstring(L, utf8);
  if (utf8) free((void *)utf8);
  if (utf16) free((void *)utf16);
  return res;
}

/* from ansi code page to utf-8 */
static int u8w_utf8toacp (lua_State *L) {
  int res = 0;
  const char *utf8 = luaL_checkstring(L, 1);
  int codepage = (int)luaL_optinteger(L, 2, CP_ACP);
  const wchar_t *utf16 = u8stows(utf8);
  const char *acp = u8lwctolmb(utf16, codepage);
  if (acp) res = 1;
  lua_pushstring(L, acp);
  if (acp) free((void *)acp);
  if (utf16) free((void *)utf16);
  return res;
}

static const luaL_Reg u8wlib[] = {
  {"getacp",     u8w_getacp},
  {"acptoutf8",  u8w_acptoutf8},
  {"utf8toacp",  u8w_utf8toacp},
  {NULL, NULL}
};

LUAMOD_API int luaopen_u8w (lua_State *L) {
  luaL_newlib(L, u8wlib);
  return 1;
}

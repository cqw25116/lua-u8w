/*
  UTF-8 Wrapper for Windows

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

#ifndef U8W_H
#define U8W_H

#include <stdio.h>
#include <windows.h>

/* from ansi code page to utf-16 */
wchar_t *u8lmbtolwc(const char *s, UINT codepage);	/* call free function to deallocate */
/* from utf-16 to ansi code page */
char *u8lwctolmb(const wchar_t *s, UINT codepage);	/* call free function to deallocate */

/* from utf-8 to utf-16 */
wchar_t *u8stows(const char *s);	/* call free function to deallocate */
/* from utf-16 to utf-8 */
char *u8wstos(const wchar_t *s);	/* call free function to deallocate */

DWORD u8GetModuleFileName(HMODULE hModule, LPSTR lpFilename, DWORD nSize);
DWORD u8FormatMessage(DWORD dwFlags, LPCVOID lpSource, DWORD dwMessageId, DWORD dwLanguageId,
	LPSTR lpBuffer, DWORD nSize, va_list *Arguments);
HMODULE u8LoadLibraryEx(LPCSTR lpLibFileName, HANDLE hFile, DWORD dwFlags);

FILE *u8fopen(const char *fname, const char *mode);
FILE *u8freopen(const char *fname, const char *mode, FILE *oldfp);
FILE *u8popen(const char *command, const char *mode);
int u8fprintf(FILE *file, const char *format, ...);
int u8printf(const char *format, ...);
char *u8fgets(char *buf, int len, FILE *file);
int u8fputs(const char *buf, FILE *file);
char *u8getenv(const char *varname);	/* call free function to deallocate */
char *u8tmpnam(char *str);
int u8system(const char *command);
int u8remove(const char *fname);
int u8rename(const char *oldfname, const char *newfname);

#if !defined(lu8w_c)
#if defined(LUA_CORE) || defined(LUA_LIB) || defined(lua_c) || defined(luac_c)
#undef LoadString

#define GetModuleFileNameA u8GetModuleFileName
#define FormatMessageA u8FormatMessage
#define LoadLibraryExA u8LoadLibraryEx

#define fopen u8fopen
#define freopen u8freopen
#define _popen u8popen
#define fprintf u8fprintf
#define printf u8printf
#define fgets u8fgets
#define fputs u8fputs
#define getenv u8getenv
#define tmpnam u8tmpnam
#define system u8system
#define remove u8remove
#define rename u8rename
#endif /* LUA_CORE or LUA_LIB or lua_c or luac_c */
#endif /* not lu8w_c */

#endif /* U8W_H */

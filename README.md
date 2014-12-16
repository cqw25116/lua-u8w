lua-u8w *(rc1 version)*
======

[Lua](http://www.lua.org/) 5.3.0 (rc1) with UTF-8 Wrapper for Windows

Released under the MIT license.

This is Lua with converter from UTF-8 to UTF-16(LE) and vice versa at Windows API and C runtime functions.
It is useful to use UTF-8 as Lua string and call Unicode functions.

See lu8w.c and lu8w.h source files, and #ifdef U8W_H directives.

Changes to original sources are:
- add precompiled header
- add lu8w.c and lu8w.h
- add #include "lu8w.h" directive in luaconf.h
- change from fwrite function to fprintf or fwprintf function
- add deallocation UTF-8 environment value string buffer
- change from main function to wmain function in lua.c
- add arguments conversion from UTF-16 to UTF-8 in wmain function
- add call setlocale function in wmain function

This solution is made with Visual Sutdio 2013 Update 4.
Makefile is modified for MinGW platform only.

lua-u8w
======

[Lua](http://www.lua.org/) 5.1.5 with UTF-8 Wrapper for Windows

Lua with converter from UTF-8 to UTF-16(LE) and vice versa at Windows API and C runtime functions.

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

Released under the MIT license

Copyright (C) 1994-2012 Lua.org, PUC-Rio.

Copyright (C) 2015 SASAKI Nobuyuki

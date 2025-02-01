# raylib_basic_demo
Raylib window without the annoying title bar flickering when it start

https://github.com/raysan5/raylib/wiki/Working-on-Windows

    raylib-5.5_win64_mingw-w64.zip

```batch
@echo off
set arg=%~1
gcc -o %arg%.exe %arg%.c -mwindows -lraylib -lgdi32 -lwinmm
```

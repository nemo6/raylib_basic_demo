# raylib_basic_demo
Raylib window without the annoying title bar flickering when it start

https://github.com/raysan5/raylib/wiki/Working-on-Windows#manual-setup-with-w64devkit

C:\w64devkit\bin
Modifier les variables d\'environnement système
PATH

https://github.com/raysan5/raylib/releases/

    raylib-5.5_win64_mingw-w64.zip

```batch
@echo off
set arg=%~1
gcc -o %arg%.exe %arg%.c -mwindows -lraylib -lgdi32 -lwinmm
```

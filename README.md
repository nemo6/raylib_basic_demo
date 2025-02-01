# raylib_basic_demo
Raylib window without the annoying title bar flickering when it start

```batch
@echo off
set arg=%~1
gcc -o %arg%.exe %arg%.c -mwindows -lraylib -lgdi32 -lwinmm
```

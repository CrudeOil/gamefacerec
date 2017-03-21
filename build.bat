@echo off

set vcdir="C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC"
set affydir="C:\Program Files (x86)\Affectiva\AffdexSDK"
set dx9dir="C:\Program Files (x86)\Microsoft DirectX SDK (June 2010)"

call %vcdir%\vcvarsall.bat x64

if exist build goto build
    mkdir build
:build
cd build

set compileflags=/Zi /W4 /EHsc /I ../include /I %affydir%\include /I %dx9dir%\Include
set linkerflags=/Fe:gamefacerec.exe

set files=../src/Affydex.cpp ../src/EmotionService.cpp ../src/GameCapture.cpp ../src/Main.cpp

cl %compileflags% %files% %linkerflags%

del *.obj
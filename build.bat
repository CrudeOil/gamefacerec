@echo off

set vcdir="C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC"
set affydir="C:\Program Files (x86)\Affectiva\AffdexSDK"

call %vcdir%\vcvarsall.bat x64

cd build

set compileflags=/W4 /EHsc /I ../include /I %affydir%\include
set linkerflags=/OUT:gamefacerec.exe

set files=../src/Affydex.cpp ../src/EmotionService.cpp ../src/GameCapture.cpp ../src/Main.cpp

cl %compileflags% %files% %linkerflags%

del *.obj
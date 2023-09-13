@echo off
cls
g++ *.cpp -o concs-comp.exe -I . -std=c++20
.\concs-comp.exe test/test.c -o test.exe
if exist .\test.exe (.\test.exe)
@echo on

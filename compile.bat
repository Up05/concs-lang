@echo off
cls
g++ *.cpp -o concs-comp.exe -I . -std=c++20 -g
.\concs-comp.exe test\test.coc .\test.c
if exist .\test.exe (.\test.exe)
@echo on

@echo off
cls
gcc *.c -o test.exe -g -O1
.\test.exe
echo on

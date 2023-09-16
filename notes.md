# Personal notes

## Compiler

1. set_label
2. if 
3. goto
6. print

set, get, set_flag, arithmetic, print - basic array things.

set[1] 0, set[2] 16, set[3] 1, 
label A, if [1] == [2] goto B, arithm[1] + [3] [1], goto A,
label B

main[1] = 0;
main[2] = 16;
main[3] = 1;

A:
if(main[1] == main[2]) goto B;
main[1] = main[1] + main[3];
goto A;
B:
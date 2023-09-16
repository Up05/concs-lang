# concs-lang

## Documentation


# Overlay
---
commands:
```
\<label>\                                   - set label
;\<index>\(==)<index>\                      - if
;;\<label>\                                 - go to
;;;;\<index>\<value>\                       - set
;;;;;\<index>\                              - print
;;;;;;\<index>\<value>\                     - set flag
;;;;;;;\<index>\<index>\<operator>\<index>\ - do arithmetic

;;;\<index>\                                - get (@DEPRECATED, NOT FULLY IMPLEMENTED)
```
---
booleans: 
```
\;\ - true, \\ - false
```
---
operators:
```
;    - add
;;   - sub
;;;  - mul
;;;; - div (int)
```
#### Label
\<index of label>\
Sets a C's label(`a:;`), you can use any amount of `;` for label names.   
Under the hood, a series of letters [a-z][A-Z] are generated as label names.

#### If
;\<data index>\<data index>
Translates to C's `if(a == b)`.  
Compares 2 values, if they're equal, executes the next command.  

#### Arithmetic
;;;;;;;\<index to output to>\<data index>\<index of operators>\<data index>

Translates to set, or ;;;;, but with unary operator and a second value in the value slot.

TODO: The rest of these...

---
### Example:
```
\;\;;;;\;\;;;\;;;;;;;\;;\;\;;;\;\;;;;;\;;\;\;;\;\;;\;\;;\;;\\;;\
```

## How to install & run

I still have a hard coded input path.

1. Download repo in any of the many ways you can.
2. EITHER open `main.cpp`, change `"test\\test.coc"` to path to your file,
   OR     create a file `test.coc` at `.\test\`. *You'll probably have it already, actually*
3. Cut `.\Concs-lang` to `%LocalAppData%\Ult1\`.
4. Build and/or run the program *I probably have an `exe`, or 3, in the repo*.
5. Enjoy and/or build the `.\test\test.c`.



## I guess, I'll leave this here

`CompilerError` shouldn't exist, imagine it's `void`
Funnily enough, I don't think there can be runtime errors here, so I don't have to store where I found a token. Ha, no!

Todo:
  Interface
  Tokenizer should, in fact, remmber the position of tokens
  Clean up cp::compile(), how are there not patterns in such a mess ;-;
  ...

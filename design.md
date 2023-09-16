# Concs-lang design

As eveyone knows, concs lang stands for concise language.

concs-lang has `;` and `\`, because all other symbols are needless and not beautiful.

# concs comp

```
default file extensions are: .c, .coc, .cos, .cis, .le, .e

concs-comp <input files> [-o <output file>] [-O <optimization level {1, 2, speed}>]

```


# concs doncs


```
\<label>\                                   - set label
;\<index>\(==)<index>\                      - if
;;\<label>\                                 - go to
- ;;;\<index>\                                - get
;;;;\<index>\<number>\                      - set
;;;;;\<index>\                              - print
;;;;;;\<index>\<bool>\                      - set flag
;;;;;;;\<index>\<index>\<operator>\<index>\ - do arithmetic
         out     in                 in
booleans: \;\ - true, \\ - false
operators:
  ;    - add
  ;;   - sub
  ;;;  - mul
  ;;;; - div (int)


\;\;\
```

```


```deprecated
;\\\<index>\\\(equals)\\\<index>\\\\ - if
;;\\<label>\\\ - go to
;;;\\\<index>\\\\ - get
;;;;\\\<index>\\\\<number>\ - set
;;;;;\\\<index>\\\\ - print

\\;\\ - label
\\\;\\\ - variable index

;;;;\\\;\\\\;\
```
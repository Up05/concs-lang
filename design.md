# Concs-lang design

As eveyone knows, concs lang stands for concise language.

concs-lang has only `;` and `\`, because all other symbols are needles and not beautiful.

# concs comp

```
default file extensions are: .c, .coc, .cos, .cis, .le, .e

concs-comp <input files> [-o <output file>] [-O <optimization level {1, 2, speed}>]


```


# concs doncs


```
\<label>\ - set label
;\<index>\(==)<index>\ - if
;;\<label>\ - go to
;;;\<index>\ - get
;;;;\<index>\<number>\ - set
;;;;;\<index>\ - print


\;\;\

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
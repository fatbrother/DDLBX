# Syntex BNF

## 1. Identifier

```ibnf
identifier = letter { letter | digit }.
```

## 2. Literal

```ibnf
literal = integer | float | string | boolean.
```

## 3. Number

```ibnf
number = integer | float.
```

## 4. Integer

```ibnf
integer = digit { digit }.
```

## 5. Float

```ibnf
float = integer "." integer.
```

## 5. String

```ibnf
string = "'" { character } "'".
```

## 6. Boolean

```ibnf
boolean = "true" | "false" | "maybe".
```

## 7. Character

```ibnf
character = letter | digit | symbol.
```

## 8. Letter

```ibnf
letter = "a" | "b" | "c" | "d" | "e" | "f" | "g" | "h" | "i" | "j" | "k" | "l" | "m" | "n" | "o" | "p" | "q" | "r" | "s" | "t" | "u" | "v" | "w" | "x" | "y" | "z" | "A" | "B" | "C" | "D" | "E" | "F" | "G" | "H" | "I" | "J" | "K" | "L" | "M" | "N" | "O" | "P" | "Q" | "R" | "S" | "T" | "U" | "V" | "W" | "X" | "Y" | "Z".
```

## 9. Digit

```ibnf
digit = "0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9".
```

## 10. Symbol

```ibnf
symbol = "!" | "@" | "#" | "$" | "%" | "^" | "&" | "*" | "(" | ")" | "-" | "_" | "+" | "=" | "[" | "]" | "{" | "}" | "|" | ";" | ":" | "'" | "," | "." | "/" | "?" | "<" | ">" | "`" | "~".
```

## 11. Operator

```ibnf
operator = "+" | "-" | "*" | "/" | "%" | "^" | "!" | "<" | ">" | "<=" | ">=" | "==" | "!=" | "&&" | "||" | "++" | "--" | "+=" | "-=" | "*=" | "/=" | "%=" | "^=" | "&=" | "|=".
```

## 12. Keyword

```ibnf
keyword = | "func" | "void" | "any" | "bool" | "num" | "str" | "obj" | "enum" | "public" | "private" | "protected" | "true" | "false" | "maybe" | "null" | "return".
```

## 13. Comment

```ibnf
comment = "//" { character } "\n".
```

## 14. Whitespace

```ibnf
whitespace = " " | "\t" | "\n" | "\r".
```

## 15. Newline

```ibnf
newline = "\n".
```

## 16. End of File

```ibnf
eof = "\0".
```

## 17. Program

```ibnf
program = { statement }.
```

## 18. Statement

```ibnf
statement = declaration | assignment | expression | return.
```

## 19. Declaration

```ibnf
declaration = "num" | "str" | "bool" | "obj" | identifier [ "=" expression ].
```

## 20. Assignment

```ibnf
assignment = identifier "=" expression.
```

## 21. Expression

```ibnf
expression = literal | identifier | function | call | binary | unary | group | array | object.
```

## 22. Return

```ibnf
return = "return" expression.
```

## 23. Function

```ibnf
function = "func" identifier "(" [ parameter { "," parameter } ] ")" [ ":" type ] block.
```

## 24. Call

```ibnf
call = identifier "(" [ argument { "," argument } ] ")".
```

## 25. Parameter

```ibnf
parameter = identifier ":" type.
```

## 26. Argument

```ibnf
argument = expression.
```

## 27. Binary

```ibnf
binary = expression operator expression.
```

## 28. Unary

```ibnf
unary = operator expression.
```

## 29. Group

```ibnf
group = "(" expression ")".
```

## 30. Array

```ibnf
array = "[" [ expression { "," expression } ] "]".
```

## 31. Object

```ibnf
object = "{" [ property { "," property } ] "}".
```

## 32. Property

```ibnf
property = identifier ":" expression.
```

## 33. Type

```ibnf
type = "void" | "any" | "bool" | "num" | "str" | "obj" | identifier.
```

## 34. Block

```ibnf
block = "{" { statement } "}".
```

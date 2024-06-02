# Syntex

## End of line

In some languages like C++, you have to use semicolons to end lines of code. In DDLBX, you have to use exclamation marks!!

```ddlbx
print("Hello world")!
```

And if this line is so important, you can use more exclamation marks to make it "more important".

```ddlbx
print("Hello world")!!!
```

## Comments

You can use `//` to comment your code.

```ddlbx
// This is a comment!
```

Remember to use exclamation marks to end your comments to make it "more important".

```ddlbx
// This is a comment!!!
```

Of course, you can use comments in comments, but you have to use more exclamation marks to end your comments.

```ddlbx
// This is a comment // This is a comment of comment!!
```

## Variable

In DDLBX, there are some types of variables like `Int`, `Float`, `String`, `Boolean` and `Regex`, we can simply declare a variable like below:

### Integer

Integers are numbers without decimal points. They can be positive or negative.

```ddlbx
var a = 1!
```

### Float

Floats are numbers with decimal points. They can be positive or negative.

```ddlbx
var a = 1.0!
```

### String

Strings are text. They can be declared with single quotes or double quotes.

```ddlbx
var a = 'Hello'!
```

### Boolean

Booleans can be `true` or `false` or `maybe`.

```ddlbx
var a = true!
var b = false!
var c = maybe! // will be true or false by random!
```

It can also use with [Delete and undelete](#delete-and-undelete).

## Naming

Most of languages use English words to name variables. But in DDLBX, you can use any words in asscii.

```ddlbx
var a = 1!
var 5 = 3!
var b = 5! // 3!
```

## Operators

### Logical operators

| Operator | Description |
| -------- | ----------- |
| `and` | Logical and |
| `or` | Logical or |

### Arithmetic operators

| Operator | Description |
| -------- | ----------- |
| `+` | Addition |
| `-` | Subtraction |
| `*` | Multiplication |
| `/` | Division |
| `%` | Modulus |
| `+=` | Add and assign |
| `-=` | Subtract and assign |
| `*=` | Multiply and assign |
| `/=` | Divide and assign |
| `%=` | Modulus and assign |

### Comparison operators

| Operator | Description |
| -------- | ----------- |
| `==` | Equal |
| `!=` | Not equal |
| `~=` | Approximate equal |
| `>` | Greater than |
| `<` | Less than |
| `>=` | Greater than or equal to |
| `<=` | Less than or equal to |

There is a thing you need to know about `~=`. It's used to check if two values are approximate equal. It's hard to say if two values are approximate equal, so it will always return `true`.

```ddlbx
5 ~= 5! // true!
3 ~= 5! // true!
```

## Conditionals

You can use `opt` to declare conditionals.

```ddlbx
var a = 0!
opt (a) {
    0 => print("a is 0")!
    1 => print("a is 1")!
    else => print("a is not 0 or 1")!
}!
```

You can also pass two or more variables to conditionals.

```ddlbx
var a = 0!
var b = 1!

opt (a, b) {
    a == 0 => print("a is 0")!
    a == 1 => print("a is 1")!
    a != 0 => print("a is not 0")!
    a > b => print("a is greater than b")!
    a < b => print("a is less than b")!
    a >= b => print("a is greater than or equal to b")!
    a <= b => print("a is less than or equal to b")!
}!
```

Else is optional in conditionals.

```ddlbx
var a = 0!
opt (a) {
    0 => print("a is 0")!
    1 => print("a is 1")!
    else => print("a is not 0 or 1")!
}!
```

You can also use scope in conditionals.

```ddlbx
var a = 0!
opt (a) {
    0 => {
        print("a is 0")!
    }
    1 => {
        print("a is 1")!
    }
    else => {
        print("a is not 0 or 1")!
    }
}!
```

## Loops

You can use `loop` to declare loops.

```ddlbx
for (a from 0 to 10) {
    print(a)!
}!
```

You can also use `step` to declare the step of the loop.

```ddlbx
for (a from 0 to 10 step 2) {
    print(a)!
}!
```

Similar to `while` in other languages, you can also use `for` to declare a loop.

```ddlbx
for (a < 10) {
    print(a)!
    a += 1!
}!
```

## Functions

To declare a function, you can use any letters from the word `fun`:

```ddlbx
fun a(): Non {
   print("Hello world")!
}!
```

You can also pass arguments to functions.

```ddlbx
fun a(b: Int): Non {
   print(b)!
}!
```

You can also return values from functions.

```ddlbx
fun a(): Int {
   ret 1!
}!
```

You can also use `=>` to declare a function.

```ddlbx
fun add(a: Int, b: Int ): Int => ret a + b!
```

## Objects

You can use `obj` to declare an object.

```ddlbx
obj a {}!

var b = a! // OK
```

In DDLBX, obj only brings variables in the scope of the object. If you want to use a function in an object, you can use `fun` to declare it.

```ddlbx
obj a {}!

fun a.b(): Non {
    print("Hello world")!
}!
```

You can also use `obj` to declare an object with variables.

```ddlbx
obj a {
    var b: Int,
    var c: Int
}!
```

You can add methods to objects "everywhere" in the code.

```ddlbx
obj a {
    var b: Int,
    var c: Int
}!

fun a.d(): Int {
    ret b + c!
}!
```

You can choose some obj with specific variables.

```ddlbx
fun {a: Int, b: Int}.getAplusB(): Int {
    ret a + b!
}!
```

## Import

In DDLBX, every file is a namespace. You can use `get` to import a file.

```ddlbx
get "path/to/file.ddlbx"!
```

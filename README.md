# DDLBX

A Desirable Develop Language Beyond Xcellence.

After learning so many programming languages, we found that there are so many duplicated syntaxes in each language. So we decided to create a new programming language that is easy to learn and use.

## Comments

You can use `//` to comment your code.

```dart
// This is a comment
```

## End of line

In some languages like C++, you have to use semicolons to end lines of code. In DDLBX, you have to use exclamation marks!!

```dart
print("Hello world")!
```

## Variables

There are some types of variables in DDLBX.

### Integers

Integers are numbers without decimal points. They can be positive or negative.

```dart
Int a = 1!
```

### Floats

Floats are numbers with decimal points. They can be positive or negative.

```dart
Float a = 1.0!
```

### Strings

Strings are text. They can be declared with single quotes or double quotes.

```dart
String a = 'Hello'!
```

### Booleans

Booleans can be `true` or `false` or `maybe`.

```dart
Bool a = true!
Bool b = false!
Bool c = maybe! // will be true or false by random
```

## Naming

Most of languages use English words to name variables. But in DDLBX, you can use any words in asscii.

```dart
String firstAlphabetLetter = 'A'!
Int 5 = 3!
print(5)! // 3
```

## Operators

### Arithmetic operators

| Operator | Description |
| -------- | ----------- |
| `+` | Addition |
| `-` | Subtraction |
| `*` | Multiplication |
| `/` | Division |
| `%` | Modulus |
| `++` | Increment |
| `--` | Decrement |
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
| `>` | Greater than |
| `<` | Less than |
| `>=` | Greater than or equal to |
| `<=` | Less than or equal to |

### Logical operators

| Operator | Description |
| -------- | ----------- |
| `&&` | Logical and |
| `\|\|` | Logical or |
| `!` | Logical not |

### Special operators

| Operator | Description |
| -------- | ----------- |
| `^` | Return `true` if code direction is up, else return `false` |
| `v` | Return `true` if code direction is down, else return `false` |
| `~` | Range operator |

As you see, the down arrow is a little bit bigger than the up arrow. It's because we are still recommending you to write code from top to bottom.

Also, we use char v as operator, but you can still use it as a variable name because [Naming](#naming).

See [Reversing](#reversing) to have an idea why we need `^` and `v`.

Range operator is used to check if lhs is in the range of rhs.

```dart
print(5 == 1~10)! // true
print(5 == 1~5)!  // false
```

Compiler will auto add 0 or inffinity to the range if you don't specify the range.

```dart
print(5 == ~10)! // true
print(5 == 1~)!  // true
print(5 == ~)!   // true
```

## Conditionals

There are only a keyword in DDLBX to do conditionals. It's `when`.

```dart
when (a) {
    1: print("a is 1")! 
}
```

Use it similar to `switch` in other languages.

```dart
when (a) {
    1: print("a is 1")!
    2: print("a is 2")!
    3: print("a is 3")!
    else: print("a is not 1, 2, or 3")!
}
```

You can also use `~` to do conditionals.

```dart
when (a) {
    1~: print("a is greater than 1")!
    2~: print("a is greater than 2")!
    3~: print("a is greater than 3")!
    else: print("a is not greater than 1, 2, or 3")!
}
```

Of course, you can have some calculations in conditionals or even cases.

```dart
when (a + b) {
    1~: print("a + b is greater than 1")!
    2~: print("a + b is greater than 2")!
    (1 + 2): print("a + b == 1 + 2")!
    else: print("a + b is not greater than 1, 2, or 3")!
}
```

In some cases, we only need to check if the statement is true or false.

```dart
when (isSuccess) => print("Success")!
```

## Loops

We don't need loops in DDLBX. We can use functions or reversing(see [Reversing](#reversing)) to implement loops.

## Functions

To declare a function, you can use any letters from the word `func`:

```dart
func a() => {
   print("Hello world")!
}
```

You can also pass arguments to functions.

```dart
func a(Int b) => {
   print(b)!
}
```

You can also return values from functions.

```dart
func a(Int b) => Int {
   return b!
}
```

## Objects

Similar to class in other languages, you can use `obj` to declare an object.

```dart
obj Player {
   Int health = 10!
}
```

## Delete and undelete

You can use it to prevent some developers from using some words in compile time.

```dart
// In this FP project, we don't want developers to use obj
delete obj!

======= other code =======
obj Player {
   Int health = 10!
} // Error: obj has been deleted
```

```dart
// In this project, the naming rule is camelCase and we don't want developers to use snake_case
delete _!

======= other code =======
String firstAlphabetLetter = 'A'!
String first_alphabet_letter = 'A'! // Error: _ has been deleted
```

If you don't want to delete a variable, you can use `undelete`.

```dart
delete func!
undelete func!
func a() => {
   print("Hello world")!
} // Ok
```

If you don't want to let anyone use `delete` and, you can also delete it.

```dart
delete delete!
```

But In a special case...

```dart
delete undelete!
```

## Reversing

You can reverse the direction of your code in scope.

```dart
String message = "Hello"!
print(message)! // Hello world
message = "world"!
reverse!
```

Implementing loops with reversing and conditionals.

```dart
// when code direction is reversed, ^ will be false
when (^) => reverse! {
Int a = 0!
print(a)!
} when (a++) ~10: reverse!
```

We need to use curly braces to wrap the code, because we don't want to reverse the whole code.

```dart
when (^) => reverse! 
print("Hello ")!
print("world ")!
when (a++) ~10: reverse!

// we will get:
// Hello world world Hello world.....
```

## Reserved words list

| Word | Description |
| ---- | ------- |
| `func` | Declare a function |
| `obj` | Declare an object |
| `when` | Conditionals |
| `else` | Else |
| `true` | true |
| `false` | false |
| `maybe` | Random of true or false |
| `delete` | Delete keyword |
| `undelete` | Undelete keyword |
| `reverse` | Reverse the direction of your code |

## References

Inspired by [DreamBerd](https://github.com/TodePond/DreamBerd.git)  
Some syntaxes are from [Kotlin](https://github.com/JetBrains/kotlin.git)

## Contributing

If you want to contribute to DDLBX, you can fork this repository and make a pull request.

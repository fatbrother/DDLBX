# DDLBX

A Desirable Develop Language Beyond Xcellence

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
Bool a = True!
Bool b = False!
Bool c = Maybe! // will be true or false by random
```

## Naming

Most of languages use English words to name variables. But in DDLBX, you can use any words in asscii.

```dart
String firstAlphabetLetter = 'A'!
Int 5 = 3!
print(5)! // 3
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

## Loops

We don't need loops in DDLBX. We can use functions or reversing(see [Reversing](#reversing)) to implement loops.


## Arithmetic

If you have learn another programming languages, you may want to add parentheses to your arithmetic expressions. But in DDLBX, you don't need to do that, you can just use spaces.

```dart
print(1 + 2*3)! //7
print(1+2 * 3)! //9
```

## Functions

To declare a function, you can use any letters from the word `func`:

```dart
func a() => {
   print("Hello world")!
}
```

## Objects

Similar to class in other languages, you can use `obj` to declare an object.

```dart
obj Player {
   Int health = 10!
}
```

## Delete

To match some special rules in practice, you can delete some words in your code.

```dart
delete 3!
print(2 + 1)! // Error: 3 has been deleted
```

You can also delete reserved words.

```dart
delete func!
func a() => {
   print("Hello world")!
} // Error: func has been deleted
```

If you don't want to delete a variable, you can use `undelete`.

```dart
delete func!
undelete func!
func a() => {
   print("Hello world")!
} // Hello world
```

If you don't want to delete any words, you can use following code:

```dart
delete delete!
```

But In a special case...

```dart
delete undelete!
```

## Reversing

You can reverse the direction of your code.

```dart
const const message = "Hello"!
print(message)! // world
const const message = "world"!
reverse!
```

Implementing loops with reversing and conditionals.

```dart
when (Int a = 0) => 0~: reverse!
print("Hello world")!
when (a++) ~10: reverse!
```

## Comments

You can use `//` to comment your code.

```dart
// This is a comment
```

## Reserved words list

| Word | Description |
| ---- | ------- |
| `func` | Declare a function |
| `obj` | Declare an object |
| `when` | Conditionals |
| `else` | Else |
| `True` | True |
| `False` | False |
| `Maybe` | Random of True or False |
| `delete` | Delete keyword |
| `undelete` | Undelete keyword |
| `reverse` | Reverse the direction of your code |

## References

Inspired by [DreamBerd](https://github.com/TodePond/DreamBerd.git)  
Some syntaxes are from [Kotlin](https://github.com/JetBrains/kotlin.git)

## Contributing

If you want to contribute to DDLBX, you can fork this repository and make a pull request.

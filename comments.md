# Types of Comments in C and C++

In C and C++, comments are used to provide explanations or annotations within the code. Comments are ignored by the compiler and do not affect the program's execution. There are two primary types of comments in C and C++: single-line comments and multi-line comments.

## 1. Single-Line Comments

Single-line comments start with `//`. Everything following `//` on that line is considered a comment.

### Example:
```cpp
// This is a single-line comment
int x = 10; // This comment explains that x is initialized to 10
```

## 2. Multi-Line Comments

Multi-line comments begin with `/*` and end with `*/`. They can span multiple lines and are useful for longer explanations.

### Example:
```cpp
/*
This is a multi-line comment.
It can be used to provide detailed descriptions
or explanations about the code.
*/
int y = 20;
```

### Important Notes:
- Comments should be clear and concise, helping to improve code readability.
- Avoid placing comments within complex expressions, as they may lead to confusion.
- Do not nest multi-line comments, as this is not allowed and can cause errors.

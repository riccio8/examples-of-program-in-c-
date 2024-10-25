---

# Bitwise Operators Guide

This guide provides a detailed overview of bitwise operators in C++, explaining their functionality, syntax, benefits, and includes exercises for practice.

## 1. **Bitwise Operators and Syntax**
Bitwise operators work on individual bits of integers, enabling precise manipulation of binary data. Below is a summary of the main bitwise operators in C++:

| Operator | Name              | Syntax  | Example (A = 60, B = 13) |
|----------|--------------------|---------|---------------------------|
| `&`      | Bitwise AND       | `A & B` | Result: 12                |
| `|`      | Bitwise OR        | `A | B` | Result: 61                |
| `^`      | Bitwise XOR       | `A ^ B` | Result: 49                |
| `~`      | Bitwise NOT       | `~A`    | Result: -61               |
| `<<`     | Left Shift        | `A << 2`| Result: 240               |
| `>>`     | Right Shift       | `A >> 2`| Result: 15                |

### Code Example
```cpp
#include <iostream>

int main() {
    int A = 60; // 0011 1100 in binary
    int B = 13; // 0000 1101 in binary

    std::cout << "A & B = " << (A & B) << std::endl;  // Bitwise AND
    std::cout << "A | B = " << (A | B) << std::endl;  // Bitwise OR
    std::cout << "A ^ B = " << (A ^ B) << std::endl;  // Bitwise XOR
    std::cout << "~A = " << (~A) << std::endl;        // Bitwise NOT
    std::cout << "A << 2 = " << (A << 2) << std::endl;// Left Shift
    std::cout << "A >> 2 = " << (A >> 2) << std::endl;// Right Shift

    return 0;
}
```

## 2. **How Each Operator Works**

- **AND (`&`)**: Only the bits set in both numbers remain as 1.

  ```cpp
  60 = 0011 1100
  13 = 0000 1101
  ----------------
       0000 1100 = 12
  ```

- **OR (`|`)**: Bits set to 1 if either of the bits in the positions is 1.

  ```cpp
  60 = 0011 1100
  13 = 0000 1101
  ----------------
       0011 1101 = 61
  ```

- **XOR (`^`)**: Sets bits to 1 where bits differ.

  ```cpp
  60 = 0011 1100
  13 = 0000 1101
  ----------------
       0011 0001 = 49
  ```

- **NOT (`~`)**: Inverts each bit.

  ```cpp
  60 = 0011 1100
  ----------------
       1100 0011 = -61 (in two’s complement form)
  ```

- **Left Shift (`<<`)**: Shifts bits to the left, fills zeros on the right (equivalent to multiplying by 2 for each shift).

  ```cpp
  60 << 2
  0011 1100 -> 1111 0000 = 240
  ```

- **Right Shift (`>>`)**: Shifts bits to the right, discards bits on the right (equivalent to dividing by 2 for each shift).

  ```cpp
  60 >> 2
  0011 1100 -> 0000 1111 = 15
  ```

## 3. **Why Use Bitwise Operators?**
1. **Optimization**: Bitwise operations are highly efficient for low-level data processing.
2. **Flag Management**: Useful in system programming for toggling flags or configurations.
3. **Bit Masks**: Allow setting, clearing, or testing specific bits in data.

## 4. **Practice Exercises**

### Exercise 1: Creating a Bitmask
Use bitwise AND `&` to isolate the last 4 bits of a number `A = 53`.

```cpp
#include <iostream>

int main() {
    int A = 53;              // 0011 0101 in binary
    int mask = 0b1111;       // 0000 1111
    int result = A & mask;

    std::cout << "Result: " << result << std::endl;  // Output: 5 (0000 0101)
    return 0;
}
```

### Exercise 2: Toggling a Specific Bit
Toggle the third bit (from the right) of `A = 13` using XOR `^`.

```cpp
#include <iostream>

int main() {
    int A = 13;               // 0000 1101 in binary
    int mask = 1 << 2;        // 0000 0100
    int result = A ^ mask;

    std::cout << "Result: " << result << std::endl;  // Output: 9 (0000 1001)
    return 0;
}
```

### Exercise 3: Checking if a Bit is Active
Verify if the fourth bit is active in `A = 22` with AND `&`.

```cpp
#include <iostream>

int main() {
    int A = 22;               // 0001 0110 in binary
    int mask = 1 << 3;        // 0000 1000
    bool is_active = (A & mask) != 0;

    std::cout << "Is Active: " << std::boolalpha << is_active << std::endl; // Output: true
    return 0;
}
```

### Exercise 4: Setting a Specific Bit
Set the fifth bit of `A = 8` using OR `|`.

```cpp
#include <iostream>

int main() {
    int A = 8;                // 0000 1000 in binary
    int mask = 1 << 4;        // 0001 0000
    int result = A | mask;

    std::cout << "Result: " << result << std::endl;  // Output: 24 (0001 1000)
    return 0;
}
```

---

### Additional Examples

- **Example: Clearing a Specific Bit**

To clear the third bit of `A = 13`, we use `AND` with a mask that has the third bit set to `0`:

```cpp
int A = 13;          // 0000 1101 in binary
int mask = ~(1 << 2); // 1111 1011 in binary
int result = A & mask;
std::cout << "Result: " << result << std::endl;  // Output: 9 (0000 1001)
```

- **Example: Swapping Two Numbers Using XOR**

Swap values of two integers without a temporary variable:

```cpp
int x = 5; // 0101
int y = 9; // 1001

x = x ^ y; // x becomes 1100
y = x ^ y; // y becomes 0101 (original x)
x = x ^ y; // x becomes 1001 (original y)

std::cout << "x: " << x << ", y: " << y << std::endl; // x: 9, y: 5
```

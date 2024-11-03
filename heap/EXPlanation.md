
# Understanding Heap and Stack in C++

Hey there! Welcome to this little guide where we'll break down the concepts of **heap** and **stack** memory in C++. Don't worry; I'll keep it chill and easy to understand. Let's dive in!

## What's the Stack?

- **Stack** is like your backpack at school. It's where you store your stuff (variables) while you're in class (a function).
- It uses **Last In, First Out (LIFO)**, meaning the last thing you put in is the first thing you take out. 
- Memory is automatically managed. When the function finishes, all the stuff in the stack disappears. Boom!

### Example of Stack

```cpp
#include <iostream>
using namespace std;

void stackExample() {
    int a = 10; // a is stored in the stack
    cout << "Stack value: " << a << endl; // Prints 10
} // a is gone when the function exits

int main() {
    stackExample();
    // a is not accessible here
    return 0;
}
```

## What's the Heap?

- **Heap** is like your attic or basement. You can store things there, but you gotta keep track of them yourself.
- Memory management is manual. You have to use `new` to allocate memory and `delete` to free it up. If you forget to clean up, you'll have a mess (memory leak).

### Example of Heap

```cpp
#include <iostream>
using namespace std;

void heapExample() {
    int* b = new int; // Allocates memory on the heap
    *b = 20; // Store 20 in the allocated space
    cout << "Heap value: " << *b << endl; // Prints 20
    delete b; // Free the memory to avoid leaks
} // b is gone, but memory is freed before function exits

int main() {
    heapExample();
    // b is not accessible here, but memory is cleaned up
    return 0;
}
```

## Key Differences

| Feature              | Stack                     | Heap                       |
|----------------------|---------------------------|----------------------------|
| **Size**             | Limited (depends on OS)   | Larger (limited by RAM)    |
| **Speed**            | Fast (auto management)    | Slower (manual management)  |
| **Lifetime**         | Automatic (function scope) | Manual (until deleted)     |
| **Allocation**       | Local variables            | Dynamic allocation with `new` |

## Memory Management

- Use `new` to allocate memory on the heap.
- Use `delete` to free that memory when you're done with it.
- Forgetting to `delete` leads to **memory leaks** – like leaving your soda can on the counter!

### Example of Memory Management

```cpp
#include <iostream>
using namespace std;

int main() {
    int* array = new int[5]; // Allocates an array on the heap
    for (int i = 0; i < 5; ++i) {
        array[i] = i * 10; // Fill it with values
        cout << "Array[" << i << "] = " << array[i] << endl; // Prints 0, 10, 20, ...
    }
    delete[] array; // Free the array memory
    return 0;
}
```

## Conclusion

And there you have it! Stack and heap memory in a nutshell. The stack is fast and automatic, while the heap gives you flexibility but requires responsibility. Remember to always clean up after yourself when using the heap

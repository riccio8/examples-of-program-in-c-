
# README for Standard C++ Libraries

**Yo!** Welcome to the ultimate guide on some of the most dope libraries in C++. We’re gonna break it down nice and easy, so you can get the hang of this stuff without breaking a sweat.


## 📚 Table of Contents

1. [Multithreading](#-multithreading)
2. [cmath](#-cmath)
3. [<algorithm>](#algorithm)
4. [<string>](#string)
5. [<iostream>](#iostream)
6. [<fstream>](#fstream)
7. [<map>](#map)
8. [<set>](#set)
9. [Common Conventions](#-common-conventions)




## 🧵 Multithreading

Alright, picture this: you’re running a fast-food joint. The more cashiers you have, the more customers you can serve at once. That’s what multithreading does! It lets you handle multiple tasks at the same time, so your program can hustle like a champ.

### 🔍 Multithreading Example

```cpp
#include <iostream>
#include <thread>

void greet(int id) {
    std::cout << "Yo from thread " << id << "!\n";
}

int main() {
    std::thread t1(greet, 1);
    std::thread t2(greet, 2);

    t1.join(); // Wait for t1 to finish up
    t2.join(); // Wait for t2 to wrap it up

    return 0;
}
```

In this jam, we’ve got two threads, kinda like having two cashiers working the register at the same time. When each one finishes up, they chill and wait for the main thread to catch up.

---

## 🧮 cmath

Now, let’s talk about `cmath`. Think of it like your math toolbox for when you need to whip out some fancy calculations. It’s got everything from square roots to trigonometry, making it super handy for when you’re crunching numbers.

### 🔍 cmath Example

```cpp
#include <iostream>
#include <cmath>

int main() {
    double number = 16.0;
    double root = sqrt(number); // Getting the square root

    std::cout << "The square root of " << number << " is " << root << ".\n";
    return 0;
}
```

In this snippet, we’re using `sqrt` to find the square root, just like a math whiz figuring out the answer to a tough problem. Easy peasy!

---

## 📦 Other Standard Libraries

### 🔧 algorithm

If `cmath` is your math toolbox, then `<algorithm>` is the Swiss Army knife for programming. It’s got all the tools you need to sort, search, and mess with your data like a pro.

#### 🔍 Example of <algorithm>

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> nums = {5, 2, 9, 1, 5, 6};
    
    std::sort(nums.begin(), nums.end()); // Sorts the numbers

    std::cout << "Sorted numbers: ";
    for (int n : nums) {
        std::cout << n << " ";
    }
    std::cout << "\n";
    
    return 0;
}
```

Here, we’re using `std::sort` to arrange our numbers from smallest to largest, like putting your shoes in order from fresh kicks to your beat-up old sneakers.

### 📝 <string>

Now let’s get real with strings. The `<string>` library is like your trusty notebook for handling all that text and characters. Whether you’re putting together a message or chopping up some text, this library’s got your back.

#### 🔍 Example of <string>

```cpp
#include <iostream>
#include <string>

int main() {
    std::string greeting = "What’s up, world!";
    
    std::cout << greeting << "\n"; // Prints the greeting
    std::cout << "Length: " << greeting.length() << " characters.\n"; // Shows how long it is
    
    return 0;
}
```

In this example, we’re creating a simple string and checking how many characters are in it, kinda like counting the words in your favorite song lyric.

### 📬 <iostream>

Let’s not forget about `<iostream>`. This bad boy is your go-to for input and output. It’s like your front desk for getting and sending info to and from your program.

#### 🔍 Example of <iostream>

```cpp
#include <iostream>

int main() {
    std::cout << "Hello, world!\n"; // Print to the console

    std::string name;
    std::cout << "Enter your name: ";
    std::cin >> name; // Get user input

    std::cout << "Nice to meet you, " << name << "!\n";
    return 0;
}
```

This snippet shows how to print to the console and take input from the user, like having a convo with your program.

### 📂 <fstream>

Next up is `<fstream>`. Think of it like your library card for reading and writing files. It helps you store data like a boss, so you don’t have to remember everything.

#### 🔍 Example of <fstream>

```cpp
#include <iostream>
#include <fstream>

int main() {
    std::ofstream myfile("example.txt"); // Create and open a file

    if (myfile.is_open()) {
        myfile << "Writing to a file.\n"; // Write to the file
        myfile.close(); // Close the file
    } else {
        std::cout << "Unable to open file.\n";
    }

    return 0;
}
```

In this example, we’re creating a file and writing some text into it, kinda like jotting down notes in your diary.

### 🗺️ <map>

Let’s talk about `<map>`. This library is like your organized closet, where you can keep track of pairs of keys and values. It’s super useful for storing data that you want to look up quickly.

#### 🔍 Example of <map>

```cpp
#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> scores;
    scores["Alice"] = 90;
    scores["Bob"] = 85;

    std::cout << "Alice's score: " << scores["Alice"] << "\n";
    std::cout << "Bob's score: " << scores["Bob"] << "\n";

    return 0;
}
```

Here, we’re using a map to associate names with scores, like keeping track of your friends' high scores in a game.

### 🔢 <set>

Last but not least, we’ve got `<set>`. This library is like a special collection where you can keep unique items. No duplicates allowed, just like your favorite playlist.

#### 🔍 Example of <set>

```cpp
#include <iostream>
#include <set>

int main() {
    std::set<int> unique_numbers;
    unique_numbers.insert(5);
    unique_numbers.insert(3);
    unique_numbers.insert(5); // This won't be added again

    std::cout << "Unique numbers: ";
    for (int n : unique_numbers) {
        std::cout << n << " "; // Prints: 3 5
    }
    std::cout << "\n";

    return 0;
}
```

In this snippet, we’re using a set to store unique numbers. If you try to add a duplicate, it just won’t let you, keeping your collection fresh.

---

## 📝 Common Conventions

Now that you’re cruising with these libraries, let’s hit up some common conventions in C++ coding. These tips will help you keep your code clean and readable.

1. **Naming Conventions**:
   - Use `camelCase` for variable names (e.g., `myVariable`).
   - Use `PascalCase` for class names (e.g., `MyClass`).
   - Constants are usually in `UPPER_CASE` (e.g., `MAX_SIZE`).

2. **Comment Your Code**:
   - Use comments to explain complex parts of your code. This is like leaving notes for yourself or others who will read your code later.
   - Use `//` for single-line comments and `/* ... */` for multi-line comments.

3. **Indentation**:
   - Keep your code neatly indented to make it easier to read. Usually, 4 spaces or a tab per level is standard.

4. **Use `const` and `constexpr`**:
   - If a variable won’t change, declare it as `const`. This is like putting a lock on something to keep it safe.
   - Use `constexpr` for compile-time constants.

5. **Error Handling**:
   - Use exceptions to handle errors instead of just returning error codes. This keeps your code cleaner and easier to debug.

---

## 🎉 Wrapping Up

There you have it, folks! A quick rundown of some standard C++ libraries that’ll help you get your programming game on point. Keep this guide handy, and you’ll be slinging code like a pro in no time!

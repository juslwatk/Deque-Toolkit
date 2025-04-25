Deque Project - CSCI 325

This is a deque project (double-ended queue) made using a dynamic double array. Aadding and removing from both the front and back, as well as accessing elements like an array are all supported.

We also made it so can work with different data types, like int, string, double, and char.



 What it does

- push_front() and push_back() – add items to either side
- pop_front() and pop_back() – remove from either side
- front() and back() – get the front or back item
- empty() – check if the deque is empty
- size() – returns how many items are in the deque
- operator[] – access an item at a specific index like an array



 Files Included

- deque.h – contains the deque class and all its functions
- main.cpp – runs all of the tests
- Makefile – used to compile the project
- tests/ – folder with test files
- README.md – this file



 How to Run It

If you’re using the Makefile:
bash
make
./deque_test


Or compile manually:
bash
g++ main.cpp tests/*.cpp -o deque_test
./deque_test




 Tests Included

The program runs a many of the tests automatically. such as the following:

- Basic integer operations with thousands of pushes/pops
- Random push and pop behavior
- Using the deque with string, char, and double
- Error handling like popping from an empty deque



 Bonus

The class is templated, which means it works with any type you give it. We tested it with integers, strings, doubles, and chars.



 Who Did What

- Justice Watkins – main deque class and integer testing
- Jacob Cochran – help with templates, other types, and file setup


There are no known issues in the program. All tests have passed
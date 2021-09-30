# Lecture 01_intro


## 01_variables.cpp

[link to file](./01_variables.cpp)

Introduces many built-in types (such as int, double, char and bool), and
also some basic operations defined on them (like +, -, +=, -=, ==, <=, and %).
The *universal and uniform initializer ({})* is introduced, together with the *const*
declaration for variables.


PPP: basically all chapter 3
CPL: all chapter 6 is dedicated to types but is too technical, 6.3.5 explains
     in detail why the universal and uniform initializer is better.



## 02_hello_name.cpp 

[link to file](./02_hello_name.cpp)

Introductory program that says hello to the user, after this one has
inserted his name and age. You can see the usage of `std::cout` and `std::cin`, and
an example of the class string.

PPP: chapter 2, take a look also at chapter 1




## 03_loops.cpp 

[link to file](./03_loops.cpp)

Example with the most common types of loops in C++: the `for` loop, the `while` and
the `do while` loop.


PPP: chapter 4.4






## 04_vars_pointers_refs.cpp

[link to file](./04_vars_pointers_refs.cpp)

Small introduction to the usage of *pointers* and *references*.

PPP: chap 17.9 for pointers and references
CPL: chap 7.2 for pointers, 7.7 for references





## 05_functions.cpp

[link to file](./05_functions.cpp)

Three different implementations of a function that swaps two integers, one of them is used to
introduce the concept of *pass by reference*.

PPP: chap 4.5 for introduction to functions, chap 8.5 for a more detailed discussion, with
also the *pass by value*, *pass by const-reference* and *pass by reference* principles and
practices.

CPL: all chap 12 is dedicated to functions, but maybe is too detailed for the moment




## 06_watch_out.cpp

[link to file](./06_watch_out.cpp)


This program shows two typical problems one can encounter in programming: the integer
overflow and the uncorrect representation of certain floating point numbers. The function
`std::setprecision()` allows the user to set the decimal precision for the output operations.


PPP: chapter 24.2






### References:

[PPP]  Programming: Principles and Practice using C++ (Second Edition), Bjarne Stroustrup, Addison-Wesley 2014, ISBN 978-0-321-99278-9

[CPL]  The C++ Programming Language, Bjarne Stroustrup, Addison-Wesley 2013, ISBN 978-0321563842

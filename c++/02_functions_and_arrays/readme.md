# Lecture 02_functions_and_arrays

## 01_auto.cpp

[link to file](./01_auto.cpp)

This program introduces the `auto` specifier. When you declare a
variable with this keyword its type will be automatically deduced by
the compiler.

PPP: chap 20.5.2
CPL: chap 2.2.2, chap 6.3.6


## 02_auto_functions.cpp
[link to file](./02_functions.cpp)

A function is a named sequence of statements. A function can return a result (return value), and since c++14 can be declared as `auto`.

PPP: 4.5


## 03_overloading.cpp

[link to file](./03_overloading.cpp)

This program contains an example of *function overloading*. You can give two
functions the same name provided that they differ by the types and/or the
number of arguments.

CPL: 12.3



## 04_templates.cpp

[link to file](./04_templates)

This program introduces the usage of *templates* for the function of the previous
example. The template allows the function to work with different kinds of types, thus
avoiding code repetitions (from the programmer).

PPP: 19.3
CPL: 3.4.1, 3.4.2


## 05_static_arrays.cpp

[link to file](./05_static_arrays.cpp)

Brief introduction to arrays in C++, examples of declaration and various initializations.
There is also a demonstration of their consecutive representation in memory.
The `std::string` class is a good alternative for `char` arrays.

PPP: 17.2 arrays, 18.6 array and pointers
CPL: 7.3 arrays



## 06_dynamic_arrays.cpp

[link to file](./06_dynamic_arrays.cpp)

Usage of the `new` function to allocate memory on the *heap* (also called free-store or dynamic memory)
and consequent usage of `delete` to free it.

PPP: 17.4
CPL: 11.2


## 07_constexpr_functions.cpp

[link to file](./07_constexpr_functions.cpp)


Since c++11, we have different ways to perform computations at compile time. In this example, we see how to use the `constexpr` keyword and basic template metaprogramming.





### References:

[PPP]  Programming: Principles and Practice using C++ (Second Edition), Bjarne Stroustrup, Addison-Wesley 2014, ISBN 978-0-321-99278-9

[CPL]  The C++ Programming Language, Bjarne Stroustrup, Addison-Wesley 2013, ISBN 978-0321563842

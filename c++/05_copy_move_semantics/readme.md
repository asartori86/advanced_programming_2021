# 06_copy_move_semantics


## 01_surprise.cpp

[link to file](./01_surprise.cpp)

This program highlights that a compiler is able to generate a default
constructor, copy constructor, copy assignment, move constructor and
move assignment, and illustrates their syntax. The function
`std::move()` is used to get a r-value reference.


PPP: chap 18.3 copying
CPL: chap 17.5 copy and move




## 02_default.cpp

[link to file](./02_default.cpp)

The compiler-generated default ctor behave very differntly if invoked
with or without `{}`. The aggregate initialization is addressed as
well.

PPP: chap 9.7.3 default constructors
CPL: chap 17.6.1 default




## 03_default.cpp

[link to file](./03_default.cpp)
Shows how to use the `default` keyword to explicitly ask the compiler
to create a default constructor (or assignment operator) even if other
constructors are present. The keyword `delete`, instead, is used to
eliminate a particular function. 
Shows the usage of *in-class* initialization and aggregate initialization and their relationships with the constructors.

PPP: chap 9.7.3
CPL: chap 17.6.1 default, chap 17.6.4 delete


## 04_buggy_vector.cpp

[link to file](./04_buggy_vector.cpp)

This program illustrates the behavior of the class Vector, that
handles some **allocated** memory, when a proper copy constructor is
not defined, and the one provided by the compiler is used (**shallow
copy**). The constructor for this class is defined `explicit`.


PPP: chap 18.4.1 explicit constructor
CPL: chap 16.2.6 explicit constructor



## 05_buggy_vector.cpp

[link to file](./05_buggy_vector.cpp)

Same as the previous one, but this time the elements are stored using a `std::unique_ptr`. No copy semantic can be defined by the compiler because it has been `delete`d in the `std::unique_ptr` class




## 06_copy_move.cpp

[link to file](./06_copy_move.cpp)

Implements the copy and move semantics for the Vector class and shows some examples.

PPP: chap 18.3 copying
CPL: chap 17.5 copy and move



### References:

[PPP] = Programming: Principles and Practice using C++ (Second Edition), Bjarne Stroustrup, Addison-Wesley 2014, ISBN 978-0-321-99278-9

[CPL] = The C++ Programming Language, Bjarne Stroustrup, Addison-Wesley 2013, ISBN 978-0321563842

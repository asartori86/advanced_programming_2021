# Lecture 04_custom_types


## 01_enum.cpp

[link to file](./01_enum.cpp)

The idea behind enumeration is to create a new type whose values are restricted to a specific range or set of values. This example illustrates the plain `enum` syntax and usage.

PPP: chap 9.5
CPL: chap 8.4



## 02_scoped_enum.cpp

[link to file](./02_scoped_enum.cpp)

Introduces the *scoped enum*, extension of the "plain enum" described before. Now the enumerator name must be qualified by the enum type name and the scope resolution operator. They are not implicitly converted to integers.

PPP: chap 9.5
CPL: chap 8.4



## 03_namespace.cpp

[link to file](./04_namespace.cpp)

`namespace` allows to group variables, functions and classes into a proper set. Examples on the usage of the `namespace` keyword are given.

PPP: 8.7 and 8.7.1
CPL: chapter 14



## 04_why_scoped.cpp

[link to file](./03_why_scoped.cpp)

This program demonstrates how the plain enum can lead to name clashing, which can be avoided through scoped enum.




## 05_struct_class.cpp

[link to file](./05_struct_class.cpp)

The program implements a very simple `struct` and a very simple `class` to show the different *default* visibility of their members.


PPP: 9.2, 9.3 and 9.4
CPL: chap 16 for classes, in particular chap 16.2.4 (class and struct)


## 06_operator_overloading.cpp

[link to file](./06_operator_overloading.cpp)

A simple example about **operator overloading**. The `friend` keyword is addressed as well.

PPP: 9.6
CPL: 3.2.1.1 (for a quick example), chap 18 for all the details


## 07_constructor_destructor.cpp

[link to file](./07_constructor_destructor.cpp)

This example introduces you to the concepts of *constructor* and *destructor* of a class. Here you can also find the first example of *operator overloading*.

PPP: chap 9.4.2 constructors, chap 17.5 destructors, chap 9.6 operator overloading
CPL: chap 16.2.5 constructors, chap 17.2 constructors and destructors, chap 18 operator overloading



## 08_template_class.cpp

[link to file](./08_template_class.cpp)

A naive implementation of a vector class, using the template for the type stored in the vector.




###References:

[PPP] = Programming: Principles and Practice using C++ (Second Edition), Bjarne Stroustrup, Addison-Wesley 2014, ISBN 978-0-321-99278-9

[CPL] = The C++ Programming Language, Bjarne Stroustrup, Addison-Wesley 2013, ISBN 978-0321563842

# Exercises - session 02

## Reverse order

- Write a program that reads from stdin the length of an array and then stores in it the numbers given from stdin. The program should then print the numbers in **reverse order**. Remember to free the used memory properly. Divide the problem into two parts:

  1. Write one **template** function that allocates on the *heap* one array of a given size, initializes its elements, and returns the pointer to the first element.

  2. Write a **template** function that prints the elements of an array in the reverse order.

- Test with integers and doubles.

- Use `std::size_t`.

  ​

*Hints*: 

- If you have to pass an array to a function, pass the pointer to its first element and the size of the array itself.


- Remember to check your code with `valgrind`. If you have a MAC, you might have nasty surprises. Run `valgrind` on a **Linux**  system. Alternatively, compile and link your code with the following flags

  `-g -fsanitize=address`  and then run your executable. If it runs fine, you have no memory leaks. If it doesn't, you have some.

  ​

## Prime numbers

- Populate an array named `primes` containing the first prime numbers smaller than 100. Consider 2 as the first prime (i.e. `primes[0] == 2`).
  
  - you are free to choose the design and the implementation.

  - please comment and motivate your choices (e.g., allocate one big
    array, or every time I find a new prime number I increase the size of
    the previous `primes` array, etc.)

*Hints*:

- The remainder of a division between two integers is computed as follows:
```c++
unsigned int remainder = 6%3;
```
- Inside a for loop, you can use `continue` to immediately go to the next iteration, `break` to exit the loop. Note that if you have two or more nested loops, the statements affect only the innermost loop.



## Sieve of Eratosthenes

- Implement the Sieve of Eratosthenes algorithm. Write a code that prints on screen the first prime numbers up to `N` **included**, where `N` is read from stdin. The first printed number is `2`.

```shell
$ ./a.out 
insert number: 5
2
3
5

$ ./a.out
insert number: 10
2
3
5
7
```

*Hints*:
- https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes :)

- the function `std::sqrt`, which computes the square root of a number, is defined in `<cmath>`
```c++
#include <cmath>
...
std::cout << std::sqrt(4) << std::endl;
```

## **Optional**: Use `std::vector`
Re-implement the exercises *Prime numbers* and *Sieve of Eratosthenes* using `std::vector` instead of built-in arrays. `std::vector` is defined in the header `<vector>`.

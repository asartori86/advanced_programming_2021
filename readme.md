# Advanced Programming [![Build Status](https://app.travis-ci.com/asartori86/advanced_programming_2021.svg?branch=master&status=created)](https://app.travis-ci.com/asartori86/advanced_programming_2021.svg?branch=master&status=created)

The course aims to provide advanced knowledge of both theoretical and practical programming in C++14 and Python3, with particular regard to the principles of object-oriented programming and best practices of software development.

Syllabus:

- Introduction to C++14. You will learn the logic and the basics of C++14, the built-in data types and how to effectively use them. Best practices in programming will be addressed.
- Object orientation in C++14. The principles of Object-Oriented programming will be presented with particular attention to their implementations in C++14. Some of the most important Design Patterns will be discussed.
- Python3. After a recap of the basics of Python3, you will learn how to program in object-oriented fashion in the Python3 programming language.
- How to combine the two languages. Several methods to combine the two languages will be presented.

## Where

- In-person lectures: University of Trieste, H2bis building, Morin room
- Remotely: via Microsoft Teams. Please join the team [here](https://teams.microsoft.com/l/team/19%3aTegYLBJNdVQcFJpcipzwG8ILBHr_PoZ_8rF-FyhOx1I1%40thread.tacv2/conversations?groupId=3c567ab0-fc8d-4af8-9fb5-5f7f4e6fcf54&tenantId=a54b3635-128c-460f-b967-6ded8df82e75). If you cannot join it, please let me know.

## When
First lecture **Monday, October 11, 2021**, then each Monday and Friday.

- Monday 14-16
- Friday 14-18

## Contact me
- email: `asartori@ictp.it`, `alberto.sartori@sissa.it`
- office: 107 old SISSA building via Beirut

## Prerequisites
- Familiarity with linux terminal and a text editor (e.g., emacs, vim)
- A bit of knowledge of git

## References

- Programming: Principles and Practice using C++ (Second Edition),
  Bjarne Stroustrup, Addison-Wesley 2014, ISBN 978-0-321-99278-9

- The C++ Programming Language, Bjarne Stroustrup, Addison-Wesley
   2013, ISBN 978-0321563842

- Fluent Pyhton. Clear, concise, and effective programming, Luciano Ramalho, O'Reilly 2015, ISBN 978-1-491-946000-8



## How to get the material
### Non-experienced git users
- Very first time `(N==0)`
  - open a terminal
  - `cd` in a suitable folder
  - `git clone https://github.com/asartori86/advanced_programming_2021.git`
  - `cd advanced-programming_2021`
  - take a look at [software carpentry lecture](http://swcarpentry.github.io/git-novice/) and [pro git book](https://git-scm.com/book/en/v2) 
- `N > 0`
  - open a terminal
  - `cd` to the folder `advanced-programming_2021`
  - `git pull origin master`
- if(conflict)
  - ask

### Experienced git users
- Very first time `(N==0)`
  - fork the repository
  - clone either your fork or this repository
  - add the other remote
- `N >= 0`
  - use branches
  - rebase on the correct master branch
  - merge the branches in your local master
  - push on the master of your fork
- if(conflict)
  - if(rebase)
    - `git add`
    - `git rebase --continue`
    - if(bigger mess)
      	- `git rebase --abort`
  - if(merge)
    - `git add`
    - `git commit`
    - `git merge --continue`
    - if(bigger mess)
      - `git merge --abort`

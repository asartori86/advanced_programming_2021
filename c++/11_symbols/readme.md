## 09 - Symbols

In this lecture, we deal with the *visibility* of the symbols among different compilation units. In particular:
- [01_greetings_library](./01_greetings_library): we discover how to generate a shared library, and how to compile "many" different files, split into headers and source files, that compose the library itself.
- [02_link_library](./02_link_library): how to use the generated library (i.e., how to link against it)
- [03_internal_external](./03_internal_external): symbols (i.e., functions and variables) can have **internal** or **external** linkage (i.e., visibility). There are two keywords to control the visibility of a symbol: `extern` for the external linkage, `static` for the internal.
- [04_static](./04_static): the `static` keyword has other meanings if applied in different contexts. It can let a local variable remember the previous value among function calls; or define a variable shared among all the objects of the same class.
- [05_one_definition_rule](./05_one_definition_rule): a collection of rules shape the so-called one-definition-rule, which dictate the avoidance of symbol repetition, i.e., a symbol can be **defined** only once.

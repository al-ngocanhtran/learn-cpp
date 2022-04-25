# C++ Objects and Class
## Definitions
- A class is a user-defined data type that can be used in programs and works as an object constructor. To create a class, we use the `class` keyword, followed by class name. A class name should be a verb, written in `CamelCase` that starts with a capital letter, and no special character, including `_` allowed.
- In C++, an object is created from a class. Multiple objects can be created of one class.
## C++ Built-in Functions

Library functions, also called built-in functions, are functions that already available and implemented across objects and can be directly called withou definition.

Common built-in functions can be found to perform mathematics operations (ie. `cos()`, `tan()`, `ceil()`,...) or manipulate strings. Those common functions are found in the cmath and cstdlib libraries. For more details, refer to [Microsoft's C++ Standard Library Reference](https://docs.microsoft.com/vi-VN/cpp/standard-library/cpp-standard-library-reference?view=msvc-170). 

## Inheritance
C++ allows single, multi-level as well as multiple inheritance.

In cases of multiple inheritance, there are two concepts: 
-  `base class` or parent 
- `derived class` (child): the class the inherits from another (parent) class. The child class inherits the attributes and methods from the parent class using the `:` symbol.
    Example: 
    ```
    Class Brand { //Base class
        public: 
            string brand = "No-brand";   
    }
    
    Class Bags: public Brand { //derived class
        public:
        string model = "X01";
        string color = "blue";
    }
    ```
## Access Specifier
Thre are three specifiers in C++. 
-  `public`: members of a class are accessible from outside the class.
-  `private`: members can only be accessed within the class, not including inherited class(es). 
- `protected`: members can only be accessed within the class and inherited class(es).

Declaring class variables/attributes as `private` or `protected` can help encapsulate and hide sensitive data from users. 

## References:
- https://www.w3schools.com/cpp/






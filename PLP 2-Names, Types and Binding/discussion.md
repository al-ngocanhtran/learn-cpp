# C++ Naming, Types and Binding#

### Keywords / Reserved Words ###
Keywords have special meaning for C++ compilers. Some common keywords are `void`, `int`, `public`, ... There are 48 keywords, and for full listing, see [this link](https://www.geeksforgeeks.org/cpp-keywords/). 

### Operators ###
C++ has many built-in operators that are categorized as follow: 
1. Arithmetic Operators: are divided into 2 types: 
    - Unary Operators: for example: Increment(++) and Decrement(–) Operators
    - Binary Operators: operators that work with 2 operands. For example: Addition(+), Subtraction(-), multiplication(*), Division(/)
2. Relational Operators: used for value comparison between 2 operands. Examples: ==, >= , <=
3. Logical Operators: && (and), || (or), ! (not equal)
4. Bitwise Operators: used to perform bit-level operations on the operands. The mathematical operations such as addition, subtraction, multiplication, etc. can be performed at bit-level for faster processing.
5. Assignment Operators: used to assigning value to a variable. Example: `=`, `+=`, `-=`, `*=`, `/=`
6. Other Operators: 
    - sizeof operator: used to compute the size of a variable
    - conditional operator: can be used instead of if..else statements
        Format:  form Expression1? Expression2: Expression3.
        - Expression1 is the condition to be considered, if Expression1 is True, execute and return result of Expression2, otherwise return result of Expression3. 

### Naming Convention ###
1. Class: 
    - The class name should be a noun.
    - Use camelCase (use upper case letters as word separators, lower case for the rest of the word).
    - The first character in the class name must be upper case.
    - Underscores (‘_’) are not permitted in the class name.

2. Functions and Function Argument Names
    - Each method/ function name should begin with a verb.
    -  Functions follow the same naming convention as class names.
3. Variables
    - The variable name should begin with an alphabet.
    - Digits may be used but only after the alphabet.
    - No special symbols can be used in variable names except for the underscore(‘_’).
    - Variable names can't contain keywords.

    *Pointer variables* should be prepended with ‘p’ and place the asterisk ‘*’ close to the variable name instead of pointer type.

    *Static variables* should be prepended with ‘s’.

4. Constants: Constants should be all capital letters with ‘_’ separators. For example, MAX_INT, TWO_PI, etc.

5. File Naming: 
    - Special characters are not allowed except for underscore (‘_’) and dash (‘-‘).
    - The file name should end with the `.cc` or `.cpp` extension.
    - Do not use filenames that already exist in /user/include. or any predefined header file name.
(Source: )

### Typing ###
C++ is a statistically typed and explicit language, as the type will be inferred by the compiler at compile time.
### Mixed-type operation ###
C++ allows mixed-type arithmetic. For example, you can multiply an integer and floating point number using multiplication operator.

# Reference #
[GeeksforGeeks C++ tutorial](https://www.geeksforgeeks.org/c-plus-plus/?ref=shm) 
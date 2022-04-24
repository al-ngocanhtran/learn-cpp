# C++ Loops and Subroutines

## C++ Loops
 
C++ allows multiple types of loop, including: 
- `for` loop: executes a statement inside the codeblock for a number of repetitions
- `while` loop: executes a statement inside the codeblock as long as a given condition is true
- `do...while` loop: checks its condition at the bottom of the loop and execute like `while` statement, except that the codeblock is always executed at least once, regardless of the check condition.
- nested loop: one or more loops can be nested inside another loop.

## C++ Functions

Every C++ program needs to have at least one function to run, which is `main()`.

- Declaration:  
A function declaration tells the compiler about a function's name, return type, and parameters. A function definition provides the actual body of the function following this general form: 
```
return_type function_name( parameter list ) {
   body of the function
}
```
- Parameters: C++ functions can accept multiple parameters of different data types, each separated by a comma. We can also use a default parameter by using the equal sign. 
```
// Example: 
void Country(string country = "Poland") {
  cout << country << "\n";
}
//if Country is called without an argument, the default value printed will be Poland.

```
- Return values: While C++ does not offer an official way to return multiple values from a single function, there are different ways to get around this. 
- Call types: By default, C++ uses call-by-value to pass arguments. In addition, it also allows pass by reference, in which reference(s) passed into a function. Solutions include return using References, Class and Object or STL tuple. 
- Recursion: C++ supports recursive functions, whose execution repeats until the condition of the base case is met. To avoid infinite recursion, To prevent infinite recursion, `if...else` statement (or similar approach) can be used to define the base case.
- Function overloading: With function overloading, multiple functions can have the same name with different parameters. 

Example: 
```
int sampleFunc(int x) {
    return x;
}
float sampleFunc(float x) {
    return x;
}
double sampleFunc(double x, double y){
    return x+y;
}

```

## References:
- https://www.w3schools.com/cpp/
- https://www.tutorialspoint.com/cplusplus/cpp_functions.htm
- https://www.educative.io/edpresso/how-to-return-multiple-values-from-a-function-in-cpp17




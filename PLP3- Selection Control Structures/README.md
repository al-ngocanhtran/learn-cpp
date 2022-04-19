# PLP3 - C++ Selection Control Structure


## Boolean Values & Expressions 
C++ has a `bool` data type that takes values `true` (1) or `false` (0).
A boolean variable declared with the bool keywork can only take values `true` or `false`, and return 1 or 0 respectively. (see sample code file).
However, it is more often to retrieve boolean values from a boolean expression.


## Conditional Statements
C++ supports common logical operations from mathematics (`!=`,`==`, `>`, `<`, `<=`, `>=`) and following conditional statements: 
- `if` to specify a block of code to be executed if a specified condition is true
- `else` to specify a code block to be executed if the same condition is false
- `else if` to specify a new condition to test, if the first condition is false
- `switch` to specify alternative code blocks to be executed

Syntax:
- If/else statement (full)
``` 
if (condition1) {
  // execute if condition1 is true
} else if (condition2) {
  // execute if condition1 is false and condition2 is true
} else {
  // execute if all conditions above is false
```
- Shorthand if/else statement
Simple if/else statements can be replaced by a shorthand if/else. A short-hand if/else, known as ternary operator, consists of 3 operands.
```
variable = (condition) ? expressionTrue : expressionFalse;
```

## Switch Statements 
Syntax:
```
switch(expression) {
  case x:
    // code block
    break;
  case y:
    // code block
    break;
  default:
    // code block
}
```
Operation:
- The `switch` expression is evalued once, whose value is compared with values of each case. If values match, the specified block of code will be executed. 
- The `break` keyword breaks out of the switch block, which means following case will be ignored and the execution of following codes inside the switch block will be terminated.
- The `default` keyword specify codes to run in case there is no case match. The default keyword must be used as the last statement in the switch, and does not need a `break` keyword.


## Short circuit 
C++ uses short-circuit evaluation in && and || to avoid unnecessary executions.
If the left hand side of || returns true the right hand side does not need to be evaluated anymore. If the left hand side of && returns false the right hand side will not need more evaluation.


## Handling "dangling-else" problems 
A dangling else problem occures when there are many nested `if` statements that the `else` part can't make clear which `if` to combine.
C++, also Java and C, resolves the problem using the following **rule**:
>"An else keyword always associates with the nearest preceeding if keyword that does NOT cause a syntax error."

To illustrate: 

```
if (condition1):
    if (condition2):
        // so something 
    else:
        // do something else
```
In this case, the `else` keyword will be associated with the second `if`, which is the nearest if, given that it does not yields any syntax errors.


See specific example in sample code file.

Sources: 
- https://www.w3schools.com/cpp/ 
- https://www.geeksforgeeks.org/short-circuiting-in-c-and-linux/ 
- http://www.mathcs.emory.edu/~cheung/Courses/561/Syllabus/2-C/dangling-else.html 
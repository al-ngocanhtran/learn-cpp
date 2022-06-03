#include <iostream>
#include <string>
#include <cmath>
#include <cstring>  
using namespace std;

//Sample code of C++ loops and subroutines

// Split String using strtok() function 
//The C library function char *strtok(char *str,
// const char *delim) breaks string str 
//into a series of tokens using the delimiter delim.
// Declaration: char *strtok(char *str, const char *delim)
//str − The contents of this string are modified and broken into smaller strings (tokens).
// delim − C string containing the delimiters.
 
void splitString(char* str)
{   
    char *ptr; //declare a pointer
    ptr = strtok(str, " ");
    while (ptr != NULL){
        cout << ptr << endl;
        ptr = strtok(NULL, " ");
    }

}

// Return multiplication of 2 integers
int multiply(int x, int y)
    {return x*y;} 

// Recursive function to calculate factorial of a number
int factorial(int n)
{
    if (n > 1) {
        return n * factorial(n - 1);
    } else {
        return 1;
    }
}

int main () 
{
    // A typical or-loop with a single statement as the body
    // Printing number from 0 to 9
    for (int i = 0; i < 10; ++i)
        std::cout << i << ' ';
    // A typical while loop to print even number from 2 to 20
    int j = 2;
    while (j < 21) {
        std::cout << j << ' ';
        j += 2;
    }
    std::cout << '\n';

    //do while statement to print even number from 2 to 20
    int x = 20;
    do { // compound statement is the loop body
        std::cout << j << " ";
        j += 2;
    } while (j < 20);
    std::cout << '\n';

    //forEach loop to print elements in an array (introduced in C++ 11)
    string arr[] = { "apple", "cider", "vinegar", "banana"};
    for (string word : arr){
        cout << word << endl;
    }

    int x = 20;
    int y = 21;
    int result = multiply(x, y);
    cout << "20 * 21 = " << result << endl;
    // Print result of recursive function
    cout << "Factorial of 20 = " << factorial(20) << endl;

    char* str = "Have fun learning C++";
    splitString(str);

    return 0;
}

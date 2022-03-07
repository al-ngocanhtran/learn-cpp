/*
Sample code: Creating Variables of Common Data Types in C++
Author: Tran Ngoc Anh
*/

#include <iostream>
using namespace std;

int main() {
    int age  = 21; //int variable
    float area = 64.1234; //float variable
    double volume = 134.1245668; //double variable
    char letter = 'n'; //char variable
    int arr[3] =  {1, 3, 5}; //int array variable
    char strArr[10] = "Hello"; //C-string variable
    int* pointAge = &age; //declare pointer variable assigned to age variable 
    
    struct Product 
    {
        char name[30];
        float amount;
        float price; 
    };

    Product candyBar;

    //print variables
    cout << "Sample int: "<< age << endl;
    cout << "Sample float: "<< area << endl;
    cout << "Sample char: "<< letter << endl;
    cout << "Sample C-String: "<< strArr << endl;
    cout << "Sample pointer: "<< pointAge << endl;

    return 0;
}



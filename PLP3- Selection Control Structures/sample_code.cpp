#include <iostream>
#include <string>

using namespace std;

int n;

//shorthand statement to check whether input is odd or even
string shorthand(int n){
    string message = "";
    message = (n % 2 == 0) ? "input is even." : "input is odd.";
}

//standard if-else statement to check whether input is odd or even
string check_if_else(int n)
{
    string message = "";
    if  (n == 0)
    {
        message = "input is 0";
    }
    else if ( n % 2 == 0) 
    {
        message = "input is even";
    } 
    else { message = "input is odd";}
    
    return message;
}

//switch case statement to check whether input is odd or even
void switch_case(int n){
    switch(n % 2 == 0) 
    {
        case true:
            cout << "input is odd";
            break;
        case false: 
            cout << "input is even";
            break;
    }
        
}

bool ticketCheck(int restriction, int p_age){
    if (restriction == 0) {
        return true;
    } else if (restriction != 0 && p_age >= restriction) {
        return true;
    } else {
        return false;
    }   
}

int main() {

  cout << "Enter an integer: ";
  cin >> n;

  cout << check_if_else(n);
  cout << shorthand(n);
  switch_case(n);

   int age_restriction_X = 18;
   int age_restriction_Y = 0;
   int age_A = 19;
   int age_B = 16;
   bool can_access_A = ticketCheck(age_restriction_X, age_A);
   bool can_access_B = ticketCheck(age_restriction_Y, age_B);
   bool can_access_C = ticketCheck(age_restriction_X, age_B);
   cout << "A can watch movie X: " << can_access_A << endl;
   cout << "B can watch movie Y: " << can_access_A << endl;
   cout << "B can watch movie X: " << can_access_A << endl;

    //short-circuiting
    int a = 1, b = 1, c = 1;
    if (a == b && c++) {
        cout << "Value of 'c' will increment as there is no short circuit"
             << endl;
    }
    else {
        cout << "Value of 'c' will not increment due to short circuit"
             << endl;
    }
  return 0;
}
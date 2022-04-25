#include <iostream>
using namespace std;

//Base Class
class Master{
    public: 
        string name;
        
        Master(string str){
            name = str;
        }

        void feed(){
            cout << name << " is feeding " << endl;
        }
};

//derived class
class Animal: public Master{
    public: 
        string type;
        int amount;

        Animal(string type, int amount){
            type = type;
            amount = amount;
        }

        void displayInfo(){
            if (amount <= 1){
                cout << amount << " "<< type << " is taken care. " << endl;
            } else {
                cout << amount << " " << type << "s are taken care." << endl;
            }
        }
};

int main(){
    //Create object of derived class
    Master p1("Amy");
    Animal dogs("poodle", 1);
    dogs.feed();
    cout << dogs.amount << " " << dogs.type << endl;
}


//Give the object class attributes 
// Give the object functions
//Create an object that inherits from the first object 
//Test how to instantiate both types of objects, call their functions, and modify their variables.

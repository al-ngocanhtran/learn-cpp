#include <iostream>
#include <string>
using namespace std;

//Base Class
class Garage{
    public: 
        Garage();
        string name;
        string brand; 
        int year;
        char* license_num;
        void displayInfo()
        {
            std::cout << "Car:" << name << std::endl;
            std::cout << "Brand:" << brand << std::endl;
            std::cout << "Age:" << year << std::endl;
            std::cout << "License Number:" << license_num << std::endl;
        }
};

//derived class
class Car: public Garage{
    public: 
        string name;
        string brand; 
        int year;
        char* license_num;
        
        Car::Car(string name, string brand, int year, char* license_num){
            name = name; 
            brand = brand;
            year = year;
            license_num = license_num;
        }

        void displayInfo();

};

int main(){
    //Create object of derived class
    Garage gara1 = Garage();
    Car car1 = Car("Mercedes", "Mercedes-Benz", "1999", "X1345");
    car1.displayInfo();
    return 0;
}


//Give the object class attributes 
// Give the object functions
//Create an object that inherits from the first object 
//Test how to instantiate both types of objects, call their functions, and modify their variables.

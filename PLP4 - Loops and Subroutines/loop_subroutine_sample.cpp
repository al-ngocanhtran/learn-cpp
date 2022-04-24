#include <iostream>
#include <tuple>
using namespace std;
/* 
void test1(int x, double y, string z){
    std::cout << "A function accepts parameters of different types" << std::endl;
}
*/

tuple<int, float, string> test2() {
    return returnVals(10, 2.0, "a string value");
}

int main () {
    auto [x, y, z] = test2();
    std::cout << x << ", " << y << ", " << z << std::endl;
}

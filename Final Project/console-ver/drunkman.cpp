#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>

using namespace std;
int main() {

    srand(time(0));
    const int space=60;
    int score = 0; 
    cout << "Keep the drunk man from falling \n ";
    cout << "Press any key to start \n ";
    cin.get();
    char drunkman = '&';
    int position = space /2;
    while (true) {
        cout << "|BUSH|" ;
        for (int i=0; i<space;i++) {
        if (i == position) 
            cout << drunkman;
        else cout << " ";}
        cout << "|BUSH|" << endl;
        int move= rand()%2;
        position = position + move;
        score += 1; 
        if ((position < 1) || (position > space -1)) {
            cout << "Uh oh, drunk man fells!" <<endl; 
            cout << "Your score:" << score <<endl;
            break;
        }

        for(int sleep=0; sleep < 10000 ; ++ sleep);
    }
    return 0;
}

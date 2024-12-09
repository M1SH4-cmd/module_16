#include <iostream>
using namespace std;

enum note{
    DO = 1, //1
    RE = 2, //2
    MI = 4, //3
    FA = 8, //4
    SOL = 16, //5
    LA = 32, //6
    SI = 64 //7
};

int main(){
    string input;
    cout << "Enter an accord (set of numbers 1-7:\t)";
    cin >> input;

    int notes = 0;

    for (char c : input) {
        if (c >= '1' && c <= '7') {
            int noteIndex = c - '1';
            notes |= (1 << noteIndex);
        }
    }

    cout << "Chosen notes:" << endl;

    if(notes & DO) cout << "DO ";
    if(notes & RE) cout << "RE ";
    if(notes & MI) cout << "MI ";
    if(notes & FA) cout << "FA ";
    if(notes & SOL) cout << "SOL ";
    if(notes & LA) cout << "LA ";
    if(notes & SI) cout << "SI ";

}
#include <iostream>
#include <sstream>
using namespace std;

int main(){
    string input;
    cout << "Enter a problem:\t";
    cin >> input;

    stringstream buffer(input);
    double num1;
    double num2;
    char op;

    buffer >> num1 >> op >> num2;

    switch(op){
        case '+': cout << "Result:" << num1 + num2 << endl;
        case '-': cout << "Result:" << num1 - num2 << endl;
        case '/': cout << "Result:" << num1 / num2 << endl;
        case '*': cout << "Result:" << num1 * num2 << endl;
        default: cout << "Invalid operator." << endl;
    }


    return 0;
}

#include <iostream>
using namespace std;

int main(){
    string integerPart;
    string floatingPart;

    cout << "Введите целую и дробную часть через пробел" << endl;
    cin >> integerPart >> floatingPart;

    integerPart += "." + floatingPart;
    double num = stod(integerPart);
    cout << num << endl;
}
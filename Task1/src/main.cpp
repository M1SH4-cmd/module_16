#include <iostream>
using namespace std;

int main(){

    const double epsilon = 0.01;
    float totalSpeed = 0;
    float speedDelta;
    char speed_str[16];
    bool machineStopped = totalSpeed - 0 < epsilon;
    do{
        cout << "\nSpeed delta:\t";
        cin >> speedDelta;
        totalSpeed += speedDelta;
        if (totalSpeed > 150) totalSpeed = 150;
        sprintf(speed_str, "Speed:\t%.1f", totalSpeed);
        cout << speed_str;
    }while(totalSpeed >= epsilon);

}

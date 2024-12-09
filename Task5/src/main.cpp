#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

enum switches {
    LIGHTS_INSIDE = 1,
    LIGHTS_OUTSIDE = 2,
    HEATERS = 4,
    WATER_PIPE_HEATING = 8,
    CONDITIONER = 16
};

void manageHeating(int switches_state, int inside_temp, int outside_temp) {
    if (outside_temp < 0) {
        if (!(switches_state & WATER_PIPE_HEATING)) {
            switches_state |= WATER_PIPE_HEATING;
            cout << "Water pipe heating ON!" << endl;
        }
    } else if (outside_temp > 5) {
        if (switches_state & WATER_PIPE_HEATING) {
            switches_state &= ~WATER_PIPE_HEATING;
            cout << "Water pipe heating OFF!" << endl;
        }
    }

    if (inside_temp < 22) {
        if (!(switches_state & HEATERS)) {
            switches_state |= HEATERS;
            cout << "Heaters ON!" << endl;
        }
    } else if (inside_temp >= 25) {
        if (switches_state & HEATERS) {
            switches_state &= ~HEATERS;
            cout << "Heaters OFF!" << endl;
        }
    }
}

void manageOutsideLights(int switches_state, bool movement, int hour) {
    if (hour >= 16 || hour < 5) {
        if (movement) {
            if (!(switches_state & LIGHTS_OUTSIDE)) {
                switches_state |= LIGHTS_OUTSIDE;
                cout << "Outside lights ON!" << endl;
            }
        } else {
            if (switches_state & LIGHTS_OUTSIDE) {
                switches_state &= ~LIGHTS_OUTSIDE;
                cout << "Outside lights OFF!" << endl;
            }
        }
    } else {
        if (switches_state & LIGHTS_OUTSIDE) {
            switches_state &= ~LIGHTS_OUTSIDE;
            cout << "Outside lights OFF!" << endl;
        }
    }
}

void manageConditioner(int switches_state, int inside_temp) {
    if (inside_temp >= 30) {
        if (!(switches_state & CONDITIONER)) {
            switches_state |= CONDITIONER;
            cout << "Conditioner ON!" << endl;
        }
    } else if (inside_temp < 25) {
        if (switches_state & CONDITIONER) {
            switches_state &= ~CONDITIONER;
            cout << "Conditioner OFF!" << endl;
        }
    }
}

void manageColorTemperature(bool lights_inside, int color_temperature, int hour) {
    if (lights_inside) {
        if (hour >= 16 && hour < 20) {
            color_temperature = 5000 - (hour - 16) * (2300 / 4);
        } else if (hour >= 20 || hour < 5) {
            color_temperature = 2700;
        } else {
            color_temperature = 5000;
        }
        cout << "Color temperature: " << color_temperature << "K" << endl;
    }
}

int simulateHour(int hour) {
    cout << "Hour: " << (hour < 10 ? "0" : "") << hour << ":00" << endl;
    hour++;
    if (hour >= 24) {
        hour = 0;
    }
    return hour;
}

int main() {
    int switches_state = 0;
    int inside_temp = 20;
    int outside_temp = 10;
    bool movement = false;
    bool lights_inside = false;
    int color_temperature = 5000;
    int hour = 0;

    for (int day = 0; day < 2; ++day) {
        for (int h = 0; h < 24; ++h) {
            hour = simulateHour(hour);

            cout << "Temperature inside, temperature outside, movement, lights:" << endl;
            string input;
            getline(cin, input);
            istringstream iss(input);
    iss >> inside_temp >> outside_temp >> movement >> lights_inside;

            manageHeating(switches_state, inside_temp, outside_temp);
            manageOutsideLights(switches_state, movement, hour);
            manageConditioner(switches_state, inside_temp);
            manageColorTemperature(lights_inside, color_temperature, hour);
        }
    }
    return 0;
}
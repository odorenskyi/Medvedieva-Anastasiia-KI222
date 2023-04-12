#include <iostream>
#include <cmath>
#include <conio.h>
#include <Windows.h>
#include <iomanip>
#include "ModulesMedvedieva.h"

using namespace std;

int main() {
    char input;

    do {
        cout << "¬вед≥ть л≥тери f, d, s або a: ";
        cin >> input;

        if (input == 'h') {
            s_calculation();
        } else if (input == 'f') {
        } else if (input == 'd') {
        } else if (input == 's') {
        } else if (input == 'a' || input == 'A' || input == 'p') {
            break;
        } else {
            cout << '\a';
        }
    } while (true);

    return 0;
}

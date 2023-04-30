#include <iostream>
#include <cmath>
#include <conio.h>
#include <Windows.h>
#include <iomanip>
#include <fstream>
#include <bitset>
#include "ModulesMedvedieva.h"

using namespace std;

string my_function(int x, int y, int z, int b) {
    return bitset<32>(result).to_string();
}

int main() {
    int x = 10, y = 20, z = 30, b = 4;
    string result = my_function(x, y, z, b);

    ofstream output_file("output.txt", ios::app);
    if (!output_file) {
        cerr << "Помилка відкриття файлу!" << endl;
        return 1;
    }

    output_file << "Результат функції для x=" << x << ", y=" << y << ", z=" << z << ", b=" << b << ": " << result << endl;

    output_file.close();

    return 0;
}

#include <iostream>
#include <fstream>
#include <bitset>
#include <conio.h>
#include <Windows.h>
#include <iomanip>


using namespace std;

int main() {
      string sentence;
      SetConsoleCP (1251);
      SetConsoleOutputCP (1251);

    int b;
    cout << "Введіть число b: ";
    cin >> b;

    ofstream output_file("read.txt", ios::app);
    if (!output_file) {
        cerr << "Помилка відкриття файлу для запису\n";
        return 1;
    }

    output_file << "Число b у двійковому форматі: " << bitset<32>(b).to_string() << endl;

    output_file.close();

    return 0;
}

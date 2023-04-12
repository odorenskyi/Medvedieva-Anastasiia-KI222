#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <iomanip>

using namespace std;

int main() {

    string sentence;
      SetConsoleCP (1251);
      SetConsoleOutputCP (1251);

    unsigned int N;
    cout << "Введіть натуральне число N: ";
    cin >> N;

    int D12 = (N >> 11) & 1;

    if (D12 == 0) {
        int num_zeroes = 0;
        while (N > 0) {
            if ((N & 1) == 0) {
                num_zeroes++;
            }
            N = N >> 1;
        }
        cout << "Кількість двійкових нулів в N: " << num_zeroes << endl;
    } else {
        int num_ones = 0;
        while (N > 0) {
            if ((N & 1) == 1) {
                num_ones++;
            }
            N = N >> 1;
        }
        cout << "Кількість двійкових одиниць в N: " << num_ones << endl;

    }
}

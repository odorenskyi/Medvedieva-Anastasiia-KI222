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
    cout << "������ ����� b: ";
    cin >> b;

    ofstream output_file("read.txt", ios::app);
    if (!output_file) {
        cerr << "������� �������� ����� ��� ������\n";
        return 1;
    }

    output_file << "����� b � ��������� ������: " << bitset<32>(b).to_string() << endl;

    output_file.close();

    return 0;
}

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <iomanip>

using namespace std;

int main() {

    string sentence;
      SetConsoleCP (1251);
      SetConsoleOutputCP (1251);

    float temp_monday, temp_tuesday, temp_wednesday, temp_thursday, temp_friday, temp_saturday, temp_sunday;

    cout << "������ ����������� � ��������: ";
    cin >> temp_monday;

    cout << "������ ����������� � �������: ";
    cin >> temp_tuesday;

    cout << "������ ����������� � ������: ";
    cin >> temp_wednesday;

    cout << "������ ����������� � ������: ";
    cin >> temp_thursday;

    cout << "������ ����������� � �'������: ";
    cin >> temp_friday;

    cout << "������ ����������� � ������: ";
    cin >> temp_saturday;

    cout << "������ ����������� � �����: ";
    cin >> temp_sunday;

    float avg_temp_celsius = (temp_monday + temp_tuesday + temp_wednesday + temp_thursday + temp_friday + temp_saturday + temp_sunday) / 7.0;
    float avg_temp_fahrenheit = avg_temp_celsius * 1.8 + 32.0;

    cout << "������� ������� �����������: " << avg_temp_celsius << " ������� ������ ��� " << avg_temp_fahrenheit << " ������� �� �����������." << endl;

    return 0;
}

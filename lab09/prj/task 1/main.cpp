#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <iomanip>


using namespace std;

int main() {
    string sentence;
      SetConsoleCP (1251);
      SetConsoleOutputCP (1251);

    int score;
    cout << "������ ������� ����: ";
    cin >> score;

    if (score >= 0 && score < 60) {
        cout << "���� ������: FX (�� ����������)" << endl;
    } else if (score >= 60 && score < 65) {
        cout << "���� ������: E (�������� ������)" << endl;
    } else if (score >= 65 && score < 75) {
        cout << "���� ������: D (��������, ��� ������ �������)" << endl;
    } else if (score >= 75 && score < 85) {
        cout << "���� ������: C (��������� ���������, ��� ������ ������� �������)" << endl;
    } else if (score >= 85 && score < 95) {
        cout << "���� ������: B (���� ����������, � ���� �������) " << endl;
    } else if (score >= 95 && score <= 100) {
        cout << "���� ������: A (������ ������ � ��������� ������� �������)" << endl;
    } else {
        cout << "������� ����� �� ������� ������� ����. ��������� �� ���." << endl;
    }

    return 0;
}

#include <iostream>
#include <string>
#include "ModulesLytvyn.h"

int main() {
    string sentence;
 SetConsoleCP (1251);
 SetConsoleOutputCP (1251);

vector<Publication> registry = {
    { "������������ �����", 104, 1, "������", "ʳ������������� �������� ��������������������� ���������������", "23.02.95" },
    { "��������", 10841, 1, "��������-�������", "̳��������� ����� ������������� ���������", "11.08.14" },
    { "���-������", 36612, 1, "������������ �������", "����� ����������� ϳ����", "2006" }
};

char choice;
do {
    cout << "������� ������:" << endl;
    cout << "1. ����� ������" << endl;
    cout << "2. ��������� ������" << endl;
    cout << "3. ������ �����" << endl;
    cout << "4. �������� �����" << endl;
    cout << "5. �����" << endl;
    cin >> choice;
    cin.ignore();
    switch (choice) {
    case '1':
        searchRecord(registry);
        break;
    case '2':
        printRegistry(registry);
        break;
    case '3':
        addRecord(registry);
        break;
    case '4':
        deleteRecord(registry);
        break;
    case '5':
        break;
    default:
        cout << "������� ����." << endl;
        break;
    }
} while (choice != '5');

ofstream outFile("reg2.txt");
  if (outFile.is_open()) {
    for (const Publication& pub : registry) {
        outFile << pub.name << "," << pub.series << "," << pub.number << endl;
}
    outFile.close();
    cout << "����� ��������� � ����." << endl;
}
  else {
    cout << "�� ������� �������� ����." << endl;
}

  return 0;
}

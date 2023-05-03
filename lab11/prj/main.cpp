#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>
#include <Windows.h>
#include <iomanip>

using namespace std;

struct Publication {
    string name;
    int series;
    int number;
    string publisher;
    string developers;
    string date;
};

void searchRecord(const vector<Publication>& registry) {
    string sentence;
 SetConsoleCP (1251);
 SetConsoleOutputCP (1251);

    string searchQuery;
    cout << "������ ����� ��������� ��� ���� �� ����� �������� ��� ������: ";
    getline(cin, searchQuery);
    bool found = false;
    for (const Publication& pub : registry) {
        if (pub.name == searchQuery || (pub.series == stoi(searchQuery.substr(0, searchQuery.find('-'))) && pub.number == stoi(searchQuery.substr(searchQuery.find('-') + 1)))) {
            cout << "�������� ���������: " << pub.name << ", ���� �� ����� ��������: " << pub.series << "-" << pub.number << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "������� �� ��������." << endl;
    }
}

void printRegistry(const vector<Publication>& registry) {
    string sentence;
    SetConsoleCP (1251);
    SetConsoleOutputCP (1251);

    char choice;
    cout << "�� ������ ������� ����� �� ������ (c) �� � ���� (f)? ";
    cin >> choice;
    if (choice == 'c') {
        for (const Publication& pub : registry) {
            cout << "����� �������: " << pub.name << endl;
            cout << "��� �������: " << pub.publisher << endl;
            cout << "����������: " << pub.developers << endl;
            cout << "���� ���������: " << pub.date << endl;
            cout << "���� �� ����� ��������: " << pub.series << "-" << pub.number << endl;
        }
    }
    else if (choice == 'f') {
        string fileName;
        cout << "������ ����� �����: ";
        cin >> fileName;
        ofstream outFile(fileName);
        if (outFile.is_open()) {
            for (const Publication& pub : registry) {
                outFile << "����� �������: " << pub.name << endl;
                outFile << "��� �������: " << pub.publisher << endl;
                outFile << "����������: " << pub.developers << endl;
                outFile << "���� ���������: " << pub.date << endl;
                outFile << "���� �� ����� ��������: " << pub.series << "-" << pub.number << endl;
            }
            outFile.close();
            cout << "����� ������� �� �����." << endl;
        }
        else {
            cout << "��������� ������� ����." << endl;
        }
    }
    else {
        cout << "������� ����" << endl;
    }
}

void addRecord(vector<Publication>& registry) {
    string sentence;
 SetConsoleCP (1251);
 SetConsoleOutputCP (1251);

    string name;
    int series;
    int number;
    string publisher;
    string developers;
    string date;
    cout << "������ ����� �������: ";
    getline(cin, name);

    cout << "������ ���� �� ����� ��������: ";
    cin >> series;
    cin.ignore();

    cout << "������ ��� �������: ";
    getline(cin, publisher);
    cin.ignore();

    cout << "������ ����������: ";
    getline(cin, developers);
    cin.ignore();

    cout << "������ ���� �������: ";
    getline(cin, date);
    cin.ignore();

    registry.push_back({ name, series, number, publisher, developers, date });
    cout << "����� ������." << endl;
}

void deleteRecord(vector<Publication>& registry) {
    string sentence;
 SetConsoleCP (1251);
 SetConsoleOutputCP (1251);

    string searchQuery;
    cout << "������ ����� ��������� ��� ���� �� ����� �������� ��� ���������: ";
    getline(cin, searchQuery);
    bool found = false;
    for (auto it = registry.begin(); it != registry.end(); it++) {
    if (it->name == searchQuery || (it->series == stoi(searchQuery.substr(0, searchQuery.find('-'))) && it->number == stoi(searchQuery.substr(searchQuery.find('-') + 1)))) {
    it = registry.erase(it);
    cout << "����� ��������." << endl;
    found = true;
  }
}
  if (!found) {
    cout << "������� �� ��������." << endl;
  }
}

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

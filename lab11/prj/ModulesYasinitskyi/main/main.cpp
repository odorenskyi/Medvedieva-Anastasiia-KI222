#include <iostream>
#include <string>
#include "ModulesYasinitskyi.h"

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

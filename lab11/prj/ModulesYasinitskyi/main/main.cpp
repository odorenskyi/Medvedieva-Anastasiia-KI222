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
    cout << "Введіть назву видання: ";
    getline(cin, name);

    cout << "Введіть серію та номер свідоцтва: ";
    cin >> series;
    cin.ignore();

    cout << "Введіть вид видання: ";
    getline(cin, publisher);
    cin.ignore();

    cout << "Введіть засновника: ";
    getline(cin, developers);
    cin.ignore();

    cout << "Введіть дату видання: ";
    getline(cin, date);
    cin.ignore();

    registry.push_back({ name, series, number, publisher, developers, date });
    cout << "Запис додано." << endl;
}

void deleteRecord(vector<Publication>& registry) {
    string sentence;
 SetConsoleCP (1251);
 SetConsoleOutputCP (1251);

    string searchQuery;
    cout << "Введіть назву публікації або серію та номер свідоцтва для видалення: ";
    getline(cin, searchQuery);
    bool found = false;
    for (auto it = registry.begin(); it != registry.end(); it++) {
    if (it->name == searchQuery || (it->series == stoi(searchQuery.substr(0, searchQuery.find('-'))) && it->number == stoi(searchQuery.substr(searchQuery.find('-') + 1)))) {
    it = registry.erase(it);
    cout << "Запис видалено." << endl;
    found = true;
  }
}
  if (!found) {
    cout << "Видання не знайдено." << endl;
  }
}

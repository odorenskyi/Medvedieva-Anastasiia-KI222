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
    cout << "Введіть назву публікації або серію та номер свідоцтва для пошуку: ";
    getline(cin, searchQuery);
    bool found = false;
    for (const Publication& pub : registry) {
        if (pub.name == searchQuery || (pub.series == stoi(searchQuery.substr(0, searchQuery.find('-'))) && pub.number == stoi(searchQuery.substr(searchQuery.find('-') + 1)))) {
            cout << "Знайдено публікацію: " << pub.name << ", серію та номер свідоцтва: " << pub.series << "-" << pub.number << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Видання не знайдено." << endl;
    }
}

void printRegistry(const vector<Publication>& registry) {
    string sentence;
    SetConsoleCP (1251);
    SetConsoleOutputCP (1251);

    char choice;
    cout << "Ви хочете вивести реєстр на консолі (c) чи у файл (f)? ";
    cin >> choice;
    if (choice == 'c') {
        for (const Publication& pub : registry) {
            cout << "Назва видання: " << pub.name << endl;
            cout << "Вид видання: " << pub.publisher << endl;
            cout << "Розробники: " << pub.developers << endl;
            cout << "Дата реєстрації: " << pub.date << endl;
            cout << "Серія та номер свідоцтва: " << pub.series << "-" << pub.number << endl;
        }
    }
    else if (choice == 'f') {
        string fileName;
        cout << "Введіть назву файлу: ";
        cin >> fileName;
        ofstream outFile(fileName);
        if (outFile.is_open()) {
            for (const Publication& pub : registry) {
                outFile << "Назва видання: " << pub.name << endl;
                outFile << "Вид видання: " << pub.publisher << endl;
                outFile << "Розробники: " << pub.developers << endl;
                outFile << "Дата реєстрації: " << pub.date << endl;
                outFile << "Серія та номер свідоцтва: " << pub.series << "-" << pub.number << endl;
            }
            outFile.close();
            cout << "Реєстр доданий до файлу." << endl;
        }
        else {
            cout << "Неможливо відкрити файл." << endl;
        }
    }
    else {
        cout << "Невірний вибір" << endl;
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

int main() {
    string sentence;
 SetConsoleCP (1251);
 SetConsoleOutputCP (1251);

vector<Publication> registry = {
    { "Студентський вісник", 104, 1, "газета", "Кіровоградський інститут сільськогосподарського машинобудування", "23.02.95" },
    { "Апостроф", 10841, 1, "інтернет-видання", "Міжнародний центр перспективних досліджень", "11.08.14" },
    { "РБК-Україна", 36612, 1, "інформаційна агенція", "Йосип Геннадійович Пінтус", "2006" }
};

char choice;
do {
    cout << "Виберіть варіант:" << endl;
    cout << "1. Пошук запису" << endl;
    cout << "2. Виведення реєстру" << endl;
    cout << "3. Додати запис" << endl;
    cout << "4. Видалити запис" << endl;
    cout << "5. Вихід" << endl;
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
        cout << "Невірний вибір." << endl;
        break;
    }
} while (choice != '5');

ofstream outFile("reg2.txt");
  if (outFile.is_open()) {
    for (const Publication& pub : registry) {
        outFile << pub.name << "," << pub.series << "," << pub.number << endl;
}
    outFile.close();
    cout << "Реєстр збережено у файл." << endl;
}
  else {
    cout << "Не вдалося зберегти файл." << endl;
}

  return 0;
}

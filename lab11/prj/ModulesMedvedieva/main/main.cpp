#include <codecvt>
#include <fstream>
#include <sstream>
#include <string>
#include "ModulesMedvedieva.h"

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

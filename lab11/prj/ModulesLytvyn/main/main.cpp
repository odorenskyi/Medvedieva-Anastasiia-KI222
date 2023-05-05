#include <iostream>
#include <string>
#include "ModulesLytvyn.h"

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

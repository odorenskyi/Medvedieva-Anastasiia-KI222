#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>
#include <Windows.h>
#include <iomanip>
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
    cout << "Ââåä³òü íàçâó ïóáë³êàö³¿ àáî ñåð³þ òà íîìåð ñâ³äîöòâà äëÿ ïîøóêó: ";
    getline(cin, searchQuery);
    bool found = false;
    for (const Publication& pub : registry) {
        if (pub.name == searchQuery || (pub.series == stoi(searchQuery.substr(0, searchQuery.find('-'))) && pub.number == stoi(searchQuery.substr(searchQuery.find('-') + 1)))) {
            cout << "Çíàéäåíî ïóáë³êàö³þ: " << pub.name << ", ñåð³þ òà íîìåð ñâ³äîöòâà: " << pub.series << "-" << pub.number << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Âèäàííÿ íå çíàéäåíî." << endl;
    }
}

void printRegistry(const vector<Publication>& registry) {
    string sentence;
    SetConsoleCP (1251);
    SetConsoleOutputCP (1251);

    char choice;
    cout << "Âè õî÷åòå âèâåñòè ðåºñòð íà êîíñîë³ (c) ÷è ó ôàéë (f)? ";
    cin >> choice;
    if (choice == 'c') {
        for (const Publication& pub : registry) {
            cout << "Íàçâà âèäàííÿ: " << pub.name << endl;
            cout << "Âèä âèäàííÿ: " << pub.publisher << endl;
            cout << "Ðîçðîáíèêè: " << pub.developers << endl;
            cout << "Äàòà ðåºñòðàö³¿: " << pub.date << endl;
            cout << "Ñåð³ÿ òà íîìåð ñâ³äîöòâà: " << pub.series << "-" << pub.number << endl;
        }
    }
    else if (choice == 'f') {
        string fileName;
        cout << "Ââåä³òü íàçâó ôàéëó: ";
        cin >> fileName;
        ofstream outFile(fileName);
        if (outFile.is_open()) {
            for (const Publication& pub : registry) {
                outFile << "Íàçâà âèäàííÿ: " << pub.name << endl;
                outFile << "Âèä âèäàííÿ: " << pub.publisher << endl;
                outFile << "Ðîçðîáíèêè: " << pub.developers << endl;
                outFile << "Äàòà ðåºñòðàö³¿: " << pub.date << endl;
                outFile << "Ñåð³ÿ òà íîìåð ñâ³äîöòâà: " << pub.series << "-" << pub.number << endl;
            }
            outFile.close();
            cout << "Ðåºñòð äîäàíèé äî ôàéëó." << endl;
        }
        else {
            cout << "Íåìîæëèâî â³äêðèòè ôàéë." << endl;
        }
    }
    else {
        cout << "Íåâ³ðíèé âèá³ð" << endl;
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
    cout << "Ââåä³òü íàçâó âèäàííÿ: ";
    getline(cin, name);

    cout << "Ââåä³òü ñåð³þ òà íîìåð ñâ³äîöòâà: ";
    cin >> series;
    cin.ignore();

    cout << "Ââåä³òü âèä âèäàííÿ: ";
    getline(cin, publisher);
    cin.ignore();

    cout << "Ââåä³òü çàñíîâíèêà: ";
    getline(cin, developers);
    cin.ignore();

    cout << "Ââåä³òü äàòó âèäàííÿ: ";
    getline(cin, date);
    cin.ignore();

    registry.push_back({ name, series, number, publisher, developers, date });
    cout << "Çàïèñ äîäàíî." << endl;
}

void deleteRecord(vector<Publication>& registry) {
    string sentence;
 SetConsoleCP (1251);
 SetConsoleOutputCP (1251);

    string searchQuery;
    cout << "Ââåä³òü íàçâó ïóáë³êàö³¿ àáî ñåð³þ òà íîìåð ñâ³äîöòâà äëÿ âèäàëåííÿ: ";
    getline(cin, searchQuery);
    bool found = false;
    for (auto it = registry.begin(); it != registry.end(); it++) {
    if (it->name == searchQuery || (it->series == stoi(searchQuery.substr(0, searchQuery.find('-'))) && it->number == stoi(searchQuery.substr(searchQuery.find('-') + 1)))) {
    it = registry.erase(it);
    cout << "Çàïèñ âèäàëåíî." << endl;
    found = true;
  }
}
  if (!found) {
    cout << "Âèäàííÿ íå çíàéäåíî." << endl;
  }
}

int main() {
    string sentence;
 SetConsoleCP (1251);
 SetConsoleOutputCP (1251);

vector<Publication> registry = {
    { "Ñòóäåíòñüêèé â³ñíèê", 104, 1, "ãàçåòà", "Ê³ðîâîãðàäñüêèé ³íñòèòóò ñ³ëüñüêîãîñïîäàðñüêîãî ìàøèíîáóäóâàííÿ", "23.02.95" },
    { "Àïîñòðîô", 10841, 1, "³íòåðíåò-âèäàííÿ", "Ì³æíàðîäíèé öåíòð ïåðñïåêòèâíèõ äîñë³äæåíü", "11.08.14" },
    { "ÐÁÊ-Óêðà¿íà", 36612, 1, "³íôîðìàö³éíà àãåíö³ÿ", "Éîñèï Ãåííàä³éîâè÷ Ï³íòóñ", "2006" }
};

char choice;
do {
    cout << "Âèáåð³òü âàð³àíò:" << endl;
    cout << "1. Ïîøóê çàïèñó" << endl;
    cout << "2. Âèâåäåííÿ ðåºñòðó" << endl;
    cout << "3. Äîäàòè çàïèñ" << endl;
    cout << "4. Âèäàëèòè çàïèñ" << endl;
    cout << "5. Âèõ³ä" << endl;
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
        cout << "Íåâ³ðíèé âèá³ð." << endl;
        break;
    }
} while (choice != '5');

ofstream outFile("reg2.txt");
  if (outFile.is_open()) {
    for (const Publication& pub : registry) {
        outFile << pub.name << "," << pub.series << "," << pub.number << endl;
}
    outFile.close();
    cout << "Ðåºñòð çáåðåæåíî ó ôàéë." << endl;
}
  else {
    cout << "Íå âäàëîñÿ çáåðåãòè ôàéë." << endl;
}

  return 0;
}

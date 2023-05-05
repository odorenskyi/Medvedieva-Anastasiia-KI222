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

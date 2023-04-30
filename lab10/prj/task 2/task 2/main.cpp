#include <iostream>
#include <fstream>
#include <ctime>
#include <conio.h>
#include <Windows.h>
#include <iomanip>


using namespace std;

int main() {
      string sentence;
      SetConsoleCP (1251);
      SetConsoleOutputCP (1251);

    ofstream output_file("text 2.txt", ios_base::app);

    if (!output_file.is_open()) {
        cout << "Помилка відкриття файлу" << endl;
        return 1;
    }

    streampos begin, end;
    ifstream file("text 2.txt", ios::binary);
    begin = file.tellg();
    file.seekg(0, ios::end);
    end = file.tellg();
    file.close();
    int size = end - begin;

    time_t now = time(nullptr);
    tm* local_time = localtime(&now);
    char time_str[20];
    strftime(time_str, 20, "%Y-%m-%d %H:%M:%S", local_time);

    output_file << "\nОб'єм файлу: " << size << " байтів\n";
    output_file << "Дата та час дозапису: " << time_str << "\n";

    output_file.close();

    cout << "Інформацію додано до файлу" << endl;

    return 0;
}

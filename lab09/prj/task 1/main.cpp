#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <iomanip>


using namespace std;

int main() {
    string sentence;
      SetConsoleCP (1251);
      SetConsoleOutputCP (1251);

    int score;
    cout << "¬вед≥ть к≥льк≥сть бал≥в: ";
    cin >> score;

    if (score >= 0 && score < 60) {
        cout << "¬аша оц≥нка: FX (не зараховано)" << endl;
    } else if (score >= 60 && score < 65) {
        cout << "¬аша оц≥нка: E (м≥н≥мальна оц≥нка)" << endl;
    } else if (score >= 65 && score < 75) {
        cout << "¬аша оц≥нка: D (непогано, але багато помилок)" << endl;
    } else if (score >= 75 && score < 85) {
        cout << "¬аша оц≥нка: C (правильне виконанн€, але значна к≥льк≥сть помилок)" << endl;
    } else if (score >= 85 && score < 95) {
        cout << "¬аша оц≥нка: B (вище середнього, Ї де€к≥ помилки) " << endl;
    } else if (score >= 95 && score <= 100) {
        cout << "¬аша оц≥нка: A (в≥дм≥нна робота з невеликою к≥льк≥стю помилок)" << endl;
    } else {
        cout << "¬ведене число не в≥дпов≥даЇ к≥лькост≥ бал≥в. —пробуйте ще раз." << endl;
    }

    return 0;
}

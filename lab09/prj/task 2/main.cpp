#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <iomanip>

using namespace std;

int main() {

    string sentence;
      SetConsoleCP (1251);
      SetConsoleOutputCP (1251);

    float temp_monday, temp_tuesday, temp_wednesday, temp_thursday, temp_friday, temp_saturday, temp_sunday;

    cout << "¬вед≥ть температуру в понед≥лок: ";
    cin >> temp_monday;

    cout << "¬вед≥ть температуру у в≥второк: ";
    cin >> temp_tuesday;

    cout << "¬вед≥ть температуру в середу: ";
    cin >> temp_wednesday;

    cout << "¬вед≥ть температуру в четвер: ";
    cin >> temp_thursday;

    cout << "¬вед≥ть температуру в п'€тницю: ";
    cin >> temp_friday;

    cout << "¬вед≥ть температуру в суботу: ";
    cin >> temp_saturday;

    cout << "¬вед≥ть температуру в нед≥лю: ";
    cin >> temp_sunday;

    float avg_temp_celsius = (temp_monday + temp_tuesday + temp_wednesday + temp_thursday + temp_friday + temp_saturday + temp_sunday) / 7.0;
    float avg_temp_fahrenheit = avg_temp_celsius * 1.8 + 32.0;

    cout << "—ередн€ тижнева температура: " << avg_temp_celsius << " градус≥в ÷ельс≥€ або " << avg_temp_fahrenheit << " градус≥в за ‘аренгейтом." << endl;

    return 0;
}

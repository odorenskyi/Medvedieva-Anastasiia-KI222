#include <iostream>
#include <string>
#include <algorithm>
#include <conio.h>
#include <Windows.h>
#include <iomanip>


class ClassLab12_Medvedieva {
private:
    double attribute;

public:
    ClassLab12_Medvedieva(double initialAttribute) {
        attribute = initialAttribute;
    }

    double getAttribute() {
        return attribute;
    }

    void setAttribute(double newAttribute) {
        attribute = newAttribute;
    }

    double calculateSurfaceArea() {
        double surfaceArea = 6 * (attribute * attribute);
    return surfaceArea;
}
};

int main() {
     std::string sentence;
     SetConsoleCP (1251);
     SetConsoleOutputCP (1251);

    ClassLab12_Medvedieva obj(3.14);

    double attributeValue = obj.getAttribute();
    double surfaceArea = obj.calculateSurfaceArea();

    std::cout << "Значення атрибута: " << attributeValue << std::endl;
    std::cout << "Область поверхні: " << surfaceArea << std::endl;

    obj.setAttribute(2.71);

    attributeValue = obj.getAttribute();
    surfaceArea = obj.calculateSurfaceArea();

    std::cout << "Оновлене значення атрибута: " << attributeValue << std::endl;
    std::cout << "Оновлена площа поверхні: " << surfaceArea << std::endl;

    return 0;
}

// source.cpp
#include "Rational.h"
#include <iostream>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Rational z1, z2, z3;

    cout << "Введіть значення для z1:" << endl;z1.Init(1, 1);
    z1.Read();

    cout << "z1: ";
    z1.Display();
    cout << ", значення: " << z1.value() << endl;
    z1.Reduce();
    z1.Display();

    cout << "Введіть значення для z2:" << endl;z2.Init(1, 1);
    z2.Read();

    cout << "z2: ";
    z2.Display();
    cout << ", значення: " << z2.value() << endl;

    //  додавання
    z3 = add(z1, z2);
    cout << "z1 + z2: ";
    z3.Display();
    cout << ", значення: " << z3.value() << endl;

    // Інкремент та декремент 
    ++z3;
    cout << "Після префіксного інкременту: " << z3 << endl;

    Rational objPostInc = z3++;
    cout << "Після постфіксного інкременту: " << z3 << " (тимчасовий об'єкт: " << objPostInc << ")" << endl;

    --z3;
    cout << "Після префіксного декременту: " << z3 << endl;

    Rational objPostDec = z3--;
    cout << "Після постфіксного декременту: " << z3 << " (тимчасовий об'єкт: " << objPostDec << ")" << endl;

    cin.get();
    return 0;
}

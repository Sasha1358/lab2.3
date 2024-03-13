// source.cpp
#include "Rational.h"
#include <iostream>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Rational z1, z2, z3;

    cout << "������ �������� ��� z1:" << endl;z1.Init(1, 1);
    z1.Read();

    cout << "z1: ";
    z1.Display();
    cout << ", ��������: " << z1.value() << endl;
    z1.Reduce();
    z1.Display();

    cout << "������ �������� ��� z2:" << endl;z2.Init(1, 1);
    z2.Read();

    cout << "z2: ";
    z2.Display();
    cout << ", ��������: " << z2.value() << endl;

    //  ���������
    z3 = add(z1, z2);
    cout << "z1 + z2: ";
    z3.Display();
    cout << ", ��������: " << z3.value() << endl;

    // ��������� �� ��������� 
    ++z3;
    cout << "ϳ��� ����������� ����������: " << z3 << endl;

    Rational objPostInc = z3++;
    cout << "ϳ��� ������������ ����������: " << z3 << " (���������� ��'���: " << objPostInc << ")" << endl;

    --z3;
    cout << "ϳ��� ����������� ����������: " << z3 << endl;

    Rational objPostDec = z3--;
    cout << "ϳ��� ������������ ����������: " << z3 << " (���������� ��'���: " << objPostDec << ")" << endl;

    cin.get();
    return 0;
}

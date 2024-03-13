// Rational.cpp
#include "Rational.h"
#include <iostream>
#include <sstream>

using namespace std;

Rational::Rational() : numerator(0), denominator(1) {}
Rational::Rational(int a, int b) : numerator(a), denominator(b) {
    Reduce();
}
Rational::Rational(const Rational& other) : numerator(other.numerator), denominator(other.denominator) {}

Rational::~Rational() {}

void Rational::Reduce() {
    int gcd = 1;
    int smaller = (numerator < denominator) ? numerator : denominator;

    for (int i = 2; i <= smaller; ++i) {
        if (numerator % i == 0 && denominator % i == 0) {
            gcd = i;
        }
    }

    if (gcd > 1) {
        numerator /= gcd;
        denominator /= gcd;
    }
}
void Rational::SetA(int value) {
    numerator = value;
}
void Rational::SetB(int value) {
    denominator = value;
}

bool Rational::Init(int a, int b) {
    numerator = a;
    denominator = b;

    if (b == 0) {
        return false;
    }
    else {
       // Reduce();
        return true;
    }
}
void Rational::Read() {
    do {
        cout << "¬вед≥ть a: ";
        cin >> numerator;
        cout << "¬вед≥ть b: ";
        cin >> denominator;
        Reduce();
    } while (!Init(numerator, denominator));
}
void Rational::Display() const {
    cout << numerator << "/" << denominator;
}

const char* Rational::toString() const {
    stringstream sout;
    sout << numerator << "/" << denominator;
    return sout.str().c_str();
}

ostream& operator<<(ostream& out, const Rational& rational) {
    out <<"A =" << rational.GetA() <<", B =" << rational.GetB();
    return out;
}
Rational& Rational::operator=(const Rational& other) {
    if (this != &other) {
        numerator = other.numerator;
        denominator = other.denominator;
    }
    return *this;
}
Rational::operator std::string() const {
    return toString();
}
Rational& Rational::operator++() {
    numerator += denominator;
    Reduce();
    return *this;
}
Rational Rational::operator++(int) {
    Rational temp = *this;
    numerator += denominator;
    Reduce();
    return temp;
}
Rational& Rational::operator--() {
    numerator -= denominator;
    Reduce();
    return *this;
}
Rational Rational::operator--(int) {
    Rational temp = *this;
    numerator -= denominator;
    Reduce();
    return temp;
}


Rational add(const Rational& l, const Rational& r) {
    Rational result(l.GetA() * r.GetB() + r.GetA() * l.GetB(), r.GetB() * l.GetB());
    result.Reduce();
    return result;
}
Rational sub(const Rational& l, const Rational& r) {
    Rational result(l.GetA() * r.GetB() - r.GetA() * l.GetB(), r.GetB() * l.GetB());
    result.Reduce();
    return result;
}
Rational mul(const Rational& l, const Rational& r) {
    Rational result(l.GetA() * r.GetA(), l.GetB() * r.GetB());
    result.Reduce();
    return result;
}
double Rational::value() const {
    return static_cast<double>(numerator) / denominator;
}
// Rational.h
#pragma once
#include <iostream>

class Rational {
private:
    int numerator;
    int denominator;

public:
    Rational();
    Rational(int a, int b);
    Rational(const Rational& other);
    ~Rational();

    double GetA() const { return numerator; }
    double GetB() const { return denominator; }
    void SetA(int value);
    void SetB(int value);

    bool Init(int, int);
    void Read();
    void Display() const;
    const char* toString() const;

    void Reduce();
    double value() const;

    friend Rational add(const Rational& l, const Rational& r);
    friend Rational sub(const Rational& l, const Rational& r);
    friend Rational mul(const Rational& l, const Rational& r);

    Rational& operator=(const Rational& other);
    operator std::string() const;
    Rational& operator++();
    Rational operator++(int);
    Rational& operator--();
    Rational operator--(int);

    friend std::ostream& operator<<(std::ostream& out, const Rational& rational);
};

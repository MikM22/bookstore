#ifndef COMPLEX
#define COMPLEX

//********************************************************************
//
// complex.h
// CSCI 241 Assignment 6
//
// Created by Mik Mieczkowski(z2010367),
// Avi Schmookler (z2005237)
// 
//
//********************************************************************
#include <tuple>
using std::tuple;

class complex {
    friend std::ostream& operator<<(std::ostream&, const Rational&);
    friend std::istream& operator>>(std::istream&, Rational&);

    double real;
    double imag;
public:
    complex(double = 0, double = 0);
    void set_complex(double, double);
    tuple<double, double> get_complex() const
    void set_real(double);
    double get_real();
    void set_imaginary(double);
    double get_imaginary();

    Rational operator+(const Rational&) const;
    Rational operator-(const Rational&) const;
    Rational operator*(const Rational&) const;
    Rational operator/(const Rational&) const;

    Rational operator+(int) const;                      
            
    // Overloaded relational operators
    bool operator==(const Rational&) const;
    bool operator<(const Rational&) const;
    bool operator<=(const Rational&) const;
    bool operator>(const Rational&) const;
    bool operator>=(const Rational&) const;
    bool operator!=(const Rational&) const;
}

#endif

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
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;
class complex {
    friend ostream& operator<<(ostream&, const complex&);
    friend istream& operator>>(istream&, complex&);

public:
    complex(double = 0, double = 0);
    void set_complex(double, double);
    tuple<double, double> get_complex() const;
    void set_real(double);
    double get_real() const;
    void set_imaginary(double);
    double get_imaginary() const;

    complex operator+(const complex&) const;
    complex operator*(const complex&) const;
 
    // Overloaded relational operators
    bool operator==(const complex&) const;
private:
    double real{0};
    double imag{0};
};

#endif

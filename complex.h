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
    friend std::ostream& operator<<(std::ostream&, const complex&);
    friend std::istream& operator>>(std::istream&, complex&);

    double real;
    double imag;
public:
    complex(double = 0, double = 0);
    void set_complex(double, double);
    tuple<double, double> get_complex() const;
    void set_real(double);
    double get_real();
    void set_imaginary(double);
    double get_imaginary();

    complex operator+(const complex&) const;
    complex operator*(const complex&) const;
 
    // Overloaded relational operators
    bool operator==(const complex&) const;
    ostream& operator<<(ostream& os, const complex& obj);
    istream & operator>>(istream& is, complex& obj);
}

#endif

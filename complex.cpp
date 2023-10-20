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
#include <iostream>
#include <iomanip>
#include <sstream>
#include "complex.h"

using namespace std;

complex::complex(double real, double imag) {
    this->real = real;
    this->imag = imag;
}
void complex::set_complex(double real, double imag) {
    this->real = real;
    this->imag = imag;
}
tuple<double, double> complex::get_complex() const {
    return make_tuple(real, imag);   
}
void complex::set_real(double real) {
    this->real = real;
}
double complex::get_real() const {
    return real;
}
void complex::set_imaginary(double imag) {
    this->imag = imag;
}
double complex::get_imaginary() const {
    return imag;
}

complex complex::operator+(const complex& other) const {
    return complex(real + other.get_real(), imag + other.get_imaginary());
}
complex complex::operator*(const complex& other) const { 
    return complex(real * other.get_real() - imag * other.get_imaginary(), real * other.get_imaginary() + imag * other.get_real());
}

// Overloaded relational operators
bool complex::operator==(const complex& other) const {
    return real == other.get_real() && imag == other.get_imaginary();
}
ostream& operator<<(ostream& os, const complex& obj) {
    ostringstream output_text;

    // Insert output into a stringstream

    output_text << "(" << obj.get_real() << ", " << obj.get_imaginary() << ")";

    // Convert the stringstream to a string and insert it into the
    // output stream

    os << output_text.str();

    // Return the updated output stream object

    return os;
}
istream& operator>>(istream& is, complex& obj) {
    char leftParen, comma, space, rightParen;

    is.get(leftParen);
    // Read the numerator   
    is >> obj.real;

    // Read and discard '/' character
    is.get(comma);
    is.get(space);

    // Read the denominator
    is >> obj.imag;
    is.get(rightParen);

    // Return the updated input stream object
    return is;
}



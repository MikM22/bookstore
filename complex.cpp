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
    void complex::set_complex(double real, double imag) {
        this->real = real;
        this->imag = imag;
    }
    tuple<double, double> get_complex() const {
        return make_tuple(real, imag);   
    }
    void set_real(double real) {
        this->real = real;
    }
    double get_real() {
        return real;
    }
    void set_imaginary(double imag) {
        this->imag = imag;
    }
    double get_imaginary() {
        return imag;
    }

    complex operator+(const complex& other) const {
        return complex(real + other.get_real(), imag + other.get_imag());
    }
    complex operator*(const complex& other) const { 
        return complex(real * other.get_real() - imag * other.get_imag(), real * other.get_imag() + imag * other.get_real());
    }
 
    // Overloaded relational operators
    bool operator==(const complex& other) const {
        return real == other.get_real() && imag == other.get_imag();
    }
    ostream& operator<<(ostream& os, const complex& obj) {
        ostringstream output_text;

        // Insert output into a stringstream

        output_text = "(" << obj.get_real() << ", " << obj.get_imag() << ")";

        // Convert the stringstream to a string and insert it into the
        // output stream

        os << output_text.str();

        // Return the updated output stream object

        return os;
    }
    istream & operator>>(istream& is, complex& obj) {
        char leftParen, comma, space, rightParen;
   
        is.get(leftParen);
        // Read the numerator   
        is >> obj.get_real();
   
        // Read and discard '/' character
        is.get(comma);
        is.get(space);
   
        // Read the denominator
        is >> obj.get_imag();
        is.get(rightParen);
   
        // Return the updated input stream object
        return is;
    }
}

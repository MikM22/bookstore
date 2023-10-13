#ifndef BOOK_H
#define BOOK_H

//********************************************************************
//
// book.h
// CSCI 241 Assignment 5
//
// Created by Mik Mieczkowski(z2010367),
// Avi Schmookler (z2005237), Matt Ratanapitaksuk (z2003352)
// 
//
//********************************************************************
#include <string>
using namespace std;

class book {
    string isbn;
    string title;
    double price;
    int quantity;
public:
    book();
    book(const string&, const string&, double, int);
    string get_ISBN();
    double get_price();
    int fulfill_order(int);
    void print();

};
#endif 

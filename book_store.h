//***************************************************************************
//
//  book_store.h
//  CSCI 241 Assignment 5
//
//  Created by Mik Mieczkowski(z2010367),
//  Avi Schmookler (z2005237), Matt Ratanapitaksuk (z2003352)
//
//***************************************************************************

#ifndef BOOKSTORE_H
#define BOOKSTORE_H
#include "book.h"
#include <string>


using namespace std;


class book_store
{
    book bookstore[30];
    int n;

public:

    book_store();
    void read_books(const string&);
    void process_orders(const string&);
    void print();
};


#endif

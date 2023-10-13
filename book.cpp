//***************************************************************************
//
//  book.cpp
//  CSCI 241 Assignment 5 
//
//  Created by Mik Mieczkowski(z2010367),
//  Avi Schmookler (z2005237), Matt Ratanapitaksuk (z2003352)
//
//***************************************************************************

/**
 * Initializes a book object to default values.
 */
#include "book.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


book::book()
{
    isbn = "";
    title = "";
    price = 0;
    quantity = 0;
}


/**
 * Initializes a book object to values selected by the user.
 *
 * @param isbn string that goes into isbn
 * @param title string that goes into title
 * @param price double that goes into price
 * @param quantity int that goes into quantity
 */
book::book(const string& isbn, const string& title, double price, int quantity)
{
    this->isbn = isbn;
    this->title = title;
    this->price = price;
    this->quantity = quantity;
}


/**
 * Gets the ISBN value of a book object.
 *
 * @return ISBN value
 */
string book::get_ISBN()
{
    return isbn;
}


/**
 * Gets the price value of a book object.
 *
 * @return price value
 */
double book::get_price()
{
    return price;
}


/**
 * Returns the number of books that are able to be ordered (shippable books) and subtracts it from quantity.
 *
 * @param order number of books the customer wants to order
 *
 * @return number of shippable books
 */
int book::fulfill_order(int order)
{
    if (order < 0)
    {
        //ordering negative, best can do is 0
        return 0;
    }
    else if (order > quantity)
    {
        //ordering more than we have, then only ship quantity
        int temp = quantity;
        quantity = 0;
        return temp;
    }
    else
    {
        //ship order
        quantity -= order;
        return order;
    }
}


/**
 * prints a book object
 */
void book::print()
{
    cout << setw(14) << left << isbn << setw(44) << left << title << right << setw(5) << fixed << setprecision(2) << price << setw(6) << quantity << endl;
}


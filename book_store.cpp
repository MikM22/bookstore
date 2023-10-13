//********************************************************************
//
// book_store.cpp
// CSCI 241 Assignment 5
//
//  Created by Mik Mieczkowski(z2010367),
//  Avi Schmookler (z2005237), Matt Ratanapitaksuk (z2003352)
//
//********************************************************************
#include "book_store.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>

using namespace std;
using std::ifstream;
int search(vector<string>, int, string);

/* 
 *default constructor
*/
book_store::book_store() {
    n = 0;
}

/*
 * creates book objects to store into the bookstore array by reading from the file specified by filename
 * @param filename directory of file to read book info from
 */

void book_store::read_books(const string& filename) {
    ifstream inputstream(filename);
    if (!inputstream) {
        cout << "Error: unable to open file " << filename << endl;
        exit(1);
    }

    string s;
    int i = 0;
    string isbn;
    string title;
    double price;
    int quantity;

    while (inputstream.good()) {
        string line;
        getline(inputstream, line);
        stringstream ss(line);
        string s;
        
        while (getline(ss, s, ':'))
        {
            if (i%4==0) {
                if (i >= 4) {
                    book b(isbn, title, price, quantity);
                    n++;
                    bookstore[(i-1)/4] = b;
                }
                isbn = s;
            } else if (i%4==1) {
                title = s;
            } else if (i%4==2) {
                price = stod(s);
            } else if (i%4 ==3) {
                quantity = stoi(s);
            }
            i++;
        }
    }
    book b(isbn, title, price, quantity);
    n++;
    bookstore[n-1] = b;
    inputstream.close();
}
/*
 * Reads orders from file specified by filename, makes specified changes to stock of each book and prints a description of each order.
 * @param filename directory of orders file
 */
void book_store::process_orders(const string& filename) {
    string s;
    ifstream inputstream(filename);
    vector<string> ISBNs;
    for (int i = 0; i < n; i++) {
        ISBNs.push_back(bookstore[i].get_ISBN());
    }
    
    int i = 0;
    string ordernumber;
    string isbn;
    int num_ordered;
    while (inputstream >> s) {
        if (i%3 == 0) {
            ordernumber = s;
        } else if (i%3 == 1) {
           isbn = s;
        } else {
            num_ordered = stoi(s);
            int index = search(ISBNs,n, isbn);
            if (index == -1) {
                cout <<"Order #" << ordernumber << ": error - ISBN " << isbn << " does not exist"<<endl;
            } else {
                book& ordered = bookstore[index];
                int num_shipped = ordered.fulfill_order(num_ordered);
                cout <<"Order #" << ordernumber << ": ISBN " << isbn << ", " << num_shipped << " of " << num_ordered << " shipped, order total $" << (ordered.get_price() * num_shipped)<< endl;
            }
        }
        i++;
    }
    inputstream.close();
}

/* finds index of string s in array arr
 * @param arr array to look in
 * @param n size of array
 * @param s item to find
 */
int search(vector<string> arr, int n, string s) {
    int low=0;
    int high=n-1;
    while (low <= high) 
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == s)
        {
            return mid;
        } else if (arr[mid] < s)
        {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}

/*
 * prints bookstore array
 */
void book_store::print() {
    for (int i = 0; i < n; i++) {
        bookstore[i].print();
    }
}

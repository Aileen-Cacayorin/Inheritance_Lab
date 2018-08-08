//
//  string.cpp
//  Inheritance Lab
//
//  Created by Aileen Cacayorin on 8/7/18.
//  Copyright © 2018 com.aileenbull. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>

#include "String.h"

using namespace std;

extern ofstream csis;


//*** constructors and destructor ***//

String::String() {
    length = 0;
    buf = new char[length + 1];
    buf[0] = '\0';
};

String::String(const char* strg) {
    length = int(strlen(strg));
    buf = new char[length + 1];
    
    for (int i = 0; i < length; i++) {
        buf[i] = strg[i];
    }
    buf[length] = '\0';
};

String::String(char lttr) {
    length = 1;
    buf = new char[length+1];
    
    buf[0] = lttr;
    buf[length] = '\0';
};

String::String(int n) {
    if (n < 0) {
        length = 0;
    } else {
        length = n;
    };
    buf = new char[length];
    buf[0] = '\0';
};

String::String(const String& strng) {
    length = strng.length;
    buf = strng.buf;
};

String::String(char lttr, int n) {
    length = n;
    buf = new char[length];
    for (int i=0; i < n; i++) {
        buf[i] = lttr;
    };
    buf[length] = '\0';
    
};

String::~String() {
    length = 0;
}

//***  operator overloaders   ***//

String& String::operator=(const String& rtStrng) {
    length = rtStrng.length;
    buf = rtStrng.buf;
    return *this;
};

String& String::operator=(const char* rtChar) {
    length = int(strlen(rtChar));
    buf = new char[length];
    
    for (int i=0; i<length; i++) {
        buf[i] = rtChar[i];
    }
    buf[length] = '\0';
    return *this;
};


//*** member functions  ***//

int String::getLength() const {
    return length;
};

void String::print() {
    cout << "\"" << buf << "\"" << " " << "Length = " << length << endl;
    csis << "\"" << buf << "\"" << " " << "Length = " << length << endl;
}




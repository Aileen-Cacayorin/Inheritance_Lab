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
    buf = new char[length];
    for (int i=0; i < length; i++) {
        buf[i] = strng.buf[i];
    }
    
};

String::String(char lttr, int n) {
    length = n;
    buf = new char[length+1];
    for (int i=0; i < n; i++) {
        buf[i] = lttr;
    };
    buf[length] = '\0';
    
};

String::~String() {
    length = 0;
}

//***  assignment operator overloaders   ***//

String& String::operator=(const String& rtStrng) {
    length = rtStrng.length;
    buf = rtStrng.buf;
    return *this;
};

String& String::operator=(const char* rtChar) {
    length = int(strlen(rtChar));
    buf = new char[length+1];
    
    for (int i=0; i<length; i++) {
        buf[i] = rtChar[i];
    }
    buf[length] = '\0';
    return *this;
};

//***  concatenation operator overloaders   ***//

String operator+(const String& a1, const String& a2) {
    int newLength = a1.length + a2.length;
    
    String temp(newLength);
    
    for (int i=0; i < a1.length; i++) {
        temp.buf[i] = a1.buf[i];
    };
    
    for (int j=0, i= a1.length; j < a2.length; i++, j++ ) {
        temp.buf[i] = a2.buf[j];
    };
    temp.length = newLength;
    temp.buf[newLength] = '\0';
    return temp;
};

String operator+(const String& strng, const char* chr) {
    int newLength = strng.length + int(strlen(chr));
    String temp;
    temp.buf = new char[newLength+1];
    temp.length = newLength;
    
    for (int i = 0; i < strng.length; i++) {
        temp.buf[i] = strng.buf[i];
    }
    
    for (int j = 0, i = strng.length; j < strlen(chr); j++, i++) {
        temp.buf[i] = chr[j];
    }
    temp.buf[newLength] = '\0';
    
    return temp;
};

String operator+(const char* chr, const String& strng)
{
    int newLength = strng.length + int(strlen(chr));
    String temp;
    temp.buf = new char[newLength+1];
    temp.length = newLength;

    strcpy(temp.buf, chr);

    for (int j = 0, i = int(strlen(chr)); j < strng.length; j++, i++) {
        temp.buf[i] = strng.buf[j];
    }

    temp.buf[newLength] = '\0';

    return temp;
}

String operator+(const String& strng, const char chr)
{
    int newLength = strng.length + 1;
    String temp;
    temp.buf = new char[newLength+1];
    temp.length = newLength;

    for (int i = 0; i < strng.length; i++) {
        temp.buf[i] = strng.buf[i];
    }

    temp.buf[newLength - 1] = chr;
    temp.buf[newLength] = '\0';

    return temp;
}

String operator+(const char chr, const String& strng)
{
    int newLength = strng.length+1;
    String temp;
    temp.buf = new char[newLength+1];
    temp.length = newLength;
    
    temp.buf[0] = chr;
    for (int i = 0, j = 1; i < strng.length; i++, j++) {
        temp.buf[j] = strng.buf[i];
    }
    
    temp.buf[newLength] = '\0';
    
    return temp;
}

String& String::operator+=(const String& strng) {
    int newLength = length + strng.length;
    char* temp = new char[newLength+1];

    int i, j;
    for (i=0; i < length; i++) {
        temp[i] = buf[i];
    }

    for (i=length, j= 0; j < strng.length; i++, j++) {
        temp[i] = strng.buf[j];
    }

    delete [] buf;
    buf = new char[newLength+1];
    length = newLength;

    for (i = 0; i < length; i++) {
        
        buf[i] = temp[i];
    }
    buf[newLength] = '\0';
    
    delete [] temp;

    return *this;

};

//*** unary overloading **//

String String::operator+() const {
    String temp(*this);
    
    for (int i = 0; i < length; i++){
        temp.buf[i] = toupper(temp.buf[i]);
    }
    
    return temp;
}

//*** comparison overloading ***//
int operator==(const String& strng1, const String& strng2){
    return strng1.buf == strng2.buf;
};

int operator!=(const String& strng1, const String& strng2){
    return strng1.buf != strng2.buf;
};

int operator< (const String& strng1, const String& strng2) {
    return strng1.buf < strng2.buf;
};

int operator<=(const String& strng1, const String& strng2) {
    return strng1.length <= strng2.length;
};

int operator> (const String& strng1, const String& strng2) {
    return strng1.length > strng2.length;
};

int operator>=(const String& strng1, const String& strng2) {
    return strng1.length >= strng2.length;
};

//*** overloading subscript operato ***//
char& String::operator[](int elem) {
    static char chr = '\0';
    
    if (elem < 0 || elem > length) {
        cout << "Error: Index is out of range." << endl;
        return chr;
    }
    else {
        return buf[elem];
    }
}

//*** member functions  ***//

int String::getLength() const {
    return length;
};

void String::print() {
    cout << "\"" << buf << "\"" << " " << "Length = " << length << endl;
    csis << "\"" << buf << "\"" << " " << "Length = " << length << endl;
    
//    cout << "\"";
//    for (int i=0; i<length; i++) {
//        cout << buf[i];
//    }
}




//
//  string.hpp
//  Inheritance Lab
//
//  Created by Aileen Cacayorin on 8/7/18.
//  Copyright © 2018 com.aileenbull. All rights reserved.
//

#ifndef string_hpp
#define string_hpp

#include <stdio.h>

using namespace std;


class String {
    protected:
        char* buf;
        int length;
    
    public:
        String();                                                       // initializes a String with no argument
        String(const char*);                                            // initializes a String with string literal argument
        String(char);                                                   // initializes a String with single char argument
        String(int);                                                    // initializes a String with int argument
        String(const String&);                                          // initializes a String as a copy from another String
        String(char, int);                                              // initializes a String with char and int argument
        ~String();                                                      // destructor
    
        //* assigment overloaders *//
        String& operator=(const String&);                               // overloads assignment operator with another String
        String& operator=(const char*);                                 // overloads assignment operator with char argument
    
        //* concatenation overloaders *//
        friend String operator+(const String&, const String&);          // overloads + operator and adds two string objects
        friend String operator+(const String& , const char*);           // overloads + operator with String and char pointer
        friend String operator+(const char*, const String&);            // overloads + operator with char and String
        friend String operator+(const String&, const char);             // overloads + operator with String and char
        friend String operator+(const char, const String&);             // overloads + operator with char and String
        String& operator+=(const String&);                              // overloads + operator and stores two arguments in left
    
        //unary overloading
        String operator+() const;                                       // returns String in uppercase

    
        void print();                                                   // prints string and string length
        int getLength() const;                                          // returns string length

};


#endif /* string_hpp */

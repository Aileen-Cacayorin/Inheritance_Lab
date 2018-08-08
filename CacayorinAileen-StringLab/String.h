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
        String();                                                   // initializes a String with no argument
        String(const char*);                                        // initializes a String with string literal argument
        String(char);                                               // initializes a String with single char argument
        String(int);                                                // initializes a String with int argument
        String(const String&);                                      // initializes a String as a copy from another String
        String(char, int);                                          // initializes a String with char and int argument
        String& operator=(const String&);                           // overloads assignment operator with another String
        String& operator=(const char*);                             // overloads assignement with char argument
        ~String();                                                  // destructor
        void print();                                               // prints string and string length
        int getLength() const;                                      // returns string length

};


#endif /* string_hpp */

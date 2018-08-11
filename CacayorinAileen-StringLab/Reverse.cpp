//
//  Reverse.cpp
//  Inheritance_Lab
//
//  Created by Aileen Cacayorin on 8/9/18.
//  Copyright © 2018 com.aileenbull. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>

#include "Reverse.h"

using namespace std;

extern ofstream csis;

ReverseString::ReverseString() : String() {
}

ReverseString::ReverseString(const ReverseString& rvrs) : String(rvrs) {
}

ReverseString::ReverseString(const char* chr) : String(chr) {
}

ReverseString& ReverseString::operator=(const ReverseString& rvrs) {
    String::operator=(rvrs);
    return *this;
};

ReverseString ReverseString::operator~() {
    ReverseString rvrs(*this);
    
    ReverseString reverse;
    int count = 0;
    
    for (int i = rvrs.length-1; i >= 0; i--) {
        reverse.buf[count] = rvrs.buf[i];
        count++;
    }
    
    reverse.buf[length] = '\0';
    reverse.length = length;
    
    return reverse;
}

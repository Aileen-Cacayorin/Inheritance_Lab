//
//  Case.cpp
//  Inheritance_Lab
//
//  Created by Aileen Cacayorin on 8/9/18.
//  Copyright © 2018 com.aileenbull. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include "Case.h"
#include <stdio.h>



#include <fstream>

using namespace std;

extern ofstream csis;

CaseString::CaseString() : String() {}

CaseString::CaseString(const CaseString& cse) : String(cse){
    lower = new char[length+1];
    upper = new char[length+1];
    for (int i=0; i < length; i++) {
        lower[i] = tolower(buf[i]);
    }
    for (int i=0; i < length; i++) {
        upper[i] = toupper(buf[i]);
    }
};

CaseString::CaseString(const char* chr) : String(chr) {
    lower = new char[length+1];
    upper = new char[length+1];
    for (int i=0; i < length; i++) {
        lower[i] = tolower(buf[i]);
    }
    for (int i=0; i < length; i++) {
        upper[i] = toupper(buf[i]);
    }
   
}

CaseString& CaseString::operator=(const CaseString& cse) {
    String::operator=(cse);
    lower = cse.lower;
    upper = cse.upper;
    return *this;
};

void CaseString::print() {
    
    String::print();
    cout << "Lower: \""  << lower <<"\" " <<"Upper: " << upper << endl;
    csis << "Lower: \""  << lower <<"\" " <<"Upper: " << upper << endl;
};

CaseString::~CaseString() {
};

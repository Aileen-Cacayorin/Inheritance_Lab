//
//  Case.hpp
//  Inheritance_Lab
//
//  Created by Aileen Cacayorin on 8/9/18.
//  Copyright © 2018 com.aileenbull. All rights reserved.
//

#ifndef Case_hpp
#define Case_hpp

#include <stdio.h>
#include <iostream>
#include <stdio.h>

#include "String.h"

class CaseString: public String {
    private:
        char* lower;
        char* upper;
    
    public:
        CaseString();                                                    // default constructor
        CaseString(const CaseString&);                                   // copy constructor
        CaseString(const char*);                                         // constructor with char argument
        CaseString& operator=(const CaseString&);                        // asignment overloader
        void print();                                                    // overwrites print function
        ~CaseString();                                                   // destructor
    

};

#endif /* Case_h */

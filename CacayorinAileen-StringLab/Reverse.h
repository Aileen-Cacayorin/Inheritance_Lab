//
//  Reverse.hpp
//  Inheritance_Lab
//
//  Created by Aileen Cacayorin on 8/9/18.
//  Copyright © 2018 com.aileenbull. All rights reserved.
//

#ifndef Reverse_hpp
#define Reverse_hpp

#include <stdio.h>
#include <iostream>
#include "String.h"

using namespace std;

class ReverseString : public String {
    public:
        ReverseString();
        ReverseString(const ReverseString&);
        ReverseString(const char*);
        ReverseString& operator=(const ReverseString&);
        ReverseString operator~();
    };



#endif /* Reverse_hpp */

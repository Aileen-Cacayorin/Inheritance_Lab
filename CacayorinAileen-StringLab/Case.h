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
    
    public:
        CaseString();
        CaseString(const CaseString&);
        CaseString(const char*);
        CaseString& operator=(const CaseString&);
        void print();
        ~CaseString();
    

};

#endif /* Case_hpp */

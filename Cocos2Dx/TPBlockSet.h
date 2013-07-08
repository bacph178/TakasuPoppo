//
//  TPBlockSet.h
//  Cocos2Dx
//
//  Created by Ace on 2013/06/26.
//
//

#ifndef __Cocos2Dx__TPBlockSet__
#define __Cocos2Dx__TPBlockSet__

#include <TPObjectExtension.h>
#include "cocos2d.h"

using namespace std;
USING_NS_CC;

class TPBlockSet : public CCObject {
private:
    TPObjectExtension *ex1;
    TPObjectExtension *ex2;
    TPObjectExtension *ex3;
    TPObjectExtension *ex4;
    TPObjectExtension *ex5;
    string type;
    int column;
    int row;
public:
    TPBlockSet(TPObjectExtension *ex1, TPObjectExtension *ex2, TPObjectExtension *ex3,
               TPObjectExtension *ex4, TPObjectExtension *ex5, string type, int column, int row);
    CCArray *getBlocksArray();
    string getType();
    TPObjectExtension *getEx1();
    TPObjectExtension *getEx2();
    TPObjectExtension *getEx3();
    TPObjectExtension *getEx4();
    TPObjectExtension *getEx5();
    void setEx4(TPObjectExtension * cp);
    void setEx5(TPObjectExtension *cp);
    void setType(string type);
    int getColumn();
    int getRow();
};


#endif /* defined(__Cocos2Dx__TPBlockSet__) */

//
//  TPBlockSet.cpp
//  Cocos2Dx
//
//  Created by Ace on 2013/06/26.
//
//

#include "TPBlockSet.h"
#include "TPObjectExtension.h"
using namespace cocos2d;
using namespace std;
USING_NS_CC;

TPBlockSet::TPBlockSet(TPObjectExtension *ex1, TPObjectExtension *ex2, TPObjectExtension *ex3,
                       TPObjectExtension *ex4, TPObjectExtension *ex5, string type, int column, int row) {
    this->ex1 = ex1;
    this->ex2 = ex2;
    this->ex3 = ex3;
    this->ex4 = ex4;
    this->ex5 = ex5;
    this->type = type;
    this->column = column;
    this->row = row;
}

CCArray *TPBlockSet::getBlocksArray() {
    CCArray *newArray = new CCArray;
    if (this->ex1 != NULL) newArray->addObject(this->ex1);
    if (this->ex2 != NULL) newArray->addObject(this->ex2);
    if (this->ex3 != NULL) newArray->addObject(this->ex3);
    if (this->ex4 != NULL) newArray->addObject(this->ex4);
    if (this->ex5 != NULL) newArray->addObject(this->ex5);
    CCLog("Added %i blocks", newArray->count());
    return newArray;
}

string TPBlockSet::getType() {
    return type;
}

int TPBlockSet::getColumn() {
    return column;
}

int TPBlockSet::getRow() {
    return row;
}

TPObjectExtension *TPBlockSet::getEx1() {
    if (ex1 != NULL) return ex1;
    else return NULL;
}

TPObjectExtension *TPBlockSet::getEx2() {
    if (ex2 != NULL) return ex2;
    else return NULL;
}

TPObjectExtension *TPBlockSet::getEx3() {
    if (ex3 != NULL) return ex3;
    else return NULL;
}

TPObjectExtension *TPBlockSet::getEx4() {
    if (ex4 != NULL) return ex4;
    else return NULL;
}

TPObjectExtension *TPBlockSet::getEx5() {
    if (ex5 != NULL) return ex5;
    else return NULL;
}

void TPBlockSet::setEx4(TPObjectExtension * cp){
    this->ex4 = cp;
}
void TPBlockSet::setEx5(TPObjectExtension * cp){
    this->ex5 = cp;
}
void TPBlockSet::setType(string c){
    this->type = c;
    
}
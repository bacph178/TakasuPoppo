//
//  TP_takasuPoppo_Swiped.cpp
//  Cocos2Dx
//
//  Created by macbook_006 on 13/06/28.
//
//

#include "TakasuPoppo.h"
#pragma mark Swipe Actions

void TakasuPoppo::swipedRight(TPObjectExtension *exObj) {
    unsigned int gid = exObj->getGid();
    if (gid != 7 && gid != 14 && gid != 21 && gid != 28 && gid != 35 && gid != 42 && gid != 49 ) {
        unsigned int swapedGit = exObj->getGid() + 1;
        TakasuPoppo::swapTilesCheck(exObj, swapedGit);
    }
}

void TakasuPoppo::swipedLeft(TPObjectExtension *exObj) {
    unsigned int gid = exObj->getGid();
    if (gid != 1 && gid != 8 && gid != 15 && gid != 22 && gid != 29 && gid != 36 && gid != 43 ) {
        unsigned int swapedGit = exObj->getGid() - 1;
        TakasuPoppo::swapTilesCheck(exObj, swapedGit);
    }
}

void TakasuPoppo::swipedUp(TPObjectExtension *exObj) {
    unsigned int gid = exObj->getGid();
    if (gid >= 7) {
        unsigned int swapedGit = exObj->getGid() - 7;
        TakasuPoppo::swapTilesCheck(exObj, swapedGit);
    }
}

void TakasuPoppo::swipedDown(TPObjectExtension *exObj) {
    unsigned int gid = exObj->getGid();
    if (gid < 43) {
        unsigned int swapedGit = exObj->getGid() + 7;
        TakasuPoppo::swapTilesCheck(exObj, swapedGit);
    }
}

#pragma mark Tile Interactions
void TakasuPoppo::swapTilesCheck(TPObjectExtension *exObj, int swpGid) {
    CCObject *object;
    CCARRAY_FOREACH(colorArray, object) {
        TPObjectExtension *objectExtension = dynamic_cast<TPObjectExtension*>(object);
        if (objectExtension->getGid() == swpGid && exObj && objectExtension) {
            TakasuPoppo::swapColorID(exObj, objectExtension);
            if (TakasuPoppo::isBlockMatched(exObj->getGid(), exObj->getID()) ||
                TakasuPoppo::isBlockMatched(objectExtension->getGid(), objectExtension->getID())) {
                TakasuPoppo::swapColorID(exObj, objectExtension);
                TakasuPoppo::swapTilesMoving(exObj, objectExtension);
            }
            else {
                TakasuPoppo::swapColorID(exObj, objectExtension);
                TakasuPoppo::swapTilesReturn(exObj, objectExtension);
            }
        }
    }
}

void TakasuPoppo::swapColorID(TPObjectExtension *exObj, TPObjectExtension *swpObj) {
    int exID = exObj->getID();
    CCSprite *exSprite = exObj->getSprite();
    int swpID = swpObj->getID();
    CCSprite *swpSprite = swpObj->getSprite();
    
    exObj->setID(swpID);
    swpObj->setID(exID);
    exObj->setSprite(swpSprite);
    swpObj->setSprite(exSprite);
    CCLog("Tile %i's color %i got swaped with tile %i's color %i.",
          exObj->getGid(), exObj->getID(), swpObj->getGid(), swpObj->getID());
}

void TakasuPoppo::swapTilesMoving(TPObjectExtension *exObj, TPObjectExtension *swpObj) {
    CCSprite *sprite = (CCSprite*)exObj->getSprite();
    CCSprite *swpSprite = (CCSprite*)swpObj->getSprite();
    sprite->runAction(CCMoveTo::create(0.1, swpObj->getPosition()));
    swpSprite->runAction(CCSequence::create(CCMoveTo::create(0.1, exObj->getPosition()),
                                            CCCallFunc::create(this, callfunc_selector(TakasuPoppo::cleanBlocks)),
                                            CCCallFunc::create(this, callfunc_selector(TakasuPoppo::afterClean)),
                                            CCCallFunc::create(this, callfunc_selector(TakasuPoppo::checkEmpty)), NULL));
    
    TakasuPoppo::swapColorID(exObj, swpObj);
    if (gridOn)TakasuPoppo::refresh();
}

void TakasuPoppo::swapTilesReturn(TPObjectExtension *exObj, TPObjectExtension *swpObj) {
    CCSprite *sprite = (CCSprite*)exObj->getSprite();
    CCSprite *swpSprite = (CCSprite*)swpObj->getSprite();
    sprite->runAction(CCSequence::create(CCMoveTo::create(0.1, swpObj->getPosition()),
                                         CCMoveTo::create(0.1, exObj->getPosition()), NULL));
    swpSprite->runAction(CCSequence::create(CCMoveTo::create(0.1, exObj->getPosition()),
                                            CCMoveTo::create(0.1, swpObj->getPosition()), NULL));
}



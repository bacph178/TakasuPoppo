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
    TPObjectExtension *swpObj = dynamic_cast<TPObjectExtension*>(colorArray->objectAtIndex(swpGid- 1));
    TakasuPoppo::swapColorID(exObj, swpObj);
    TakasuPoppo::matchList();
    movedSprite = exObj;
    swapedSprite = swpObj;
    if (toDestroyArray->count() != 0) {
        this->runAction(CCSequence::create(CCCallFunc::create(this, callfunc_selector(TakasuPoppo::swapTilesMoved)),
                                           CCDelayTime::create(0.1),
                                           CCCallFunc::create(this, callfunc_selector(TakasuPoppo::cleanBlocks)),
                                           CCDelayTime::create(0.1),
                                           CCCallFunc::create(this, callfunc_selector(TakasuPoppo::afterClean)),
                                           CCDelayTime::create(0.1),
                                           CCCallFunc::create(this, callfunc_selector(TakasuPoppo::checkEmpty)),
                                           NULL));
    }
    else {
        TakasuPoppo::swapColorID(exObj, swpObj);
        TakasuPoppo::swapTilesBack();
    }
}

void TakasuPoppo::swapColorID(TPObjectExtension *exObj, TPObjectExtension *swpObj) {
    int exID = exObj->getID();
    int swpID = swpObj->getID();
    exObj->setID(swpID);
    swpObj->setID(exID);
    
    CCSprite *moveSprite = exObj->getSprite();
    CCSprite *swapSprite = swpObj->getSprite();
    exObj->setSprite(swapSprite);
    swpObj->setSprite(moveSprite);
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

void TakasuPoppo::swapTilesMoved() {
    CCPoint moveDes = swapedSprite->getSprite()->getPosition();
    CCPoint swapDes = movedSprite->getSprite()->getPosition();
    swapedSprite->getSprite()->runAction(CCMoveTo::create(0.1, swapDes));
    movedSprite->getSprite()->runAction(CCMoveTo::create(0.1, moveDes));
}

void TakasuPoppo::swapTilesBack() {
    CCPoint moveDes = swapedSprite->getSprite()->getPosition();
    CCPoint swapDes = movedSprite->getSprite()->getPosition();
    movedSprite->getSprite()->runAction(CCSequence::create(CCMoveTo::create(0.1, moveDes),
                                         CCMoveTo::create(0.1, swapDes), NULL));
    swapedSprite->getSprite()->runAction(CCSequence::create(CCMoveTo::create(0.1, swapDes),
                                            CCMoveTo::create(0.1, moveDes), NULL));
}

void TakasuPoppo::testFunc(CCObject *ex1, CCObject *ex2) {

}

void TakasuPoppo::moveBlock(TPObjectExtension *exObj1) {
    exObj1->setControlTrigger(false);
    
}

void TakasuPoppo::moveAnotherBlock(TPObjectExtension *exObj2) {
    
}
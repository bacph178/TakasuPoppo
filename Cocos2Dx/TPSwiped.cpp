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
    if (exObj->getControlTrigger() != false && swpObj->getControlTrigger() != false &&
        exObj->getSprite()->numberOfRunningActions() == 0 && swpObj->getSprite()->numberOfRunningActions() == 0) {
        TakasuPoppo::swapColorID(exObj, swpObj);
        TakasuPoppo::matchList();
        movedSprite = exObj;
        swapedSprite = swpObj;
        if (toDestroyArray->count() != 0) {
            controlable = false;
            this->runAction(CCSequence::create(
                                               CCCallFunc::create(this, callfunc_selector(TakasuPoppo::checkPosition)),
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

void TakasuPoppo::swapTilesBack() {
    CCPoint moveDes = swapedSprite->getPosition();
    CCPoint swapDes = movedSprite->getPosition();
    
    movedSprite->getSprite()->runAction(CCSequence::create(
                    CCCallFuncND::create(this, callfuncND_selector(TakasuPoppo::switchControlable), (void*)movedSprite),
                    CCMoveTo::create(0.1, moveDes),
                    CCMoveTo::create(0.1, swapDes),
                    CCCallFuncND::create(this, callfuncND_selector(TakasuPoppo::switchControlable), (void*)movedSprite), NULL));
    
    swapedSprite->getSprite()->runAction(CCSequence::create(
                    CCCallFuncND::create(this, callfuncND_selector(TakasuPoppo::switchControlable), (void*)swapedSprite),
                    CCMoveTo::create(0.1, swapDes),
                    CCMoveTo::create(0.1, moveDes),
                    CCCallFuncND::create(this, callfuncND_selector(TakasuPoppo::switchControlable), (void*)swapedSprite), NULL));
}

void TakasuPoppo::switchControlable(TPObjectExtension *exObj) {
    bool controlable = exObj->getControlTrigger();
    controlable = !controlable;
}

void TakasuPoppo::checkPosition() {
    if (swapedSprite->getSprite()->getPosition().x != swapedSprite->getPosition().x ||
        swapedSprite->getSprite()->getPosition().y != swapedSprite->getPosition().y ) {
        swapedSprite->getSprite()->runAction(CCMoveTo::create(0.1, swapedSprite->getPosition()));
    }
    if (movedSprite->getSprite()->getPosition().x != movedSprite->getPosition().x ||
        movedSprite->getSprite()->getPosition().y != movedSprite->getPosition().y ) {
        movedSprite->getSprite()->runAction(CCMoveTo::create(0.1, movedSprite->getPosition()));
    }

}

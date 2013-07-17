//
//  TPClean.cpp
//  Cocos2Dx
//
//  Created by Ace on 2013/07/01.
//
//

#include "TakasuPoppo.h"
#include "TPBlockSet.h"
void TakasuPoppo::cleanBlocks() {
    CCObject *object;
    if (toDestroyArray->count() != 0) {
        CCARRAY_FOREACH(toDestroyArray, object) {
            hintCounter = 3;
            TPBlockSet *blockSet = dynamic_cast<TPBlockSet*>(object);
            
            if (blockSet->getEx1()->getSprite() != NULL) {
                CCSprite *ex1 = blockSet->getEx1()->getSprite();
                ex1->runAction(CCSequence::create(
                                                  CCCallFuncND::create(this, callfuncND_selector(TakasuPoppo::spriteChange),
                                                                       (void*)blockSet->getEx1()),
                                                  CCCallFuncND::create(this, callfuncND_selector(TakasuPoppo::changeID),
                                                                       (void*)blockSet->getEx1()),
                                                  CCDelayTime::create(0.3),

                                                  
                                                  CCRemoveSelf::create(), NULL));
                    
            }
            
            if (blockSet->getEx2()->getSprite() != NULL) {
                CCSprite *ex2 = blockSet->getEx2()->getSprite();
                ex2->runAction(CCSequence::create(
                                                  CCCallFuncND::create(this, callfuncND_selector(TakasuPoppo::spriteChange),
                                                                       (void*)blockSet->getEx2()),
                                                  CCCallFuncND::create(this, callfuncND_selector(TakasuPoppo::changeID),
                                                                       (void*)blockSet->getEx2()),
                                                  CCDelayTime::create(0.3),

                                                  CCRemoveSelf::create(), NULL));
            }
            
            if (blockSet->getEx3()->getSprite() != NULL) {
                CCSprite *ex3 = blockSet->getEx3()->getSprite();
                ex3->runAction(CCSequence::create(
                                                  CCCallFuncND::create(this, callfuncND_selector(TakasuPoppo::spriteChange),
                                                                       (void*)blockSet->getEx3()),
                                                  CCCallFuncND::create(this, callfuncND_selector(TakasuPoppo::changeID),
                                                                       (void*)blockSet->getEx3()),
                                                  CCDelayTime::create(0.3),

                                                  CCRemoveSelf::create(), NULL));
            }
            
            if (blockSet->getEx4() && blockSet->getEx4() != NULL &&
                blockSet->getEx4()->getSprite() != NULL) {
                CCSprite *ex4 = blockSet->getEx4()->getSprite();
        
                ex4->runAction(CCSequence::create(
                                                  CCCallFuncND::create(this, callfuncND_selector(TakasuPoppo::spriteChange),
                                                                       (void*)blockSet->getEx4()),
                                                  CCCallFuncND::create(this, callfuncND_selector(TakasuPoppo::changeID),
                                                                       (void*)blockSet->getEx4()),
                                                  CCDelayTime::create(0.3),

                                                  CCRemoveSelf::create(), NULL));
            }
            if (blockSet->getEx5() && blockSet->getEx5() != NULL &&
                blockSet->getEx5()->getSprite() != NULL) {
                CCSprite *ex5 = blockSet->getEx5()->getSprite();
                ex5->runAction(CCSequence::create(
                                                  CCCallFuncND::create(this, callfuncND_selector(TakasuPoppo::spriteChange),
                                                                       (void*)blockSet->getEx5()),
                                                  CCCallFuncND::create(this, callfuncND_selector(TakasuPoppo::changeID),
                                                                       (void*)blockSet->getEx5()),
                                                  CCDelayTime::create(0.3),

                                                  CCRemoveSelf::create(), NULL));
            }
        }
    }
    toDestroyArray->removeAllObjects();
}

void TakasuPoppo::afterClean() {
    CCObject *object;
    CCARRAY_FOREACH_REVERSE(colorArray, object) {
        TPObjectExtension *exObj = dynamic_cast<TPObjectExtension*>(object);
        if (exObj->getID() == 7 && exObj->getCoordination().y != 0) {
            CCObject *object2;
            CCARRAY_FOREACH_REVERSE(colorArray, object2) {
                TPObjectExtension *exObj2 = dynamic_cast<TPObjectExtension*>(object2);
                if (exObj2->getCoordination().x == exObj->getCoordination().x &&
                    exObj2->getCoordination().y < exObj->getCoordination().y &&
                    exObj2->getID() != 7) {
                    int blocksAway = exObj->getCoordination().y - exObj2->getCoordination().y;
                    //CCPoint movePos = exObj->getPosition();
                    CCSprite *toMoveSprite =  exObj2->getSprite();
                    //toMoveSprite->runAction(CCMoveTo::create(movingSpeed * blocksAway, movePos));
                    toMoveSprite->runAction(CCMoveBy::create(movingSpeed * blocksAway, ccp(0, - 90 * blocksAway)));
                    TakasuPoppo::swapColorID(exObj, exObj2);
                    exObj->setControlTrigger(!exObj->getControlTrigger());
                    exObj2->setControlTrigger(!exObj2->getControlTrigger());
                    break;
                }
            }
        }
    }    
}

void TakasuPoppo::changeID(CCNode *sender, void* data) {
    TPObjectExtension *exObj = (TPObjectExtension*)data;
    exObj->setID(7);
}


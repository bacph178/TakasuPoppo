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
            
            TPBlockSet *blockSet = dynamic_cast<TPBlockSet*>(object);
            
            CCSprite *ex1 = blockSet->getEx1()->getSprite();
            CCSprite *ex2 = blockSet->getEx2()->getSprite();
            CCSprite *ex3 = blockSet->getEx3()->getSprite();
            
            ex1->runAction(CCSequence::create(CCDelayTime::create(0.2),
                                               CCRemoveSelf::create(), NULL));
            ex2->runAction(CCSequence::create(CCDelayTime::create(0.2),
                                              CCRemoveSelf::create(), NULL));
            ex3->runAction(CCSequence::create(CCDelayTime::create(0.2),
                                              CCRemoveSelf::create(), NULL));
            
//            TakasuPoppo::popParticles(blockSet->getEx1()->getPosition());
//            TakasuPoppo::popParticles(blockSet->getEx2()->getPosition());
//            TakasuPoppo::popParticles(blockSet->getEx3()->getPosition());
            
            blockSet->getEx1()->setID(7);
            blockSet->getEx2()->setID(7);
            blockSet->getEx3()->setID(7);
            
            if (blockSet->getEx4() && blockSet->getEx4() != NULL) {
                CCSprite *ex4 = blockSet->getEx4()->getSprite();
                ex4->runAction(CCSequence::create(CCDelayTime::create(0.1),
                                                  CCRemoveSelf::create(), NULL));
//                TakasuPoppo::popParticles(blockSet->getEx4()->getPosition());
                blockSet->getEx4()->setID(7);
            }
            if (blockSet->getEx5() && blockSet->getEx5() != NULL) {
                CCSprite *ex5 = blockSet->getEx5()->getSprite();
                ex5->runAction(CCSequence::create(CCDelayTime::create(0.1),
                                                  CCRemoveSelf::create(), NULL));
//                TakasuPoppo::popParticles(blockSet->getEx5()->getPosition());
                blockSet->getEx5()->setID(7);
            }
        }
    }
    toDestroyArray->removeAllObjects();
    toDestroyArray->retain();
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
                    break;
                }
            }
        }
    }    
}


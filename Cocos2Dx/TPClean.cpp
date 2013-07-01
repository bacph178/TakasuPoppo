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
            this->removeChild(ex1);
            this->removeChild(ex2);
            this->removeChild(ex3);
            blockSet->getEx1()->setID(7);
            blockSet->getEx2()->setID(7);
            blockSet->getEx3()->setID(7);
            if (blockSet->getEx4()) {
                CCSprite *ex4 = blockSet->getEx4()->getSprite();
                ex4->removeFromParentAndCleanup(true);
                blockSet->getEx4()->setID(7);
            }
            if (blockSet->getEx5()) {
                CCSprite *ex5 = blockSet->getEx5()->getSprite();
                ex5->removeFromParentAndCleanup(true);
                blockSet->getEx5()->setID(7);
            }
        }
    }
}

void TakasuPoppo::afterClean() {
    CCObject *object;
    CCARRAY_FOREACH(toDestroyArray, object){
        TPBlockSet *blockSet = dynamic_cast<TPBlockSet*>(object);
        if (blockSet->getType() == "TrioRight" ||
            blockSet->getType() == "TrioLeft" ||
            blockSet->getType() == "TrioMid" ) {
            CCPoint coor1 = blockSet->getEx1()->getCoordination();
            CCPoint coor2 = blockSet->getEx2()->getCoordination();
            CCPoint coor3 = blockSet->getEx3()->getCoordination();
            CCObject *blockObject;
            CCARRAY_FOREACH_REVERSE(colorArray, blockObject) {
                TPObjectExtension *exObj = dynamic_cast<TPObjectExtension*>(blockObject);
                if ((exObj->getCoordination().x == coor1.x && exObj->getCoordination().y < coor1.y) ||
                    (exObj->getCoordination().x == coor2.x && exObj->getCoordination().y < coor2.y) ||
                    (exObj->getCoordination().x == coor3.x && exObj->getCoordination().y < coor3.y)) {
                    CCLog("ExObj ID %i", exObj->getGid());
                    CCSprite *toMoveSprite = exObj->getSprite();
                    CCObject *bottomObject = colorArray->objectAtIndex(exObj->getGid() + 6);
                    TPObjectExtension *bottomEx = dynamic_cast<TPObjectExtension*>(bottomObject);
                    toMoveSprite->runAction(CCMoveTo::create(0.3, bottomEx->getPosition()));
                    TakasuPoppo::swapColorID(exObj, bottomEx);
                }
            }
        }
        toDestroyArray->removeObject(blockSet);
    }
}


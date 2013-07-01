//  Created by MinhNT on 13/05/16.
//  Copyright FRAMGIA 2013年. All rights reserved.
//

#include "TakasuPoppo.h"
#include "SimpleAudioEngine.h"
#include "TPObjectExtension.h"
#include "TPBlockSet.h"
//#include "Touches.h"
using namespace cocos2d;
using namespace CocosDenshion;
using namespace std;

#pragma mark Default

CCScene* TakasuPoppo::scene() {
    CCScene *scene = CCScene::create();
    TakasuPoppo *layer = TakasuPoppo::create();
    scene->addChild(layer);
    return scene;
}

bool TakasuPoppo::init() {
    srand(time(0));
    if (!CCLayer::init()) return false;
    
    colorArray = new CCArray;
    toDestroyArray = new CCArray;
    pickedArray = new CCArray;
    
    debugTilesArray = new CCArray;
    
    TakasuPoppo::addBlocksToArray();
    TakasuPoppo::addTileMap();
    
    CCSprite *background = CCSprite::create("PuzzleBackgroud3.png");
    background->setPosition(ccp(winSize.width/2, winSize.height/2));
    this->addChild(background, -2, -2);
    float x = 0;
    float y = 0;
    float z = 0;
    this->getCamera()->setCenterXYZ(x, y + 0.000000005, z);
    
    TakasuPoppo::setupDebugButton();
    TakasuPoppo::checkTile();
    this->setTouchEnabled(true);
    this->scheduleUpdate();
    return true;
}

void TakasuPoppo::update(float dt) {
    if (swipeRight) {
        CCObject *object = NULL;
        CCARRAY_FOREACH(pickedArray, object) {
            TPObjectExtension *exObject = dynamic_cast<TPObjectExtension*>(object);
            TakasuPoppo::swipedRight(exObject);
            swipeRight = false;
            pickedArray->removeObject(object);
        }      
    }
    if (swipeLeft) {
        CCObject *object = NULL;
        CCARRAY_FOREACH(pickedArray, object) {
            TPObjectExtension *exObject = dynamic_cast<TPObjectExtension*>(object);
            TakasuPoppo::swipedLeft(exObject);
            swipeLeft = false;
            pickedArray->removeObject(object);
        }
    }
    if (swipeUp) {
        CCObject *object = NULL;
        CCARRAY_FOREACH(pickedArray, object) {
            TPObjectExtension *exObject = dynamic_cast<TPObjectExtension*>(object);
            TakasuPoppo::swipedUp(exObject);
            swipeUp = false;
            pickedArray->removeObject(object);
        }

    }
    if (swipeDown) {
        CCObject *object = NULL;
        CCARRAY_FOREACH(pickedArray, object) {
            TPObjectExtension *exObject = dynamic_cast<TPObjectExtension*>(object);
            TakasuPoppo::swipedDown(exObject);
            swipeDown = false;
            pickedArray->removeObject(object);
        }
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


#pragma mark Array

void TakasuPoppo::addBlocksToArray() {
    for (int i = 0; i < 49; i ++) {
        TPObjectExtension *exObj = new TPObjectExtension(0, 0, NULL, ccp(0, 0), ccp(0, 0), false);
        colorArray->addObject(exObj);
    }
}

void TakasuPoppo::setValuesForExObj(TPObjectExtension *exObj, int colorID, int gid, CCSprite *sprite,
                                    CCPoint position, CCPoint coordination, bool trigger) {
    exObj->setID(colorID);
    exObj->setGid(gid);
    exObj->setSprite(sprite);
    exObj->setPosition(position);
    exObj->setCoordination(coordination);
    exObj->setControlTrigger(trigger);
    CCSprite *toMoveSprite = exObj->getSprite();
    toMoveSprite->runAction(CCMoveTo::create(0.1, exObj->getPosition()));
}

void TakasuPoppo::checkAndAddToRemove() {
    CCObject *object;
    CCARRAY_FOREACH(colorArray, object) {
        TPObjectExtension *exObj = dynamic_cast<TPObjectExtension*>(object);
        int gid = exObj->getGid();
        int id = exObj->getID();
        if (TakasuPoppo::isBlockMatched(gid, id)) {
            toDestroyArray->addObject(exObj);
        }
    }
}

void TakasuPoppo::removeObjectsFromDestroyArray() {
    if (toDestroyArray->count() > 0) {
        CCObject *object;
        CCARRAY_FOREACH(toDestroyArray, object) {
            TPObjectExtension *exObj = dynamic_cast<TPObjectExtension*>(object);
            CCSprite *toRemoveSprite = exObj->getSprite();
            exObj->setID(7);
            exObj->setSprite(NULL);
            if (toRemoveSprite)toRemoveSprite->removeFromParentAndCleanup(true);
            TakasuPoppo::onRemoveMoveTiles(exObj);
            if (gridOn)TakasuPoppo::refresh();
        }
    }
}

void TakasuPoppo::onRemoveMoveTiles(TPObjectExtension *exObj) {
    
    
}

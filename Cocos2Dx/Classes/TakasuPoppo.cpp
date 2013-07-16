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
    srand(time(NULL));
    if (!CCLayer::init()) return false;
    
    colorArray = new CCArray;
    toDestroyArray = new CCArray;
    pickedArray = new CCArray;
    hintArray = new CCArray;
    
    TakasuPoppo::addBlocksToArray();
    TakasuPoppo::addTileMap();
    TakasuPoppo::lookForMatches();
    
    controlable = true;

    //===============================================================
    debugTilesArray = new CCArray;
    TakasuPoppo::setupDebugButton();
    //===============================================================
    
    this->setTouchEnabled(true);
    
    this->scheduleUpdate();
    this->schedule(schedule_selector(TakasuPoppo::fixedUpdate));
    
    return true;
}

void TakasuPoppo::update(float dt) {
    deltaTime = dt;
    if (hintCounter > 0) {
        this->unschedule(schedule_selector(TakasuPoppo::hintGeneration));
        hintCounter -= dt;
    }
    if (hintCounter <= 0 && hintDisplaying == false) {
        hintArray->removeAllObjects();
        TakasuPoppo::lookForMatches();
        this->scheduleOnce(schedule_selector(TakasuPoppo::hintGeneration), 0);
    }
    
    if (controlable) {
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
}

void TakasuPoppo::fixedUpdate(float time) {
    TakasuPoppo::matchList();
    if (toDestroyArray->count() != 0 && inTheMove == false && inTheFall == false) {
        this->unschedule(schedule_selector(TakasuPoppo::smartGeneration));
        this->runAction(CCSequence::create(CCDelayTime::create(0.4),
                                           CCCallFunc::create(this, callfunc_selector(TakasuPoppo::cleanBlocks)),
                                           CCDelayTime::create(0.1),
                                           CCCallFunc::create(this, callfunc_selector(TakasuPoppo::afterClean)),
                                           CCDelayTime::create(0.1),
                                           CCCallFunc::create(this, callfunc_selector(TakasuPoppo::scheduleGenerate)),
                                           NULL));
        this->schedule(schedule_selector(TakasuPoppo::fallingBoolSwitch), 0.1);
    }
}

void TakasuPoppo::fallingBoolSwitch(float dt) {
    inTheFall = true;    
    fallCounter += deltaTime;
    if (fallCounter > 0.1) {
        inTheFall = false;
        this->unschedule(schedule_selector(TakasuPoppo::fallingBoolSwitch));
    }
}

void TakasuPoppo::movingBoolSwitch(float dt) {
    inTheMove = true;
    moveCounter += deltaTime;
    if (moveCounter > 0.1) {
        inTheMove = false;
        this->unschedule(schedule_selector(TakasuPoppo::movingBoolSwitch));
    }
}

void TakasuPoppo::scheduleGenerate() {
    this->schedule(schedule_selector(TakasuPoppo::smartGeneration), 0.1);
}

void TakasuPoppo::hintGeneration() {
    if (hintCounter <= 0 && !this->getChildByTag(778)) {
        hintDisplaying = true;
        int hintCount = hintArray->count();
        int hintIndex = hintCount - 1;
        int hintRandom = rand() %hintIndex;
        
        if (hintCount > 0) {
            CCLog("Hint count: %i Index: %i", hintCount, hintIndex);
            TPObjectExtension *exObj = dynamic_cast<TPObjectExtension*>(hintArray->objectAtIndex(hintRandom));
            CCLog("Object on coor X%iY%i ID %i has a chance for combo.", (int)exObj->getCoordination().x, (int)exObj->getCoordination().y, exObj->getID());
            CCRenderTexture *tex = TakasuPoppo::outlineEffect(exObj->getSprite(), 10, ccc3(255, 255, 255), 90);
            this->addChild(tex, exObj->getSprite()->getZOrder() - 1, 778);
        }
    }
}

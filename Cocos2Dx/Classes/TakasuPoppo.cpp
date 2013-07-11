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
    
    TakasuPoppo::addBlocksToArray();
    TakasuPoppo::addTileMap();
    
    CCSprite *background = CCSprite::create("PuzzleBackgroud3.png");
    background->setPosition(ccp(winSize.width/2, winSize.height/2));
    this->addChild(background, -2, -2);
    
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
        TakasuPoppo::cleanBlocks();
        this->runAction(CCSequence::create(CCCallFunc::create(this, callfunc_selector(TakasuPoppo::cleanBlocks)),
                                           CCDelayTime::create(0.1),
                                           CCCallFunc::create(this, callfunc_selector(TakasuPoppo::afterClean)),
                                           CCDelayTime::create(0.1),
                                           CCCallFunc::create(this, callfunc_selector(TakasuPoppo::smartGeneration)),
                                           NULL));

        this->schedule(schedule_selector(TakasuPoppo::fallingBoolSwitch));
    }
}

void TakasuPoppo::fallingBoolSwitch(float dt) {
    inTheFall = true;    
    fallCounter += deltaTime;
    if (fallCounter > 0.4) {
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

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
    
    debugTilesArray = new CCArray;
    testArray = new CCArray;
    
    TakasuPoppo::addBlocksToArray();
    TakasuPoppo::addTileMap();
    TakasuPoppo::matchList();
    
    
    CCSprite *background = CCSprite::create("PuzzleBackgroud3.png");
    background->setPosition(ccp(winSize.width/2, winSize.height/2));
    this->addChild(background, -2, -2);
    TakasuPoppo::lookForMatches();

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

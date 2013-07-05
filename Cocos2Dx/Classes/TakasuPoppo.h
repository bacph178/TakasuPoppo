//  Created by MinhNT on 13/05/16.
//  Copyright FRAMGIA 2013年. All rights reserved.
//

#ifndef __TAKASUPOPPO_H__
#define __TAKASUPOPPO_H__

#include "cocos2d.h"
#include "TPObjectExtension.h"
USING_NS_CC;
class TakasuPoppo : public cocos2d::CCLayer {
private:
    CCPoint startSwipePoint;
    CCPoint movingSwipePoint;
    CCPoint endSwipePoint;
    
    CCSprite *buttonSprite;
    CCSprite *refreshButton;
    CCSprite *removeButton;
    
    CCTMXLayer *layer;
    CCTMXTiledMap *map;
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    
    CCArray *colorArray;
    CCArray *toDestroyArray;
    CCArray *pickedArray;
    
    CCArray *debugTilesArray;
    CCArray *testArray;
    
    bool spriteContained;
    bool swiping;
    bool swipeRecognized;
    
    bool swipeRight;
    bool swipeLeft;
    bool swipeUp;
    bool swipeDown;
    
    bool gridOn = false;
public:
    //TakasuPoppo
    static cocos2d::CCScene* scene();
    virtual bool init();
    virtual void update(float dt);
    void menuCloseCallback(CCObject* pSender);
    
    //TPTouch
    virtual void ccTouchesBegan(CCSet *touches, CCEvent *event);
    virtual void ccTouchesMoved(CCSet *touches, CCEvent *event);
    virtual void ccTouchesEnded(CCSet *touches, CCEvent *event);
    bool touchPosValidation(CCPoint touchLoc);
    
    //TPMap
    void addTileMap();
    void createFixture();
    void checkEmpty();
    void generateRandomBlock(TPObjectExtension *exObj);
    CCPoint tileCoorForPosition(CCPoint position);
    
    void addBlocksToArray();
    void setValuesForExObj(TPObjectExtension *exObj, int colorID, int gid, CCSprite *sprite, CCPoint position, CCPoint coordination, bool trigger);
    void checkAndAddToRemove();
    void removeObjectsFromDestroyArray();
    void onRemoveMoveTiles(TPObjectExtension *exObj);
    
    //TPMatch
    bool isTileMatched(int gid, int typeID);
    bool isBlockMatched(int gid, int typeID);
    
    bool isRightTriMatch(int gid, int typeID);
    bool isLeftTriMatch(int gid, int typeID);
    bool isTopTriMatch(int gid, int typeID);
    bool isBottomTriMatch(int gid, int typeID);
    
    bool isLeftQuadMatch(int gid, int typeID);
    bool isRightQuadMatch(int gid, int typeID);
    bool isUpQuadMatch(int gid, int typeID);
    bool isDownQuadMatch(int gid, int typeID);
    
    bool isMidHorMatch(int gid, int typeID);
    bool isMidVerMatch(int gid, int typeID);
    
    bool isPentaHorMatch(int gid, int typeID);
    bool isPentaVerMatch(int gid, int typeID);
    
    void lookForMatches();
    TPObjectExtension *coorToExObj(CCPoint);
    
    bool sumOfMatches(TPObjectExtension *exA, TPObjectExtension *exB,
                      TPObjectExtension *ex1, TPObjectExtension *ex2, TPObjectExtension *ex3);
    
    bool matchPatternHorTwo(CCPoint coor, CCArray pointsArray);

    
    CCArray *matchList();
    CCArray *getMatchHor(TPObjectExtension *exObj);
    CCArray *getMatchVer(TPObjectExtension *exObj);
    
    //TPClean
    void cleanBlocks();
    void afterClean();
    
    //TPSwiped
    void swapTilesCheck(TPObjectExtension *exObj, int swpGid);
    void swapTilesMoving(TPObjectExtension *exObj, TPObjectExtension *swpObj);
    void swapTilesReturn(TPObjectExtension *exObj, TPObjectExtension *swpObj);
    void swapColorID(TPObjectExtension *exObj, TPObjectExtension *swpObj);
    
    void swipedUp(TPObjectExtension *exObj);
    void swipedDown(TPObjectExtension *exObj);
    void swipedLeft(TPObjectExtension *exObj);
    void swipedRight(TPObjectExtension *exObj);
    
    //TPParticles
    void popParticles(CCPoint position);
    void remoteParticles();
    
    void setupDebugButton();
    void switchGrid();
    void remove();
    void refresh();
    void checkTile();
    void destroyAllBlocks();
    
    CREATE_FUNC(TakasuPoppo);
};

#endif
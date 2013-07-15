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
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    
    CCPoint startSwipePoint;        //The starting point of swiping action
    CCPoint movingSwipePoint;       //The points that change during moving action
    CCPoint endSwipePoint;          //The points at the end of swiping action
    
    CCSprite *buttonSprite;         //A sprite for debug grid button
    CCSprite *refreshButton;        //A sprite for refresh grid button
    CCSprite *removeButton;         //A sprite for remove grid button
    
    CCTMXLayer *layer;              //The TMX Layer
    CCTMXTiledMap *map;             //The TMX Map
    
    CCArray *colorArray;            //Main blocks array, consist of TPObjectEx, stupidly named
    CCArray *toDestroyArray;        //To be removed blocks will be inserted to this array
    CCArray *pickedArray;           //The array of object to be moved with swipe button, 1 object only
    
    TPObjectExtension *movedSprite; //The sprite to be moved with swipe button
    TPObjectExtension *swapedSprite;//The sprite to be swaped with moving sprite
    
    CCArray *debugTilesArray;       //The array consisting of debug objects
    
    float moveCounter;              //Counter time for move swipe action
    float fallCounter;              //Counter time for falling counter action
    float deltaTime;                //Public variable for delta time
    
    float movingSpeed = 0.07;       //For all moving speed
    
    bool spriteContained;           //Bool for the touch on sprite's trigger
    bool swiping;                   //Bool for swiping action
    bool swipeRecognized;           //Bool for swipe action recognized
    
    bool controlable;               //If the sprites are on the move, rends controlable false
    
    bool inTheMove;                 //True if there are sprites in moving action
    bool inTheFall;                 //True if sprites are falling
    
    bool swipeRight;                //True if swipe right action is recognized
    bool swipeLeft;                 //True if swipe left action is recognized
    bool swipeUp;                   //True if swipe up action is recognized
    bool swipeDown;                 //True if swipe down action is recognized
    
    bool gridOn = false;
    
    
public:
    #pragma mark Takasu Poppo 
    static cocos2d::CCScene* scene();
    virtual bool init();
    virtual void update(float dt);
    void menuCloseCallback(CCObject* pSender);
    
    //Fixed update for executing game's logic
    void fixedUpdate(float time);
    
    //Scheduler for moving time delay
    void movingBoolSwitch(float time);
    //Scheduler for falling time delay
    void fallingBoolSwitch(float time);
    //Unschedule generation
    void scheduleGenerate();
    
    #pragma mark Touch
    virtual void ccTouchesBegan(CCSet *touches, CCEvent *event);
    virtual void ccTouchesMoved(CCSet *touches, CCEvent *event);
    virtual void ccTouchesEnded(CCSet *touches, CCEvent *event);
    //Validate touch position, returns false if out of map
    bool touchPosValidation(CCPoint touchLoc);
    
    #pragma mark Map
    //Creates TMX Map
    void addTileMap();
    //Add fixture to TMX Layer
    void createFixture();
    
    //Check if there is an empty block, not in use
    void checkEmpty();
    //Generate a random sprite on EX object
    void generateRandomBlock(TPObjectExtension *exObj);
    //Generate a certain sprite on EX Object
    void generateBlock(TPObjectExtension *exObj1, int type);
    
    //Returns a coordination for position
    CCPoint tileCoorForPosition(CCPoint position);
    
    //Inserts empty blocks to array, to be assigned in the next function
    void addBlocksToArray();
    //Set values for EX Object
    void setValuesForExObj(TPObjectExtension *exObj, int colorID, int gid, CCSprite *sprite, CCPoint position, CCPoint coordination, bool trigger);
    
    #pragma mark Match
    //Check if there is matching pair in the begining, gotta rewrite it later
    bool isTileMatched(int gid, int typeID);
    
    //Check matching blocks and add them to destroy array
    void matchList();
    //Called in matchList function, to determinte Horizontal Matches
    CCArray *getMatchHor(TPObjectExtension *exObj);
    //Called in matchList function, to determinte Vertical Matches
    CCArray *getMatchVer(TPObjectExtension *exObj);
    
    //Returns a sum of possible matches
    int lookForMatches();
    //Returns true if match exists with objects
    bool sumOfMatches(TPObjectExtension *exA, TPObjectExtension *exB,
                      TPObjectExtension *ex1, TPObjectExtension *ex2, TPObjectExtension *ex3);
    
    //Returns an EX Object for coordination, awesome
    TPObjectExtension *coorToExObj(CCPoint);
    
    //Check before swapping a sprite if a match will be possible
    bool matchAble(CCPoint coor, int type);
    
    //Generate a match if there is a shortage
    void smartGeneration();
    
    #pragma mark Clean
    //Remove blocks from destroy array
    void cleanBlocks();
    //Move the blocks on the top of the destroyed blocks down
    void afterClean();
    
    #pragma mark Swiped
    //If swipe is recognizes, run into one of the followings
    void swipedUp(TPObjectExtension *exObj);
    void swipedDown(TPObjectExtension *exObj);
    void swipedLeft(TPObjectExtension *exObj);
    void swipedRight(TPObjectExtension *exObj);
    
    //Check the moving object and swapping object if action is possible, stupidly named
    void swapTilesCheck(TPObjectExtension *exObj, int swpGid);
    
    //Swap 2 blocks sprites and type IDs
    void swapColorID(TPObjectExtension *exObj, TPObjectExtension *swpObj);
    //Turn on or off controlable bool
    void switchControlable(TPObjectExtension *exObj);
    
    //Check if swapedSprite and movedSprite are in their position
    void checkPosition();
    //Runs and return, for when moving is not possible
    void swapTilesBack();
    
    #pragma mark Particles
    //Pop particles
    void popParticles(CCPoint position);
    //Remote particles run function, not available yet
    void remoteParticles();
    
    #pragma mark Debug
    void setupDebugButton();
    void switchGrid();
    void remove();
    void refresh();
    void destroyAllBlocks();
    
    CREATE_FUNC(TakasuPoppo);
};

#endif
//
//  TP_Map.cpp
//  Cocos2Dx
//
//  Created by macbook_006 on 13/06/28.
//
//

#include "TakasuPoppo.h"
#pragma mark Tile Functions

void TakasuPoppo::addTileMap () {
    map = CCTMXTiledMap::create("90x90TileMap.tmx");
    this->addChild(map, -1, -1);
    layer = map->layerNamed("Layer");
    CCLog("Layer width %f and height %f", layer->getContentSize().width, layer->getContentSize().height);
    TakasuPoppo::createFixture();
    
    CCArray *pChildrenArray = map->getChildren();
    CCObject *pObject = NULL;
    CCSpriteBatchNode *child = NULL;
    CCARRAY_FOREACH(pChildrenArray, pObject) {
        child = ((CCSpriteBatchNode *)pObject);
        if (!child) break;
        child->getTexture()->setAntiAliasTexParameters();
    }
}

void TakasuPoppo::createFixture() {
    CCSize layerSize = layer->getLayerSize();
    
    for (int y = 0; y < layerSize.height; y++) {
        for (int x = 0; x < layerSize.width; x++) {
            
            CCSprite *tileSprite = layer->tileAt(ccp(x, y));
            unsigned int m_gid = layer->tileGIDAt(ccp(x, y));
            
            char tileName[7][20];
            strcpy(tileName[0], "Candy");
            strcpy(tileName[1], "Candy2");
            strcpy(tileName[2], "Candy3");
            strcpy(tileName[3], "Candy4");
            strcpy(tileName[4], "Candy5");
            strcpy(tileName[5], "Candy6");
            strcpy(tileName[6], "Candy7");
            
            int randomTile = rand() % 7;
            char spriteName[100];
            
            while (TakasuPoppo::isTileMatched(m_gid, randomTile)) randomTile = rand() % 7;
            
            sprintf(spriteName, "%s.png", tileName[randomTile]);
            
            CCSprite *randomTileSprite = CCSprite::create(spriteName);
            CCPoint tilePosition = ccp(tileSprite->getPositionX() + tileSprite->getContentSize().width/2,
                                       tileSprite->getPositionY() + tileSprite->getContentSize().height/2);
            CCPoint tileCoordination = TakasuPoppo::tileCoorForPosition(tilePosition);
            randomTileSprite->setPosition(ccp(tilePosition.x, tilePosition.y + 10));
            CCObject *object = colorArray->objectAtIndex(m_gid - 1);
            TPObjectExtension *exObj = dynamic_cast<TPObjectExtension*>(object);
            TakasuPoppo::setValuesForExObj(exObj, randomTile, m_gid, randomTileSprite, tilePosition, tileCoordination, true);
  
            this->addChild(randomTileSprite, 3, 300 + m_gid);
        }
    }
}

CCPoint TakasuPoppo::tileCoorForPosition(CCPoint position) {
    float x = position.x / map->getTileSize().width;
    float y = ((winSize.height - (winSize.height - layer->getContentSize().height)) - position.y) /
               (map->getTileSize().height);
    CCPoint transPos = ccp(floor(x), floor(y));
    return transPos;
}

void TakasuPoppo::checkEmpty() {
    CCObject *object;
    CCARRAY_FOREACH_REVERSE(colorArray, object) {
        TPObjectExtension *exObj = dynamic_cast<TPObjectExtension*>(object);
        if (exObj->getID() == 7) {
            generateRandomBlock(exObj);
        }
    }
    controlable = true;
}

void TakasuPoppo::generateRandomBlock(TPObjectExtension *exObj) {
    char tileName[7][20];
    strcpy(tileName[0], "Candy");
    strcpy(tileName[1], "Candy2");
    strcpy(tileName[2], "Candy3");
    strcpy(tileName[3], "Candy4");
    strcpy(tileName[4], "Candy5");
    strcpy(tileName[5], "Candy6");
    strcpy(tileName[6], "Candy7");
    int randomTile = rand() % 7;
    char spriteName[100];
    
    sprintf(spriteName, "%s.png", tileName[randomTile]);
    
    CCSprite *randomTileSprite = CCSprite::create(spriteName);
    randomTileSprite->setPosition(ccp(exObj->getPosition().x, exObj->getPosition().y + 70));
    randomTileSprite->runAction(CCMoveTo::create(0.3, exObj->getPosition()));
    
    exObj->setSprite(randomTileSprite);
    exObj->setID(randomTile);
    this->addChild(randomTileSprite, 3, 300 + exObj->getGid());
}

void TakasuPoppo::generateBlock(TPObjectExtension *exObj1, int type) {
    if (type == 0) {
        CCSprite *randomTileSprite = CCSprite::create("Candy.png");
        randomTileSprite->setPosition(ccp(exObj1->getPosition().x, exObj1->getPosition().y + 70));
        randomTileSprite->runAction(CCMoveTo::create(0.3, exObj1->getPosition()));
        exObj1->setSprite(randomTileSprite);
        exObj1->setID(0);
        this->addChild(randomTileSprite, 3, 300 + exObj1->getGid());
        return;
    }
    if (type == 1) {
        CCSprite *randomTileSprite = CCSprite::create("Candy2.png");
        randomTileSprite->setPosition(ccp(exObj1->getPosition().x, exObj1->getPosition().y + 70));
        randomTileSprite->runAction(CCMoveTo::create(0.3, exObj1->getPosition()));
        exObj1->setSprite(randomTileSprite);
        exObj1->setID(1);
        this->addChild(randomTileSprite, 3, 300 + exObj1->getGid());
        return;
    }
    if (type == 2) {
        CCSprite *randomTileSprite = CCSprite::create("Candy3.png");
        randomTileSprite->setPosition(ccp(exObj1->getPosition().x, exObj1->getPosition().y + 70));
        randomTileSprite->runAction(CCMoveTo::create(0.3, exObj1->getPosition()));
        exObj1->setSprite(randomTileSprite);
        exObj1->setID(2);
        this->addChild(randomTileSprite, 3, 300 + exObj1->getGid());
        return;
    }
    if (type == 3) {
        CCSprite *randomTileSprite = CCSprite::create("Candy4.png");
        randomTileSprite->setPosition(ccp(exObj1->getPosition().x, exObj1->getPosition().y + 70));
        randomTileSprite->runAction(CCMoveTo::create(0.3, exObj1->getPosition()));
        exObj1->setSprite(randomTileSprite);
        exObj1->setID(3);
        this->addChild(randomTileSprite, 3, 300 + exObj1->getGid());
        return;
    }
    if (type == 4) {
        CCSprite *randomTileSprite = CCSprite::create("Candy5.png");
        randomTileSprite->setPosition(ccp(exObj1->getPosition().x, exObj1->getPosition().y + 70));
        randomTileSprite->runAction(CCMoveTo::create(0.3, exObj1->getPosition()));
        exObj1->setSprite(randomTileSprite);
        exObj1->setID(4);
        this->addChild(randomTileSprite, 3, 300 + exObj1->getGid());
        return;
    }
    if (type == 5) {
        CCSprite *randomTileSprite = CCSprite::create("Candy6.png");
        randomTileSprite->setPosition(ccp(exObj1->getPosition().x, exObj1->getPosition().y + 70));
        randomTileSprite->runAction(CCMoveTo::create(0.3, exObj1->getPosition()));
        exObj1->setSprite(randomTileSprite);
        exObj1->setID(5);
        this->addChild(randomTileSprite, 3, 300 + exObj1->getGid());
        return;
    }
    if (type == 6) {
        CCSprite *randomTileSprite = CCSprite::create("Candy7.png");
        randomTileSprite->setPosition(ccp(exObj1->getPosition().x, exObj1->getPosition().y + 70));
        randomTileSprite->runAction(CCMoveTo::create(0.3, exObj1->getPosition()));
        exObj1->setSprite(randomTileSprite);
        exObj1->setID(6);
        this->addChild(randomTileSprite, 3, 300 + exObj1->getGid());
        return;
    }
    if (type == 7) {
        CCLog("Are you an idiot to assign an nothing to an empty block?");
        generateRandomBlock(exObj1);
        return;
    }

    CCLog("The stupidity knows no bound.");
    generateRandomBlock(exObj1);
    
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

//
//  TP_TakasuPoppo_Match.cpp
//  Cocos2Dx
//
//  Created by macbook_006 on 13/06/28.
//
//

#include "TakasuPoppo.h"
#include "TPBlockSet.h"
#pragma mark Matching Control

bool TakasuPoppo::isTileMatched(int gid, int typeID) {
    int leftTile = gid -1, leftLeftTile = gid - 2,
    rightTile = gid +1, rightRightTile = gid + 2,
    topTile = gid - 7, topTopTile = gid - 14,
    bottomTile = gid +7, bottomBottomTile = gid + 14;
    
    CCObject *tileObject;
    CCARRAY_FOREACH(colorArray, tileObject) {
        TPObjectExtension *cp = (TPObjectExtension*)(tileObject);
        CCObject *thisObject;
        if (gid != 1 && gid != 2 &&
            gid != 8 && gid != 9 &&
            gid != 15 && gid != 16 &&
            gid != 22 && gid != 23 &&
            gid != 29 && gid != 30 &&
            gid != 36 && gid != 37 &&
            gid != 43 &&gid != 44 ) {
            if (cp->getGid() == leftTile && cp->getID() == typeID) {
                CCObject *thisObject = colorArray->objectAtIndex(leftLeftTile);
                CCARRAY_FOREACH(colorArray, thisObject) {
                    TPObjectExtension *thisCp = (TPObjectExtension*)(thisObject);
                    if (thisCp->getGid() == leftLeftTile && thisCp->getID() == typeID) return true; continue;
                }
            }
        }
        if (gid != 6 && gid != 7 &&
            gid != 13 && gid != 14 &&
            gid != 20 && gid != 21 &&
            gid != 27 && gid != 28 &&
            gid != 34 && gid != 35 &&
            gid != 41 && gid != 42 &&
            gid != 48 && gid != 49 ) {
            if (cp->getGid() == rightTile && cp->getID() == typeID) {
                CCARRAY_FOREACH(colorArray, thisObject) {
                    TPObjectExtension *thisCp = (TPObjectExtension*)(thisObject);
                    if (thisCp->getGid() == rightRightTile && thisCp->getID() == typeID) return true; continue;
                }
            }
        }
        if (gid >= 15) {
            if (cp->getGid()  == topTile && cp->getID() == typeID) {
                CCARRAY_FOREACH(colorArray, thisObject) {
                    TPObjectExtension *thisCp = (TPObjectExtension*)(thisObject);
                    if (thisCp->getGid()  == topTopTile && thisCp->getID() == typeID) return true; continue;
                }
            }
        }
        if (gid <= 35) {
            if (cp->getGid()  == bottomTile && cp->getID() == typeID) {
                CCARRAY_FOREACH(colorArray, thisObject) {
                    TPObjectExtension *thisCp = (TPObjectExtension*)(thisObject);
                    if (thisCp->getGid() == bottomBottomTile && thisCp->getID() == typeID) return true; continue;
                }
            }
        }
    }
    return false;
}

bool TakasuPoppo::isBlockMatched(int gid, int typeID) {
    CCLog("GID %i & Color %i", gid, typeID);
    if (gid != 1 && gid != 2 && gid != 6 && gid !=7 &&
        gid != 8 && gid != 9 && gid != 13 &&  gid !=14 &&
        gid != 15 && gid != 16 && gid != 20 && gid !=21 &&
        gid != 22 && gid != 23 && gid != 27 && gid !=28 &&
        gid != 29 && gid != 30 && gid != 34 &&  gid !=35 &&
        gid != 36 && gid != 37 && gid != 41 && gid !=42 &&
        gid != 43 && gid != 44 && gid != 48 && gid !=49) {
        if (TakasuPoppo::isPentaHorMatch(gid, typeID)) {
            CCLog("Penta Hor");
            return true;
        }
    }
    
    if (gid >= 15 && gid <= 35) {
        if (TakasuPoppo::isPentaVerMatch(gid, typeID)) {
            CCLog("Penta Ver");
            return true;
        }
    }
    
    if (gid != 1 && gid != 2 && gid != 7 &&
        gid != 8 && gid != 9 && gid != 14 &&
        gid != 15 && gid != 16 && gid != 21 &&
        gid != 22 && gid != 23 && gid != 28 &&
        gid != 29 && gid != 30 && gid != 35 &&
        gid != 36 && gid != 37 && gid != 42 &&
        gid != 43 && gid != 44 && gid != 49) {
        if (TakasuPoppo::isLeftQuadMatch(gid, typeID)) {
            CCLog("Left Quad");
            return true;
        }
    }
    
    if (gid != 1 && gid != 6 && gid != 7 &&
        gid != 8 && gid != 13 && gid != 14 &&
        gid != 15 && gid != 20 && gid != 21 &&
        gid != 22 && gid != 27 && gid != 28 &&
        gid != 29 && gid != 34 && gid != 35 &&
        gid != 36 && gid != 41 && gid != 42 &&
        gid != 43 && gid != 48 && gid != 49) {
        if (TakasuPoppo::isRightQuadMatch(gid, typeID)) {
            CCLog("Right Quad");
            return true;
        }
    }
    
    if (gid >= 15 && gid <= 42) {
        if (TakasuPoppo::isUpQuadMatch(gid, typeID)) {
            CCLog("Top Quad");
            return true;
        }
    }
    
    if (gid >= 8 && gid <= 35) {
        if (TakasuPoppo::isDownQuadMatch(gid, typeID)) {
            CCLog("Bottom Quad");
            return true;
        }
    }
    
    if (gid != 1 &&  gid !=7 &&
        gid != 8 &&  gid !=14 &&
        gid != 15 &&  gid !=21 &&
        gid != 22 &&  gid !=28 &&
        gid != 29 &&  gid !=35 &&
        gid != 36 &&  gid !=42 &&
        gid != 43 &&  gid !=49) {
        if (TakasuPoppo::isMidHorMatch(gid, typeID)) {
            CCLog("Mid Hor");
            return true;
        }
    }
    
    if (gid >= 8 && gid <= 42) {
        if (TakasuPoppo::isMidVerMatch(gid, typeID)) {
            CCLog("Mid Ver");
            return true;
        }
    }
    
    if (gid != 1 && gid != 2 &&
        gid != 8 && gid != 9 &&
        gid != 15 && gid != 16 &&
        gid != 22 && gid != 23 &&
        gid != 29 && gid != 30 &&
        gid != 36 && gid != 37 &&
        gid != 43 && gid != 44 ) {
        if (TakasuPoppo::isLeftTriMatch(gid, typeID)) {
            CCLog("Left Tri");
            return true;
        }
    }
    
    if (gid != 6 && gid != 7 &&
        gid != 13 && gid != 14 &&
        gid != 20 && gid != 21 &&
        gid != 27 && gid != 28 &&
        gid != 34 && gid != 35 &&
        gid != 41 && gid != 42 &&
        gid != 48 && gid != 49 ) {
        if (TakasuPoppo::isRightTriMatch(gid, typeID)) {
            CCLog("Right Tri");
            return true;
        }
    }
    
    if (gid >= 15) {
        if (TakasuPoppo::isTopTriMatch(gid, typeID)) {
            CCLog("Top Tri");
            return true;
        }
    }
    
    if (gid <= 35) {
        if (TakasuPoppo::isBottomTriMatch(gid, typeID)) {
            CCLog("Bottom Tri");
            return true;
        }
    }
    return false;
}

bool TakasuPoppo::isRightTriMatch(int gid, int typeID) {
    int gidToIndex = gid - 1;
    CCObject *rightObject = colorArray->objectAtIndex(gidToIndex + 1);
    TPObjectExtension *rightExObj = dynamic_cast<TPObjectExtension*>(rightObject);
    CCObject *rightRightObject = colorArray->objectAtIndex(gidToIndex + 2);
    TPObjectExtension *rightRightEx = dynamic_cast<TPObjectExtension*>(rightRightObject);
    if (rightExObj->getID() == typeID && rightRightEx->getID() == typeID) {
        CCObject *object = colorArray->objectAtIndex(gidToIndex);
        TPObjectExtension *mainObject = dynamic_cast<TPObjectExtension*>(object);
        TPBlockSet *blockSet = new TPBlockSet(mainObject, rightExObj, rightRightEx, NULL, NULL,
                                              "TrioRight", mainObject->getCoordination().x, mainObject->getCoordination().y);
        toDestroyArray->addObject(blockSet);
        return true;
    }
    return false;
}

bool TakasuPoppo::isLeftTriMatch(int gid, int typeID) {
    int gidToIndex = gid - 1;
    CCObject *leftObject = colorArray->objectAtIndex(gidToIndex - 1);
    TPObjectExtension *leftExObj = dynamic_cast<TPObjectExtension*>(leftObject);
    CCObject *leftLeftObject = colorArray->objectAtIndex(gidToIndex - 2);
    TPObjectExtension *leftLeftEx = dynamic_cast<TPObjectExtension*>(leftLeftObject);
    CCLog("Left Object ID: %i ; Left Left Object ID: %i", leftExObj->getID(), leftLeftEx->getID());
    CCLog("Left Object GID:%i ; Left Left Object GID:%i", leftExObj->getGid(), leftLeftEx->getGid());
    if (leftExObj->getID() == typeID && leftLeftEx->getID() == typeID) {
        CCObject *object = colorArray->objectAtIndex(gidToIndex);
        TPObjectExtension *mainObject = dynamic_cast<TPObjectExtension*>(object);
        TPBlockSet *blockSet = new TPBlockSet(leftLeftEx, leftExObj, mainObject, NULL, NULL,
                                              "TrioLeft", mainObject->getCoordination().x, mainObject->getCoordination().y);
        toDestroyArray->addObject(blockSet);
        return true;
    }
    return false;
}

bool TakasuPoppo::isTopTriMatch(int gid, int typeID) {
    int gidToIndex = gid - 1;
    CCObject *topObject = colorArray->objectAtIndex(gidToIndex - 7);
    TPObjectExtension *topExObj = dynamic_cast<TPObjectExtension*>(topObject);
    CCObject *topTopObj = colorArray->objectAtIndex(gidToIndex - 14);
    TPObjectExtension *topTopEx = dynamic_cast<TPObjectExtension*>(topTopObj);
    if (topExObj->getID() == typeID && topTopEx->getID() == typeID) return true;
    return false;
}

bool TakasuPoppo::isBottomTriMatch(int gid, int typeID) {
    int gidToIndex = gid - 1;
    CCObject *bottomObject = colorArray->objectAtIndex(gidToIndex + 7);
    TPObjectExtension *bottomExObj = dynamic_cast<TPObjectExtension*>(bottomObject);
    CCObject *bottomBottomObject = colorArray->objectAtIndex(gidToIndex + 14);
    TPObjectExtension *bottomBottomEx = dynamic_cast<TPObjectExtension*>(bottomBottomObject);
    if (bottomExObj->getID() == typeID && bottomBottomEx->getID() == typeID) return true;
    return false;
}

bool TakasuPoppo::isLeftQuadMatch(int gid, int typeID) {
    int gidToIndex = gid - 1;
    CCObject *leftObject = colorArray->objectAtIndex(gidToIndex - 1);
    TPObjectExtension *leftExObj = dynamic_cast<TPObjectExtension*>(leftObject);
    CCObject *leftLeftObject = colorArray->objectAtIndex(gidToIndex - 2);
    TPObjectExtension *leftLeftEx = dynamic_cast<TPObjectExtension*>(leftLeftObject);
    CCObject *rightObject = colorArray->objectAtIndex(gidToIndex + 1);
    TPObjectExtension *rightExObj = dynamic_cast<TPObjectExtension*>(rightObject);
    if (leftExObj->getID() == typeID && leftLeftEx->getID() == typeID && rightExObj->getID() == typeID) return true;
    return false;
}

bool TakasuPoppo::isRightQuadMatch(int gid, int typeID) {
    int gidToIndex = gid - 1;
    CCLOG("%d",gidToIndex);
    CCObject *rightObject = colorArray->objectAtIndex(gidToIndex + 1);
    TPObjectExtension *rightExObj = dynamic_cast<TPObjectExtension*>(rightObject);
    CCObject *rightRightObject = colorArray->objectAtIndex(gidToIndex + 2);
    TPObjectExtension *rightRightEx = dynamic_cast<TPObjectExtension*>(rightRightObject);
    CCObject *leftObject = colorArray->objectAtIndex(gidToIndex - 1);
    TPObjectExtension *leftExObj = dynamic_cast<TPObjectExtension*>(leftObject);
    if (rightExObj->getID() == typeID && rightRightEx->getID() == typeID && leftExObj->getID() == typeID) return true;
    return false;
}

bool TakasuPoppo::isUpQuadMatch(int gid, int typeID) {
    int gidToIndex = gid - 1;
    CCObject *topObject = colorArray->objectAtIndex(gidToIndex - 7);
    TPObjectExtension *topExObj = dynamic_cast<TPObjectExtension*>(topObject);
    CCObject *topTopObj = colorArray->objectAtIndex(gidToIndex - 14);
    TPObjectExtension *topTopEx = dynamic_cast<TPObjectExtension*>(topTopObj);
    CCObject *bottomObject = colorArray->objectAtIndex(gidToIndex + 7);
    TPObjectExtension *bottomExObj = dynamic_cast<TPObjectExtension*>(bottomObject);
    if (topExObj->getID() == typeID && topTopEx->getID() == typeID && bottomExObj->getID() == typeID) return true;
    return false;
}

bool TakasuPoppo::isDownQuadMatch(int gid, int typeID) {
    int gidToIndex = gid - 1;
    CCObject *bottomObject = colorArray->objectAtIndex(gidToIndex + 7);
    TPObjectExtension *bottomExObj = dynamic_cast<TPObjectExtension*>(bottomObject);
    CCObject *bottomBottomObject = colorArray->objectAtIndex(gidToIndex + 14);
    TPObjectExtension *bottomBottomEx = dynamic_cast<TPObjectExtension*>(bottomBottomObject);
    CCObject *topObject = colorArray->objectAtIndex(gidToIndex - 7);
    TPObjectExtension *topExObj = dynamic_cast<TPObjectExtension*>(topObject);
    if (bottomExObj->getID() == typeID && bottomBottomEx->getID() == typeID && topExObj->getID() == typeID) return true;
    return false;
}

bool TakasuPoppo::isMidHorMatch(int gid, int typeID) {
    int gidToIndex = gid - 1;
    CCObject *leftObject = colorArray->objectAtIndex(gidToIndex - 1);
    TPObjectExtension *leftExObj = dynamic_cast<TPObjectExtension*>(leftObject);
    CCObject *rightObject = colorArray->objectAtIndex(gidToIndex + 1);
    TPObjectExtension *rightExObj = dynamic_cast<TPObjectExtension*>(rightObject);
    if (leftExObj->getID() == typeID && rightExObj->getID() == typeID) {
        CCObject *object = colorArray->objectAtIndex(gidToIndex);
        TPObjectExtension *mainObject = dynamic_cast<TPObjectExtension*>(object);
        TPBlockSet *blockSet = new TPBlockSet(leftExObj, mainObject, rightExObj, NULL, NULL,
                                              "TrioMid", mainObject->getCoordination().x, mainObject->getCoordination().y);
        toDestroyArray->addObject(blockSet);
        return true;
    }
    return false;
}

bool TakasuPoppo::isMidVerMatch(int gid, int typeID) {
    int gidToIndex = gid - 1;
    CCObject *topObject = colorArray->objectAtIndex(gidToIndex - 7);
    TPObjectExtension *topExObj = dynamic_cast<TPObjectExtension*>(topObject);
    CCObject *bottomObject = colorArray->objectAtIndex(gidToIndex + 7);
    TPObjectExtension *bottomExObj = dynamic_cast<TPObjectExtension*>(bottomObject);
    if (topExObj->getID() == typeID && bottomExObj->getID() == typeID) return true;
    return false;
}

bool TakasuPoppo::isPentaHorMatch(int gid, int typeID) {
    int gidToIndex = gid - 1;
    CCObject *rightObject = colorArray->objectAtIndex(gidToIndex + 1);
    TPObjectExtension *rightExObj = dynamic_cast<TPObjectExtension*>(rightObject);
    CCObject *rightRightObject = colorArray->objectAtIndex(gidToIndex + 2);
    TPObjectExtension *rightRightEx = dynamic_cast<TPObjectExtension*>(rightRightObject);
    CCObject *leftObject = colorArray->objectAtIndex(gidToIndex - 1);
    TPObjectExtension *leftExObj = dynamic_cast<TPObjectExtension*>(leftObject);
    CCObject *leftLeftObject = colorArray->objectAtIndex(gidToIndex - 2);
    TPObjectExtension *leftLeftEx = dynamic_cast<TPObjectExtension*>(leftLeftObject);
    if (leftExObj->getID() == typeID && leftLeftEx->getID() == typeID &&
        rightExObj->getID() == typeID && rightRightEx->getID() == typeID) return true;
    return false;
}

bool TakasuPoppo::isPentaVerMatch(int gid, int typeID) {
    int gidToIndex = gid - 1;
    CCObject *topObject = colorArray->objectAtIndex(gidToIndex - 7);
    TPObjectExtension *topExObj = dynamic_cast<TPObjectExtension*>(topObject);
    CCObject *topTopObj = colorArray->objectAtIndex(gidToIndex - 14);
    TPObjectExtension *topTopEx = dynamic_cast<TPObjectExtension*>(topTopObj);
    CCObject *bottomObject = colorArray->objectAtIndex(gidToIndex + 7);
    TPObjectExtension *bottomExObj = dynamic_cast<TPObjectExtension*>(bottomObject);
    CCObject *bottomBottomObject = colorArray->objectAtIndex(gidToIndex + 14);
    TPObjectExtension *bottomBottomEx = dynamic_cast<TPObjectExtension*>(bottomBottomObject);
    if (topExObj->getID() == typeID && topTopEx->getID() == typeID &&
        bottomExObj->getID() == typeID && bottomBottomEx->getID() == typeID) return true;
    return false;
}

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
    if (topExObj->getID() == typeID && topTopEx->getID() == typeID) {
        CCObject *object = colorArray->objectAtIndex(gidToIndex);
        TPObjectExtension *mainObject = dynamic_cast<TPObjectExtension*>(object);
        TPBlockSet *blockSet = new TPBlockSet(topTopEx, topExObj, mainObject, NULL, NULL,
                                              "TrioTop", mainObject->getCoordination().x, mainObject->getCoordination().y);
        toDestroyArray->addObject(blockSet);
        return true;
    }
    return false;
}

bool TakasuPoppo::isBottomTriMatch(int gid, int typeID) {
    int gidToIndex = gid - 1;
    CCObject *bottomObject = colorArray->objectAtIndex(gidToIndex + 7);
    TPObjectExtension *bottomExObj = dynamic_cast<TPObjectExtension*>(bottomObject);
    CCObject *bottomBottomObject = colorArray->objectAtIndex(gidToIndex + 14);
    TPObjectExtension *bottomBottomEx = dynamic_cast<TPObjectExtension*>(bottomBottomObject);
    if (bottomExObj->getID() == typeID && bottomBottomEx->getID() == typeID) {
        CCObject *object = colorArray->objectAtIndex(gidToIndex);
        TPObjectExtension *mainObject = dynamic_cast<TPObjectExtension*>(object);
        TPBlockSet *blockSet = new TPBlockSet(mainObject, bottomExObj, bottomBottomEx, NULL, NULL,
                                              "TrioBottom", mainObject->getCoordination().x, mainObject->getCoordination().y);
        toDestroyArray->addObject(blockSet);
        return true;
    }
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
    if (leftExObj->getID() == typeID && leftLeftEx->getID() == typeID && rightExObj->getID() == typeID) {
        CCObject *object = colorArray->objectAtIndex(gidToIndex);
        TPObjectExtension *mainObject = dynamic_cast<TPObjectExtension*>(object);
        TPBlockSet *blockSet = new TPBlockSet(leftLeftEx, leftExObj, mainObject, rightExObj, NULL,
                                              "QuadLeft", mainObject->getCoordination().x, mainObject->getCoordination().y);
        toDestroyArray->addObject(blockSet);
        return true;
    }
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
    if (rightExObj->getID() == typeID && rightRightEx->getID() == typeID && leftExObj->getID() == typeID) {
        CCObject *object = colorArray->objectAtIndex(gidToIndex);
        TPObjectExtension *mainObject = dynamic_cast<TPObjectExtension*>(object);
        TPBlockSet *blockSet = new TPBlockSet(leftExObj, mainObject, rightExObj, rightRightEx, NULL,
                                              "QuadRight", mainObject->getCoordination().x, mainObject->getCoordination().y);
        toDestroyArray->addObject(blockSet);
        return true;
    }
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
    if (topExObj->getID() == typeID && topTopEx->getID() == typeID && bottomExObj->getID() == typeID) {
        CCObject *object = colorArray->objectAtIndex(gidToIndex);
        TPObjectExtension *mainObject = dynamic_cast<TPObjectExtension*>(object);
        TPBlockSet *blockSet = new TPBlockSet(topTopEx, topExObj, mainObject, bottomExObj, NULL,
                                              "QuadTop", mainObject->getCoordination().x, mainObject->getCoordination().y);
        toDestroyArray->addObject(blockSet);
        return true;
    }
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
    if (bottomExObj->getID() == typeID && bottomBottomEx->getID() == typeID && topExObj->getID() == typeID) {
        CCObject *object = colorArray->objectAtIndex(gidToIndex);
        TPObjectExtension *mainObject = dynamic_cast<TPObjectExtension*>(object);
        TPBlockSet *blockSet = new TPBlockSet(topExObj, mainObject, bottomExObj, bottomBottomEx, NULL,
                                              "QuadBottom", mainObject->getCoordination().x, mainObject->getCoordination().y);
        toDestroyArray->addObject(blockSet);
        return true;
    }
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
                                              "TrioHor", mainObject->getCoordination().x, mainObject->getCoordination().y);
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
    if (topExObj->getID() == typeID && bottomExObj->getID() == typeID) {
        CCObject *object = colorArray->objectAtIndex(gidToIndex);
        TPObjectExtension *mainObject = dynamic_cast<TPObjectExtension*>(object);
        TPBlockSet *blockSet = new TPBlockSet(topExObj, mainObject, bottomExObj, NULL, NULL,
                                              "TrioVer", mainObject->getCoordination().x, mainObject->getCoordination().y);
        toDestroyArray->addObject(blockSet);
        return true;
    }
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
        rightExObj->getID() == typeID && rightRightEx->getID() == typeID) {
        CCObject *object = colorArray->objectAtIndex(gidToIndex);
        TPObjectExtension *mainObject = dynamic_cast<TPObjectExtension*>(object);
        TPBlockSet *blockSet = new TPBlockSet(leftLeftEx, leftExObj, mainObject, rightExObj, rightRightEx,
                                              "PentaHor", mainObject->getCoordination().x, mainObject->getCoordination().y);
        toDestroyArray->addObject(blockSet);
        return true;
    }
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
        bottomExObj->getID() == typeID && bottomBottomEx->getID() == typeID) {
        CCObject *object = colorArray->objectAtIndex(gidToIndex);
        TPObjectExtension *mainObject = dynamic_cast<TPObjectExtension*>(object);
        TPBlockSet *blockSet = new TPBlockSet(topTopEx, topExObj, mainObject, bottomExObj, bottomBottomEx,
                                              "PentaVer", mainObject->getCoordination().x, mainObject->getCoordination().y);
        toDestroyArray->addObject(blockSet);
        return true;
    }
    return false;
}

CCArray *TakasuPoppo::matchList() {
    CCArray *match = new CCArray();
        for (int y = 0; y < 7; y++) {
            for (int x = 0; x < 5; x++) {
                CCPoint coor = ccp(x, y);
                int gid = layer->tileGIDAt(coor);
                int gidToIndex = gid - 1;
                CCObject *object = colorArray->objectAtIndex(gidToIndex);
                TPObjectExtension *exObj = dynamic_cast<TPObjectExtension*>(object);
                if (exObj->getCoordination().x == coor.x &&
                    exObj->getCoordination().y == coor.y) {
                    
                    if (TakasuPoppo::getMatchHor(exObj)->count() >= 2) {
                        
                        //match->addObjectsFromArray(TakasuPoppo::getMatchHor(exObj));
                        TPObjectExtension* cp1 = (TPObjectExtension*)getMatchHor(exObj)->objectAtIndex(0);
                        TPObjectExtension* cp2 = (TPObjectExtension*)getMatchHor(exObj)->objectAtIndex(1);
                        TPBlockSet *blockset = new TPBlockSet(exObj, cp1, cp2, NULL, NULL, "TrioRight", exObj->getCoordination().x , exObj->getCoordination().y);
                        if(TakasuPoppo::getMatchHor(exObj)->count() == 3)
                        {
                            TPObjectExtension* cp3 = (TPObjectExtension*)getMatchHor(exObj)->objectAtIndex(2);
                            blockset->setEx4(cp3);
                            blockset->setType("QuadRight");
                            if(TakasuPoppo::getMatchHor(exObj)->count() == 4)
                            {
                                TPObjectExtension* cp4 = (TPObjectExtension*)getMatchHor(exObj)->objectAtIndex(2);
                                blockset->setEx5(cp4);
                                blockset->setType("PentaHor");
                            }
                        }
                        match->addObject(blockset);
                        x += getMatchHor(exObj)->count();
                        CCLog("Hor Object on GID %i has match", exObj->getGid());
                    }
                }
            }
        }
        
        for (int x = 0; x < 7; x++) {
            for (int y = 0; y < 5; y++) {
                CCPoint coor = ccp(x, y);
                int gid = layer->tileGIDAt(coor);
                int gidToIndex = gid - 1;
                CCObject *object = colorArray->objectAtIndex(gidToIndex);
                TPObjectExtension *exObj = dynamic_cast<TPObjectExtension*>(object);
                if (exObj->getCoordination().x == coor.x &&
                    exObj->getCoordination().y == coor.y) {
                    if (TakasuPoppo::getMatchVer(exObj)->count() >= 2) {
                        //match->addObjectsFromArray(TakasuPoppo::getMatchVer(exObj));
                        
                        TPObjectExtension* cp1 = (TPObjectExtension*)getMatchVer(exObj)->objectAtIndex(0);
                        TPObjectExtension* cp2 = (TPObjectExtension*)getMatchVer(exObj)->objectAtIndex(1);
                        TPBlockSet *blockset = new TPBlockSet(exObj, cp1, cp2, NULL, NULL, "TrioTop", exObj->getCoordination().x , exObj->getCoordination().y);
                        if(TakasuPoppo::getMatchVer(exObj)->count() == 3)
                        {
                            TPObjectExtension* cp3 = (TPObjectExtension*)getMatchVer(exObj)->objectAtIndex(2);
                            blockset->setEx4(cp3);
                            blockset->setType("QuadTop");
                            if(TakasuPoppo::getMatchVer(exObj)->count() == 4)
                            {
                                TPObjectExtension* cp4 = (TPObjectExtension*)getMatchVer(exObj)->objectAtIndex(2);
                                blockset->setEx5(cp4);
                                blockset->setType("PentaVer");
                            }
                        }
                        match->addObject(blockset);

                        y += getMatchVer(exObj)->count();
                        CCLog("Ver Object on GID %i has match", exObj->getGid());
                    }
                }
            }
        }
    return match;
}

CCArray *TakasuPoppo::getMatchHor(TPObjectExtension *exObj) {
    CCArray *matches = new CCArray;
    int colNum= exObj->getCoordination().x;
    for (int ct = 1; colNum + ct < 7; ct++) {
        CCLOG("Colum .....%d",colNum);
        CCPoint coor = ccp(colNum + ct, exObj->getCoordination().y);
        int gid = layer->tileGIDAt(coor);
        int gidToIndex = gid-1;
        CCObject *object = colorArray->objectAtIndex(gidToIndex);
        TPObjectExtension *checkObj = dynamic_cast<TPObjectExtension*>(object);
        if (checkObj->getID() == exObj->getID()) {
            matches->addObject(checkObj);
            //CCLog("CheckObj Gid: %i, CID: %i ", checkObj->getGid(), checkObj->getID());
        }
        else return matches;
    }
    return matches;
}

CCArray *TakasuPoppo::getMatchVer(TPObjectExtension *exObj) {
    CCArray *matches = new CCArray;
    int rowNum= exObj->getCoordination().y;
    for (int ct = 1; rowNum + ct < 7; ct++) {
        CCPoint coor = ccp(exObj->getCoordination().x, rowNum + ct);
        int gid = layer->tileGIDAt(coor);
        int gidToIndex = gid - 1;
        CCObject *object = colorArray->objectAtIndex(gidToIndex);
        TPObjectExtension *checkObj = dynamic_cast<TPObjectExtension*>(object);
        if (checkObj->getCoordination().x == coor.x &&
            checkObj->getCoordination().y == coor.y &&
            checkObj->getID() == exObj->getID()) {
            matches->addObject(checkObj);
        }
        else return matches;
    }
    return matches;
}


/*
 |======================================|
 |        Grid Variables Mapping        |
 |======================================|
 |    |     -2  -1   0  +1  +2  +3      |
 |----|---------------------------------|
 | -3 |              j                  |
 | -2 |          y   h   i              |
 | -1 |      k   l   e   f   g          |
 |  0 |      m   n  [a]  b   c   d      |
 | +1 |          s   o   p   t          |
 | +2 |          x   q   r              |
 |======================================|
 */

void TakasuPoppo::lookForMatches() {
    int match = 0;
    for (int x = 0; x < 7; x++) {
        for (int y = 0; y < 7; y++) {
            CCPoint aPoint = ccp(x, y);
            CCPoint bPoint = ccp(x + 1, y);
            CCPoint cPoint = ccp(x + 2, y);
            CCPoint dPoint = ccp(x + 3, y);
            CCPoint ePoint = ccp(x, y - 1);
            CCPoint fPoint = ccp(x + 1, y - 1);
            CCPoint gPoint = ccp(x + 2, y - 1);
            CCPoint hPoint = ccp(x, y - 2);
            CCPoint iPoint = ccp(x + 1, y - 2);
            CCPoint jPoint = ccp(x, y - 3);
            CCPoint kPoint = ccp(x - 2, y - 1);
            CCPoint lPoint = ccp(x - 1, y - 1);
            CCPoint mPoint = ccp(x - 2, y);
            CCPoint nPoint = ccp(x - 1, y);
            CCPoint oPoint = ccp(x, y + 1);
            CCPoint pPoint = ccp(x + 1, y + 1);
            CCPoint qPoint = ccp(x, y + 2);
            CCPoint rPoint = ccp(x + 1, y + 2);
            CCPoint sPoint = ccp(x - 1, y + 1);
            CCPoint tPoint = ccp(x + 2, y + 1);
            CCPoint xPoint = ccp(x - 1, y + 2);
            CCPoint yPoint = ccp(x - 1, y - 2);
            
            TPObjectExtension *aExObj = TakasuPoppo::coorToExObj(aPoint);
            TPObjectExtension *bExObj = TakasuPoppo::coorToExObj(bPoint);
            TPObjectExtension *cExObj = TakasuPoppo::coorToExObj(cPoint);
            TPObjectExtension *dExObj = TakasuPoppo::coorToExObj(dPoint);
            TPObjectExtension *eExObj = TakasuPoppo::coorToExObj(ePoint);
            TPObjectExtension *fExObj = TakasuPoppo::coorToExObj(fPoint);
            TPObjectExtension *gExObj = TakasuPoppo::coorToExObj(gPoint);
            TPObjectExtension *hExObj = TakasuPoppo::coorToExObj(hPoint);
            TPObjectExtension *iExObj = TakasuPoppo::coorToExObj(iPoint);
            TPObjectExtension *jExObj = TakasuPoppo::coorToExObj(jPoint);
            TPObjectExtension *kExObj = TakasuPoppo::coorToExObj(kPoint);
            TPObjectExtension *lExObj = TakasuPoppo::coorToExObj(lPoint);
            TPObjectExtension *mExObj = TakasuPoppo::coorToExObj(mPoint);
            TPObjectExtension *nExObj = TakasuPoppo::coorToExObj(nPoint);
            TPObjectExtension *oExObj = TakasuPoppo::coorToExObj(oPoint);
            TPObjectExtension *pExObj = TakasuPoppo::coorToExObj(pPoint);
            TPObjectExtension *qExObj = TakasuPoppo::coorToExObj(qPoint);
            TPObjectExtension *rExObj = TakasuPoppo::coorToExObj(rPoint);
            TPObjectExtension *sExObj = TakasuPoppo::coorToExObj(sPoint);
            TPObjectExtension *tExObj = TakasuPoppo::coorToExObj(tPoint);
            TPObjectExtension *xExObj = TakasuPoppo::coorToExObj(xPoint);
            TPObjectExtension *yExObj = TakasuPoppo::coorToExObj(yPoint);
            
            if (bExObj != NULL && bExObj->getID() == aExObj->getID()) {
                if (TakasuPoppo::sumOfMatches(aExObj, bExObj, lExObj, sExObj, mExObj)) match++;
                if (TakasuPoppo::sumOfMatches(aExObj, bExObj, gExObj, tExObj, dExObj)) match++;
            }
            if (eExObj != NULL && eExObj->getID() == aExObj->getID()) {
                if (TakasuPoppo::sumOfMatches(aExObj, eExObj, iExObj, jExObj, yExObj)) match++;
                if (TakasuPoppo::sumOfMatches(aExObj, eExObj, pExObj, qExObj, sExObj))match++;
            }
            if (hExObj != NULL && hExObj->getID() == aExObj->getID()) {
                if (TakasuPoppo::sumOfMatches(aExObj, hExObj, dExObj, fExObj, NULL)) match++;
            }
            if (qExObj != NULL && qExObj->getID() == aExObj->getID()) {
               if (TakasuPoppo::sumOfMatches(aExObj, qExObj, pExObj, sExObj, NULL)) match++;
            }
            if (mExObj != NULL && mExObj->getID() == aExObj->getID()) {
                if (TakasuPoppo::sumOfMatches(aExObj, mExObj, dExObj, sExObj, NULL)) match++;
            }
            if (cExObj != NULL && cExObj->getID() == aExObj->getID()) {
                if (TakasuPoppo::sumOfMatches(aExObj, cExObj, fExObj, pExObj, NULL)) match++;
            }
        }
    }
    CCLog("There are %i possible matches", match);
}

bool TakasuPoppo::sumOfMatches(TPObjectExtension *exA, TPObjectExtension *exB,
                               TPObjectExtension *ex1, TPObjectExtension *ex2, TPObjectExtension *ex3) {

        if (ex1 != NULL && ex1->getID() == exA->getID()) {
            CCLog("Block on GID %i has possibility combo with GID %i and GID %i", exA->getGid(), exB->getGid(), ex1->getGid());
            return true;
        }
        if (ex2 != NULL && ex2->getID() == exA->getID()) {
            CCLog("Block on GID %i has possibility combo with GID %i and GID %i", exA->getGid(), exB->getGid(), ex2->getGid());
            return true;
        }
        if (ex3 != NULL && ex3->getID() == exA->getID()) {
            CCLog("Block on GID %i has possibility combo with GID %i and GID %i", exA->getGid(), exB->getGid(), ex3->getGid());
            return true;
        }
    
    return false;
}

TPObjectExtension *TakasuPoppo::coorToExObj(CCPoint coor) {
    if ((coor.x >= 0 && coor.x < 7) && (coor.y >= 0 && coor.y < 7)) {
        int gid = layer->tileGIDAt(coor);
        int gidToIndex = gid - 1;
        CCObject *object = colorArray->objectAtIndex(gidToIndex);
        TPObjectExtension *exObj = dynamic_cast<TPObjectExtension*>(object);
        return exObj;
    }
    return NULL;
}



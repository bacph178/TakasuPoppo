//
//  TPParticles.cpp
//  Cocos2Dx
//
//  Created by Ace on 2013/07/02.
//
//

#include "TakasuPoppo.h"

void TakasuPoppo::popParticles(CCPoint point) {
    //CCTexture2D *texture = CCTextureCache::sharedTextureCache()->textureForKey("Star.png");
    CCParticleSystemQuad *pop = new CCParticleSystemQuad;
    pop = CCParticleFireworks::create();
    pop->setTexture(CCTextureCache::sharedTextureCache()->addImage("Star.png"));
    pop->setPosition(point);
    pop->setGravity(CCPointZero);
    
    pop->setAngle(140);
    pop->setAngleVar(360);
    
    pop->setSpeed(80);
    //pop->setSpeedVar(360);
    
    pop->setStartSize(40);
    
    pop->setLife(0.1);
    pop->setPositionType(kCCPositionTypeRelative);
    
    pop->setRadialAccel(-50);
    //pop->setRadialAccelVar(-100);
    
    //pop->setTangentialAccel(-50);
    pop->setTotalParticles(9);
    //pop->setRotatePerSecond(0);
    pop->setAutoRemoveOnFinish(true);
    pop->setAtlasIndex(0);
    pop->setBlendAdditive(false);
    //pop->setOrderOfArrival(0);
    pop->setOpacityModifyRGB(false);
    pop->setDuration(0.5);
    pop->setEmissionRate(200);
    //pop->setEndRadius(50);
    this->addChild(pop, 5, 777);
}

void TakasuPoppo::remoteParticles() {
    this->removeChildByTag(777, true);
}

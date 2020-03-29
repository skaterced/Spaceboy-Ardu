#ifndef _CONTROLS_ 
#define _CONTROLS_ 

#include "globals.h"
#include "trigo.h"
#include "player.h"
#include "shot.h"

void controls(Player* p1){
  if (ab.pressed(RIGHT_BUTTON)){
    if (ab.everyXFrames(2)){
      if (++p1->dir>15)
        p1->dir=0;
    }
  }
  if (ab.pressed(LEFT_BUTTON)){
    if (ab.everyXFrames(2)){
      if (--p1->dir>127)
        p1->dir=15;
    }
  }
  if (ab.pressed(UP_BUTTON)){
    if (ab.everyXFrames(2)){
      p1->speed+=trigoVec(p1->dir,3,vec2(0,0));
      if (magn(p1->speed)>SPEED_MAX) {
        p1->speed-=trigoVec(p1->dir,3,vec2(0,0));
      }
    }
  }
  if (ab.justPressed(A_BUTTON)){    //another weapons allows to hold fire button
    if (0==p1->coolDown){ 
      for (int i=0;i<SHOTS_MAX;i++){        
        if (0==p1->shots[i].actif){          
          p1->shots[i].actif=SHOT_DURATION;
          p1->coolDown=COOLDOWN;
          p1->shots[i].pos=p1->pos+trigoVec(p1->dir,10,vec2(0,0));
          p1->shots[i].dir=p1->dir;
          p1->shots[i].speed=p1->speed+trigoVec(p1->dir,5,vec2(0,0));
          i=99;
        }
      }
    }
  }
}

#endif

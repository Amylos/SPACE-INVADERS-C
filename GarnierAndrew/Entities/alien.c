/**********************************************
 * File: alien.c
 *
 *  Created on: 12-01-2022
 *      Author: <author>
 *
 *********************************************/
#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "entity.h"
#include "alien.h"

/*************************GRAPHICS ALIENS****************************/

static t_graphic*pGraphic = NULL;

int AlienGraphicInit(char*rocketFileImageStr,SDL_Renderer*pRenderer){
	pGraphic= EntityGraphicInit( rocketFileImageStr,pRenderer);
	return(pGraphic == NULL);
}

int AlienGraphicRelease(void){
	EntityGraphicRelease(pGraphic);
	return 0;
}


struct s_alien{
	_ENTITY_COMMON_FIELDS_
};


/************************BEHAVIOR OF ALIENS***************************/

t_alien*AlienCreate(SDL_Rect frame, SDL_Point speed, SDL_Color color){
	/******************************************************
	 * ToDo: alien entity creation & initialization
	 * */

	t_alien *pAlien = (t_alien*)malloc(sizeof(t_alien));

	if(pAlien == NULL){
		printf("ALienCreate() MEMORY ALLOCATION FAILED");
		return NULL;
	}

	*pAlien = (t_alien){
		.m_frame = frame,
		.m_speed = speed,
		.m_color = color,
	};


	return pAlien;
}

t_alien*AlienDestroy(t_alien*pAlien){
	/******************************************************
	 * ToDo: alien entity destruction
	 * */
	EntityDestroy((t_entity*)pAlien);

	return NULL;
}

void AlienDraw(const t_alien*pAlien, SDL_Renderer*pRenderer){
	/******************************************************
	 * ToDo: alien entity drawing
	 * */

	EntityDraw((t_entity*)pAlien, pRenderer, pGraphic);
}

int  AlienMove(t_alien*pAlien, const SDL_Rect*pArea){
	/******************************************************
	 * ToDo: ship entity moving
	 * 		 return value must be adapted
	 * */

	int ySpeed = pAlien->m_speed.y;
	pAlien->m_speed.y = 0;
	t_collision col = EntityMove((t_entity*)pAlien, pArea);
	pAlien->m_speed.y = ySpeed;

	if(col == COLLISION_LEFT || col == COLLISION_RIGHT){
		pAlien->m_speed.x *=-1;
		pAlien->m_frame.y += pAlien->m_speed.y;
		if(pAlien->m_frame.y  >= pArea->y + pArea->h - pAlien->m_frame.h){
			return 1;
		}
		if(pAlien->m_speed.x <0){
			pAlien->m_speed.x += -2;
		}
		else{
			pAlien->m_speed.x += 2;
		}
		return 0;
	}

	return (col == COLLISION_BOT);

}








/*<$$$$$$$-BASE-$$$$$$$>*/



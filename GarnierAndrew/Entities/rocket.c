/**********************************************
 * File: rocket.c
 *
 *  Created on: 12/01/2022
 *      Author: <author>
 *
 *********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "entity.h"
#include "rocket.h"

/************************GRAPHICS ROCKETS***************************/

static t_graphic*pGraphic = NULL;

int RocketGraphicInit(char*rocketFileImageStr,SDL_Renderer*pRenderer){
	pGraphic= EntityGraphicInit( rocketFileImageStr,pRenderer);
	return(pGraphic == NULL);
}

int RocketGraphicRelease(void){
	EntityGraphicRelease(pGraphic);
	return 0;
}


/************************BEHAVIOR OF ROCKETS***************************/

struct s_rocket{
	_ENTITY_COMMON_FIELDS_
};

t_rocket*RocketCreate(SDL_Rect frame, SDL_Point speed, SDL_Color color){
	/******************************************************
	 * ToDo: rocket entity creation & initialization
	 * */

	t_rocket *pRocket = (t_rocket*)malloc(sizeof(t_rocket));

	if(pRocket == NULL){
			printf("RocketCreate() MEMORY ALLOCATION FAILED");
			return NULL;
		}

	*pRocket = (t_rocket){
		.m_frame = frame,
		.m_speed = speed,
		.m_color = color,
	};

	return pRocket;
}


t_rocket*RocketDestroy(t_rocket*pRocket){
	/******************************************************
	 * ToDo: rocket entity destruction
	 * */
	EntityDestroy((t_entity*)pRocket);

	return NULL;
}

void RocketDraw(const t_rocket*pRocket, SDL_Renderer*pRenderer){
	/******************************************************
	 * ToDo: rocket entity drawing
	 * */
	EntityDraw((t_entity*)pRocket, pRenderer, pGraphic);
}

int  RocketMove(t_rocket*pRocket, const SDL_Rect*pArea){
	/******************************************************
	 * ToDo: rocket entity moving
	 * 		 return value must be adapted
	 * */
	pRocket->m_frame.y += pRocket->m_speed.y;

	if(pRocket->m_frame.y<= pArea->y) return 1;

	return 0;
}

int RocketHit(const t_rocket*pRocket, const t_rocket*pOther){

		return  SDL_HasIntersection(&pRocket->m_frame, &pOther->m_frame);
}

/*<$$$$$$$-BASE-$$$$$$$>*/

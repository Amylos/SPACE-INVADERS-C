/**********************************************
 * File: ship.c
 *
 *  Created on: 12-01-2022
 *      Author: <author>
 *
 *********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "entity.h"
#include "ship.h"

/*************************GRAPHICS SHIP****************************/

static t_graphic*pGraphic = NULL;

int ShipGraphicInit(char*rocketFileImageStr,SDL_Renderer*pRenderer){
	pGraphic= EntityGraphicInit( rocketFileImageStr,pRenderer);
	return(pGraphic == NULL);
}

int ShipGraphicRelease(void){
	EntityGraphicRelease(pGraphic);
	return 0;
}

/************************BEHAVIOR OF SHIP***************************/

struct s_ship{
	_ENTITY_COMMON_FIELDS_
	int 	waiting;
};

t_ship*ShipCreate(SDL_Rect frame, SDL_Color color){
	/******************************************************
	 * ToDo: ship entity creation & initialization
	 * */


	t_ship*pShip = (t_ship*)EntityCreate(frame, (SDL_Point){0,0},color);
	pShip = (t_ship*)realloc(pShip,sizeof(t_ship));
	pShip->waiting = 1;

	return pShip;
}

t_ship*ShipDestroy(t_ship*pShip){
	/******************************************************
	 * ToDo: ship entity destruction
	 * */
	EntityDestroy((t_entity*)pShip);

	return NULL;
}

void ShipDraw(const t_ship*pShip, SDL_Renderer*pRenderer){
	/******************************************************
	 * ToDo: ship entity drawing
	 * */
	EntityDraw((t_entity*)pShip, pRenderer, pGraphic);
}

int ShipMoveToX(t_ship*pShip, int iToX, const SDL_Rect*pArea){
	/******************************************************
	 * ToDo: ship entity moving to iToX
	 * */

	pShip->m_frame.x = iToX - pShip->m_frame.w/2;

	if(pShip->m_frame.x <= pArea->x)	pShip->m_frame.x = pArea->x +1;
	if(pShip->m_frame.x >= pArea->x + pArea->w - pShip->m_frame.w)	pShip->m_frame.x = pArea->x + pArea->w - pShip->m_frame.w -1;
	return 0;
}

SDL_Point ShipHotPoint(const t_ship*pShip){
	return (SDL_Point){
		.x = pShip->m_frame.x+pShip->m_frame.w/2,
		.y = pShip->m_frame.y-2
	};
}

t_ship*ShipEngage(t_ship*pShip,SDL_Rect*pFrame){
	pShip->m_frame=*pFrame;
	return pShip;
}


int ShipHit(t_ship*pShip,t_entity*pEntityB){

	if(pShip->waiting){
		return 0;
	}
	return EntityHit((t_entity*)pShip,(t_entity*)pEntityB);
}


//t_ship*ShipSetWainting(t_ship*pShip, int waiting){
//	pShip->waiting = waiting;
//	return pShip;
//}
/*<$$$$$$$-BASE-$$$$$$$>*/

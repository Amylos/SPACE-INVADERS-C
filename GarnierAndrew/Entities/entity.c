/*
 * entity.c
 *
 *  Created on: 28 janv. 2022
 *      Author: Garnier
 */

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <assert.h>
#include "entity.h"

struct s_graphic{

	_ENTITY_COMMON_FIELDS_TEXTURE_

};

t_graphic*EntityGraphicInit(char*entityFileImageStr,SDL_Renderer*pRenderer){
	t_graphic *pGraphic = (t_graphic*)malloc(sizeof(t_graphic));
	assert(pGraphic);

	pGraphic->pImageSurface = IMG_Load(entityFileImageStr);
	if(pGraphic->pImageSurface == NULL){
		fprintf(stderr,"Failed to load image %s\n",SDL_GetError());
		return pGraphic;
	}
	pGraphic->pImageTexture = SDL_CreateTextureFromSurface(pRenderer,pGraphic->pImageSurface);
	return pGraphic;
}

t_graphic*EntityGraphicRelease(t_graphic*pGraphic){

	if(pGraphic->pImageTexture){
		SDL_DestroyTexture(pGraphic->pImageTexture);
		pGraphic->pImageTexture = NULL;
	}
	if(pGraphic->pImageSurface){
		SDL_FreeSurface(pGraphic->pImageSurface);
		pGraphic->pImageSurface = NULL;
	}
	free(pGraphic);

	return NULL;
}



 struct s_entity{
	 _ENTITY_COMMON_FIELDS_
 };

t_entity*EntityCreate(SDL_Rect frame, SDL_Point speed, SDL_Color color){

	t_entity *pEntity = (t_entity*)malloc(sizeof(t_entity));
	assert(pEntity);
	*pEntity = (t_entity){
		.m_frame = frame,
		.m_speed = speed,
		.m_color = color,
	};
	return pEntity;
}

t_entity*EntityDestroy(t_entity*pEntity){
	assert(pEntity);
	free(pEntity);
	return NULL;
}

void EntityDraw(const t_entity*pEntity, SDL_Renderer*pRenderer,t_graphic*pGraphic){
	assert(pEntity);
	//assert(pGraphic);

	if(pGraphic->pImageTexture){
		SDL_SetTextureBlendMode(pGraphic->pImageTexture, SDL_BLENDMODE_ADD);
		SDL_RenderCopy(pRenderer,pGraphic->pImageTexture, NULL, &pEntity->m_frame);
	}
	else{
		SDL_SetRenderDrawColor(pRenderer,pEntity->m_color.r, pEntity->m_color.g, pEntity->m_color.b, pEntity->m_color.a);
		SDL_RenderFillRect(pRenderer, &pEntity->m_frame);
	}
}


t_collision  EntityMove(t_entity*pEntity, const SDL_Rect*pArea){
	assert(pEntity);
	pEntity->m_frame.x += pEntity->m_speed.x;
	pEntity->m_frame.y += pEntity->m_speed.y;

	if(pEntity->m_frame.x <= pArea->x && pEntity->m_frame.y >= pArea->y *2){
		pEntity->m_frame.x=pArea->x;
		return COLLISION_LEFT;
	}

	if(pEntity->m_frame.x + pEntity->m_frame.w >= pArea->x + pArea->w){
		pEntity->m_frame.x = pArea->x + pArea->w - pEntity->m_frame.w;
		return COLLISION_RIGHT;
	}

	if(pEntity->m_frame.y <= pArea->y) return COLLISION_TOP;
	if(pEntity->m_frame.y  >= pArea->y + pArea->h - pEntity->m_frame.h-5){
		return COLLISION_BOT;
	}

	return COLLISION_NONE;
}


int EntityHit(t_entity*pEntityA,t_entity*pEntityB){

	 return SDL_HasIntersection(&pEntityA->m_frame,&pEntityB->m_frame);
}


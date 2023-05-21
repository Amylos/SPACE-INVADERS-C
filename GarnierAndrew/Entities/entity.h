/*
 * entity.h
 *
 *  Created on: 28 janv. 2022
 *      Author: Garnier
 */

typedef struct s_graphic t_graphic;

t_graphic*EntityGraphicInit(char*entityFileImageStr,SDL_Renderer*pRenderer);
t_graphic*EntityGraphicRelease(t_graphic*pGraphic);

typedef enum e_collision{
	COLLISION_NONE = 0,
	COLLISION_LEFT,
	COLLISION_RIGHT,
	COLLISION_TOP,
	COLLISION_BOT,
}t_collision;

#define	_ENTITY_COMMON_FIELDS_\
	SDL_Rect	m_frame;	\
	SDL_Point	m_speed;	\
	SDL_Color	m_color;

#define _ENTITY_COMMON_FIELDS_TEXTURE_\
	SDL_Surface*	pImageSurface; \
	SDL_Texture*	pImageTexture;

typedef struct s_entity t_entity;

t_entity*EntityCreate(SDL_Rect frame, SDL_Point speed, SDL_Color color);
t_entity*EntityDestroy(t_entity*pEntity);

void EntityDraw(const t_entity*pEntity, SDL_Renderer*pRenderer,t_graphic*pGraphic);
t_collision EntityMove(t_entity*pEntity, const SDL_Rect*pArea);


int EntityHit(t_entity*pEntityA,t_entity*pEntityB);

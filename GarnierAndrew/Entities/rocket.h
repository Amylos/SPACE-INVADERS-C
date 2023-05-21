/**********************************************
 * File: rocket.h
 *
 *  Created on: <2022-01-12>
 *      Author: <$$$$$$$-BASE-$$$$$$$>
 *
 *********************************************/

int RocketGraphicInit(char*rocketFileImageStr,SDL_Renderer*pRenderer);
int RocketGraphicRelease(void);


typedef struct s_rocket t_rocket;

t_rocket*RocketCreate(SDL_Rect frame, SDL_Point speed, SDL_Color color);
t_rocket*RocketDestroy(t_rocket*pRocket);
void RocketDraw(const t_rocket*pRocket, SDL_Renderer*pRenderer);
int  RocketMove(t_rocket*pRocket, const SDL_Rect*pArea);
int RocketHit(const t_rocket*pRocket, const t_rocket*pOther);

/*<$$$$$$$-BASE-$$$$$$$>*/

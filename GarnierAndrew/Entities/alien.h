/**********************************************
 * File: alien.h
 *
 *  Created on: <2022-01-12>
 *      Author: <$$$$$$$-BASE-$$$$$$$>
 *
 *********************************************/

int AlienGraphicInit(char*alienFileImageStr,SDL_Renderer*pRenderer);
int AlienGraphicRelease(void);

typedef struct s_alien t_alien;

t_alien*AlienCreate(SDL_Rect frame, SDL_Point speed, SDL_Color color);
t_alien*AlienDestroy(t_alien*pAlien);

void AlienDraw(const t_alien*pAlien, SDL_Renderer*pRenderer);
int  AlienMove(t_alien*pAlien, const SDL_Rect*pArea);



/*<$$$$$$$-BASE-$$$$$$$>*/

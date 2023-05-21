/**********************************************
 * File: ship.h
 *
 *  Created on: <2022-01-12>
 *      Author: <$$$$$$$-BASE-$$$$$$$>
 *
 *********************************************/

int ShipGraphicInit(char*shipFileImageStr,SDL_Renderer*pRenderer);
int ShipGraphicRelease(void);

typedef struct s_ship t_ship;

t_ship*ShipCreate(SDL_Rect frame, SDL_Color color);
t_ship*ShipDestroy(t_ship*pShip);
void ShipDraw(const t_ship*pShip, SDL_Renderer*pRenderer);
int ShipMoveToX(t_ship*pShip, int iToX, const SDL_Rect*pArea);
SDL_Point ShipHotPoint(const t_ship*pShip);
t_ship*ShipEngage(t_ship*pShip,SDL_Rect*pFrame);

int ShipHit(t_ship*pShip,t_entity*pEntityB);

//t_ship*ShipSetWainting(t_ship*pShip, int waiting);

/*<$$$$$$$-BASE-$$$$$$$>*/

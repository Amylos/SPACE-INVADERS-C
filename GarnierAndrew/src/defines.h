/**********************************************
 * File: defines.h
 *
 *  Created on: <2022-01-12>
 *      Author: <$$$$$$$-BASE-$$$$$$$>
 *
 *********************************************/

#define APP_WINDOW_TITLE				("Space Invaders")
#define APP_WINDOW_WIDTH				(1200)
#define APP_WINDOW_HEIGHT				(900)
#define APP_WINDOW_COLOR_BKGND			(SDL_Color){20,20,20,255}
#define APP_WINDOW_COLOR_DELIMITING		(SDL_Color){2,250,20,255}
#define APP_WINDOW_PADDING_TOP			(40)
#define APP_WINDOW_PADDING_BOT			(40)
#define APP_WINDOW_PADDING_HRZ			(20)

#define APP_ANIMATE_RATE				(30)

#define SHIP_IMAGE_FILE_STR				("./Resources/Images/spaceship.jpeg")
#define SHIP_SIZE						(60)
#define SHIP_COLOR						(SDL_Color){200,200,200,255}
#define SHIP_LIFE						(10)

#define ROCKET_WIDTH					(4)
#define ROCKET_HEIGHT					(30)
#define ROCKET_SPEED					(-15)
#define ROCKET_COLOR					(SDL_Color){240,20,20,255}

#define ALIEN_IMAGE_FILE_STR			("./Resources/Images/alien.jpeg")
#define ALIEN_SIZE						(60)
#define ALIEN_SPACING					(15)
#define ALIEN_SPEED						(SDL_Point){10, ALIEN_SIZE+ALIEN_SPACING*2}
#define ALIEN_COLOR						(SDL_Color){40,200,20,255}

#define ROCKETS_IMAGE_FILE_STR			("./Resources/Images/rocket.jpg")
#define APP_ROCKETS_NB_MAX				(10)
#define APP_ALIENS_NB_MAX				(50)

#define APP_WINDOW_IMAGE_FILE_STR		("./Resources/Images/galaxie.jpeg")

/*<$$$$$$$-BASE-$$$$$$$>*/

/*
 ============================================================================
 Name        : NomPrenon.c
 Author      : <author>
 Version     : <version>
 Copyright   : <copyright>
 Description : SpaceInvaders in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include "app.h"

int main(int argc, char*argv[]) {

	printf("======ENTER SpaceInvaders========\n");
	t_app*pTheApp=AppCreate();
	int ret=AppRun(pTheApp);
	pTheApp=AppDestroy(pTheApp);
	printf("======EXIT  SpaceInvaders========\n");
	return ret;
}

/*<$$$$$$$-BASE-$$$$$$$>*/

/***************************************************
 * File: app.h
 *
 *  Created on: <2022-01-12>
 *      Author: <$$$$$$$-BASE-$$$$$$$>
 *
 ***************************************************/
typedef struct s_app t_app;

t_app*AppCreate(void);
t_app*AppDestroy(t_app*pApp);
int AppRun(t_app*pApp);


/*<$$$$$$$-BASE-$$$$$$$>*/

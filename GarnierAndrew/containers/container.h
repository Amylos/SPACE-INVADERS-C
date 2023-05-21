/*
 * container.h
 *
 *  Created on: 6 janv. 2022
 *      Author: Garnier
 */


typedef	void*(*t_ptfV)(void*);
typedef	void*(*t_ptfVV)(void*,void*);
typedef	void*(*t_ptfVVV)(void*,void*,void*);

typedef struct s_container t_container;


t_container*ContainerNew(t_ptfV cpDeleteItemFunc);
t_container*ContainerDel(t_container *pContainer);


t_container*ContainerFlush(t_container*pContainer);

void*ContainerPushBack(t_container*pContainer, void*pItem);
void*ContainerPushFront(t_container*pContainer, void*pItem);
void*ContainerPushhAt(t_container*pContainer, void*pItem, size_t szAt);



void*ContainerParse(t_container*pContainer, t_ptfVV pParseFunc, void*pParam);
//void*ContainerParseTwo(t_container*pContainer, t_ptfVVV pParseFunc, void*pParam,void*pParamTwo);
void*ContainerParseDelIf(t_container* pContainer,t_ptfVV pParseFunc, void* pParam);

void*ContainerIntersectDelIf(t_container*pContainerA,t_container*pContainerB, t_ptfVV pIntersectFunc,t_ptfV ScoreFunc,void*pApp);


size_t ContainerCard(const t_container*pContainer);
void*ContainerGetBack(const t_container*pContainer);
void*ContainerGetFront(const t_container*pContainer);

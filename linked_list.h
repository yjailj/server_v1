#pragma once
/*
	FILE :linked_list.h

	链表宏定义头文件

*/

#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include "client_structs.h"
//#include "def.h"

/*
	数据插入链表（建立一个循环双向链表，list为头，item为尾）
*/
#define INSERT_TO_LIST(list,item,prev,next)\
if(!list)\
{\
	list = item;\
	list->prev = list->next = list;\
}\
else\
{\
	item->prev = list->prev;\
	item->next = list;\
	list->prev = item;\
	item->prev->next = item;\
}\



/*
	从链表中取数据
*/
#define REMOVE_FROM_LIST(list,item,prev,next)\
if (item == list)\
{\
	if(item == item->next)\
		list = NULL;\
	else\
		list = item->next;\
\
}\
\
if (list)\
{\
	item->prev->next = item->next;	\
	item->next->prev = item->prev;	\
}\

/*
	链表数据检索循环开始的宏定义
*/
#define LIST_WHILE(list,item,temp_d,next)\
if ((item = list))\
{\
	do {\
		temp_d = item->next;\

		/*
h			在这里将对被遍历的item进行定义的操作，之后在LIST_WHILEEND定义的内容将被清除

		*/

		/*
		链表数据检索循环结束的宏定义
		*/
#define LIST_WHILEEND(list,item,temp_d)\
		item = temp_d;\
	} while (list&&item&&(item!=list));\
}\

		/*
			跳过链表的宏定义
		*/
#define LIST_SKIP(item,temp_d)\
{\
item = temp_d;\
continue;\
}\


#endif // !__LINKED_LIST_H__

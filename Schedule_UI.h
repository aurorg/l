#ifndef SCHEDULE_UI_H_
#define SCHEDULE_UI_H_

#include "../Common/List.h"
#include "../Service/Schedule.h"
//#include "../Service/Play.h"

static const int SCHEDULE_PAGE_SIZE =5;

//安排演出界面
void Schedule_UI_MgtEntry(int play_id);

//添加新演出计划界面
int Schedule_UI_Add(int play_id);

//修改演出计划界面
int Schedule_UI_Modify(int id);

//删除演出计划界面
int Schedule_UI_Delete(int id);

#endif

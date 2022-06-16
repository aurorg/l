#include "Schedule.h"
#include "../Common/List.h"
#include "../Persistence/Schedule_Persist.h"
#include "Ticket.h"
#include <stdio.h>
#include "../Service/Sale.h"

//根据剧目ID获取演出计划
int Schedule_Srv_FetchByPlay(schedule_list_t list,int play_id)
{
	return Schedule_Perst_SelectByPlay(list,play_id); 

}

//添加新的演出计划
int Schedule_Srv_Add( schedule_t *data)
 {
	return Schedule_Perst_Insert(data);
}

//修改演出计划
int Schedule_Srv_Modify(const schedule_t *data)
 {
	return Schedule_Perst_Update(data);
}

//根据ID删除演出计划
 int Schedule_Srv_DeleteByID(int id)
{
	return Schedule_Perst_RemByID(id);
}

//安排演出票
//根据ID获取演出计划
int Schedule_Srv_FetchByID(int id,schedule_t *buf)
{
	return Schedule_Perst_SelectByID(id,buf);
}
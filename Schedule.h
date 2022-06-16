#ifndef SCHEDULE_H_
#define SCHEDULE_H_

#include "../Common/Common.h"

typedef struct{
    int hour;
    int minute;
    int second;
}ttms_time_t;

typedef struct{
    int year;
    int mouth;
    int day;
}ttms_data_t;

typedef struct{
    int id;//演出计划ID
    int play_id;//上映剧目ID
    int studio_id;//演出厅ID
    ttms_data_t date;//放映日期
    ttms_time_t time;//放映时间
    int seat_count;//座位数
}schedule_t;

typedef struct schedule_node{
    schedule_t data;//实体数据
    struct schedule_node *next;//后向指针
    struct schedule_node *prev;//前向指针
}schedule_node_t,*schedule_list_t;

//根据剧目ID获取演出计划
int Schedule_Srv_FetchByPlay(schedule_list_t list,int play_id);

//添加新的演出计划
int Schedule_Srv_Add( schedule_t *data);

//修改演出计划
int Schedule_Srv_Modify(const schedule_t *data);

//根据ID删除演出计划
int Schedule_Srv_DeleteByID(int id);

//根据ID获取演出计划
int Schedule_Srv_FetchByID(int id,schedule_t*buf);

#endif

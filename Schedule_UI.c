#include "Schedule_UI.h"
#include "../Common/List.h"
#include "../Service/Schedule.h"
#include "../Service/Play.h"
#include "../Service/Studio.h"
#include "../Service/Seat.h"
#include <stdio.h>
#include <stdlib.h>
#include "../Ticket_UI.h"


//安排演出界面
void Schedule_UI_MgtEntry(int play_id){
    int i,id;
    int choice;

    schedule_list_t head;
    schedule_node_t *pos;
    Pagination_t paging;



   //调用List_Init()函数初始化演出计划信息链表；
   //初始化分页参数paging 
    List_Init(head,schedule_node_t);
    paging.offset =0;
    paging.pageSize =SCHEDULE_PAGE_SIZE;//页数

    paging.totalRecords = Schedule_Srv_FetchAll(head);
    Paging_Locate_FirstPage(head,paging);
    do{
        printf(
				"\n==================================================================\n");
		printf(
				"************************** 演出计划信息 ************************\n");
		printf("%8s %8s  %8s  %8s    %8s      %8s\n", "演出计划ID", "上映剧目ID", "演出厅ID",
				"放映日期", "放映时间","座位数");
		printf(
				"------------------------------------------------------------------\n");
		
		Paging_ViewPage_ForEach(head, paging, schedule_node_t, pos, i){
			printf("%6d   %8d  %8d      %d-%d-%d    %d:%d:%d %8d \n", pos->data.id,
					pos->data.play_id, pos->data.studio_id, pos->data.date.year,
					pos->data.date.month,pos->data.date.day,pos->data.time.hour,
					pos->data.time.minute,pos->data.time.second,pos->data.seat_count);
		}

		printf(
				"--------------- 共:%2d页 ----------------------- 页数 :%2d/%2d -----\n",
				paging.totalRecords, Pageing_CurPage(paging),
				Pageing_TotalPages(paging));
		
        
        
        printf("\n\n\n\n"); 
        
        
        printf(
				"******************************************************************\n");
		printf(
				"[P]上一页         |   [N]下一页         |   [A]添加演出计划   |\n[D]删除演出计划   |   [U]修改演出计划   |   [T]生成演出票     |\n[0]返回上层       |");
		printf(
				"\n\n\n\n==================================================================\n");
        printf("请输入您要进行的操作:");
		fflush(stdin);
        setbuf(stdin,NULL);
		scanf("%c", &choice);
		setbuf(stdin,NULL);
		fflush(stdin);
    }

switch (choice) {
		case 'A':
		case 'a':
            system("clear");
			printf("请输入要生成的演出计划的剧目ID:");
			scanf("%d", &id);
			if (Schedule_UI_Add(id)) 
			{
				paging.totalRecords = Schedule_Srv_FetchAll(head);
				Paging_Locate_LastPage(head, paging, schedule_node_t);
			}
			break;

		case 'D':
		case 'd':
            system("clear");
			printf("请输入要删除的演出计划ID:");
			scanf("%d", &id);
			if (Schedule_UI_Delete(id)) {	
				paging.totalRecords = Schedule_Srv_FetchAll(head);
				List_Paging(head, paging, schedule_node_t);
			}
			break;
		case 'U':
		case 'u':
            system("clear");
			printf("请输入要修改的演出计划ID");
			scanf("%d", &id);
			if (Schedule_UI_Modify(id)) {	
				paging.totalRecords = Schedule_Srv_FetchAll(head);
				List_Paging(head, paging, schedule_node_t);
			}
			break;
		case 'T':
		case 't':
            system("clear");
			int id;
			printf("请选择要管理哪个演出计划的演出票(ID):");
			scanf("%d",&id);
			Ticket_UI_MgtEntry(id);
			break;
		case 'P':
		case 'p':
            system("clear");
			if (!Pageing_IsFirstPage(paging)) {
				Paging_Locate_OffsetPage(head, paging, -1, schedule_node_t);
			}
			break;
		case 'N':
		case 'n':
            system("clear");
			if (!Pageing_IsLastPage(paging)) {
				Paging_Locate_OffsetPage(head, paging, 1, schedule_node_t);
			}
			break;
		}
	} while (choice != 0);
	
	
    system("clear");
	List_Destroy(head, schedule_node_t);//链表销毁
}
 
//添加新演出计划界面
int Schedule_UI_Add(int play_id){

	play_t buf;
	if(!Play_Srv_FetchByID(play_id,&buf)){
		printf("该剧目不存在！\n");
		printf("按[ENTER]返回上一层\n");
		setbuf(stdin,NULL);
		getchar();
		return 0;
	}

     //初始化
	schedule_t rec;
	int newRecCount =0; 
	char choice;

	do {
		system("clear");
		printf("\n=======================================================\n");
		printf("****************  添加新演出计划  ****************\n");
		printf("-------------------------------------------------------\n");
		
		
		printf("剧目名字%s\n",buf.name);
		rec.play_id = play_id;//上映剧目ID
		printf("演出厅ID:");//判定演出厅是否存在
		setbuf(stdin,NULL);
		scanf("%d",&rec.studio_id);//输入演出厅ID
		studio_t buf;
	
		while( !Studio_Srv_FetchByID(rec.studio_id, &buf)  )
	{
		printf("该演出厅不存在!\n");
		printf("请重新输入演出厅ID:");
		setbuf(stdin,NULL);
		scanf("%d",&rec.studio_id);
	}


		printf("放映日期(年-月-日):");
		fflush(stdin);
		setbuf(stdin,NULL);
		scanf("%d-%d-%d",&rec.date.year,&rec.date.month,&rec.date.day);

		printf("放映时间(时-分-秒):");
		fflush(stdin);
		setbuf(stdin,NULL);
		scanf("%d-%d-%d",&rec.time.hour,&rec.time.minute,&rec.time.second);

		seat_list_t seat_list;
		List_Init(seat_list,seat_node_t);
		int stand_seatCount = Seat_Srv_FetchValidByRoomID(seat_list,buf.id);
		printf("座位数量(<=%d):",stand_seatCount);//判断座位数量
		fflush(stdin);
		setbuf(stdin,NULL);
		scanf("%d",&rec.seat_count);
 

		while( rec.seat_count > stand_seatCount )
	{
		printf("重新输入座位数量(<=%d):",stand_seatCount);
		setbuf(stdin,NULL);
		scanf("%d",&rec.seat_count);
	}
	
		printf("=======================================================\n");

		if (Schedule_Srv_Add(&rec)) {
			newRecCount += 1;
			printf("新演出计划添加成功!\n");

		} else
			printf("新演出计划添加失败!\n");

		printf("-------------------------------------------------------\n");
		printf("[A]继续添加, [R]返回上层:");
		fflush(stdin);

		while (getchar() != '\n');
		setbuf(stdin,NULL);
		scanf("%c", &choice);

	} while ('a' == choice || 'A' == choice);
	system("clear");
	return newRecCount;
}


//修改演出计划界面
int Schedule_UI_Modify(int id){
	
	//初始化
	int rtn = 0;
	schedule_t rec;
	schedule_list_t list;
	int seatcount;

	 
	if (!Schedule_Srv_FetchByID(id, &rec)) {
		printf("该演出计划不存在!\n按 [Enter] 返回上层!\n");
		setbuf(stdin,NULL);
		getchar();
		return 0;
	}
	else
	{
	printf("\n=======================================================\n");
	printf("****************  修改演出计划  ****************\n");
	printf("-------------------------------------------------------\n");

		printf("剧目ID:");
		setbuf(stdin,NULL);
		scanf("%d",&rec.play_id);
		play_t buf;
		while( !Play_Srv_FetchByID(rec.play_id,&buf ) )
		{
			printf("该剧目不存在!\n");
			printf("请重新输入剧目ID\n:",rec.play_id);
			setbuf(stdin,NULL);
			scanf("%d",&rec.play_id);
		}


		printf("演出厅ID:");
		setbuf(stdin,NULL);
		scanf("%d",&rec.studio_id);
		studio_t buf2;
		while( !Studio_Srv_FetchByID(rec.studio_id, &buf2)  )
	{
		printf("该演出厅不存在!\n");
		printf("请重新输入演出厅ID:");
		setbuf(stdin,NULL);
		scanf("%d",&rec.studio_id);
	}
		
		
		printf("放映日期(年-月-日):");
		fflush(stdin);
		setbuf(stdin,NULL);
		scanf("%d-%d-%d",&rec.date.year,&rec.date.month,&rec.date.day);

		printf("放映时间(时-分-秒):");
		fflush(stdin);
		setbuf(stdin,NULL);
		scanf("%d-%d-%d",&rec.time.hour,&rec.time.minute,&rec.time.second);

		seat_list_t seat_list;
		List_Init(seat_list,seat_node_t);
		int stand_seatCount = Seat_Srv_FetchValidByRoomID(seat_list,rec.studio_id);
		printf("座位数量(<=%d):",stand_seatCount);//判断
		fflush(stdin);
		setbuf(stdin,NULL);
		scanf("%d",&rec.seat_count);
		while( rec.seat_count > stand_seatCount )
	{
		printf("重新输入座位数量(<=%d):",stand_seatCount);
		setbuf(stdin,NULL);
		scanf("%d",&rec.seat_count);
	}

	
	printf("-------------------------------------------------------\n");

    //根据返回值判断修改剧目的信息是否成功了
	if (Schedule_Srv_Modify(&rec)) {
		rtn = 1;
		printf(
				"成功修改剧目信息!\n按下 [Enter] 返回上层!\n");
	} else
		printf("修改剧目信息失败!\nPress [Enter]返回上层!\n");

	setbuf(stdin,NULL);
	getchar();
}
	return rtn;//rtn实际上就是1或者非1，返回1就代表修改演出计划成功了
}



//删除演出计划界面
int Schedule_UI_Delete(int id){
	int rtn = 0;

	if (Schedule_Srv_DeleteByID(id)) {
		printf(
				"成功删除该演出计划!\n按下[Enter] 返回上层!\n");
		rtn = 1;
	} else {
		printf("该演出计划不存在!\n按下 [Enter] 返回上层!\n");
	}
	setbuf(stdin,NULL);
	getchar();
	system("clear");
	return rtn;//同上，返回1代表删除演出计划成功
 
}




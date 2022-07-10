#include "Ticket_UI.h"

#include "../Common/List.h"
#include "../Service/Ticket.h"
#include "../Service/Schedule.h"
#include "../Service/Play.h"
#include "../Service/Studio.h"

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
//生成演出票界面
void Ticket_UI_MgtEntry(int schedule_id)
 {	
	 schedule_t rec;
	 if (! Schedule_Srv_FetchByID(schedule_id,&rec)) {
		printf("该演出计划不存在!\n按 [Enter] 返回上层!\n");
		setbuf(stdin,NULL);
		getchar();
	 
	}
	play_t rec2; 
	if (!Play_Srv_FetchByID(rec.play_id, &rec2)) {
		printf("该剧目不存在!\n按 [Enter] 返回上层!\n");
		setbuf(stdin,NULL);
		getchar();
		 
	}
	
	
		printf(
				"\n==================================================================\n");
		printf(
				"*************************** 演出计划信息 ***************************\n");
		printf("%8s %8s  %8s  %8s  %8s %8s\n", "演出计划ID", "上映剧目ID", "演出厅ID",
				"放映日期", "放映时间","座位数");
		printf(
				"------------------------------------------------------------------\n");
		

			printf("%8d %8d  %8d  %d/%d/%d  %d/%d/%d %8d \n",rec.id ,
					rec.play_id, rec.studio_id, rec.date.year,
					rec.date.month,rec.date.day,rec.time.hour,
					rec.time.minute,rec.time.second,rec.seat_count);
        printf(
				"******************************************************************\n");
				printf(
				"\n==================================================================\n");
		printf(
				"********************** 剧目信息 **********************\n");
		printf("%5s %15s   %9s  %5s  %20s  %13s\n", "ID", "剧目名字", "出品地区",
				"时长", "开始->结束","票价");
		printf(
				"------------------------------------------------------------------\n");
			printf("%5d %10s  %8s  %5d  %d/%d/%d->%d/%d/%d  %5d\n", rec2.id,rec2.name,rec2.area,
			rec2.duration,rec2.start_date.year,rec2.start_date.month,rec2.start_date.day,rec2.end_date.year,
			rec2.end_date.month,rec2.end_date.day,rec2.price);
        printf(
				"******************************************************************\n");
		printf(
				"[A]生成演出票　　|　　[B]重新生成票 　　|　　 [0]返回上层\n");
		printf(
				"==================================================================\n");
		char choice;
		printf("请输入您要进行的操作:");
			setbuf(stdin,NULL);
			scanf("%c", &choice);
			switch(choice)
			{
				case 'A':
				case 'a':
					Ticket_Srv_GenBatch( rec.studio_id);
					break;
				case 'B':
				case 'b':
					printf("重新");
					Ticket_Srv_DeleteBatch(schedule_id);
					Ticket_Srv_GenBatch(rec.studio_id);
					break;
				case '0':
					break;
				default:
					printf("输入有误!\n");
					break;
			}
		printf("按[ENTER]返回上层");
		setbuf(stdin,NULL);
		getchar();
		system("clear");
}

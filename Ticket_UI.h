#ifndef TICKET_UI_H_
#define TICKET_UI_H_
#include "../Common/List.h"
#include "../Service/Ticket.h"
#include "../Service/Seat.h"
#include "../Service/Schedule.h"
#include "../View/Play_UI.h"

static const int TICKET_PAGE_SIZE=8;

void Ticket_UI_MgtEntry(int schedule_id);

#endif
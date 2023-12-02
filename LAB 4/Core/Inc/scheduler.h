/*
 * scheduler.h
 *
 *  Created on: Dec 6, 2022
 *      Author: USER
 */

#include "stdint.h"




#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_


 typedef struct {
void (* pTask ) ( void );
uint32_t Delay ;
uint32_t Period ;
uint8_t RunMe ;
uint32_t TaskID ;
} sTask ;


#define SCH_MAX_TASKS 50
#define NO_TASK_ID	0
#define TIME_CYCLE 10;
sTask SCH_tasks[SCH_MAX_TASKS];

void SCH_Init(void);
uint32_t SCH_Add_Task(void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD);
void SCH_Update(void);
void SCH_Dispatch_Task(void);
uint8_t SCH_Remove_Task(uint32_t TaskID);

#endif /* INC_SCHEDULER_H_ */

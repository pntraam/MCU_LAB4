/*
 * scheduler.c
 *
 *  Created on: Dec 6, 2022
 *      Author: USER
 */

#include"scheduler.h"


void SCH_Init(){
	unsigned int i;
	for(i = 0; i < SCH_MAX_TASKS; i++){
		SCH_Remove_Task(i);
	}
}

uint32_t SCH_Add_Task(void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD){
	unsigned char i = 0;
	while((SCH_tasks[i].pTask != 0) && (i < SCH_MAX_TASKS)){
		i++;
	}
	SCH_tasks[i].pTask = pFunction;
	SCH_tasks[i].Delay = DELAY/TIME_CYCLE;
	SCH_tasks[i].RunMe = 0;
	SCH_tasks[i].Period = PERIOD/TIME_CYCLE;
	SCH_tasks[i].TaskID = i;
	return SCH_tasks[i].TaskID;
}

void SCH_Update (void) {
	for (int i = 0; i < SCH_MAX_TASKS ; i++) {

		if (SCH_tasks[i].pTask) {
			if (SCH_tasks[i].Delay <= 0) {
				SCH_tasks[i].RunMe += 1;
				if (SCH_tasks[i].Period != 0) {
					SCH_tasks[i].Delay = SCH_tasks[i].Period;
				}
			}
			else {
				SCH_tasks[i].Delay--;
			}

		}
	}
}

void SCH_Dispatch_Task (void) {

	unsigned int i;
	for(i = 0; i < SCH_MAX_TASKS; i++){
		if(SCH_tasks[i].RunMe > 0){
			(*SCH_tasks[i].pTask)();
			SCH_tasks[i].RunMe--;
			if(SCH_tasks[i].Period == 0){
				SCH_Remove_Task(SCH_tasks[i].TaskID);
			}
		}
	}

}

uint8_t SCH_Remove_Task(uint32_t TaskID){
	if (TaskID >= SCH_MAX_TASKS) {
		return 0;
	}
	if(SCH_tasks[TaskID].pTask == 0){
		return 0;
	}
	SCH_tasks[TaskID].pTask = 0x0000;
	SCH_tasks[TaskID].Delay = 0;
	SCH_tasks[TaskID].RunMe = 0;
	SCH_tasks[TaskID].Period = 0;
	return 1;
}

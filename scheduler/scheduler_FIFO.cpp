/*
 * SchedulerSTRR.cpp
 *
 *  Created on: Sep 7, 2019
 *      Author: keith
 *
 *      implements FIFO scheduling algorithm
 *      not pre-emptive
 */

//TODO fill in content

#include "../includes/scheduler_FIFO.h"

bool Scheduler_FIFO::time_to_switch_processes(int tick_count, PCB &p) {
  sort();
  return Scheduler::time_to_switch_processes(tick_count, p);
}

void Scheduler_FIFO::sort() { }  // no sorting needed in FIFO

/*
 * scheduler.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */

//TODO fill in content
#include "../includes/scheduler.h"

void Scheduler::add(PCB p) {
  sort(); // SRTF sort
  ready_q->push(p);  // adds pcb to scheduler queue (memory)
}

PCB Scheduler::getNext() {
  PCB new_process;
  if (!(isEmpty())) { // if scheduler queue (memory) has processes to retrieve
    new_process = ready_q->front();
    ready_q->pop();
  }
  return new_process; // returns uninitialized process if none exists, if one does exists, pops process from queue (memory) and returns
}

bool Scheduler::isEmpty() {
  return ready_q->empty(); // uses queue function 'empty()' to determine if there are any processes currently in memory
}

bool Scheduler::time_to_switch_processes(int tick_count, PCB &p) {
  if (preemptive == true && ( (p.required_cpu_time - p.remaining_cpu_time) % time_slice == 0) ) { // Preemptive algorithm will be used and the current tick count is greater than allowed by time slice
    return true;
  }
  if (p.remaining_cpu_time <= 0) { // Remaining alloted CPU time left is zero
    return true;
  }
  return false;
}

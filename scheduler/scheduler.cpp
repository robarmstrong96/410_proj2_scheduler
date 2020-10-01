/*
 * scheduler.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */

//TODO fill in content
#include "../includes/scheduler.h"

void Scheduler::add(PCB p) {
  ready_q->push(p);
}

PCB Scheduler::getNext() {
  PCB new_process;
  if (!(isEmpty())) {
    new_process = ready_q->front();
    ready_q->pop();
  }
  return new_process;
}

bool Scheduler::isEmpty() {
  return ready_q->empty();
}

bool Scheduler::time_to_switch_processes(int tick_count, PCB &p) {
  if (p.remaining_cpu_time == 0) { // Remainging alloted CPU time left is zero
    return true;
  }
  else if (preemptive == true && (time_slice > tick_count)) { // Preemptive algorithm will be used and the current tick count is greater than allowed by time slice
    return true;
  }
  return false;
}

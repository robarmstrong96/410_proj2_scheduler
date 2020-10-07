/*
 * SchedulerSRTF.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 *
 *      implements shortest remaining time first scheduling algorithm
 *     pre-emptive
 */

//TODO fill in content

#include "../includes/scheduler_SRTF.h"
#include <algorithm>
#include <iostream>

bool comp(PCB a, PCB b); // custom function for sorting

bool Scheduler_SRTF::time_to_switch_processes(int tick_count, PCB &p) {
  sort();
  return Scheduler::time_to_switch_processes(tick_count, p);
}

void Scheduler_SRTF::sort() { // bad solution for sorting, but whatever works amirite (even though it doesn't seem to work)?
  std::vector<PCB> temp_queue;
  if (!ready_q->empty()) {
    while(!ready_q->empty()) {
      temp_queue.push_back(ready_q->front());
      ready_q->pop();
    }
    std::sort(temp_queue.begin(), temp_queue.end(), comp);
    for (int i = 0; i < temp_queue.size(); i++) {
      ready_q->push(temp_queue[i]);
    }
  }
}

bool comp(PCB a, PCB b) {
  return (a.remaining_cpu_time < b.remaining_cpu_time);
}

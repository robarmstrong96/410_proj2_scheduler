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
  if (preemptive == true && (time_slice > tick_count)) { // Preemptive algorithm will be used and the current tick count is greater than allowed by time slice
    return true;
  }
}

void Scheduler_SRTF::sort() { // bad solution for sorting, but whatever works amirite?
  std::vector<PCB> temp_queue;
  for (int i = 0; i < ready_q->size(); i++) {
    temp_queue.push_back(ready_q->front());
    ready_q->pop();
  }
  std::sort(temp_queue.begin(), temp_queue.end(), comp);
  std::cout << "Remaining Time: ";
  for (int i = 0; i < temp_queue.size(); i++) {
    if (!temp_queue.empty()) {
      std::cout << "[" << temp_queue[i].remaining_cpu_time << "] ";
    }
    ready_q->push(temp_queue[i]);
  }
  std::cout << std::endl;
}

bool comp(PCB a, PCB b) {
  std::cout << "Is " << a.remaining_cpu_time << " less than " << b.remaining_cpu_time << "?";
  if (a.remaining_cpu_time < b.remaining_cpu_time) {
    std::cout << " Yes!" << std::endl;
  }
  else {
    std::cout << " No." << std::endl;
  }
  return a.remaining_cpu_time < b.remaining_cpu_time;
}

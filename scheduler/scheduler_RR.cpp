/*
 * SchedulerSTRR.cpp
 *
 *  Created on: Sep 7, 2019
 *      Author: keith
 *
 *      implements round robin scheduling algorithm
 *      pre-emptive
 */

//TODO fill in content

#include "../includes/scheduler_RR.h"

bool Scheduler_RR::time_to_switch_processes(int tick_count, PCB &p) {
  if (tick_count > 0 ) {
    std::cout << "Tick Count: " << tick_count << " p.arrival_time: " << p.arrival_time << std::endl;
    if (preemptive == true && ( (tick_count - p.arrival_time) % time_slice == 0) ) { // Preemptive algorithm will be used and the current tick count is greater than allowed by time slice
      return true;
    }
  }
  if (p.remaining_cpu_time <= 0) { // Remainging alloted CPU time left is zero
    return true;
  }
  // Scheduler::time_to_switch_processes(tick_count, p);
}

void Scheduler_RR::sort() { }

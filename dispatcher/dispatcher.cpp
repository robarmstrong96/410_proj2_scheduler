/*
 * Dispatcher.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */

//TODO fill in content

#include "../includes/dispatcher.h"

PCB Dispatcher::get_from_CPU() {
  is_valid_job_on_cpu = false;
  return cpu->get_process_off_core(); // get_process_off_core returns current process or uninitialized process if no current process
}

void Dispatcher::put_on_CPU(PCB &process) {
  cpu->put_process_on_core(process);
  is_valid_job_on_cpu = true;
}

bool Dispatcher::isValidJobOnCPU() {
  return is_valid_job_on_cpu;
}

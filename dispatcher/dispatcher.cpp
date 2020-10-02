/*
 * Dispatcher.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */

//TODO fill in content

#include "../includes/dispatcher.h"

PCB Dispatcher::get_from_CPU() {
  is_valid_job_on_cpu = false; // no job on cpu anymore
  return cpu->get_process_off_core(); // get_process_off_core returns current process or uninitialized process if no current process
}

void Dispatcher::put_on_CPU(PCB &process) {
  is_valid_job_on_cpu = true; // job put on cpu, set to true
  cpu->put_process_on_core(process); // puts job on cpu
}

bool Dispatcher::isValidJobOnCPU() {
  std::cout << "valid? -> " << is_valid_job_on_cpu << " current_process status: " << cpu->get_COPY_of_Current_Process().isEmpty() << std::endl;
  return is_valid_job_on_cpu; // getter for is_valid_job_on_cpu dispatcher class variable
}

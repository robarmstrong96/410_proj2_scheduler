/*
 * Stats.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 */

//TODO fill in content

#include "../includes/stats.h"
#include <iostream>

void Stats::showAllProcessInfo() {
  std::vector<PCB>::iterator item;
  for (item = vec->begin(); item != vec->end(); item++) {
    std::cout << "Process " << item->process_number << "Required CPU time:" << item->required_cpu_time << " arrived:" << item->arrival_time << " started:" << item->start_time << " finished:" << item->finish_time << std::endl;
  }
}

float Stats::get_av_response_time() {
  return av_response_time;
}

float Stats::get_av_turnaround_time() {
  return av_turnaround_time;
}

float Stats::get_av_wait_time() {
  return av_wait_time;
}

void Stats::calcStats() {
    std::vector<PCB>::iterator item = vec->begin();

     // Add upp all corresponding values
     for (item = vec->begin(); item != vec->end(); item++) {
      av_wait_time += (item->finish_time - item->arrival_time - item->required_cpu_time);
      av_turnaround_time += (item->finish_time - item->arrival_time);
      av_response_time += (item->start_time - item->arrival_time);
    }

    // calculate average values
    av_wait_time = av_wait_time / vec->size();
    av_turnaround_time = av_turnaround_time / vec->size();
    av_response_time = av_response_time / vec->size();
}

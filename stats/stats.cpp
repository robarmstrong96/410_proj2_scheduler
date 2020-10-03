/*
 * Stats.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 */

//TODO fill in content

#include "../includes/stats.h"
#include <iostream>
#include <numeric>

Stats::Stats(std::vector<PCB> &finished_vector) {
  vec = &finished_vector;
  calcStats();
}

void Stats::showAllProcessInfo() {
  std::vector<PCB>::iterator item;
  for (item = vec->begin(); item != vec->end(); item++) {
    std::cout << "Process " << item->process_number << " Required CPU time:" << item->required_cpu_time << " arrived:" << item->arrival_time << " started:" << item->start_time << " finished:" << item->finish_time << std::endl;
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
    std::vector<float> response;
    std::vector<float> turnaround;
    std::vector<float> wait;

     // Add upp all corresponding values
     for (item = vec->begin(); item != vec->end(); item++) {
      response.push_back(item->start_time - item->arrival_time);
      turnaround.push_back(item->finish_time - item->arrival_time);
      wait.push_back(item->finish_time - item->arrival_time - item->required_cpu_time);
    }

    // calculate average values
    av_response_time = std::accumulate(wait.begin(), wait.end(), 0.0) / response.size();
    av_turnaround_time = std::accumulate(turnaround.begin(), turnaround.end(), 0.0) / turnaround.size();
    av_wait_time = std::accumulate(response.begin(), response.end(), 0.0) / wait.size();
}

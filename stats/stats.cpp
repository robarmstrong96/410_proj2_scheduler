/*
 * Stats.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 */

//TODO fill in content

void Stats::showAllProcessInfo() {
  vector<PCB>::iterator vec_it = vec->begin();
  for (item in vec_it) {
    c_out << "Process " << item.process_number << "Required CPU time:" << item.required_CPU_time << " arrived:" << item.arrival_time << " started:" << item.start_time << " finished:" << item.finish_time << endl;
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
    vector<PCB>::iterator vec_it = vec->begin();

     // Add upp all corresponding values
    for (item in vec_it) {
      av_wait_time += (item.finish_time - item.arrival_time - item.required_CPU_time);
      av_turnaround_time += (item.finish_time - item.arrival_time);
      av_response_time += (item.start_time - item.arrival_time);
    }

    // calculate average values
    av_wait_time = av_wait_time / vec.size();
    av_turnaround_time = av_turnaround_time / vec.size();
    av_response_time = av_response_time / vec.size();
}

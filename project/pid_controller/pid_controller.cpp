/**********************************************
 * Self-Driving Car Nano-degree - Udacity
 *  Created on: December 11, 2020
 *      Author: Mathilde Badoual
 **********************************************/

#include "pid_controller.h"
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

PID::PID() : p_error(0.0),
             i_error(0.0),
             d_error(0.0),
             prev_cte(0.0),
             is_initialized(false),
             Kp(0.0),
             Ki(0.0),
             Kd(0.0),
             output_lim_max(0.0),
             output_lim_min(0.0),
             delta_time(0.0) {}

PID::~PID() {}

void PID::Init(double Kpi, double Kii, double Kdi, double output_lim_maxi, double output_lim_mini) {
   /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   **/
   Kp = Kpi;
   Ki = Kii;
   Kd = Kdi;
   output_lim_max = output_lim_maxi;
   output_lim_min = output_lim_mini;
   p_error = 0.0;
   i_error = 0.0;
   d_error = 0.0;
   prev_cte = 0.0;
   delta_time = 0.0;
   is_initialized = false;
}


void PID::UpdateError(double cte) {
   /**
   * TODO: Update PID errors based on cte.
   **/
   p_error = cte;

   if (!is_initialized) {
      d_error = 0.0;
      prev_cte = cte;
      is_initialized = true;
   } else if (delta_time > 0.0) {
      d_error = (cte - prev_cte); // delta_time;
      prev_cte = cte;
   } else {
      d_error = 0.0;
      prev_cte = cte;
   }

   if (delta_time > 0.0) {
      i_error += cte; // * delta_time;
   }
}

double PID::TotalError() {
   /**
   * TODO: Calculate and return the total error
    * The code should return a value in the interval [output_lim_mini, output_lim_maxi]
   */
    double control = -(Kp * p_error + Ki * i_error + Kd * d_error);
    if (control > output_lim_max) {
        control = output_lim_max;
    } else if (control < output_lim_min) {
        control = output_lim_min;
    }
    return control;
}

double PID::UpdateDeltaTime(double new_delta_time) {
   /**
   * TODO: Update the delta time with new value
   */
   delta_time = new_delta_time;
   return delta_time;
}

/**
 * @file robot_motion_handler.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/robot_motion_handler.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
RobotMotionHandler::RobotMotionHandler() :
    heading_angle_(0),
  speed_(0),
  max_speed_(10) {
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

/*
 * Translate 4 arrow keys to appropriate command. The angle is changed
 * by delta 10 and is never negative or larger than 360. The speed is
 * incremented by 1 at each press.
 */

void RobotMotionHandler::AcceptCommand(enum event_commands cmd) {
  switch (cmd) {
    case COM_TURN_LEFT : {
      int new_angle = heading_angle_ - 10;
      if (new_angle < 0) {
       heading_angle_ = 360 + (new_angle);
     } else {
       heading_angle_ = new_angle;
     }
     break;
    }
    case COM_TURN_RIGHT : {
     int new_angle = heading_angle_ + 10;
     if (new_angle > 360) {
       heading_angle_ = new_angle - 360;
     } else {
       heading_angle_ = new_angle;
     }
     break;
    }
    case COM_SPEED_UP:
     if (speed_ < max_speed_) {
       speed_ = speed_ + 1;
     }
     break;
    case COM_SLOW_DOWN:
     if (speed_ > 0) {
       speed_ = speed_ - 1;
     }
     break;
   default:
    std::cerr << "FATAL: bad actuator command" << std::endl;
    assert(0);
  } /* switch() */
} /* accept_command() */

void RobotMotionHandler::UpdateVelocity(SensorTouch st) {
  if (st.activated()) {
    heading_angle_ = -st.angle_of_contact();
  }
}

NAMESPACE_END(csci3081);

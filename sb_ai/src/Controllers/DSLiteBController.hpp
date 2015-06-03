#pragma once

#include "ros/ros.h"
#include <string>
#include <iostream>
#include "sb_ai.h"
#include "sb_msgs/AISimMap.h"
#include "AI/dstarliteB/GridWorld.h"
#include <geometry_msgs/Twist.h>
#include "ControllerBase.hpp"

namespace dsliteB{
	class DSLiteBController: public ai::ControllerBase{
  
	private:
		int * map_ptr;
		int width; 
		int height;
		int start;
		int goal;
		geometry_msgs::Twist twist_msg;
		int next_movement;
		ros::Subscriber map_sub;
	  
	protected:
		geometry_msgs::Twist GetTwistMsg(int next_move);
	  
	public:
		DSLiteBController(ros::NodeHandle& nh);	  
		void MapCallback(const sb_msgs::AISimMap::ConstPtr& msg);
		geometry_msgs::Twist Update();
  };

}


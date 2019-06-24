#include "ros/ros.h"
#include "std_srvs/Trigger.h"
#include "geometry_msgs/PoseStamped.h"
#include "geometry_msgs/Twist.h"
#include "std_srvs/Empty.h"
#include <geometry_msgs/Twist.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <tf/tf.h>
#include <tf/transform_listener.h>
#include <stdlib.h>
#include <tf/transform_datatypes.h>

using namespace std;


vector<geometry_msgs::PoseStamped> getPoseFile(string FileName)
{
    


}


tf::StampedTransform getPose(string FileName, tf::TransformListener listener)
{
    tf::StampedTransform transform;
    try{ 
      listener.waitForTransform("odom","base_link",ros::Time(0),ros::Duration(3));
      listener.lookupTransform("odom", "base_link",
                               ros::Time(0), transform);  
    }
        catch (tf::TransformException &ex) {
            ROS_ERROR("%s",ex.what());  
    }
    return transform;
}


int main()
{

    



    return 0;
}
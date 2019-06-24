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


tf::StampedTransform getPose(tf::TransformListener listener)
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

geometry_msgs::Twist calculateTwist(tf::TransformListener listener, tf::StampedTransform ref_trans)
{
    tf::StampedTransform main_frame_trans = getPose(listener);
    tf::StampedTransform trans_diff = ref_trans.inverseTimes(main_frame_trans);

    return twist;
}


Angles convertQuternionToRollPitchYaw(const tf::StampedTransform &trans)
{
    Angles rollpitchyaw;

    tf::Quaternion q(trans.getRotation());
    tf::Matrix3x3 m(q);
    m.getRPY(rollpitchyaw.roll,rollpitchyaw.pitch,rollpitchyaw.yaw);
    
    return rollpitchyaw;
}



int main()
{

    



    return 0;
}
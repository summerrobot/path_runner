#include "path_runner.hpp"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "path_runner_node");
    ros::NodeHandle n;
    ros::Publisher cmd_vel_pub = n.advertise<geometry_msgs::Twist>("/teleop_joy/cmd_vel", 1000);
    tf::TransformListener listener;
    geometry_msgs::Twist twist{calculateTwist(listener)};
    cmd_vel_pub.publish(twist);
    ros::Rate loop_rate(10);



    ros::spinOnce();
    loop_rate.sleep();

    return 0;
}
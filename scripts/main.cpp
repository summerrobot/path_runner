#include "path_runner.hpp"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "path_runne_node");
    ros::NodeHandle n;
    ros::Publisher chatter_pub = n.advertise<geometry_msgs::Twist>("/teleop_joy/cmd_vel", 1000);
    ros::Rate loop_rate(10);
    
    // TODO make a publisher
    return 0;
}
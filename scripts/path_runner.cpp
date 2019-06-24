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

string INPUTFILENAME{"PostionLogger"};


struct Angles {
    double roll;
    double pitch;
    double yaw;
};


string getFilePath()
{
    const char* home = getenv("USER");

    if (!home)
    {
        std::cerr << "USER is not defined." << std::endl;
    }

    std::string USER_STRING = home;

    string filePath{"/home/" + USER_STRING +  "/Desktop/" + INPUTFILENAME + ".yaml"};

    return filePath;

}


vector<tf::StampedTransform> getPoseFileAndSetPosesIntoVector(string filePath)
{

    string line;
    vector<tf::StampedTransform> poses;
    

    ifstream inputfile{filePath};

    if(!inputfile)
    {
        std::cerr << "Error: cannot open file"<<std::endl;
    }

    // Read from file

    while(inputfile)
    {
        double x, y , z , yaw;
        Angles rollpitchyaw;

        tf::Vector3 position; 
        tf::StampedTransform pose;
        

        getline(inputfile,line);
        cout << line << endl;

        stringstream XYZYAW(line);

        XYZYAW>> x >> y >> z >> yaw;

        // Set position
        position.setX(x);
        position.setY(y);
        position.setZ(z);
        rollpitchyaw.yaw = yaw;

        pose.setOrigin(position);

        // set rotation
        tf::Quaternion orientation{convertRollPitchYawToQuartention(rollpitchyaw)};
        pose.setRotation(orientation);

        // Put into poses
        poses.push_back(pose);

    }

    return poses;

}

tf::Quaternion convertRollPitchYawToQuartention(const Angles &rollPitchYaw)
{
    tf::Quaternion posequartion;
    posequartion.setRPY(rollPitchYaw.roll, rollPitchYaw.pitch, rollPitchYaw.yaw);
    posequartion.normalize();
    return posequartion;
} 











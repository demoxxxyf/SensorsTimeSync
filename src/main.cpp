#include <ros/ros.h>
#include "subandpub.h"
 
int main(int argc, char **argv) {
    ros::init(argc, argv, "node");
    subscriberANDpublisher sp;
    ROS_INFO("main done! ");
    ros::spin();
}


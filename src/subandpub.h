#ifndef __SUBANDPUB_H__
#define __SUBANDPUB_H__
//ros头文件
#include <ros/ros.h>
//时间同步
#include <message_filters/subscriber.h>
#include <message_filters/sync_policies/approximate_time.h>
#include <message_filters/synchronizer.h>
//传感器消息
#include <sensor_msgs/Image.h>
#include <sensor_msgs/image_encodings.h>
#include <sensor_msgs/PointCloud2.h>
 
class subscriberANDpublisher{
public:
    subscriberANDpublisher();
    void callback(const sensor_msgs::ImageConstPtr &image, const sensor_msgs::PointCloud2ConstPtr &pointcloud);
 
private:
    ros::NodeHandle nh;
    ros::Publisher camera_pub;
    ros::Publisher lidar_pub;
    message_filters::Subscriber<sensor_msgs::PointCloud2> lidar_sub;//雷达订阅
    message_filters::Subscriber<sensor_msgs::Image> camera_sub;//相机订阅
 
    typedef message_filters::sync_policies::ApproximateTime<sensor_msgs::Image, sensor_msgs::PointCloud2> syncpolicy;//时间戳对齐规则
    typedef message_filters::Synchronizer<syncpolicy> Sync;
    boost::shared_ptr<Sync> sync_;//时间同步器
 
};
#endif


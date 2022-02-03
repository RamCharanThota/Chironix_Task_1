#include <ros/ros.h>
#include <geometry_msgs/Twist.h> 
#include <stdlib.h> 

double required_duration=10;

int main(int argc, char **argv)
{
  ros::init(argc, argv, "rotate_husky_clockwise");

  ros::NodeHandle nh;

  ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 1000);

  ros::Rate loop_rate(10);
  while (ros::ok())
  {
   geometry_msgs::Twist cmd_msg;
   cmd_msg.angular.z=0.5;
   /*pub.publish(cmd_msg);
     ros::spinOnce();
     loop_rate.sleep();*/
    ros::Time beginTime = ros::Time::now();
    ros::Time endTime =ros::Time::now(); 
    double duration =  ros::Duration(endTime-beginTime).toSec();
    while(duration < required_duration )
    {
        pub.publish(cmd_msg);
        ros::Duration(0.1).sleep();
        endTime =ros::Time::now();
        duration =  ros::Duration(endTime-beginTime).toSec(); 
       
    }

  return 0;
  }

}

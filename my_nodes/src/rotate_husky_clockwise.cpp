#include <ros/ros.h>
#include <geometry_msgs/Twist.h> 
#include <stdlib.h> 

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
   pub.publish(cmd_msg);
   ros::spinOnce();

    loop_rate.sleep();
  }


  return 0;
}

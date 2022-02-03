#include <ros/ros.h>
#include <geometry_msgs/Twist.h> 
#include <stdlib.h> 

double max_rotation_duration=10;

int main(int argc, char **argv)
{

  // initalising the ROS 
  ros::init(argc, argv, "rotate_husky_clockwise");
 // initialising the node handle to facilitate the communication with master
  ros::NodeHandle nh;
  // informing the master that this node publish to /cmd_vel topic 
  ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 1000);
  
 // run until, node is killed
  while (ros::ok())
  {
   // declaring the geometry message
   geometry_msgs::Twist cmd_msg;
   // command message to rotate robot cloclwise
   cmd_msg.angular.z=-0.5;
   // variables to check the rotation duration
   ros::Time begin_time = ros::Time::now();
   ros::Time end_time =ros::Time::now(); 
   double duration =  ros::Duration(end_time-begin_time).toSec();
   // loop rate 10 hz
    ros::Rate loop_rate(10);
   //rotate the robot till time reaches max rotation duration
    while(duration < max_rotation_duration )
    {   
        // publish the command msg on cmd_vel topic
        pub.publish(cmd_msg);
        // pause the node to maintain require loop rate
        loop_rate.sleep();
        end_time =ros::Time::now();
        duration =  ros::Duration(end_time-begin_time).toSec();
        ROS_INFO("Robot is rotating clock-wise,Time Lapsed: [%f]", duration) ;
       
    }
  ROS_INFO("Stopping the Robot as max rotation duration is completed ..");

  return 0;
  }

}

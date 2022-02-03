#! /usr/bin/env python

import rospy
from geometry_msgs.msg import Twist

# initalising the ROS
rospy.init_node('rotate_husky_anti_clockwise')

# informing the master that this node publish to /cmd_vel topic
pub = rospy.Publisher('/cmd_vel', Twist, queue_size=1)

max_rotation_duration = 10


# declaring the geometry twist message
cmd_msg = Twist()
# command message to rotate robot anti cloclwise
cmd_msg.angular.z = 1

# variables to check the rotation duration
start_time = rospy.get_time()
end_time = rospy.get_time()
duration = end_time - start_time

loop_rate = rospy.Rate(20)
                   # rotate the robot till time reaches max rotation duration
while duration < max_rotation_duration:
  pub.publish(cmd_msg)
  loop_rate.sleep()
  end_time = rospy.get_time()
  duration = end_time - start_time
  print("Robot is rotating anti clock-wise,Time Lapsed:", duration)
  
print("Stopping the Robot as rotation duration is completed ..")
                  
                      
                   

    

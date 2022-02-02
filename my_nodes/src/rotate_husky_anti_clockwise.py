#! /usr/bin/env python

import rospy
from geometry_msgs.msg import Twist

rospy.init_node('rotate_husky_anti_clockwise')

pub= rospy.Publisher('/cmd_vel',Twist,queue_size=1)

loop_rate=rospy.Rate(10)

cmd_msg=Twist()
cmd_msg.angular.z=0.5

while not rospy.is_shutdown():
                   pub.publish(cmd_msg)
                   loop_rate.sleep()
    

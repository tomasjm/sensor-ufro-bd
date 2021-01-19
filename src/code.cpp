
//INCLUDE
#include <ros/ros.h>
#include <sensor_msgs>
//CODE
using namespace dji_osdk_ros;

sensor_msgs::BatteryState battery_state_;


void batteryStateSubCallback(const sensor_msgs::BatteryState::ConstPtr& batteryState)
{
  battery_state_ = *batteryState;
}



ros::Subscriber batteryStateSub;

int main(int argc ,char** argv)
{
  ros::init(argc, argv, "telemetry_node");
  ros::NodeHandle nh;
  batteryStateSub  = nh.subscribe("dji_osdk_ros/battery_state", 10, &batteryStateSubCallback);

  ros::Duration(1).sleep();
  ros::AsyncSpinner spinner(4);
  spinner.start();

  int elapsedTimeInS = 0;
  int timeToPrintInS = 30;

  while (elapsedTimeInS < timeToPrintInS)
  {
    std::cout << "Counter = " << elapsedTimeInS << ":\n";
    std::cout << "-------\n";

    ROS_INFO("battery Info :");
    ROS_INFO("battery's capacity: %f", battery_state_.capacity);
    ROS_INFO("battery's voltage: %f", battery_state_.voltage);
    ROS_INFO("battery's current: %f", battery_state_.current);
    ROS_INFO("battery's percentage : %f\n", battery_state_.percentage);
    std::cout << "-------\n\n";
    ros::Duration(1).sleep();
    elapsedTimeInS += 1;
  }

  std::cout << "Done printing!\n";
  
  ROS_INFO_STREAM("Finished. Press CTRL-C to terminate the node");
  ros::waitForShutdown();

  return 0;
}

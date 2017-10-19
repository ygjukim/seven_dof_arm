#include <ros/ros.h>

#include <moveit/move_group_interface/move_group.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>

int main(int argc, char** argv)
{
	ros::init(argc, argv, "remove_collision_objects");
	ros::NodeHandle nh_;

	ros::AsyncSpinner spinner(1);
	spinner.start();

	moveit::planning_interface::PlanningSceneInterface current_scene;

	sleep(5.0);

	std::vector<std::string> objectIDs;
	objectIDs.push_back("cylinder1");

	current_scene.removeCollisionObjects(objectIDs);

	ros::shutdown();

	return 0;
}
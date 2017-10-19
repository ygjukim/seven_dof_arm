#include <ros/ros.h>

#include <moveit/move_group_interface/move_group.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>

int main(int argc, char** argv)
{
	ros::init(argc, argv, "create_collision_objects");
	ros::NodeHandle nh_;

	ros::AsyncSpinner spinner(1);
	spinner.start();

	moveit::planning_interface::PlanningSceneInterface current_scene;

	sleep(3.0);

	moveit_msgs::CollisionObject cylinder;
	cylinder.id = "cylinder1";

	shape_msgs::SolidPrimitive primitive;
	primitive.type = primitive.CYLINDER;
	primitive.dimensions.resize(3);
	primitive.dimensions[0] = 0.6;		// height
	primitive.dimensions[1] = 0.2;		// radius

	geometry_msgs::Pose pose;
	pose.orientation.w = 1.0;
	pose.position.x = 0.0;
	pose.position.y = -0.4;
	pose.position.z = 0.4;

	cylinder.primitives.push_back(primitive);
	cylinder.primitive_poses.push_back(pose);
	cylinder.operation = cylinder.ADD;

	std::vector<moveit_msgs::CollisionObject> collisionObjects;
	collisionObjects.push_back(cylinder);

	current_scene.addCollisionObjects(collisionObjects);

	ros::shutdown();

	return 0;
}
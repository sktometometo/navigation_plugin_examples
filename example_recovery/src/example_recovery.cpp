#include <example_recovery/example_recovery.h>
#include <pluginlib/class_list_macros.h>
#include <nav_core/parameter_magic.h>

PLUGINLIB_EXPORT_CLASS(example_recovery::ExampleRecovery, nav_core::RecoveryBehavior)

namespace example_recovery
{
ExampleRecovery::ExampleRecovery(): initialized_(false)
{
}

void ExampleRecovery::initialize(
            std::string name,
            tf2_ros::Buffer*,
            costmap_2d::Costmap2DROS* global_costmap,
            costmap_2d::Costmap2DROS* local_costmap)
{
    if (not initialized_) {
        ros::NodeHandle private_nh("~/" + name);
        initialized_ = true;
    } else {
        ROS_ERROR("You should not call initialize twice on this object, doing nothing");
    }
}

ExampleRecovery::~ExampleRecovery()
{
}

void ExampleRecovery::runBehavior()
{
  if (not initialized_)
  {
    ROS_ERROR("This object must be initialized before runBehavior is called");
    return;
  }
}

};

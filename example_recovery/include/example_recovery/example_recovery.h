#ifndef EXAMPLE_RECOVERY_H
#define EXAMPLE_RECOVERY_H
#include <nav_core/recovery_behavior.h>
#include <costmap_2d/costmap_2d_ros.h>
#include <tf2_ros/buffer.h>

namespace example_recovery
{

class ExampleRecovery : public nav_core::RecoveryBehavior
{
public:
    ExampleRecovery();
    ~ExampleRecovery();

    void initialize(
            std::string name,
            tf2_ros::Buffer*,
            costmap_2d::Costmap2DROS* global_costmap,
            costmap_2d::Costmap2DROS* local_costmap);
    void runBehavior();

private:
    bool initialized_;
};
};

#endif

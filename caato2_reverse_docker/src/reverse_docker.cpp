#include "caato2_reverse_docker/reverse_docker.h"

ReverseDockAction::ReverseDockAction(std::string name) : as_(nh_, name, false), action_name_(name)
  {
    as_.registerGoalCallback(boost::bind(&ReverseDockAction::goalCB, this));
    as_.registerPreemptCallback(boost::bind(&ReverseDockAction::preemptCB, this));
    reverse_goal_server = nh_.advertiseService("caato2_reverse_goal", &ReverseDockAction::reverseGoalCB, this);
    pose_subscriber = nh_.subscribe("amcl_pose", 100, &ReverseDockAction::poseSubscriberCB, this);
    feedback_.executing = false;
    result_.success = false;
    as_.start();
  }

  ReverseDockAction::~ReverseDockAction(void)
  {
  }

  void ReverseDockAction::executeCB(const caato2_reverse_docker::ReverseDockActionConstPtr& goal)
  {
  }

  void ReverseDockAction::goalCB()
  {
    goal_pose = geometry_msgs::Pose{};
    goal_pose = as_.acceptNewGoal()->goal_pose;
  }

  void ReverseDockAction::preemptCB()
  {
    ROS_INFO("%s: Preempted", action_name_.c_str());
    as_.setPreempted();
  }

  bool ReverseDockAction::reverseGoalCB(caato2_stm::navigate_goal::Request& req, caato2_stm::navigate_goal::Response& res)
  {
    goal_pose = req.nav_goal;

    if (as_.isActive())
    {
      feedback_.executing = true;
      as_.publishFeedback(feedback_);
      return true;
    }

    return false;
  }

  void ReverseDockAction::reverseGoalExecutor()
  {
    if (!feedback_.executing)
    {
      return;
    }

    while (!result_.success)
    {
        ros::spinOnce();
    }
  }

  void ReverseDockAction::poseSubscriberCB(const geometry_msgs::PoseWithCovarianceStamped& msg)
  {
    current_pose = msg.pose.pose;
  }
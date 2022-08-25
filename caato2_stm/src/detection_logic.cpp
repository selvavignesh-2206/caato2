
void getAvgPositionAngle (const aprilTags_ros::AprilTagDetectionArray& msg) {

    if (start_avg) {
        apriltags_ros::AprilTagDetection detection;
        int size = msg.detections.size();

        if (size != 1) {
            ROS_ERROR("More than one apriltag is detected");
        } else {
            aprilTags_ros::AprilTagDetection detect = msg.detections[0];
            geometry_msgs::PoseStamped pose = detect.pose;
            geometry_msgs::Pose p = pose.pose;
            geometry_msgs::Point point = p.position;

            float x = point.x;
            float y = point.y;
            float z = point.z;

            tf2::Quaternion opticalTagQuad = p.orientation;
            tf2::Vector3 *optical_tag_ origin = new  tf::Vector3 (tfScaler(x), tfScaler(y), tfScaler(z));
            tf2::Transform *optical_tag = new tf::Transform(*optical_tag_quad, *optical_tag_origin);
            tf::Tansform tag_cam = optical_tag->inverse() 
            tf::Transform tag_base = tag_cam * 
            tf::Transform base_tag = tag_base.inverse();

            float x2 = base_tag.getOrigin().x();
            float y2 = base_tag.getOrigin().y();
            float z2 = base_tag.getOrigin().y();
            float yaw = tf::getYaw (base_tag.getRoatiion();
            float yy =
        }
    }
}
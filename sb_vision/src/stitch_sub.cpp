#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>

const static std::string CV_WINDOW = "StitcherSub";

void imageCallback(const sensor_msgs::ImageConstPtr& msg){
	try{
		ROS_INFO("Got something..");		
		cv::imshow(CV_WINDOW, cv_bridge::toCvShare(msg, "bgr8")->image);
		//if(cv::waitKey(30) == 27){
			
		//}
	}catch (cv_bridge::Exception& e){
		ROS_ERROR("Could not convert from '%s' to 'bgr8'.", msg->encoding.c_str());
	}
}

int main(int argc, char **argv){
	ros::init(argc, argv, "image_listener");
	ros::NodeHandle nh;

	cv::namedWindow(CV_WINDOW);
	//cv::startWindowThread();
	image_transport::ImageTransport it(nh);
	image_transport::Subscriber sub = it.subscribe("stitcher", 1, imageCallback);
	
	ros::spin();
	cv::destroyWindow(CV_WINDOW);
	return 0;
}
cmake_minimum_required(VERSION 2.8)
project( Pylon_Detector )
find_package( OpenCV REQUIRED )
add_executable( Pylon_Detector Pylon_Detector.cpp )
target_link_libraries( Pylon_Detector ${OpenCV_LIBS} )

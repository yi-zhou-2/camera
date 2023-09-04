#ifndef __HK_CAMERA_H_
#define __HK_CAMERA_H_
#include<opencv2\opencv.hpp>
#include<string>
#include"system.h"
using namespace std;

void __run(cv::VideoCapture*, cv::VideoWriter*, unsigned int);
int HaiK_camera(string filename , Param*);

#endif
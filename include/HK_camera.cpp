#include<opencv2\opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<string>
#include "HK_camera.h"
#include"system.h"
using namespace std;


void __run(cv::VideoCapture* cap, cv::VideoWriter* videoWriter,unsigned int time)
{
	cv::Mat frame;
	bool ret;
	unsigned int figure_cout = 0;
	while (true)
	{
		ret = (*cap).read(frame);
		if (ret)
		{
			figure_cout += 1;
			cv::imshow("input", frame);
			(*videoWriter).write(frame);
			if (cv::waitKey(1) == 'q')
			{
				break;
			}
			if (figure_cout >= time)
				break;
		}
	}
}
int HaiK_camera(string filename, Param*para)
{
	//编码格式
	//string save = para->get_filepath() + filename;
	int time = para->get_fps() * para->get_time();
	int fourcc = cv::VideoWriter::fourcc(para->get_video_code(0), para->get_video_code(1), para->get_video_code(2), para->get_video_code(3));
	
	cv::VideoWriter videoWriter(filename, fourcc, para->get_fps(), cv::Size(para->get_frame_size(0), para->get_frame_size(1)));
	//capture对象
	cv::VideoCapture cap(para->get_camera());
	
	if (!cap.isOpened())
	{
		std::cerr << "无法打开摄像头！" << std::endl;
		return -1;
	}
	cout << filename << endl;
	__run(&cap, &videoWriter, time);

	// 释放摄像头资源
	cap.release();
	// 关闭VideoWriter对象
	videoWriter.release();
	// 关闭OpenCV窗口
	cv::destroyAllWindows();
	return 0;
}





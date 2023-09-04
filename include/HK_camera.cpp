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
	//�����ʽ
	//string save = para->get_filepath() + filename;
	int time = para->get_fps() * para->get_time();
	int fourcc = cv::VideoWriter::fourcc(para->get_video_code(0), para->get_video_code(1), para->get_video_code(2), para->get_video_code(3));
	
	cv::VideoWriter videoWriter(filename, fourcc, para->get_fps(), cv::Size(para->get_frame_size(0), para->get_frame_size(1)));
	//capture����
	cv::VideoCapture cap(para->get_camera());
	
	if (!cap.isOpened())
	{
		std::cerr << "�޷�������ͷ��" << std::endl;
		return -1;
	}
	cout << filename << endl;
	__run(&cap, &videoWriter, time);

	// �ͷ�����ͷ��Դ
	cap.release();
	// �ر�VideoWriter����
	videoWriter.release();
	// �ر�OpenCV����
	cv::destroyAllWindows();
	return 0;
}





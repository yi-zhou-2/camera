#include<opencv2\opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<iostream>
#include "HK_camera.h"
#include "file_name.h"
#include "system.h"

using namespace std;
/*
void capture_video(Param* para)
{

	string file_save = get_file_name(para);
	HaiK_camera(file_save, para);
}
void pa(Param*aa)
{
	
	aa->set_camera("rtsp://admin:adma8211@192.168.1.64:554/Streaming/Channels/101");
	aa->set_fps(25);
	aa->set_frame_size(0, 1280);
	aa->set_frame_size(1, 720);
	aa->set_code("MPEG-4", ".avi");
	aa->set_filename("default");
	aa->set_filepath("./vides/");
	aa->print_parameter();
}
void print_(Param* aa) {
	cout << aa->get_camera() << endl;
	cout << aa->get_fps() << endl;
	cout << aa->get_frame_size(0) << endl;
	cout << aa->get_frame_size(1) << endl;
	cout << aa->get_code() << endl;
	cout << aa->get_type() << endl;
	cout << aa->get_filename() << endl;
	cout << aa->get_filepath() << endl;
}*/
const string chineseTXT[10][5] = { {"主菜单","开始录制视频","参数查看","修改参数","退出系统"},
	{"修改参数","修改配置文件路径","导入配置文件","返回"}


};
void menu(const string*chinese,int index)
{
	cout << "\n		欢迎进入小黑框监控视频数据集采集系统" << endl;
	cout << "\n*******************************************************************" << endl;
	cout << "	--"<<chinese[0]<<"--" << endl;
	for (int i = 1; i <= index; i++)
	{
		cout << "		["<<i<<"]--" << chinese[i] << endl;
	}
	cout << "*******************************************************************" << endl;
}

void opareter_1(int index) {
	cout << "请输入操作数[";
	for (int i = 1; i < index; i++)
		cout << i << ',';
	cout << index << "]:";
}
int get_num(int x, int index)
{
	menu(chineseTXT[x],index);
	for (int i = 0; i < 20;i++) {
		int temp;
		opareter_1(index);
		cin >> temp;
		if ((temp <= index) && (temp > 0))
			return temp;
		else
			cout << "ERROR:Out of data option " << endl;
	}
	return -1;
}
void submenu(Param&para) {
	while (true) {
		int menu_num_1 = get_num(1, 3);
		if (menu_num_1 == 1) {
			string config;
			string option;
			cout << "当前配置文件为:" << para.get_config() << endl;
			cout << "请输入完整的配置文件路径:";
			cin >> config;
			cout << para.get_config() << "将被" << config << "替换，是否继续执行此操作（y or n）？" << endl;
			cin >> option;
			if (option == "y") {
				para.set_config(config);
			}
		}
		if (menu_num_1 == 2) {
			read_config(&para);
			cout << "\n-----------------------------------------------------------" << endl;
			para.print_parameter();
			cout << "\n-----------------------------------------------------------" << endl;
		}
		if ((menu_num_1 == 3) ||(menu_num_1==-1)) {
			break;
		}
	}
	
}
int main_ss() {
	Param aa;
	
	read_config(&aa);
	int menu_num = 0;
	bool flag = true;
	
	for (int i=0; flag; i++)
	{
		menu_num = get_num(0, 4);
		if (menu_num == 1) {
			menu_num = 0;
			cout << "\n-----------------------------------------------------------" << endl;
			string file_save = get_file_name(&aa);
			HaiK_camera(file_save, &aa);
			cout << "\n-----------------------------------------------------------" << endl;
		}
		if (menu_num == 2) {
			menu_num = 0;
			cout << "\n-----------------------------------------------------------" << endl;
			aa.print_parameter();
			cout << "\n-----------------------------------------------------------" << endl;

		}
		if (menu_num == 3) {
			menu_num = 0;
			submenu(aa);
		}
		if ((menu_num == 4)||(menu_num==-1))
		{
			menu_num = 0;
			cout << "正在退出" << endl;
			flag = false;
		}
	}
	return 0;
}


int main() {
	main_ss();
	
	
	//main_menu(0, 4);
	//main_menu(1, 4);
	return 0;
}
#include"system.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Param::Param(string path)
{
	__config_path__ = path;
	_camera = "None";
	_fps = 0;
	_frame_size[0] = 0;
	_frame_size[1] = 0;
	_camera_type = "None";
	_format = "None";
	_time = 0;
	_filename = "None";
	_filepath = "None";
}
Param::~Param() {

}
//camera属性操作
void Param::set_camera(string url) {
	_camera = url;
}
string Param::get_camera() {
	return _camera;
}
//fps属性操作
void Param::set_fps(int fps) {
	_fps = fps;
}
int Param::get_fps() {
	return _fps;
}
//frame_size属性操作
void Param::set_frame_size(unsigned int index, int WH) {
	_frame_size[index] = WH;
}
int Param::get_frame_size(unsigned int index) {
	return _frame_size[index];
}
//编码属性操作
void Param::set_code(string code,string type) {
	
	if (code == "MPEG-4")
	{
		if(type == ".avi")
		{
			_video_code[0] = 'X';
			_video_code[1] = 'V';
			_video_code[2] = 'I';
			_video_code[3] = 'D';
		}
		else if(type == ".mp4")
		{
			_video_code[0] = 'M';
			_video_code[1] = 'P';
			_video_code[2] = '4';
			_video_code[3] = 'V';
		}
	}
	else 
	{
		code = "MPEG-4";
		type = ".avi";
		_video_code[0] = 'X';
		_video_code[1] = 'V';
		_video_code[2] = 'I';
		_video_code[3] = 'D';
	}
	_format = code;
	_camera_type = type;
}
string Param::get_code() {
	return _format;
}
string Param::get_type() {
	return _camera_type;
}
char Param::get_video_code(unsigned int index) {
	return _video_code[index];
}
//filename属性
void Param::set_filename(string filename) {
	_filename = filename;
}
string Param::get_filename() {
	return _filename;
}
//file_path
void Param::set_filepath(string path) {
	_filepath = path;
}
string Param::get_filepath() {
	return _filepath;
}
void Param::print_parameter()
{
	cout << "参数如下 :" << endl;
	cout << "CameraUrl:" << _camera << endl;
	cout << "FPS      :" << _fps << endl;
	cout << "time     :" << _time << endl;
	cout << "Width    :" << _frame_size[0] << endl;
	cout << "Height   :" << _frame_size[1] << endl;
	cout << "Format   :" << _camera_type << endl;
	cout << "Incode   :" << _format << endl;
	cout << "VideoCode:" << _video_code[0] << _video_code[1] << _video_code[2] << _video_code[3] << endl;
	cout << "Filename :" << _filename << endl;
	cout << "VideoPath:" << _filepath << endl;
	cout << "Cfgpath  :" << __config_path__ <<'\n' << endl;
	
}
string Param::get_config()
{
	return __config_path__;
}
void Param::set_time( int time) {
	_time = time;
}
int Param::get_time() {
	return _time;
}
void Param::set_config(string config) {
	__config_path__ = config;
}

string print_csdn(unsigned int i) {
	char temp[11]{ 0 };

	string ss(&parameter_code[i][0], &parameter_code[i][strlen(parameter_code[i])]);
	return ss;
}


//数据保存读写
void read_config(Param* para) {
	ifstream f(para->get_config());
	
	string temp_1;
	for (int i = 0; i < 15; i++)
	{
		char bufLine[128]{0};
		f.getline(bufLine, 128);
		string ss_one(&bufLine[0], &bufLine[9]);
		for (int j = 0; j < 15; j++)
		{
			if (ss_one == print_csdn(j))
			{
				if (j == 0)
				{
					string ss_tow(&bufLine[10], &bufLine[40]);
					string ss_t(&bufLine[40], &bufLine[strlen(bufLine)]);
					para->set_camera(ss_tow + ss_t);
				}
				else if (j == 1) {
					string ss_tow(&bufLine[10], &bufLine[strlen(bufLine)]);
					para->set_fps(string_to_uint(ss_tow));
				}
					
				else if (j == 2)
				{
					string ss_tow(&bufLine[10], &bufLine[strlen(bufLine)]);
					para->set_frame_size(0, string_to_uint(ss_tow));
				}
				else if (j == 3) {
					string ss_tow(&bufLine[10], &bufLine[strlen(bufLine)]);
					para->set_frame_size(1, string_to_uint(ss_tow));
				}
					
				else if (j == 4) {
					string ss_tow(&bufLine[10], &bufLine[strlen(bufLine)]);
					temp_1 = ss_tow;
				}
				else if (j == 5) {
					string ss_tow(&bufLine[10], &bufLine[strlen(bufLine)]);
					para->set_code(temp_1, ss_tow);
				}
				else if (j == 6) {
					string ss_tow(&bufLine[10], &bufLine[strlen(bufLine)]);
					para->set_filename(ss_tow);
				}
				else if (j == 7) {
					string ss_tow(&bufLine[10], &bufLine[strlen(bufLine)]);
					para->set_filepath(ss_tow);
				}
				else if (j == 8) {
					string ss_tow(&bufLine[10], &bufLine[strlen(bufLine)]);
					para->set_time(string_to_uint(ss_tow));
				}

			}
		}
		
	}
	f.close();
}
unsigned int string_to_uint(string str)
{
	unsigned int num = atoi(str.c_str());
	return num;
}

void trim(string& s)
{
	/*
	if( !s.empty() )
	{
		s.erase(0,s.find_first_not_of(" "));
		s.erase(s.find_last_not_of(" ") + 1);
	}
	*/
	int index = 0;
	if (!s.empty())
	{
		while ((index = s.find(' ', index)) != string::npos)
		{
			s.erase(index, 1);
		}
	}

}

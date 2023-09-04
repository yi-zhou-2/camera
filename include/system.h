#ifndef __system_H_
#define __system_H_
#include <iostream>

#include <string>
//#include <cstring>
//#include <vector>
using namespace std;

char const parameter_code[10][10] = {
	"CameraUrl",
	"FPS      ",
	"Width    ",
	"Height   ",
	"Format   ",
	"Incode   ",
	"Filename ",
	"VideoPath",
	"Time     ",
	"Cfgpath  "
	
};
class Param
{
public:
	Param(string path="./config.txt");
	~Param();
	//camera���Բ���
	void set_camera(string url);
	string get_camera();
	//fps���Բ���
	void set_fps(int);
	int get_fps();
	//frame_size���Բ���
	void set_frame_size(unsigned int , int);
	int get_frame_size(unsigned int);
	//�������Բ���
	void set_code(string, string);
	string get_code();
	string get_type();
	char get_video_code(unsigned int index);
	void set_time(int);
	int get_time();
	//filename����
	void set_filename(string filename);
	string get_filename();
	//file_path
	void set_filepath(string path);
	string get_filepath();
	void print_parameter();
	void set_config(string);
	string get_config();
private:
	//����ͷ
	string _camera;
	int _fps;
	int _frame_size[2];
	char _video_code[5];
	string _camera_type;   //��׺
	string _format;
    int _time;
	//�ļ�
	string _filename;	//������Ƶ����
	string _filepath;	//������Ƶ·��
	//���Ʋ���
	string __config_path__ = "./config.txt";
};
//�����ļ��Ķ�д
string print_csdn(unsigned int);
//���ݱ����д
void read_config(Param*);
void write_config(Param*);
unsigned int string_to_uint(string str);
void trim(string& s);
//ϵͳ�ܹ�
#endif

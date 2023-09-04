#include <time.h>
#include<iostream>
#include<string.h>
#include"system.h"
using namespace std;



string _get_time() {
	time_t t = time(NULL);
	struct tm* stime = localtime(&t);
	char tmp[32]{ 0 };
	snprintf(tmp, sizeof(tmp), "%04d_%02d_%02d__%02d_%02d_%02d", 1900 + stime->tm_year, 1 + stime->tm_mon, stime->tm_mday, stime->tm_hour, stime->tm_min, stime->tm_sec);
	string ss(&tmp[0], &tmp[strlen(tmp)]);
	return ss;
}
string get_file_name(Param*para ) {
	string file_save;
	string file_p = para->get_filename();
	if (file_p == "default")
	{
		file_p = "Infrared";
	}
	string suffix = _get_time();
	file_save = para->get_filepath()+file_p + '_' + suffix+ para->get_type();
	
	return file_save;
}
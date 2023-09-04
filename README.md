# 相机获取数据
本设计是用于获取海康摄像头的数据，其他摄像头的使用请参考opencv VideoCapture使用。
# 目录结构说明
文件总目录包含：
```
release:exe文件运行标准目录试样。
include：C++程序源代码目录。
```

# 环境要求
源程序编译环境：
```shell
C++ opencv=4.8.0
Visual Studio 2019
```


# 配置文件说明：
配置文件config.txt,是默认的配置文件。简言之就是，exe文件启动就会读取此文件。

当需要自定义参数时，可备份配置文件后，修改配置文件内容。也可以创建新得配置文件，在程序运行时修改配置文件路径，并更新配置参数即可满足
```
CameraUrl=rtsp://admin:adma8211@192.168.1.64:554
FPS      =30
Width    =1280
Height   =720
Format   =MPEG-4
Incode   =.avi
Filename =default
VideoPath=./videos/
Time     =5
```
其中：
```
CameraUrl：是网络摄像头的rtsp协议端口，利用opencv中 <kbd>cV::VideoCapture cap(rtsp)</kbd>创建VideoCapture对象对摄像头操作。
FPS：视频帧率。
Width Height：视频分辨率的宽和长。
Format：视频编码格式，目前之允许MPEG-4编码。
Incode：视频格式，MP4（.mp4）和AVI(.avi)两种格式都可以.
Filename:视频名称，默认为default(Infrared),最后保存的视频名称为Filename_Y_M_D__H_M_S(年月日时分秒),
VideoPath：视频保存目录，注意后面必须加个'/'。
Time：录制视频的时间
```
#camera

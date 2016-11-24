# SSG
Set a Small Goal
=============================
这是我们“拯救世界和平，维护人间正义”小组内维护的第一个项目，我们叫她“Set a Small Goal”，先定个目标，比如写个人体识别和追踪的项目
作者：来自世界一流实验室～

##功能描述
    人体追踪和识别的工作已经有很多了，我们要实现的效果与传统的方法又稍微有一些不同。<br>
    利用多个静止的普通RGB摄像头，识别场景中的人物，并且能够追踪人物的运动，通过多个标定好的摄像头确定人物在空间中的位置。<br>
    为了降低项目的难度，我们在这里简化场景复杂度，假设场景中背景的颜色单一，且场景中同时只出现1个人。
**************************************************************************

##技术要求
    （此技术要求乃鄙人粗浅之理解，如有拙劣，还望赐教）
####1. Human Detection：<br>
检测场景中的人物出现，并保存此人物的相关特征<br>

####2. Human Tracking：<br>
根据人物的特征，追踪人物的运动<br>

####3. Stereo Vision：<br>
通过多个摄像头确定人物在空间中的位置<br>
*******************************************************************

##开源资料
* [BGSLibrary](https://github.com/andrewssobral/bgslibrary)<br>
>A background subtraction library.背景分割开源库，有近20种背景分割的方法,[CSDN教程](http://blog.csdn.net/FRD2009041510/article/details/45669843)<br>

* [OpenCVBlobsLib](https://github.com/Steelskin/cvblob)<br>
>基于Opencv的斑点检测库<br>

* [cvBlob](https://code.google.com/archive/p/cvblob/)<br>
>基于Opencv的斑点检测库，带一定功能的追踪（追踪效果一般）<br>

* [OpenTLD](http://www.gnebehay.com/tld/)<br>
>TLD算法的开源库<br>

* [Simple Vehicle Counting](https://github.com/andrewssobral/simple_vehicle_counting)<br>
>一个开源的计算车流量的程序，基于cvBlob和BGSLibrary，[作者Andrews Sobral网站](https://www.behance.net/gallery/4057777/Vehicle-Detection-Tracking-and-Counting)<br>

* OpenCV<br>
>Opencv中contrib模块中的KCF算法，TLD算法，MultiTracking等Tracking by Detecting的例子，还有Kalman Filter等纯追踪的例子<br>

#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/highgui/highgui.hpp"
#include<stdio.h>
//video colour sepration
using namespace cv;
using namespace std;


void lowR(int, void *);
void highR(int, void *);
void lowG(int, void *);
void highG(int, void *);
void lowB(int, void *);
void highB(int, void *);


int low_r=30, low_g=30, low_b=30;
int high_r=100, high_g=100, high_b=100;


int main()
{
    Mat frame;
    VideoCapture cap(0);
    
    namedWindow("Video Capture", WINDOW_NORMAL);
    namedWindow("Object DetectionR", WINDOW_NORMAL);
    namedWindow("Object DetectionG", WINDOW_NORMAL);
    namedWindow("Object DetectionB", WINDOW_NORMAL);

    createTrackbar("Low R","Object DetectionR", &low_r, 255, lowR);
    createTrackbar("High R","Object DetectionR", &high_r, 255, highR);
    createTrackbar("Low G","Object DetectionG", &low_g, 255, lowG);
    createTrackbar("High G","Object DetectionG", &high_g, 255, highG);
    createTrackbar("Low B","Object DetectionB", &low_b, 255, lowB);
    createTrackbar("High B","Object DetectionB", &high_b, 255, highB);
    while(char(waitKey(1))!='q'){
        cap>>frame;
	Mat frame_threshold,frameC(frame.rows,frame.cols,CV_8UC3,Scalar(0,0,0));
        if(frame.empty())
            break;
        inRange(frame,Scalar(0,0,low_r), Scalar(255,255,high_r),frame_threshold);
        for(int i=1;i<frame_threshold.rows;i++)
		for(int j=0;j< frame_threshold.cols;j++)
			if( frame_threshold.at<uchar>(i,j)==0)
				frameC.at<Vec3b>(i,j)[2]=255;
	
	imshow("Object DetectionR",frameC);
	

	inRange(frame,Scalar(0,low_g,0), Scalar(255,high_g,255),frame_threshold);
        for(int i=1;i<frame_threshold.rows;i++)
		for(int j=0;j< frame_threshold.cols;j++)
			//if( frame_threshold.at<uchar>(i,j)==0)
				frameC.at<Vec3b>(i,j)[2]=0;
        for(int i=1;i<frame_threshold.rows;i++)
		for(int j=0;j< frame_threshold.cols;j++)
			if( frame_threshold.at<uchar>(i,j)==0)
				frameC.at<Vec3b>(i,j)[1]=255;        



	imshow("Object DetectionG",frameC);

	inRange(frame,Scalar(low_b,0,0), Scalar(high_b,255,255),frame_threshold);
        for(int i=1;i<frame_threshold.rows;i++)
		for(int j=0;j< frame_threshold.cols;j++)
				frameC.at<Vec3b>(i,j)[1]=0;
        for(int i=1;i<frame_threshold.rows;i++)
		for(int j=0;j< frame_threshold.cols;j++)
			if( frame_threshold.at<uchar>(i,j)==0)
				frameC.at<Vec3b>(i,j)[0]=255;



        imshow("Object DetectionB",frameC);
    }
    return 0;
}
void lowR(int, void *)
{
    low_r = min(high_r-1, low_r);
    setTrackbarPos("Low R","Object DetectionR", low_r);
}
void highR(int, void *)
{
    high_r = max(high_r, low_r+1);
    setTrackbarPos("High R", "Object DetectionR", high_r);
}

void lowG(int, void *)
{
    low_g = min(high_g-1, low_g);
    setTrackbarPos("Low G","Object DetectionG", low_g);
}


void highG(int, void *)
{
    high_g = max(high_g, low_g+1);
    setTrackbarPos("High G", "Object DetectionG", high_g);
}


void lowB(int, void *)
{
    low_b= min(high_b-1, low_b);
    setTrackbarPos("Low B","Object DetectionB", low_b);
}


void highB(int, void *)
{
    high_b = max(high_b, low_b+1);
    setTrackbarPos("High B", "Object DetectionB", high_b);
}

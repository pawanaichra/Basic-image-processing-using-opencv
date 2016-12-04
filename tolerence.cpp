#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;
int main()
{
	Mat var2=imread("test.jpg",1);
	int a=10;
	int b=10;
	int c=10;
	int d=10;
	int e=10;
	int f=10;
	int i,j;
	namedWindow("window1",WINDOW_AUTOSIZE);
	imshow("window1",var2);
	createTrackbar("red","window1",&a,255);
	createTrackbar("blue","window1",&b,255);
	createTrackbar("green","window1",&c,255);
	createTrackbar("red_tol","window1",&d,255);
	createTrackbar("blue_tol","window1",&e,255);
	createTrackbar("green_tol","window1",&f,255);
	Mat var3(var2.rows, var2.cols, CV_8UC3, Scalar(0,0,0));//255,255,255
	while(1){
		
		
		for(i=0;i<var2.rows;i++)
	{
		for(j=0;j<var2.cols;j++)
		{
			if((var2.at<Vec3b>(i,j)[0]>(b-e))&&(var2.at<Vec3b>(i,j)[1]>(c-f))&&(var2.at<Vec3b>(i,j)[2]>(a-d))&&(var2.at<Vec3b>(i,j)[0]<(b+e))&&(var2.at<Vec3b>(i,j)[1]<(c+f))&&(var2.at<Vec3b>(i,j)[2]<(a+d)))
			{
				var3.at<Vec3b>(i,j)[0]=var2.at<Vec3b>(i,j)[0];
				var3.at<Vec3b>(i,j)[1]=var2.at<Vec3b>(i,j)[1];
				var3.at<Vec3b>(i,j)[2]=var2.at<Vec3b>(i,j)[2];
			}
			else
			{
				var3.at<Vec3b>(i,j)[0]=255;
				var3.at<Vec3b>(i,j)[1]=255;
				var3.at<Vec3b>(i,j)[2]=255;
			}
				
			
		}
	}
		imshow("window1", var3);
		if(waitKey(10)=='q')
		break;
	
		}
	
return 0;
}


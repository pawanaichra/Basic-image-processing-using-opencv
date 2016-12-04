#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;
int main()
{
	Mat var1=imread("test.jpg",1);
	Mat var2(2*var1.rows, 2*var1.cols, CV_8UC3, Scalar(0,0,0));
	int i,j,k,m;
	for(i=0;i<var2.rows;i++)
	{
		for(j=0;j<var2.cols;j++)
		{
			var2.at<Vec3b>(i,j)=var1.at<Vec3b>(i/2,j/2);
			
		}
	}
	Mat var3(var1.rows/2, var1.cols/2, CV_8UC3, Scalar(0,0,0));
	for(i=0;i<var3.rows;i++)
	{
		for(j=0;j<var3.cols;j++)
		{	
				var3.at<Vec3b>(i,j)=(var1.at<Vec3b>(2*i+1,2*j)+var1.at<Vec3b>(2*i,2*j)+var1.at<Vec3b>(2*i,2*j+1)+var1.at<Vec3b>(2*i+1,2*j+1))/4;
		}
	}
	namedWindow("window1",WINDOW_AUTOSIZE);
	namedWindow("window2",WINDOW_AUTOSIZE);
	namedWindow("window3",WINDOW_AUTOSIZE);
	imshow("window1", var2);
	imshow("window2", var1);
	imshow("window3", var3);
	waitKey(0);
	return 0;
}


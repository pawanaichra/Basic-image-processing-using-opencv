#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <math.h>
using namespace cv;
using namespace std;

int main()
{
	int l_y,l_x,a=50;
	Mat var1 = imread("test.jpg",1);

	Mat var2(var1.rows,var1.cols,CV_8UC1,Scalar(0));
	Mat var3(var1.rows,var1.cols,CV_8UC1,Scalar(0));
	Mat var4(var1.rows,var1.cols,CV_8UC1,Scalar(0));


	namedWindow("window",WINDOW_AUTOSIZE);

	imshow("window",var1);
	createTrackbar("pawan","window",&a,255);
	

	for(int i=0;i<var1.rows;i++)
	{

		for(int j=0;j<var1.cols;j++)
		{

			var2.at<uchar>(i,j)=(var1.at<Vec3b>(i,j)[0]+var1.at<Vec3b>(i,j)[1]+var1.at<Vec3b>(i,j)[2])/3;

		}

	}

	for(int i=1;i<var3.rows-1;i++)
	{
		for(int j=1;j<var3.cols-1;j++)
		{
			l_x=var2.at<uchar>(i,j-1)*(-0.5)+var2.at<uchar>(i,j+1)*(0.5);

			l_y=var2.at<uchar>(i-1,j)*(0.5)+var2.at<uchar>(i+1,j)*(-0.5);

			var3.at<uchar>(i,j)=sqrt(l_x*l_x+l_y*l_y);
		}
	}

	

	while(1)
	{

		for(int i=1;i<var3.rows-1;i++)
		{
			for(int j=1;j<var3.cols-1;j++)
			{
				if(var3.at<uchar>(i,j)>a)
				{
					var4.at<uchar>(i,j)=255;
				}
				else
				{
					var4.at<uchar>(i,j)=0;
				}

			}
		}
		imshow("window",var4);
		if(waitKey(10)=='q')
			break;

	}

	


	return 0;

}

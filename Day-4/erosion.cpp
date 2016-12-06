#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;
int main()
{
	Mat var1=imread("test1.jpg",1);
	Mat var2(var1.rows, var1.cols, CV_8UC1, Scalar(0));
	Mat var3(var1.rows, var1.cols, CV_8UC1, Scalar(0));
	Mat var4(var1.rows, var1.cols, CV_8UC1, Scalar(0));
	int i,j,k,l;
	for(i=0;i<var1.rows;i++)
	{
		for(j=0;j<var1.cols;j++)
		{
			var2.at<uchar>(i,j)=(var1.at<Vec3b>(i,j)[0]+var1.at<Vec3b>(i,j)[1]+var1.at<Vec3b>(i,j)[2])/3;
		}
	}
	for(i=0;i<var2.rows;i++)
	{
		for(j=0;j<var2.cols;j++)
		{
			if(var2.at<uchar>(i,j)>150)
				var3.at<uchar>(i,j)=255;
			else
				var3.at<uchar>(i,j)=0;
		}
	}
	int flag;
	for(i=1;i<var1.rows-1;i++)
	{
		for(j=1;j<var1.cols-1;j++)
		{
			for(k=-1;k<2;k++)
			{
				for(l=-1;l<2;l++)
				{
					if(var3.at<uchar>(i+k,j+l)==0)
					{
						var4.at<uchar>(i,j)=0;
						flag=1;
						break;
					}
					else
						var4.at<uchar>(i,j)=255;
						
				}
				if(flag==1)
				{
					flag=0;
					break;
				}
			}
		}
	}



	namedWindow("window1",WINDOW_AUTOSIZE);
	imshow("window1", var4);
	waitKey(0);
return 0;
}




































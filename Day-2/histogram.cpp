#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;
int main()
{
	Mat var1=imread("test.jpg",1);
	Mat var2(257, var1.cols, CV_8UC3, Scalar(0,0,0));
	int i,j,count[300];
	for(i=0;i<300;i++)
	{
		count[i]=0;
	}
	for(i=0;i<var1.rows;i++)
	{
		for(j=0;j<var1.cols;j++)
		{
			for(int k=0;k<256;k++)
			{
				if(var1.at<Vec3b>(i,j)[0]==k)
					count[k]++;
			}
				
			
		}
	}
	for(i=0;i<var2.cols;i++)
		
	{
		for(j=0;j<count[i];j++)
			var2.at<Vec3b>(i,j)[0]=255;
	}
		
		
	namedWindow("window1",WINDOW_AUTOSIZE);
	imshow("window1", var2);
	waitKey(0);
	return 0;
}

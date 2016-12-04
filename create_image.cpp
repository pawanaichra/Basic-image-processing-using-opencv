#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;

int main()
{

	Mat var1(200,200,CV_8UC3,Scalar(0,0,0));

	for(int i=0;i<200;i++)
	{
		for(int j=0;j<200;j++)
		{
			if(i>j&&200-i>j)
			{
				var1.at<Vec3b>(i,j)[0]=255;
				var1.at<Vec3b>(i,j)[1]=255;
				var1.at<Vec3b>(i,j)[2]=255;
			}

			if(i<j&&200-i<j)
				var1.at<Vec3b>(i,j)[1]=255;

			if(i<j&&200-i>j)
				var1.at<Vec3b>(i,j)[0]=255;

			if(i>j&&200-i<j)
				var1.at<Vec3b>(i,j)[2]=255;
		}

	}

	namedWindow("window1",WINDOW_AUTOSIZE);

	imshow("window1",var1);
	waitKey(0);
	return 0;

}
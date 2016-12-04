#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;

int main()
{
int i,j,a=50;
Mat var1 = imread("test.jpg",1);

namedWindow("window",WINDOW_AUTOSIZE);

imshow("window",var1);
createTrackbar("pawan","window",&a,255);





while(1)
{
Mat var2(var1.rows,var1.cols,CV_8UC1,Scalar(0));
Mat var3(var1.rows,var1.cols,CV_8UC1,Scalar(0));




		
for(i=0;i<var2.rows;i++)
{

for(j=0;j<var2.cols;j++)
{

var2.at<uchar>(i,j)=(var1.at<Vec3b>(i,j)[0]+var1.at<Vec3b>(i,j)[1]+var1.at<Vec3b>(i,j)[2])/3;

if(var2.at<uchar>(i,j)>a)
{
var3.at<uchar>(i,j)=255;
}
else
{
var3.at<uchar>(i,j)=0;
}

}

}


	


imshow("window",var3);
if(waitKey(10)=='q')
break;
}





return 0;

}

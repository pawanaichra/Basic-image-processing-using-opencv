#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;

int main()
{
Mat var1=imread("test.jpg",1);


Mat var2(var1.rows,var1.cols,CV_8UC1,Scalar(0));
Mat var3(var1.rows,var1.cols,CV_8UC1,Scalar(0));

int i,j;
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
{
var3.at<uchar>(i,j)=255;
}
else
{
var3.at<uchar>(i,j)=0;
}

}

}





namedWindow("RGB",WINDOW_AUTOSIZE);
imshow("RGB",var1);
namedWindow("Gray",WINDOW_AUTOSIZE);
imshow("Gray",var2);
namedWindow("Binary",WINDOW_AUTOSIZE);
imshow("Binary",var3);

waitKey(0);

return 0;
}

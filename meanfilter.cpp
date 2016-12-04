#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;

int main()
{
int sum_g,sum_b,sum_r;
Mat var1 = imread("test.jpg",1);

for(int i=0;i<var1.rows-2;i++)
{

for(int j=0;j<var1.cols-2;j++)
{

sum_g=(var1.at<Vec3b>(i,j)[0]+var1.at<Vec3b>(i+1,j)[0]+var1.at<Vec3b>(i+2,j)[0]+var1.at<Vec3b>(i,j+1)[0]+var1.at<Vec3b>(i,j+2)[0]+var1.at<Vec3b>(i+1,j+1)[0]+var1.at<Vec3b>(i+1,j+2)[0]+var1.at<Vec3b>(i+2,j+1)[0]+var1.at<Vec3b>(i+2,j+2)[0])/9;

sum_b=(var1.at<Vec3b>(i,j)[1]+var1.at<Vec3b>(i+1,j)[1]+var1.at<Vec3b>(i+2,j)[1]+var1.at<Vec3b>(i,j+1)[1]+var1.at<Vec3b>(i,j+2)[1]+var1.at<Vec3b>(i+1,j+1)[1]+var1.at<Vec3b>(i+1,j+2)[1]+var1.at<Vec3b>(i+2,j+1)[1]+var1.at<Vec3b>(i+2,j+2)[1])/9;

sum_r=(var1.at<Vec3b>(i,j)[2]+var1.at<Vec3b>(i+1,j)[2]+var1.at<Vec3b>(i+2,j)[2]+var1.at<Vec3b>(i,j+1)[2]+var1.at<Vec3b>(i,j+2)[2]+var1.at<Vec3b>(i+1,j+1)[2]+var1.at<Vec3b>(i+1,j+2)[2]+var1.at<Vec3b>(i+2,j+1)[2]+var1.at<Vec3b>(i+2,j+2)[2])/9;

var1.at<Vec3b>(i+1,j+1)[0]=sum_g;
var1.at<Vec3b>(i+1,j+1)[1]=sum_b;
var1.at<Vec3b>(i+1,j+1)[2]=sum_r;

}

}

namedWindow("window1",WINDOW_AUTOSIZE);

imshow("window1",var1);
waitKey(0);
return 0;

}

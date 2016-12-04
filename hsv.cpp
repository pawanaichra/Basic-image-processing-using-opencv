#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;

int main()
{

Mat var1 = imread("test.jpg",1);

Mat var2(var1.rows,var1.cols,CV_8UC1,Scalar(0));

cvtColor(var1,var2,CV_BGR2HSV);

namedWindow("HSV",WINDOW_AUTOSIZE);

imshow("HSV",var2);
waitKey(0);
return 0;

}

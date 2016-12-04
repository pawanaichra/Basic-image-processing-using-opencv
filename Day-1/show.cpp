#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;

int main()
{

	Mat var1 = imread("test.jpg",1);

	namedWindow("window1",WINDOW_AUTOSIZE);

	imshow("window1",var1);

	waitKey(0);
	
	return 0;

}

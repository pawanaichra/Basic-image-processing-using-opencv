#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;

int main()
{

	Mat img,var3,var4;

	VideoCapture a(0);

	while(a.isOpened())
	{
		a>>img;

		blur(img,var3,Size(5,5));

		Canny(var3,var4,30,150);


		namedWindow("video",WINDOW_AUTOSIZE);
		imshow("video",var4);
		if(waitKey(30)=='q')
			break;
	}

	return 0;


}
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;

int main()
{

	Mat img;

	VideoCapture a(0);

	while(a.isOpened())
	{
		a>>img;


		namedWindow("video",WINDOW_AUTOSIZE);

		imshow("video",img);
		if(waitKey(30)=='q')
		{
			imwrite("test.jpg",img);
			break;
		}

			
	}

	return 0;
		


}
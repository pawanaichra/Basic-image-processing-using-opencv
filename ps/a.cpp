#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/objdetect/objdetect.hpp"

using namespace cv;
using namespace std;

int main()
{

	Mat frame = imread("test.jpg",1);
	Mat face_gray;

	std::vector<Rect> faces;

	cvtColor(frame,frame_gray,CV_BGR2GRAY);

	equlizeHist(frame_gray,frame_gray);


	CascadeClassifier face_cascade;

	face_cascade = CascadeClassifier("haarcascade_frontalface_default.xml");

	face_cascade.detectMultiScale(frame_gray,faces,1.1,2,0|CV_HAAR_SCALE<Size(30,30));


	for(int i=0; i<faces.size();i++)
	{
		Point center(faces[i].x + faces[i]*(0.5) , faces[i].y + faces[i].height*(0.5));
		ellipse(frame,center,size(faces[i].width*(0.5) , faces[i].height*(0.5)) , 0 , 0 , 360, Scalar(255,0,255), 4, 8, 0);

		
	

	}

	namedWindow("window1",WINDOW_AUTOSIZE);

	imshow("window1",frame);
	waitKey(0);
	return 0;

}
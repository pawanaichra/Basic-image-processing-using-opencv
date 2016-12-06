#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <stack>

using namespace std;
using namespace cv;

Mat img = imread("shapes.jpg", 1);
void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
	
	int Color1 = (int)img.at<Vec3b>(y, x)[0];
	int Color2 = (int)img.at<Vec3b>(y, x)[1];
	int Color3 = (int)img.at<Vec3b>(y, x)[2];


	if (event == EVENT_LBUTTONDOWN)
	{
		Mat vis(img.rows, img.cols, CV_8UC1, Scalar(0));
		stack<Point2d> S;
		Point2d A;
		
		A = Point2d(y, x);
		S.push(A);



		while (!S.empty())
		{
			A = S.top();
			S.pop();
			int X = A.x;
			int Y = A.y;
			vis.at<uchar>(X, Y) = 255;
			
			for (int l = X - 1; l < X + 2; l++)
			{
				for (int p = Y - 1; p < Y + 2; p++)
				{
					if (img.at<Vec3b>(l, p)[0] == Color1 && img.at<Vec3b>(l, p)[1] == Color2 && img.at<Vec3b>(l, p)[2] == Color3  && vis.at<uchar>(l, p) != 255)
					{
						A = Point2d(l, p);
						S.push(A);
						vis.at<uchar>(l, p) = 255;
						img.at<Vec3b>(l, p)[2] = 255;
						img.at<Vec3b>(l, p)[1] = 0;
						img.at<Vec3b>(l, p)[0] = 0;

					}
				}
			}
		}
		
		namedWindow("W1", 1);
		imshow("W1", img);
	}
}

int main()
{

	
	if (img.empty())
	{
		cout << "Error loading the image" << endl;
		return -1;
	}

	
	namedWindow("ImageDisplay", 1);

	setMouseCallback("ImageDisplay", CallBackFunc, &img);

	imshow("ImageDisplay", img);
	waitKey(0);

	return 0;

}

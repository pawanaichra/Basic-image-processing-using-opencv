#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include<stdio.h>
int i, j;

using namespace cv;
using namespace std;
bool R1(int R, int G, int B ){
	bool e1 = (R>95) && (G>40) && (B>20) && ((max(R, max(G, B)) - min(R, min(G, B)))>15) && (abs(R - G)>15) && (R>G) && (R>B);
	bool e2 = (R>220) && (G>210) && (B>170) && (abs(R - G) <= 15) && (R>B) && (G>B);
	return (e1 || e2);
}

bool R2(float Y, float Cr, float Cb) {
	bool e3 = Cr <= 1.5862*Cb + 20;
	bool e4 = Cr >= 0.3448*Cb + 76.2069;
	bool e5 = Cr >= -4.5652*Cb + 234.5652;
	bool e6 = Cr <= -1.15*Cb + 301.75;
	bool e7 = Cr <= -2.2857*Cb + 432.85;
	return e3 && e4 && e5 && e6 && e7;
}

bool R3(float H, float S, float V) {
	return (H<25) || (H > 230);
}

Mat GetSkin(Mat const &src) {
	// allocate the result matrix
	Mat dst = src.clone();

	Vec3b cwhite = Vec3b::all(255);
	Vec3b cblack = Vec3b::all(0);

	Mat src_ycrcb, src_hsv;
	cvtColor(src, src_ycrcb, CV_BGR2YCrCb);
	src.convertTo(src_hsv, CV_32FC3);
	cvtColor(src_hsv, src_hsv, CV_BGR2HSV);
	normalize(src_hsv, src_hsv, 0.0, 255.0, NORM_MINMAX, CV_32FC3);

	for (int i = 0; i < src.rows; i++) {
		for (int j = 0; j < src.cols; j++) {

			Vec3b pix_bgr = src.ptr<Vec3b>(i)[j];
			int B = pix_bgr.val[0];
			int G = pix_bgr.val[1];
			int R = pix_bgr.val[2];
			// apply rgb rule
			bool a = R1(R, G, B);

			Vec3b pix_ycrcb = src_ycrcb.ptr<Vec3b>(i)[j];
			int Y = pix_ycrcb.val[0];
			int Cr = pix_ycrcb.val[1];
			int Cb = pix_ycrcb.val[2];
			// apply ycrcb rule
			bool b = R2(Y, Cr, Cb);

			Vec3f pix_hsv = src_hsv.ptr<Vec3f>(i)[j];
			float H = pix_hsv.val[0];
			float S = pix_hsv.val[1];
			float V = pix_hsv.val[2];
			// apply hsv rule
			bool c = R3(H, S, V);

			if (!(a&&b&&c))
				dst.ptr<Vec3b>(i)[j] = cblack;
		}
	}
	return dst;
}


int main(int argc, const char *argv[]) {
	Mat image;
	VideoCapture cap("ps.mp4");
	int a = 0, b = 0, c = 1, d = 0, e = 0, f = 0, g = 0, h = 0, counter = 0, kp = 0, z = 0;
	while (1)
	{
		z++;
		if (z % 10 != 0)
			continue;
		cap >> image;
		Mat skin = GetSkin(image);
		GaussianBlur(skin, skin, Size(7, 7), 1.5, 1.5);
		Mat Gray;
		cvtColor(skin, Gray, CV_BGR2GRAY);
		for (i = 0; i<Gray.rows; i++)
		{
			for (j = 0; j<Gray.cols; j++)
			{
				if (Gray.at<uchar>(i, j)>80)
					Gray.at<uchar>(i, j) = 255;
				else
					Gray.at<uchar>(i, j) = 0;
			}
		}
		// Show the results:
		namedWindow("original", WINDOW_AUTOSIZE);
		//namedWindow("skin", 1);
		namedWindow("Gray", WINDOW_AUTOSIZE);

		imshow("original", image);
		//imshow("skin", skin);
		imshow("Gray", Gray);

		c = 1;
		a = 0;
		b = 0;
		for (i = 200; i < Gray.rows - 200; i++)
		{
			for (j = 200; j < Gray.cols - 200; j++)
			{
				if (Gray.at<uchar>(i, j) == 255)
				{
					a += i;
					b += j;
					c++;//kp++;
					//counter=1;

				}
			}
		}
		a = a / c;
		b = b / c;
		if (b == 0 && g>0 && h>0 && a == 0)
		{
			f++;

		}
		h = a; g = b;
		cout << "Count = " << f << "\n ";


		if (waitKey(20) >= 0)
			break;
	}
}

#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/highgui/highgui.hpp"
#include<bits/stdc++.h>

#include<stdio.h>

//canny filter using function
using namespace cv;
using namespace std;
	
	typedef struct Q{
	int x,y;}stt;
int main(){
	Mat var1=imread("try2.jpg",1);//Mat is a data type 
	Mat var2(var1.rows,var1.cols,CV_8UC1,Scalar(0));
	struct Q *q;
		
	stack<stt*> S;
	int count=0;
	for(int i=1;i<var1.rows-1;i++)
		for(int j=1;j<var1.cols-1;j++){
			if(var2.at<uchar>(i,j)==0&&var1.at<Vec3b>(i,j)[2]>200&&var1.at<Vec3b>(i,j)[1]<30&&var1.at<Vec3b>(i,j)[0]<30){
				q=(stt*)malloc(sizeof(struct Q));
				q->x=i;
				q->y=j;
				S.push(q);
				count++;
				var2.at<uchar>(i,j)=255;
			}
			while(!S.empty()){
			q=(stt*)S.top();
			S.pop();
			int ia=q->x,ja=q->y;
			for(int a=-1;a<=1;a++)
			for(int b=-1;b<=1;b++)
				if(var2.at<uchar>(ia+a,ja+b)==0&&var1.at<Vec3b>(ia+a,ja+b)[2]>200&&var1.at<Vec3b>(ia+a,ja+b)[1]<30&&var1.at<Vec3b>(a+ia,b+ja)[0]<30){
				q=(stt*)malloc(sizeof(struct Q));
				q->x=ia+a;
				q->y=ja+b;
				S.push(q);
				var2.at<uchar>(a+ia,b+ja)=255;
				}
			}
		
		}
		printf("count = %d \n",count);
namedWindow("windows2");//name of window
namedWindow("windows1");//name of window
imshow("windows2",var2);	imshow("windows1",var1);
	waitKey(0);




}

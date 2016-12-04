#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <cmath>
using namespace std;
using namespace cv;

int main(){

  Mat var1 = imread("test.jpg",1);
  //Mat var2x(var1.rows,var1.cols,CV_8UC3,Scalar(0,0,0));
  //Mat var2y(var1.rows,var1.cols,CV_8UC3,Scalar(0,0,0));
  Mat var2(var1.rows,var1.cols,CV_8UC3,Scalar(0,0,0));


  int Gx[3][3] ={{-1,0,1},{-2,0,2},{-1,0,1}};
  int Gy[3][3] ={{1,2,1},{0,0,0},{-1,-2,-1}};

//Gx Kernel
  for(int i = 1 ; i<var1.rows-1 ;i++){
    for(int j = 1; j<var1.cols-1 ;j++){
	int sumx[3] ={0,0,0};
	int sumy[3] ={0,0,0};
      for(int k =0 ; k<3 ;k++){
		for(int l =0 ;l<3;l++){	  
	    sumx[0] += var1.at<Vec3b>(i+k-1,j+l-1)[0]*Gx[k][l];
		sumx[1] += var1.at<Vec3b>(i+k-1,j+l-1)[1]*Gx[k][l];
		sumx[2] += var1.at<Vec3b>(i+k-1,j+l-1)[2]*Gx[k][l];
 		sumy[0] += var1.at<Vec3b>(i+k-1,j+l-1)[0]*Gy[k][l];
		sumy[1] += var1.at<Vec3b>(i+k-1,j+l-1)[1]*Gy[k][l];
		sumy[2] += var1.at<Vec3b>(i+k-1,j+l-1)[2]*Gy[k][l];
	   }} 
		for(int m=0;m<3;m++){
          
		  if(sqrt(sumx[m]*sumx[m]+sumy[m]*sumy[m]) < 256) 
			var2.at<Vec3b>(i,j)[m] = (int) sqrt(sumx[m]*sumx[m]+sumy[m]*sumy[m]);
		  else
			var2.at<Vec3b>(i,j)[m] = 0 ;
		}
 }}







namedWindow("Sobel",WINDOW_AUTOSIZE); 
imshow("Sobel",var2); 
waitKey(0);


return 0;
}




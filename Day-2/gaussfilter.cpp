#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;

int main(){

  Mat var1 = imread("test.jpg",1);
  Mat var2(var1.rows,var1.cols,CV_8UC3,Scalar(0,0,0));

  int ker[3][3] ={{1,2,1},{2,4,2},{1,2,1}};
  
  //var2 = var1 ;

  for(int i = 1 ; i<var1.rows-1 ;i++){
    for(int j = 1; j<var1.cols-1 ;j++){
	int sum[3] ={0,0,0};
      for(int k =0 ; k<3 ;k++){
		for(int l =0 ;l<3;l++){	  
	    sum[0] += var1.at<Vec3b>(i+k-1,j+l-1)[0]*ker[k][l];
		sum[1] += var1.at<Vec3b>(i+k-1,j+l-1)[1]*ker[k][l];
		sum[2] += var1.at<Vec3b>(i+k-1,j+l-1)[2]*ker[k][l];
	   }} 
		var2.at<Vec3b>(i,j)[0] = sum[0] / 16 ;
		var2.at<Vec3b>(i,j)[1] = sum[1] / 16;
		var2.at<Vec3b>(i,j)[2] = sum[2] / 16 ;
 }}

namedWindow("Gaussian",WINDOW_AUTOSIZE); 
imshow("Gaussian",var2); 
waitKey(0);
return 0;
}




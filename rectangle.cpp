#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;

int main(){
 Mat var1(200,400,CV_8UC1,Scalar(255));


 for(int i =0;i<200;i++) {
  for(int j=300;j<400;j++){
	var1.at<uchar>(i,j) = 0 ;
}
}
namedWindow("Rectangle",WINDOW_AUTOSIZE);
imshow("Rectangle",var1);
waitKey(0);
return 0;
}

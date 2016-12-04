#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;

int main(){
 Mat var1(640,640,CV_8UC1,Scalar(0));

 for(int i =0;i<var1.rows;i++) {
  for(int j=0;j<var1.cols;j++){
    if((i/80 + j/80)%2 == 0)
      var1.at<uchar>(i,j) = 0;
    else
      var1.at<uchar>(i,j) = 255;
}
}


namedWindow("Chess",WINDOW_AUTOSIZE);
imshow("Chess",var1);
waitKey(0);
return 0;
}

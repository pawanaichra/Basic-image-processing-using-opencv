#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <stdio.h>
#include <string.h>
#include <ctype.h>

using namespace cv;
using namespace std;


int main()
{
    Mat img;
    int i,j;

VideoCapture a("2.mp4");

	while(a.isOpened())
	{
		a>>img;

	
    	namedWindow("people detector", 1);
    	HOGDescriptor hog;
    	hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());
    	vector<Rect> found, found_filtered;

    	 hog.detectMultiScale(img, found, 0, Size(8,8), Size(32,32), 1.05, 2);
    	 for(i = 0; i < found.size(); i++ )
        {
            Rect r = found[i];
            for(j = 0; j < found.size(); j++ )
                if( j != i && (r & found[j]) == r)
                    break;
            if(j == found.size() )
                found_filtered.push_back(r);
        }
        for(i = 0; i < found_filtered.size(); i++ )
        {
            Rect r = found_filtered[i];
            // the HOG detector returns slightly larger rectangles than the real objects.
            // so we slightly shrink the rectangles to get a nicer output.
            r.x += cvRound(r.width*0.1);
            r.width = cvRound(r.width*0.8);
            r.y += cvRound(r.height*0.07);
            r.height = cvRound(r.height*0.8);
            rectangle(img, r.tl(), r.br(), cv::Scalar(0,255,0), 3);
        }
       

        imshow("people detector", img);
        
        if( waitKey(30) == 'q' )
            break;
    
    }
    return 0;
}
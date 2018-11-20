#include<opencv2/opencv.hpp>  
#include<opencv2/core/core.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp> 
#include<iostream>
using namespace cv;  
using namespace std;

int main01()
{
	Mat srcImage = imread("D:\\mymatlab\\toolbox\\images\\imdata\\pillsetc.png");
	Mat midImage, dstImage;
	Canny(srcImage, midImage, 100, 250, 3);
	cvtColor(midImage, dstImage, CV_GRAY2BGR);
	GaussianBlur(midImage, midImage, Size(9, 9), 2, 2);
	//vector<Vec4i> lines;
	//HoughLinesP(midImage, lines, 1, CV_PI / 180, 80, 600, 0);
	vector<Vec3f> circles;
	HoughCircles(midImage, circles, CV_HOUGH_GRADIENT, 1.5, 10,200, 100, 0,0);
	for (size_t i = 0; i < circles.size(); i++)
	{
		Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
		int radius = cvRound(circles[i][2]);
		//绘制圆心  
		circle(srcImage, center,3, Scalar(255, 255, 255),8, 8, 0);


		char string[25];
		_itoa(i+1, string, 10);
		putText(srcImage,string , Point((circles[i][0]), (circles[i][1])), 1, 3, Scalar(255, 255, 255));
		
		//绘制圆轮廓  
		circle(srcImage, center, radius, Scalar(155, 50, 255), 3, 8, 0);

		//Vec4i l = lines[i];
		//line(dstImage, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(255, 255, 255), 1, CV_AA);
	}
	imshow("【效果图】", srcImage);
    waitKey();
	return 0;
} 
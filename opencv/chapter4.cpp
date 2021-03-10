#include<iostream>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/core.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
using namespace std;
using namespace cv;


////////////// Draw Shapes and Text //////////////////////

//int main() {
//
//	// Blank Image
//	Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255));
//
//	circle(img, Point(256, 256), 155, Scalar(0, 69, 255), FILLED);
//	rectangle(img, Point(130, 226), Point(382, 286), Scalar(255, 255, 255), FILLED);
//	line(img, Point(130, 296), Point(382, 296), Scalar(255, 255, 255), 2);
//
//	putText(img, "Murtaza's Workshop", Point(137, 262), FONT_HERSHEY_DUPLEX, 0.75, Scalar(0, 69, 255), 2);
//
//	imshow("Image", img);
//	waitKey(0);
//
//	return 0;
//}

int main() {
	// Blank Image
	Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255));

	circle(img, Point(226, 226),100, Scalar(0,69,255), FILLED);
	rectangle(img, Rect(126, 326, 200, 50), Scalar(53, 20, 69),FILLED);
	putText(img, "welcome to szu!", Point(150, 260), FONT_HERSHEY_PLAIN,1, Scalar(255, 255, 255), 1);

	imshow("Image", img);
	waitKey(0);
	return 0;
}
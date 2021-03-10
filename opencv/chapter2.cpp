#include <opencv2\imgcodecs.hpp>
#include <opencv2\imgproc.hpp>
#include <opencv2\highgui.hpp>
#include <iostream>
using namespace std;
using namespace cv;

/////////////// Basic Functions 

int main() {
	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat imgGray,imgGaussian, imgCanny, imgDil, imgErode;
	cvtColor(img, imgGray,COLOR_BGR2GRAY);
	imshow("gray", imgGray);
	GaussianBlur(img, imgGaussian, Size(7, 7), 5, 0);
	Canny(img, imgCanny, 25, 75);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(7, 7));
	dilate(img, imgDil, kernel);
	erode(img, imgErode, kernel);
	imshow("img", img);
	imshow("gray", imgGray);
	imshow("imgGaussian", imgGaussian);
	imshow("imgCanny", imgCanny);
	imshow("imgDil", imgDil);
	imshow("imgErode", imgErode);
	waitKey(0);
	return 0;
}

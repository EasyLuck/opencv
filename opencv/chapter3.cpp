#include <opencv2\imgcodecs.hpp>
#include <opencv2\imgproc.hpp>
#include <opencv2\highgui.hpp>
#include <iostream>
using namespace std;
using namespace cv;

/////////////// Resize and Crop 

//void main() {
//
//	string path = "Resources/test.png";
//	Mat img = imread(path);
//	Mat imgResize, imgCrop;
//
//	//cout << img.size() << endl;
//	resize(img, imgResize, Size(), 0.5, 0.5);
//
//	Rect roi(200, 100, 300, 300);
//	imgCrop = img(roi);
//
//	imshow("Image", img);
//	
//	imshow("Image Resize", imgResize);
//	imshow("Image Crop", imgCrop);
//	waitKey(0);
//}

int main() {
	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat imgResize, imgCrop;
	resize(img, imgResize, Size(300, 300), 0, 0);
	Rect roi(100,100,300,300);
	imgCrop = img(roi);
	imshow("img",img);
	imshow("imgResize",imgResize);
	imshow("imgCrop", imgCrop);
	waitKey(0);
	return 0;
}
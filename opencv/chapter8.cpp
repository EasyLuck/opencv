#include <opencv2/imgcodecs.hpp>
#include "opencv2/objdetect.hpp"
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

/////////////// Face Detection //////////////////////

//int main() {
//
//	string path = "Resources/test.png";
//	Mat img = imread(path);
//
//	CascadeClassifier faceCascade;
//	faceCascade.load("Resources/haarcascade_frontalface_default.xml");
//
//	if (faceCascade.empty()) { cout << "XML file not loaded"<< endl; }
//
//	vector<Rect> faces;
//	faceCascade.detectMultiScale(img, faces, 1.1, 10);
//
//	for (int i = 0; i < faces.size(); i++)
//	{
//		rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 3);
//	}
//
//	imshow("Image", img);
//	waitKey(0);
//
//	return 0;
//}

#include<opencv2\objdetect.hpp>
int main() {
	string path = "Resources/test.png";
	Mat img = imread(path);
	vector<Rect> faces;
	CascadeClassifier faceClassier;
	faceClassier.load("Resources/haarcascade_frontalface_default.xml");
	if (faceClassier.empty()) {
		cout << "no xml be loaded." << endl;
		return 1;
	}
	faceClassier.detectMultiScale(img, faces, 1.1, 10);
	for (int i = 0; i < faces.size(); i++) {
		rectangle(img, faces[i].tl(), faces[i].br(), Scalar(0, 255, 0), 3);
	}
	imshow("objdetect", img);
	waitKey(0);
	return 0;
}
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;
using namespace std;

/////////////// Project 3 ¨C License Plate Detector //////////////////////

int main() {

	Mat img;
	VideoCapture cap(0);

	CascadeClassifier plateCascade;
	plateCascade.load("Resources/haarcascade_frontalface_default.xml");

	if (plateCascade.empty()) {
		cout << "XML file not loaded" << endl; 
		return 1;
	}

	vector<Rect> plates;
	Mat imgCrop;
	while (true) {

		cap.read(img);
		plateCascade.detectMultiScale(img, plates, 1.1, 3);
		cout << plates.size() << endl;

		for (int i = 0; i < plates.size(); i++)
		{
			imgCrop = img(plates[i]);
			imshow(to_string(i), imgCrop);
			imwrite("Resources/Plates/" + to_string(i) + ".png", imgCrop);
			rectangle(img, plates[i].tl(), plates[i].br(), Scalar(255, 0, 255), 1);
		}

		imshow("Image", img);
		waitKey(1);
	}
	return 0;
}
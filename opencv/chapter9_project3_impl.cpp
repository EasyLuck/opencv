#include<iostream>
#include<opencv2\core.hpp>
#include<opencv2\highgui.hpp>
#include<opencv2\imgproc.hpp>
#include<opencv2\imgcodecs.hpp>

using namespace std;
using namespace cv;

// Document Detection

Mat imgOriginal,imgGray, imgBlur, imgCanny, imgDil, imgErode, imgWarp, imgCrop;
Mat preProcessing(Mat imgOriginal) {
	Mat img;
	cvtColor(imgOriginal, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);
	Canny(imgBlur, imgCanny, 25, 75);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDil, kernel);
	return imgDil;
}

vector<Point> getContours(Mat img) {
	vector<Point> points;
	vector <vector<Point>> contours;
	vector<Point> approxCurve;
	vector<Vec4i> hierarchy;
	int maxArea = 0;
	// find contours
	findContours(img, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	// get the four corner Rect and area>1000.
	for (int i = 0; i < contours.size(); i++) {
		int area = contourArea(contours[i]);
		if (area > 1000 && area > maxArea) {
			double peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], approxCurve,peri*0.02,true);
			if ( approxCurve.size() == 4) {
				maxArea = area;
				points = { approxCurve[0],approxCurve[1],approxCurve[2],approxCurve[3] };
			}
		}
	}
	return points;
}

vector<Point> reorder(vector<Point> points) {
	vector<Point> newPoints;
	vector<int> sumPoints, subPoints;

	for (int i = 0; i < 4; i++)
	{
		sumPoints.push_back(points[i].x + points[i].y);
		subPoints.push_back(points[i].x - points[i].y);
	}

	newPoints.push_back(points[min_element(sumPoints.begin(), sumPoints.end()) - sumPoints.begin()]); //0
	newPoints.push_back(points[max_element(subPoints.begin(), subPoints.end()) - subPoints.begin()]); //1
	newPoints.push_back(points[min_element(subPoints.begin(), subPoints.end()) - subPoints.begin()]); //2
	newPoints.push_back(points[max_element(sumPoints.begin(), sumPoints.end()) - sumPoints.begin()]); //3
	return newPoints;
}

Mat getWarp(Mat img, vector<Point> corner,float width,float height) {
	Point2f src[4] = {corner[0],corner[1],corner[2],corner[3] };
	Point2f dst[4] = { {0.f,0.f},{width,0.f},{0.f,height},{width,height}};
	Mat m = getPerspectiveTransform(src, dst);
	warpPerspective(img, imgWarp, m, Point(width,height));
	return imgWarp;
}

int main() {
	float w = 420, h = 596;
	// 1. preprocess picture.
	string path = "Resources/paper.jpg";
	imgOriginal = imread(path);
	resize(imgOriginal, imgOriginal, Size(), 0.5, 0.5);
	Mat img = preProcessing(imgOriginal);
	// 2. get contrours.
	vector<Point> points = getContours(img);
	// 3. reorder the points of corner.
	vector<Point> docPoints = reorder(points);
	// 4. warp  picture.
	Mat warpImg = getWarp(imgOriginal, docPoints,w,h);
	imshow("original", imgOriginal);
	imshow("warp", warpImg);
	// 5. Crop 
	int cropVal = 5;
	Rect roi(cropVal, cropVal, w - (2 * cropVal), h - (2 * cropVal));
	imgCrop = imgWarp(roi);
	imshow("imgCrop", imgCrop);
	waitKey(0);
	return 0;
}
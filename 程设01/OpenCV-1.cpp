#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

void main()
{
	Mat  image, grayImage;
	image = imread("G:/Pictures/Saved Pictures/photograph lr/DSC04584.jpg", IMREAD_COLOR);
	//image = imread("C:/Users/xbwei/Pictures/600x600.jpg", IMREAD_COLOR);
	cvtColor(image, grayImage, COLOR_RGB2GRAY, 0);

	namedWindow("Original Image", WINDOW_AUTOSIZE);
	imshow("Original Image", image);
	imshow("Gray Image", grayImage);

	cout << "Image Size: " << image.size << endl;
	cout << "Original Image Channels: " << image.channels() << endl;
	cout << "Gray Image Channels: " << grayImage.channels() << endl;

	waitKey(0);
}
/*-------------------- -
作者：地灯
来源：CSDN
原文：https ://blog.csdn.net/sinat_34707539/article/details/82804545 
版权声明：本文为博主原创文章，转载请附上博文链接！*/
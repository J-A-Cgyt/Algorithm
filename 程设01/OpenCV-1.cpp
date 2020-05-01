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
���ߣ��ص�
��Դ��CSDN
ԭ�ģ�https ://blog.csdn.net/sinat_34707539/article/details/82804545 
��Ȩ����������Ϊ����ԭ�����£�ת���븽�ϲ������ӣ�*/
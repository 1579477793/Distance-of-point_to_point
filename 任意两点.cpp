#include<opencv2/opencv.hpp>  
#include<opencv2/core/core.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp> 
#include<iostream>

using namespace cv;
using namespace std;

const int kvalue = 15;//˫���˲������С 
class pic
{
public:
	vector<Vec3f> circles;
	void processing(Mat &src)
	{
		resize(src, src, Size(), 0.4, 0.4);
		Mat mode(src.rows, src.cols, CV_8U, Scalar::all(0));
		Mat bf;//�ԻҶ�ͼ�����˫���˲�  
		bilateralFilter(src, bf, kvalue, kvalue * 2, kvalue / 2);
		//imshow(" ˫��", bf);


		HoughCircles(bf, circles, CV_HOUGH_GRADIENT, 1, 10, 100, 5, 0, 10);//����任���Բ  

		for (size_t i = 0; i < 7; i++)//�ѻ���任������Բ������  
		{
			Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
			int radius = cvRound(circles[i][2]);
			circle(mode, center, 0, Scalar(255, 255, 255), 1, 8, 0);
			circle(mode, center, radius, Scalar(255, 255, 255), 1, 8, 0);
			cout << i << ":" << endl;
			cout << cvRound(circles[i][0]) << "\t" << cvRound(circles[i][1]) << "\t"
				<< cvRound(circles[i][2]) << endl;//�ڿ���̨���Բ������Ͱ뾶  
			cout << "--------------------------" << endl;
			char string[25];
			_itoa(i, string, 10);
			putText(mode, string, Point((circles[i][0]), (circles[i][1])), 1, 3, Scalar(255, 255, 255));
		}
		imshow("������ȡ", mode);
	}
	void dis(int a, int b)
	{
		double dis1 = cvRound(circles[a][0]) - cvRound(circles[b][0]);
		double dis2 = cvRound(circles[a][1]) - cvRound(circles[b][1]);
		double dis = sqrt(dis1*dis1 + dis2*dis2);
		cout << "P" << a << "&" << "P" << b << "=" << dis;
	}
	void dis0()
	{
		int max_num0 = 0; //��¼���ֵ���±꣬��ʼֵ��0
		int max_num1 = 0; //��¼���ֵ���±꣬��ʼֵ��0
		int max_num2 = 0; //��¼���ֵ���±꣬��ʼֵ��0
		int max_num3 = 0; //��¼���ֵ���±꣬��ʼֵ��0
		int max_num4 = 0; //��¼���ֵ���±꣬��ʼֵ��0
		int max_num5 = 0; //��¼���ֵ���±꣬��ʼֵ��0
	
		for (int i = 0; i < 7; i++)//ȷ��0�ŵ�
		{
			Mat temp = Mat::zeros(1, 7, CV_64F);
			double dis1 = cvRound(circles[0][0]) - cvRound(circles[i][0]);
			double dis2 = cvRound(circles[0][1]) - cvRound(circles[i][1]);
			double s = sqrt(dis1*dis1 + dis2*dis2);
			double arr[7];//���峤����7������
			arr[i] = s;
			cout << arr[i] << " ";
			
			if (i==6)
			{
				for (int j = 0; j < 7; j++)
		  	 {
				if (arr[j] > arr[max_num0]) //��ǰ���������ֵ��
					 max_num0 = j;
			  }
				cout << "0���Ӧ�±���:" <<  max_num0 << " ֵΪ:" << arr[max_num0]<< endl;	
			 }		
		  }
		
		if (max_num0!=1)
		{
			
			for (int i = 0; i < 7; i++)//ȷ��1�ŵ�
			{

				Mat temp = Mat::zeros(1, 7, CV_64F);
				double dis1 = cvRound(circles[1][0]) - cvRound(circles[i][0]);
				double dis2 = cvRound(circles[1][1]) - cvRound(circles[i][1]);
				double s = sqrt(dis1*dis1 + dis2*dis2);
				double arr[7];//���峤����10������
				arr[i] = s;
				cout << arr[i] << " ";
				if (i == 6)
				{
					for (int j = 0; j < 7; j++)
					{

						if (arr[j] > arr[max_num1]) //��ǰ���������ֵ��
							max_num1 = j;
					}
					cout << "1���Ӧ�±���:" << max_num1 << " ֵΪ:" << arr[max_num1] << endl;

				}
			}
		}
		
		if ((max_num0 != 2) && (max_num1 != 2))
		{
			for (int i = 0; i < 7; i++)//ȷ��2�ŵ�
			{

				Mat temp = Mat::zeros(1, 7, CV_64F);
				double dis1 = cvRound(circles[2][0]) - cvRound(circles[i][0]);
				double dis2 = cvRound(circles[2][1]) - cvRound(circles[i][1]);
				double s = sqrt(dis1*dis1 + dis2*dis2);
				double arr[7];//���峤����10������
				arr[i] = s;
				cout << arr[i] << " ";
				if (i == 6)
				{
					for (int j = 0; j < 7; j++)
					{

						if (arr[j] > arr[max_num2]) //��ǰ���������ֵ��
							max_num2 = j;
					}
					cout << "2���Ӧ�±���:" << max_num2 << " ֵΪ:" << arr[max_num2] << endl;

				}
			}
		}

		if ((max_num0 != 3) && (max_num1 != 3)&&(max_num2!=3))
		{
			for (int i = 0; i < 7; i++)//ȷ��3�ŵ�
			{

				Mat temp = Mat::zeros(1, 7, CV_64F);
				double dis1 = cvRound(circles[3][0]) - cvRound(circles[i][0]);
				double dis2 = cvRound(circles[3][1]) - cvRound(circles[i][1]);
				double s = sqrt(dis1*dis1 + dis2*dis2);
				double arr[7];//���峤����10������
				arr[i] = s;
				cout << arr[i] << " ";
				if (i == 6)
				{
					for (int j = 0; j < 7; j++)
					{

						if (arr[j] > arr[max_num3]) //��ǰ���������ֵ��
							max_num3 = j;
					}
					cout << "3���Ӧ�±���:" << max_num3 << " ֵΪ:" << arr[max_num3] << endl;

				}
			}
		}
		
		if ((max_num0 != 4) && (max_num1 != 4) && (max_num2 != 4) && (max_num3 != 4))
		{
			for (int i = 0; i < 7; i++)//ȷ��3�ŵ�
			{

				Mat temp = Mat::zeros(1, 7, CV_64F);
				double dis1 = cvRound(circles[4][0]) - cvRound(circles[i][0]);
				double dis2 = cvRound(circles[4][1]) - cvRound(circles[i][1]);
				double s = sqrt(dis1*dis1 + dis2*dis2);
				double arr[7];//���峤����10������
				arr[i] = s;
				cout << arr[i] << " ";
				if (i == 6)
				{
					for (int j = 0; j < 7; j++)
					{

						if (arr[j] > arr[max_num4]) //��ǰ���������ֵ��
							max_num4 = j;
					}
					cout << "4���Ӧ�±���:" << max_num4 << " ֵΪ:" << arr[max_num4] << endl;

				}
			}
		}
		if ((max_num0 != 5) && (max_num1 != 5) && (max_num2 != 5) && (max_num3 != 5) && (max_num4 != 5))
		{
			for (int i = 0; i < 7; i++)//ȷ��3�ŵ�
			{

				Mat temp = Mat::zeros(1, 7, CV_64F);
				double dis1 = cvRound(circles[5][0]) - cvRound(circles[i][0]);
				double dis2 = cvRound(circles[5][1]) - cvRound(circles[i][1]);
				double s = sqrt(dis1*dis1 + dis2*dis2);
				double arr[7];//���峤����10������
				arr[i] = s;
				cout << arr[i] << " ";
				if (i == 6)
				{
					for (int j = 0; j < 7; j++)
					{

						if (arr[j] > arr[max_num4]) //��ǰ���������ֵ��
							max_num4 = j;
					}
					cout << "5���Ӧ�±���:" << max_num5 << " ֵΪ:" << arr[max_num5] << endl;

				}
			}
		}

	
		





	}

};



int main()
{
	Mat src_gray = imread("D:\\YJS\\322����\\6\\728-600-457.bmp", 0);//��ȡԭͼ  
	pic p;
	p.processing(src_gray);
	p.dis0();
	waitKey(); 
	return 0;
}

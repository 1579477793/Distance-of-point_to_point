#include<opencv2/opencv.hpp>  
#include<opencv2/core/core.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp> 
#include<iostream>
//extern int max_num0;
using namespace cv;
using namespace std;
//extern int max_num0;
const int kvalue = 15;//双边滤波邻域大小 
class pic
{
public:
	vector<Vec3f> circles;
	void processing(Mat &src)
	{
		resize(src, src, Size(), 0.4, 0.4);
		Mat mode(src.rows, src.cols, CV_8U, Scalar::all(0));
		Mat bf;//对灰度图像进行双边滤波  
		bilateralFilter(src, bf, kvalue, kvalue * 2, kvalue / 2);
		//imshow(" 双边", bf);


		HoughCircles(bf, circles, CV_HOUGH_GRADIENT, 1, 10, 100, 5, 0, 10);//霍夫变换检测圆  

		//for (size_t i = 0; i < circles.size(); i++)//把霍夫变换检测出的圆画出来  
		for (size_t i = 0; i < 7; i++)//把霍夫变换检测出的圆画出来  
		{
			Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
			int radius = cvRound(circles[i][2]);
			circle(mode, center, 0, Scalar(255, 255, 255), 1, 8, 0);
			circle(mode, center, radius, Scalar(255, 255, 255), 1, 8, 0);
			cout << i << ":" << endl;
			cout << cvRound(circles[i][0]) << "\t" << cvRound(circles[i][1]) << "\t"
				<< cvRound(circles[i][2]) << endl;//在控制台输出圆心坐标和半径  
			cout << "--------------------------" << endl;
			char string[25];
			_itoa(i, string, 10);
			putText(mode, string, Point((circles[i][0]), (circles[i][1])), 1, 3, Scalar(255, 255, 255));
		}
		imshow("特征提取", mode);
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
		int max_num[6] = { 0 };
		double arr[7] = { 0.0 };
		double M[7][7] = { 0.0 };
		int max_row;
		int max_col;
		double max =0.0;
		int n;
		for (int k = 0; k < 7;k++)
		{
			for (int i = 0; i < 7; i++)
			{
				Mat temp = Mat::zeros(1, 7, CV_64F);
				double dis1 = cvRound(circles[k][0]) - cvRound(circles[i][0]);
				double dis2 = cvRound(circles[k][1]) - cvRound(circles[i][1]);
				double s = sqrt(dis1*dis1 + dis2*dis2);
				//double arr[7];//定义长度是7的数组
				//arr[i] = s;
				M[k][i] = s;
				//cout << arr[i] << "  ";
				if (i==6)
				{
					for (n = 0; n<7; n++)
					{
						if (M[k][n] > max)
					  {
						max = M[k][n];
						max_col = n;
						
					  }
					}
					
				}
			}
			
				cout << k << "对应最大元素" << max_col << "  " << M[k][max_col] << endl;
		}
		/*for (int k = 0; k < 7; k++)
		{
		for (int i = 0; i < 7; i++)
		{
		cout << M[k][i] << " ";
		}
		cout << endl;
		}*/





		//cout << "0点对应下标是:" << num[0][0] << " 值为:" << a << endl;
		//if (max_num[0] != 1)
		//	cout << "1点对应下标是:" << max_num[1] << " 值为:" << arr[max_num[1]] << endl;
		//if ((max_num[0] != 2) && (max_num[1] != 2))
		//	cout << "2点对应下标是:" << max_num[2] << " 值为:" << arr[max_num[2]] << endl;
		//if ((max_num[0] != 3) && (max_num[1] != 3) && (max_num[2] != 3))
		//	cout << "3点对应下标是:" << max_num[3] << " 值为:" << arr[max_num[3]] << endl;
		//if ((max_num[0] != 4) && (max_num[1] != 4) && (max_num[2] != 4) && (max_num[3] != 4))
		//	cout << "4点对应下标是:" << max_num[4] << " 值为:" << arr[max_num[4]] << endl;
		//if ((max_num[0]!= 5) && (max_num[1] != 5) && (max_num[2] != 5) && (max_num[3] != 5) && (max_num[4] != 5))
		//	cout << "5点对应下标是:" << max_num[5] << " 值为:" << arr[max_num[5]] << endl;


		/*	int m, n;
			int max_col1, max_col2, max_col3, max_col4, max_col5, max_col0;

			for (n = 0; n < 7; n++)
			{
			m = 0;
			if (M[m][n] > max)
			{
			max = M[m][n];
			max_col0 = n;
			}

			}
			cout << m << "对应最大元素" << max_col0 << "  " << M[m][max_col0] << endl;

			if (max_col0!=1)
			{
			for (n = 0; n < 7; n++)
			{
			m = 1;
			if (M[m][n] > max)
			{
			max = M[m][n];
			max_col1 = n;
			}

			}
			cout << m << "对应最大元素" << max_col1 << "  " << M[m][max_col1] << endl;
			}*/

		
		



		/*


		for (int i = 0; i < 7; i++)//确定0号点
		{
			Mat temp = Mat::zeros(1, 7, CV_64F);
			double dis1 = cvRound(circles[0][0]) - cvRound(circles[i][0]);
			double dis2 = cvRound(circles[0][1]) - cvRound(circles[i][1]);
			double s = sqrt(dis1*dis1 + dis2*dis2);
			double arr[7];//定义长度是7的数组
			arr[i] = s;
			cout << arr[i] << "   ";

			if (i == 6)
			{
				for (int j = 0; j < 7; j++)
				{
					if (arr[j] > arr[max_num0]) //当前的数比最大值大
						max_num0 = j;
				}
				cout << "0点对应下标是:" << max_num0 << " 值为:" << arr[max_num0] << endl;
			}
		}

		if (max_num0 != 1)
		{

			for (int i = 0; i < 7; i++)//确定1号点
			{

				Mat temp = Mat::zeros(1, 7, CV_64F);
				double dis1 = cvRound(circles[1][0]) - cvRound(circles[i][0]);
				double dis2 = cvRound(circles[1][1]) - cvRound(circles[i][1]);
				double s = sqrt(dis1*dis1 + dis2*dis2);
				double arr[7];//定义长度是10的数组
				arr[i] = s;
				cout << arr[i] << "   ";
				if (i == 6)
				{
					for (int j = 0; j < 7; j++)
					{

						if (arr[j] > arr[max_num1]) //当前的数比最大值大
							max_num1 = j;
					}
					cout << "1点对应下标是:" << max_num1 << " 值为:" << arr[max_num1] << endl;

				}
			}
		}

		if ((max_num0 != 2) && (max_num1 != 2))
		{
			for (int i = 0; i < 7; i++)//确定2号点
			{

				Mat temp = Mat::zeros(1, 7, CV_64F);
				double dis1 = cvRound(circles[2][0]) - cvRound(circles[i][0]);
				double dis2 = cvRound(circles[2][1]) - cvRound(circles[i][1]);
				double s = sqrt(dis1*dis1 + dis2*dis2);
				double arr[7];//定义长度是10的数组
				arr[i] = s;
				cout << arr[i] << "   ";
				if (i == 6)
				{
					for (int j = 0; j < 7; j++)
					{

						if (arr[j] > arr[max_num2]) //当前的数比最大值大
							max_num2 = j;
					}
					cout << "2点对应下标是:" << max_num2 << " 值为:" << arr[max_num2] << endl;

				}
			}
		}

		if ((max_num0 != 3) && (max_num1 != 3) && (max_num2 != 3))
		{
			for (int i = 0; i < 7; i++)//确定3号点
			{

				Mat temp = Mat::zeros(1, 7, CV_64F);
				double dis1 = cvRound(circles[3][0]) - cvRound(circles[i][0]);
				double dis2 = cvRound(circles[3][1]) - cvRound(circles[i][1]);
				double s = sqrt(dis1*dis1 + dis2*dis2);
				double arr[7];//定义长度是10的数组
				arr[i] = s;
				cout << arr[i] << "   ";
				if (i == 6)
				{
					for (int j = 0; j < 7; j++)
					{

						if (arr[j] > arr[max_num3]) //当前的数比最大值大
							max_num3 = j;
					}
					cout << "3点对应下标是:" << max_num3 << " 值为:" << arr[max_num3] << endl;

				}
			}
		}

		if ((max_num0 != 4) && (max_num1 != 4) && (max_num2 != 4) && (max_num3 != 4))
		{
			for (int i = 0; i < 7; i++)//确定3号点
			{

				Mat temp = Mat::zeros(1, 7, CV_64F);
				double dis1 = cvRound(circles[4][0]) - cvRound(circles[i][0]);
				double dis2 = cvRound(circles[4][1]) - cvRound(circles[i][1]);
				double s = sqrt(dis1*dis1 + dis2*dis2);
				double arr[7];//定义长度是10的数组
				arr[i] = s;
				cout << arr[i] << "   ";
				if (i == 6)
				{
					for (int j = 0; j < 7; j++)
					{

						if (arr[j] > arr[max_num4]) //当前的数比最大值大
							max_num4 = j;
					}
					cout << "4点对应下标是:" << max_num4 << " 值为:" << arr[max_num4] << endl;

				}
			}
		}
		if ((max_num0 != 5) && (max_num1 != 5) && (max_num2 != 5) && (max_num3 != 5) && (max_num4 != 5))
		{
			for (int i = 0; i < 7; i++)//确定3号点
			{

				Mat temp = Mat::zeros(1, 7, CV_64F);
				double dis1 = cvRound(circles[5][0]) - cvRound(circles[i][0]);
				double dis2 = cvRound(circles[5][1]) - cvRound(circles[i][1]);
				double s = sqrt(dis1*dis1 + dis2*dis2);
				double arr[7];//定义长度是10的数组
				arr[i] = s;
				cout << arr[i] << "   ";
				if (i == 6)
				{
					for (int j = 0; j < 7; j++)
					{

						if (arr[j] > arr[max_num4]) //当前的数比最大值大
							max_num4 = j;
					}
					cout << "5点对应下标是:" << max_num5 << " 值为:" << arr[max_num5] << endl;

				}
			}
		}





		*/


	}

};



int main()
{
	Mat src_gray = imread("D:\\YJS\\322曲率\\3\\560-309-308.bmp", 0);//读取原图  
	pic p;
	p.processing(src_gray);
	//p.dis0();
	waitKey();
	return 0;
}

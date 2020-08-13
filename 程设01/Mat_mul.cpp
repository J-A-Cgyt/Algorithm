#include <iostream>
#include <stdlib.h>
#include <stdio.h>

class matrix_cgyt
{  //到目前为止，无法完成向量剖分 不过基本的思路算是已经实现了，有空再完善吧 20200811
public:
	int rows;
	int cols;
	double* data;

	matrix_cgyt(int rows, int cols, double* data)
	{
		this->cols = cols;
		this->rows = rows;
		this->data = data;
	}

	void Mat_mul(matrix_cgyt m1, matrix_cgyt m2, matrix_cgyt res)  //矩阵乘法
	{
		//res的data*需要在函数外赋值
		res.cols = m2.cols;
		res.rows = m1.rows;
		if (m1.cols * m1.rows == 1 & m2.cols * m2.rows == 1)
		{
			res.data[0] = m1.data[0] * m2.data[0];
			//std::cout << res.data[0]<<' ';
		}
		else
		{
		//先剖分 矩阵1
			int colsH_Left = m1.cols / 2;  int colsH_Right = m1.cols - colsH_Left;
			int rowsH_Top = m1.rows / 2;    int rowsH_Button = m1.rows - rowsH_Top;
			int numbers = colsH_Left * rowsH_Top;
			int numbers_2 = colsH_Right * rowsH_Top;
			int numbers_3 = colsH_Left * rowsH_Button;
			int numbers_4 = colsH_Right * rowsH_Button;

			//创建子矩阵 A for m1
			double* subdataA11 = (double*)malloc(sizeof(double)*numbers);
			matrix_cgyt subA11 = matrix_cgyt(rowsH_Top, colsH_Left, subdataA11);

			double* subdataA12 = (double*)malloc(sizeof(double)*numbers_2);
			matrix_cgyt subA12 = matrix_cgyt(rowsH_Top, colsH_Right, subdataA12);

			double* subdataA21 = (double*)malloc(sizeof(double)*numbers_3);
			matrix_cgyt subA21 = matrix_cgyt(rowsH_Button, colsH_Left, subdataA21);

			double* subdataA22 = (double*)malloc(sizeof(double)*numbers_4);
			matrix_cgyt subA22 = matrix_cgyt(rowsH_Button, colsH_Right, subdataA22);
		
			int subIdx11 = 0;
			int subIdx12 = 0;
			int subIdx21 = 0;
			int subIdx22 = 0;

			for (int i = 0; i < (m1.cols * m1.rows); i++)
			{
				if (i%m1.cols < m1.cols / 2)
				{
					if (i < numbers + numbers_2)
					{
						subA11.data[subIdx11] = m1.data[i];
						//std::cout<< m1.data[i];
						//std::cout << subA11.data[subIdx11] << " ";
						subIdx11 = subIdx11 + 1;
					}
					else
					{
						subA21.data[subIdx21] = m1.data[i];
						//std::cout<< m1.data[i];
						subIdx21 = subIdx21 + 1;
					}
				}
				else if (i%m1.cols >= m1.cols / 2)
				{
					if (i < numbers + numbers_3)
					{
						subA12.data[subIdx12] = m1.data[i];
						//std::cout<< m1.data[i];
						subIdx12 = subIdx12 + 1;
					}
					else
					{
						subA22.data[subIdx22] = m1.data[i];
						//std::cout<< m1.data[i];
						subIdx22 = subIdx22 + 1;
					}
				}
			}
			outMat(subA11); outMat(subA12); outMat(subA21); outMat(subA22);

			//创建子矩阵 B for m2
			int colsH = m1.cols / 2;
			int rowsH = m1.rows / 2;
			numbers = colsH * rowsH;

			double* subdataB11 = (double*)malloc(sizeof(double)*numbers);
			matrix_cgyt subB11 = matrix_cgyt(rowsH, colsH, subdataB11);

			double* subdataB12 = (double*)malloc(sizeof(double)*numbers);
			matrix_cgyt subB12 = matrix_cgyt(rowsH, colsH, subdataB12);

			double* subdataB21 = (double*)malloc(sizeof(double)*numbers);
			matrix_cgyt subB21 = matrix_cgyt(rowsH, colsH, subdataB21);

			double* subdataB22 = (double*)malloc(sizeof(double)*numbers);
			matrix_cgyt subB22 = matrix_cgyt(rowsH, colsH, subdataB22);
				
			subIdx11 = 0;
			subIdx12 = 0;
			subIdx21 = 0;
			subIdx22 = 0;
			
			for (int i = 0; i < (numbers * 4); i++)
			{

				if (i%m2.cols < m2.cols / 2)
				{
					if (i < numbers * 2)
					{
						subB11.data[subIdx11] = m2.data[i];
						//std::cout<< m2.data[i];
						subIdx11 = subIdx11 + 1;
					}
					else
					{
						subB21.data[subIdx21] = m2.data[i];
						//std::cout<< m2.data[i];
						subIdx21 = subIdx21 + 1;
					}
				}
				else if (i%m2.cols >= m2.cols / 2)
				{
					if (i < numbers * 2)
					{
						subB12.data[subIdx12] = m2.data[i];
						//std::cout<< m2.data[i];
						subIdx12 = subIdx12 + 1;
					}
					else
					{
						subB22.data[subIdx22] = m2.data[i];
						//std::cout << m2.data[i];
						subIdx22 = subIdx22 + 1;
					}
				}
			}
			//outMat(subB11); outMat(subB12); outMat(subB21); outMat(subB22);

		//分组矩阵乘法
			//临时变量
			double* dataTA = (double*)malloc(sizeof(double) * res.cols * res.rows / 4);
			matrix_cgyt tempA = matrix_cgyt(res.rows / 2, res.cols / 2, dataTA);
			double* dataTB = (double*)malloc(sizeof(double) * res.cols * res.rows / 4);
			matrix_cgyt tempB = matrix_cgyt(res.rows / 2, res.cols / 2, dataTB);

			//结果子矩阵

			//计算过程
			double* dataC11 = (double*)malloc(sizeof(double) * res.cols * res.rows / 4);
			matrix_cgyt C11 = matrix_cgyt(res.rows / 2, res.cols / 2, dataC11);
			Mat_mul(subA11, subB11, tempA);
			Mat_mul(subA12, subB21, tempB);
			Mat_add(tempA, tempB, C11);

			double* dataC12 = (double*)malloc(sizeof(double) * res.cols * res.rows / 4);
			matrix_cgyt C12 = matrix_cgyt(res.rows / 2, res.cols / 2, dataC12);
			Mat_mul(subA11, subB12, tempA);
			Mat_mul(subA12, subB22, tempB);
			Mat_add(tempA, tempB, C12);

			double* dataC21 = (double*)malloc(sizeof(double) * res.cols * res.rows / 4);
			matrix_cgyt C21 = matrix_cgyt(res.rows / 2, res.cols / 2, dataC21);
			Mat_mul(subA21, subB11, tempA);
			Mat_mul(subA22, subB21, tempB);
			Mat_add(tempA, tempB, C21);

			double* dataC22 = (double*)malloc(sizeof(double) * res.cols * res.rows / 4);
			matrix_cgyt C22 = matrix_cgyt(res.rows / 2, res.cols / 2, dataC22);
			Mat_mul(subA21, subB12, tempA);
			Mat_mul(subA22, subB22, tempB);
			Mat_add(tempA, tempB, C22);
			
			Mat_merge(res, C11, C12, C21, C22);
		}
	}

	void Mat_add(matrix_cgyt m1, matrix_cgyt m2, matrix_cgyt res)  //矩阵求和
	{
		if (m1.cols == m2.cols & m2.rows == m1.rows)
		{
			int number = m1.cols * m1.rows;
			for (int i = 0; i < number; i++)
			{
				res.data[i] = m1.data[i] + m2.data[i];
			}
		}
		else
		{
			printf("矩阵维数必须相等");
		}
	}

	void Mat_merge(matrix_cgyt res,
		matrix_cgyt m11, matrix_cgyt m12,
		matrix_cgyt m21, matrix_cgyt m22
		)  //矩阵拼装 拼装仅针对方阵结果
	{
		int numbers = m11.cols * m11.rows;			
		
		int subIdx11 = 0;
		int subIdx12 = 0;
		int subIdx21 = 0;
		int subIdx22 = 0;
		
		for (int i = 0; i < (numbers * 4); i++)
		{

			if (i%res.cols < res.cols / 2)
			{
				if (i < numbers * 2)
				{
					res.data[i] = m11.data[subIdx11];
					//std::cout<< m1.data[i];
					subIdx11 = subIdx11 + 1;
				}
				else
				{
					res.data[i] = m21.data[subIdx21];
					//std::cout<< m1.data[i];
					subIdx21 = subIdx21 + 1;
				}
			}
			else if (i%res.cols >= res.cols / 2)
			{
				if (i < numbers * 2)
				{
					res.data[i] = m12.data[subIdx12];
					//std::cout<< m1.data[i];
					subIdx12 = subIdx12 + 1;
				}
				else
				{
					res.data[i] = m22.data[subIdx22];
					//std::cout << m1.data[i];
					subIdx22 = subIdx22 + 1;
				}
			}
		}
	}


	void outMat(matrix_cgyt C)
	{
		printf("\n");

		for (int i = 0; i < C.cols * C.rows; i++)
		{
			std::cout << C.data[i] << " ";
			if ((i + 1) % C.cols == 0)
			{
				printf("\n");
			}
		}

	}
};

//double dataA[4] = {1, 2, 3, 4 };
//double dataB[4] = {3, 2, 1, 4 };
double dataA[16] = {1, 2, 3, 4, 
					5, 6, 7, 8, 
					9,10,11,12, 
				   13,14,15,16};

double dataB[16] = {1, 0, 1, 0, 
					0, 1, 0, 0, 
					0, 0, 1, 0,  
					0, 3, 0, 1};

int main()
{
	matrix_cgyt A = matrix_cgyt(3, 3, dataA);
	matrix_cgyt B = matrix_cgyt(3, 3, dataB);

	double* dataC = (double*)std::malloc(sizeof(double) * B.cols * A.rows);

	matrix_cgyt C = matrix_cgyt(A.rows, B.cols, dataC);

	C.Mat_mul(A, B, C);

	printf("\n");

	for (int i = 0; i < C.cols * C.rows; i++)
	{
		std::cout << C.data[i] << " ";
		if ((i + 1) % C.cols == 0)
		{
			printf("\n");
		}
	}

	return 0;
}


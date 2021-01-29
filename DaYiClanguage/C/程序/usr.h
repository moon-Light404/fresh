#include <iostream>
#include <string>
using namespace std;

/********* Begin *********/
class Matrix
{
	//矩阵类的声明
    private:
	int row;
	int coal;
	int p[10][10];

	public:
	Matrix(int r,int c);
	void Fill(int value);
	void Set(int r,int c,int value);
	void Print();
	int Get(int  r,int c);
	

    friend Matrix operator+(Matrix &m1,Matrix &m2);
	friend Matrix operator-(Matrix &m1,Matrix &m2);
	friend Matrix operator*(Matrix &m1,Matrix &m2);
    
};
//矩阵类的定义
 Matrix::Matrix(int r,int c):row(r),coal(c){

}

void Matrix::Fill(int value)
{
	for(int i=0;i<row;i++)
	for(int j=0;j<coal;j++)
	{
		p[i][j]=value;
	}
}
void Matrix::Set(int r,int c,int value)
{
	p[r][c]=value;
}

void Matrix::Print()
{
	for(int i=0;i<row;i++){
	
	for(int j=0;j<coal;j++)
		{
		  cout<<p[i][j]<<" ";
		}
		cout<<endl;
       } 
}

int Matrix::Get(int r,int c)
{
	return p[r][c];
}
Matrix operator+(Matrix& m1,Matrix &m2)
{
    //实现矩阵加法
    Matrix d(m1.row,m2.coal);
	for(int i=0;i<m1.row;i++)
	{
	for(int j=0;i<m1.coal;j++)
	{
	d.p[i][j]=m1.p[i][j]+m2.p[i][j];
    }
    }
    return d;
    
}

Matrix operator-(Matrix& m1,Matrix &m2)
{
    //实现矩阵减法
     Matrix d(m1.row,m2.coal);
    for(int i=0;i<m1.row;i++)
    {
	for(int j=0;i<m1.coal;j++)
	{
	d.p[i][j]=m1.p[i][j]-m2.p[i][j];
    }
    }
    return d;
    
}

Matrix operator*(Matrix& m1,Matrix &m2)
{
    //实现矩阵乘法
    Matrix d(m1.row,m2.coal);
	for(int i=0;i<m1.row;i++)
	{
	for(int j=0;j<m1.coal;j++)
	{
	for(int k=0;k<m1.coal;k++)
	{
	d.p[i][j]+=m1.p[i][k]*m2.p[k][j];
	}
	}
	}
    return d;
    
}
/********* End *********/

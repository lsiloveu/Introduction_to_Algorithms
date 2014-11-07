/**********************************************************************
���Ŷ���������������������ۣ�����װ��

	������double OptimalBST(double *p, double *q, int n)
	���ã��������Ŷ�����������������۲�������Ŷ��������
		ʱ�临�Ӷȣ�O(n^3)
		�ռ临�Ӷȣ�O(n^2)

���Ŷ���������������������ۣ���δ��װ��

	������double OptimalBST(double *p, double *q, int n, double **e, int **root)
	���ã��������Ŷ������������������
		ʱ�临�Ӷȣ�O(n^3)
		�ռ临�Ӷȣ�O(n^2)

��ӡ���Ŷ����������(δ��װ)

	������void PrintOptimalBST(int first, int last, int **root)
	���ã�	������Ŷ��������
	ʱ�临�Ӷȣ�O(n)
	�ռ临�Ӷȣ�O(n^2)
************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define Inf 0x7fffffff
/**********************************************************************
���Ŷ���������������������ۣ�(δ��װ)

	������double OptimalBST(double *p, double *q, int n, double **e, int **root)
		p:		�ؼ������У�k1,k2����kn)��Ӧ�ĸ�������
		q:		�������d0,d1����dn����Ӧ�ĸ�������
		n:		����������Ľڵ���
		e:		���ڴ���������������������
		root:	��¼�����ؼ���ki,ki+1����kn�������ĸ�
	����ֵ��	�������Ŷ������������������
	��ӡֵ��	��
	ʱ�临�Ӷȣ�O(n^3)
	�ռ临�Ӷȣ�O(n^2)
************************************************************************/
double Find_OptimalBST(double *p, double *q, int n, double **e, int **root)
{
	int i, j, l ,r;
	double Min;

	double **w = (double **) malloc( sizeof(double *) * (n + 2));
	for( i = 0; i <= n + 1; i++)
		w[i] = (double *) malloc(sizeof(double) * (n + 1));
	for( i = 0; i <= n + 1; i++)
		for( j = 0; j <= n; j++)
			w[i][j] = 0;
	
	for( i = 1; i <= n + 1; i++)
	{
		e[i][i-1] = q[i-1];
		w[i][i-1] = q[i-1];
	}

	for(l = 1; l <= n; l++)
		for(i = 1; i <= n - l +1; i++)
		{
			j = i + l -1;
			e[i][j] = Inf;
			w[i][j] = w[i][j-1] + p[j] + q[j];
			for( r = i; r <= j; r++)
			{
				Min = e[i][r-1] + e[r+1][j] + w[i][j];
				if( Min <e[i][j])
				{
					e[i][j] = Min;
					root[i][j] = r;
				}
			}
		}

		return e[1][n];
}

/**********************************************************************
��ӡ���Ŷ����������(δ��װ)

	������void PrintOptimalBST(int first, int last, int **root)
		first:		��ʼ�ڵ����
		last:		���ڵ����
		root:	��¼�����ؼ���ki,ki+1����kn�������ĸ�
	����ֵ��	��
	��ӡֵ��	������Ŷ��������
	ʱ�临�Ӷȣ�O(n)
	�ռ临�Ӷȣ�O(n^2)
************************************************************************/
void PrintOptimalBST(int first, int last, int **root)
{
	if( first > last)
		return;
	//�������
	printf("%d ", root[first][last]);
	PrintOptimalBST(first,root[first][last] - 1, root);
	PrintOptimalBST(root[first][last] + 1, last, root);
	/*
	//ǰ�����
	PrintOptimalBST(first,root[first][last] - 1, root);
	printf("%d ", root[first][last]);
	PrintOptimalBST(root[first][last] + 1, last, root);

	//�������
	
	PrintOptimalBST(first,root[first][last] - 1, root);
	PrintOptimalBST(root[first][last] + 1, last, root);
	printf("%d ", root[first][last]);
	*/
	
}
/**********************************************************************
���Ŷ���������������������ۣ�����װ��

	������double OptimalBST(double *p, double *q, int n)
		p:		�ؼ������У�k1,k2����kn)��Ӧ�ĸ�������
		q:		�������d0,d1����dn����Ӧ�ĸ�������
		n:		����������Ľڵ���

	����ֵ��	�������Ŷ������������������
	��ӡֵ��	��
	ʱ�临�Ӷȣ�O(n^3)
	�ռ临�Ӷȣ�O(n^2)
************************************************************************/
double OptimalBST(double *p, double *q, int n)
{
	int i, j;
	double E_T;
	int **root = (int **) malloc( sizeof(int *) * (n + 2));
	double **e = (double **) malloc( sizeof(double *) * (n + 2));

	for( i = 0; i <= n + 1; i++)
	{
		e[i] = (double *) malloc(sizeof(double) * (n + 1));
		root[i] = (int *) malloc(sizeof(int) * (n + 1));
	}
	for( i = 0; i <= n + 1; i++)
		for( j = 0; j <= n; j++)
		{
			e[i][j] = 0;
			root[i][j] = 0;
		}
	E_T = Find_OptimalBST(p, q, n, e, root);
	PrintOptimalBST(1, n, root);
	printf("\n");
	return E_T;
}
		
		
int main()
{
	double p[6] = {0,0.15, 0.10, 0.05, 0.10, 0.20};
	double q[6] = {0.05, 0.10, 0.05, 0.05, 0.05, 0.10};
	double E;	
	E = OptimalBST(p, q, 5);
	printf("%f\n", E);
	system("pause");
	return 0;
}
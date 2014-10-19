/**********************************************************************
�������˷���(δ��װ)

	������void MatrixChainOrder(int *p, int n, int **m, int **s)
	���ã�����������˷���˵���С����	
		ʱ�临�Ӷȣ�O(n^3)
		�ռ临�Ӷȣ�O(n^2)

����������˷�����С������(δ��װ)
	������void PrintOptimalPapens( int **s, int i, int j)
	���ã���ӡ�������������˵�	
	**	ʱ�临�Ӷȣ�O(n)
		�ռ临�Ӷȣ�O(n^2)

�������˷���(��װ)
	������void MaxtrixOrder(int *p, int n)
	���ã���ӡ�������������˵�;��ӡ������˵���С����
		ʱ�临�Ӷȣ�O(n^3)
		�ռ临�Ӷȣ�O(n^2)
************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define Inf 0x7fffffff
/**********************************************************************
�������˷���(δ��װ)

	������void MatrixChainOrder(int *p, int n, int **m, int **s)
		p:	n�������ά����ɵ�����p[n+1]ά
		n:	�������
		m��	������˵���С����
		s:	�������mʱȡ�õ����Ŵ��۴���k��ֵ
	����ֵ��	��
	��ӡֵ��	��
	ʱ�临�Ӷȣ�O(n^3)
	�ռ临�Ӷȣ�O(n^2)
************************************************************************/
void MatrixChainOrder(int *p, int n, int **m, int **s)
{
	int i, j, l, k, q;
	for( i = 1; i <= n; i++)
  		m[i][i] = 0;
	for( l = 2; l <= n; l++)
		for(i = 1; i <= n - l + 1; i++)
		{
			j = i + l - 1;
			m[i][j] = Inf;
			
			for( k = i; k < j ; k ++)
			{
				q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
				if( q < m[i][j])
				{
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
}
/**********************************************************************
����������˷�����С������(δ��װ)

	������void PrintOptimalPapens( int **s, int i, int j)
		s:	�������mʱȡ�õ����Ŵ��۴���k��ֵ
		i:	��i�������������
		j:	��j�������������
	����ֵ��	��
	��ӡֵ��	��ӡ�������������˵�
**	ʱ�临�Ӷȣ�O(n)
	�ռ临�Ӷȣ�O(n^2)
************************************************************************/
void PrintOptimalPapens( int **s, int i, int j)
{
	if( i == j )
		printf("A%d", i);
	else
	{
		printf("(");
		PrintOptimalPapens(s, i, s[i][j]);
		PrintOptimalPapens(s, s[i][j]+1, j);
		printf(")");
	}
}

/**********************************************************************
�������˷���(��װ)

	������void MaxtrixOrder(int *p, int n)
		p:	n�������ά����ɵ�����p[n+1]ά
		n:	�������	
	����ֵ��	��
	��ӡֵ��	��ӡ�������������˵�;��ӡ������˵���С����
**	ʱ�临�Ӷȣ�O(n)
	�ռ临�Ӷȣ�O(n^2)
************************************************************************/
void MaxtrixOrder(int *p, int n)
{
	int i, j;
	int **m = (int **) malloc(sizeof(int *) * (n + 1));
	int **s = (int **) malloc(sizeof(int *) * (n + 1));
	for( i = 0; i < n + 1; i++)
	{
		m[i] = (int *) malloc(sizeof(int) * (n + 1));
		s[i] = (int *) malloc(sizeof(int) * (n + 1));
	}
	for( i = 0; i < n + 1; i++)
		for( j = 0; j < n + 1; j++)
		{
			m[i][j] = 0;
			s[i][j] = 0;
		}
	MatrixChainOrder(p, n, m, s);
	PrintOptimalPapens(s, 1, n);
	printf("\n%d\n",m[1][n]);
}
int main()
{
	int p[] = {30,35,15,5,10,20,25};
	MaxtrixOrder(p,6);//������1*n+1ά�ģ����������n
	system("pause");
	return 0;
}
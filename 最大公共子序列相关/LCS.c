/**********************************************************************
��󹫹�������(����������

	������int Lcs_length( char *str1, char *str2, int **c, int **b)
	���ã�������󹫹������г���	
		ʱ�临�Ӷȣ�O(mn)
		�ռ临�Ӷȣ�O(mn)

	������void Print_Lcs( char *str, int **b, int i, int j)
	���ã������󹫹�������
		�����󹫹������У�
		ʱ�临�Ӷȣ�O(m+n)
		�ռ临�Ӷȣ�O(mn)

	������void Find_Lcs( char *str1, char *str2)
	���ã������󹫹������м��䳤�ȣ�
		ʱ�临�Ӷȣ��������󻨷���O(MN)��ʱ�䣬����ʱ������O��M+N)��ʱ�䣬����������ջ�����O(MN)��ʱ�䡣
		�ռ临�Ӷȣ��������󻨷���O(MN)�Ŀռ䣬��Ǻ���Ҳ������O(MN)�Ŀռ䣬����������ջ�����O(MN)�Ŀռ䡣

��󹫹��Ӵ���������

	������void Find_conLCS( char *str1, char *str2) 
	���ã������󹫹��Ӵ������ȣ�	
		ʱ�临�Ӷȣ�O(mn)
		�ռ临�Ӷȣ�O(mn)

	������void Find_conLCS1( char *longstr, char *shortstr)
	���ã��Ľ���ĺ����������󹫹��Ӵ����䳤��
		ʱ�临�Ӷȣ�O(mn)
		�ռ临�Ӷȣ�O(len(shortstr))

�����������У�
	������int Find_LIS( int *Array, int len)
	���ã����������������г��ȣ����ö�̬�滮˼�룩
		ʱ�临�Ӷȣ�O(n^2)
		�ռ临�Ӷȣ�O(n)

	������int BinSearch( int *Array, int len, int num)�����޸ĵĶ��ֲ��ң�
	���ã�����num��Ҫ�����λ�ã����ڴ����������һ��С�ڻ���������Ԫ�أ���ֱ�ӷ���low��
		ʱ�临�Ӷȣ�O(lgn)
		�ռ临�Ӷȣ�O(n)

	������int Find_LIS1( int *Array, int len)
	���ã����������������г��ȣ����ö��ֲ��ң�
		ʱ�临�Ӷȣ�O(nlgn)
		�ռ临�Ӷȣ�O(n)
************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EQUAL	1	//EQUAL��ʾc[i][j]����c[i-1][j-1]+1����=====��ʱ������������ͬ���ַ�
#define UP		2	//UP��ʾc[i][j]����c[i-1][j]����============��ʱ��������û����ͬ���ַ�
#define LEFT	3	//LEFT��ʾc[i][j]����[ci][j-1]����==========��ʱ��������û����ͬ���ַ�


/**************************************************************
������int Lcs_length( char *str1, char *str2, int **c, int **b)
���룺	str1:	���Ƚ��ַ���1
		str2:	���Ƚ��ַ���2
		**c:	������󹫹������г���
		**b:	������󹫹������м���·��

����ֵ��str1��str2��󹫹�������
ʱ�临�Ӷȣ�O(mn)
�ռ临�Ӷȣ�O(mn)
***************************************************************/
int Lcs_length( char *str1, char *str2, int **c, int **b)
{
	int len1 = strlen(str1),
		len2 = strlen(str2);
	int i,j;
	for( i = 1; i <= len1; i++)
		c[i][0] = 0;
	for ( j = 0; j <= len2; j++)
		c[0][j] = 0;
	for(  i = 1; i <= len1; i++)
		for( j = 1; j <= len2; j++)
		{	
			/*******************************
			ʹ��i-1��j-1
			�㷨��������д���ǱȽ�str1[i]��str[j]�������㷨�������ϵ����������±�����1��ʼ��
			����ʹ��i-1�Լ�j-1������������±��0��ʼ
			********************************/
			if( str1[i-1] == str2[j-1] )											
			{
				c[i][j] = c[i-1][j-1] + 1;
				b[i][j] = EQUAL; 
			}
			else if (c[i-1][j] >= c[i][j-1])
				{
					c[i][j] = c[i-1][j];
					b[i][j] = UP;
				}
			else 
				{
					c[i][j] = c[i][j-1];
					b[i][j] = LEFT;
				}
		}
		return c[len1][len2];
}

/**************************************************************
������void Print_Lcs( char *str, int **b, int i, int j
		str:	���Ƚ��ַ���1
		**b:	������󹫹������м���·��
		i:		���Ƚ��ַ���1�ĳ���
		j:		���Ƚ��ַ���2�ĳ���

����ֵ����
��ӡֵ������ַ���1���ַ���2�������������
ʱ�临�Ӷȣ�O(m+n)
�ռ临�Ӷȣ�O(m+n)
***************************************************************/
void Print_Lcs( char *str, int **b, int i, int j)
{
	if( i == 0 || j == 0)
		return;
	if( b[i][j] == EQUAL)
	{
		Print_Lcs(str, b, i - 1, j - 1);
		printf("%c ", str[i-1]);
	}
	else if ( b[i][j] == UP )
		Print_Lcs(str, b, i - 1, j);
	else 
		Print_Lcs(str, b, i , j - 1);
}

/**************************************************************
������void Find_Lcs( char *str1, char *str2)
		str1:	���Ƚ��ַ���1
		str2:	���Ƚ��ַ���2
����ֵ����
��ӡֵ�������󹫹������г����Լ���󹫹�������
ʱ�临�Ӷȣ�O(mn)
�ռ临�Ӷȣ�O(mn)
***************************************************************/
void Find_Lcs( char *str1, char *str2)
{
	int i,j,length;
	int len1 = strlen(str1),
		len2 = strlen(str2);
	//�����ά����
	int **c = (int **)malloc(sizeof(int*) * (len1 + 1));
	int **b = (int **)malloc(sizeof(int*) * (len1 + 1));
	for( i = 0; i<= len1; i++ )	////����Ⱥ�֮ǰû�ӣ������ڴ�й©
	{
		c[i] = (int *)malloc(sizeof(int) * (len2 + 1));
		b[i] = (int *)malloc(sizeof(int) * (len2 + 1));
	}

	//��c[len1][len2]��b[len1][len2]��ʼ��Ϊ0
	for ( i = 0; i<= len1; i++)
		for( j = 0; j <= len2; j++)
		{
			c[i][j] = 0;
			b[i][j] = 0;
		}
	
	//����LCS�ĳ���
	length = Lcs_length(str1, str2, c, b);
	printf("The number of the Longest-Common-Subsequence is %d\n", length);
	
	//��������b����������
	printf("The Longest-Common-Subsequence is: ");
	Print_Lcs(str1, b, len1, len2);
	printf("\n");

	//��̬�ڴ��ͷ�
	for ( i = 0; i <= len1; i++)
	{
		free(c[i]);
		free(b[i]);
	}
	free(c);
	free(b);
}

/**************************************************************
������void Find_conLCS( char *str1, char *str2)
		str1:	���Ƚ��ַ���1
		str2:	���Ƚ��ַ���2
����ֵ����
��ӡֵ�������󹫹��Ӵ������Լ���󹫹��Ӵ�
ʱ�临�Ӷȣ�O(mn)
�ռ临�Ӷȣ�O(mn)
***************************************************************/
void Find_conLCS( char *str1, char *str2)
{
	int i,j;
	int len = 0, end = -1, start = 0;
	int len1 = strlen(str1),
		len2 = strlen(str2);

	int **c = (int **)malloc(sizeof(int *) * (len1 + 1));
	for( i = 0; i <= len1; i++ )
		c[i] = (int *)malloc(sizeof(int) * (len2 + 1));
	
	for( i = 0; i <= len1; i++ )	//�������Ҫ�Ѷ�̬����Ķ�λ�������㣬�������bug
		for( j = 0; j <= len2; j++ )
			c[i][j] = 0;

	for( i = 1; i <= len1; i++ )
		for( j = 1; j <= len2; j++ )
		{
			if( str1[i-1] == str2[j-1])
				c[i][j] = c[i-1][j-1] + 1;
			if( c[i][j] > len)
			{
				len = c[i][j];
				end = j;
			}
		}
	start = end - len + 1;
	printf("The number of Longest of continuous subsequence is : %d\n", len);
	printf("The longest of continuous subsequence is :");
	for( j = start; j <= end; j++)
		printf("%c ", str2[j-1]);
	printf("\n");

	for( i = 0; i <= len1; i++ )
		free(c[i]);
	free(c);
}

/**************************************************************
������void Find_conLCS1( char *longstr, char *shortstr)
		longstr:	���Ƚ��ַ���1
		shotrstr:	���Ƚ��ַ���2
����ֵ����
��ӡֵ�������󹫹��Ӵ������Լ���󹫹��Ӵ�
ʱ�临�Ӷȣ�O(mn)
�ռ临�Ӷȣ�O(len(shortstr))
***************************************************************/
void Find_conLCS1( char *longstr, char *shortstr)
{
	int i, j;
	int len1 = strlen(longstr),
		len2 = strlen(shortstr);
	int len = 0, end = -1, start;

	int *c = (int *)malloc(sizeof(int) * (len2 + 1));
	
	for( i = 0; i <= len2; i++ )
		c[i] = 0;
	
	for( i = 0; i <= len1; i++)
		for( j = len2-1; j >= 0; j--)	//������Ҫ���ŶԱȣ�������һ�е�c[j-1]��ֵ�ᱻ����
		{
			if( longstr[i] == shortstr[j])
			{
				if( i == 0 || j == 0 )
					c[j] = 1;
				else c[j] = c[j-1] +1;
			}
			else c[j] = 0;
		
			if( c[j] > len)
			{
				len = c[j];
				end = j;
			}
		}

	start = end - len + 1;
	printf("The number of Longest of substring is : %d\n", len);
	printf("The longest of continuous subsequence is :");
	for( i = start; i <= end; i++ )
		printf("%c ", shortstr[i]);
	printf("\n");

	free(c);
}

/**************************************************************
������int Find_LIS( int *Array, int len)
		array:	������������
		len:	���������еĳ���
����ֵ�������������г���
��ӡֵ����������������м��䳤��
ʱ�临�Ӷȣ�O(n^2)
�ռ临�Ӷȣ�O(n)

���������int arr2[]={-1,2,4,3,4,5,6,1,2,3,4,5,6,7,-7};
    		int n2=15;
���ǻ���ִ��󣬴����
int Find_LIS( int *Array, int len)
{
	int i,j;
	int count = 1, last = -1;
	int *lis = (int *)malloc(sizeof(int) * len);
	int *index = (int *)malloc(sizeof(int) * len);

	for( i = 0; i < len; i++)
	{
		lis[i] = 1;
		index[i] = 0;
	}

	for(i = 1; i < len; i++)
		for(j = 0; j < i; j++)
		{
			if( Array[i] > Array[j] && lis[j] + 1 >= lis[i])//�������������һ���ǵ�ǰ�������������
			{
				lis[i] = lis[j] + 1;
				if( lis[i] > count)	//�����ӵ�
				{
					index[lis[j] - 1] = j; //���ڲ��������������У�lis[j]-1��ԭ���ǣ����������±�ʱ��Ҫ��1����1��ʼ��count��
					count = lis[j];
					last = i;	//��¼������������е�����Ǹ�ֵ  ������ֵ
				}
			}		
		}

	index[count++] = last;
	for(i = 0; i < len; i++)
		printf("%d ", lis[i]);
	printf("\n");
	for( i = 0; i< count; i++)
		printf("%d ", index[i]);
	
	printf("������������Ϊ��");
	for( i = 0;i < count; i++)
		printf("%d ", Array[index[i]]);
	printf("\n");

	free(lis);
	free(index);
	return count;
}
***************************************************************/


/**************************************************************
������int Find_LIS( int *Array, int len)
		array:	������������
		len:	���������еĳ���
����ֵ�������������г���
��ӡֵ����������������г���
ʱ�临�Ӷȣ�O(n^2)
�ռ临�Ӷȣ�O(n)
***************************************************************/
int Find_LIS( int *Array, int len)
{
	int i, j, maxlen = 0;
	int *lis = (int *)malloc(sizeof(int) * len);
	
	for(i = 0; i < len; i++)
	{
		lis[i] = 1;
		for(j = 0; j < i; j++)
		{
			if( Array[i] > Array[j] && lis[j] + 1 > lis[i])//�������������һ���ǵ�ǰ�������������
				lis[i] = lis[j] + 1;
		}
		if( lis[i] > maxlen)
			maxlen = lis[i];
	}
	return maxlen;
}

/**************************************************************
������int BinSearch( int *Array, int len, int num)
		Array:	���������������
		len:	��������ĳ���
		num:	�����������
����ֵ��������Ҫ�����λ��
��ӡֵ����
ʱ�临�Ӷȣ�O(lg N)
�ռ临�Ӷȣ�O(n)
***************************************************************/
int BinSearch( int *Array, int len, int num)
{
	int low = 0, high = len - 1, mid;
	
	while(low <= high)
	{
		mid = low + ( high - low ) / 2;
		if(num == Array[mid])
			return mid;
		else if( num < Array[mid])
			high = mid - 1;
		else low = mid + 1;	
	}
	return low;
}

/**************************************************************
������int Find_LIS1( int *Array, int len)
		array:	������������
		len:	���������еĳ���
����ֵ�������������г���
��ӡֵ����������������г���
ʱ�临�Ӷȣ�O(nlgn)
�ռ临�Ӷȣ�O(n)
***************************************************************/
int Find_LIS1(int *Array, int len)
{
	int i, nMax = 0, pos;

	int *B = (int *)malloc(sizeof(int) * len);
	B[0] = Array[0];

	for( i = 1; i < len; i++)
	{
		if( Array[i] > B[nMax])
			B[++nMax] = Array[i];
		else //Array[i]С�ڻ��������B�е�Ԫ��
		{
			/***********************************************************************************************
			�ҳ�Array[i]��Ҫ�����λ�ã����Array[i]���������У������B[pos] < Array[i] < B[pos+1]
			�ҳ����ϵ�pos���ٽ�B[pos]���³�Array[i]
			************************************************************************************************/
			pos = BinSearch(B, nMax, Array[i]);
												
			B[pos] = Array[i];
		}
	}

	return (nMax + 1); //����B�±���0��ʼ���������ʱ��Ҫ+1
}

int main()
{
	char x[10] = "abcdefghi";
	char y[10] = "bdeghibjk";
	int arr[]={100,-1,4,2,3,5,6,-7};
	//100, -1, 4, 2, 3, 5, 6, -7
    int n=8;
	int arr1[]={1,2,3,4,5,6,7,-1,2,4,3,4,5,6,-7};
    	int n1=15;
	int arr2[]={-1,2,4,3,4,5,6,1,2,3,4,5,6,7,-7};
    	int n2=15;

	printf("%d\n",Find_LIS(arr2,n2));
	Find_Lcs(x,y);
	Find_conLCS1(x,y);
	system("pause");
}
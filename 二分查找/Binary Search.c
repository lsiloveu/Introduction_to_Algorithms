/**********************************************************************
���ֲ���(ѭ��ʵ��)��

	������int BinSearch( int *Array, int len, int num)
	���ã����������ڴ���������������ţ����ݲ����������򷵻�-1)	
		ʱ�临�Ӷȣ�O(lgn)
		�ռ临�Ӷȣ�O(n)

���ֲ���(�ݹ�ʵ��)��
	������int Binsearch1( int *Array, int len, int num)
	���ã����������ڴ���������������ţ����ݲ����������򷵻�-1)	
		ʱ�临�Ӷȣ�O(lgn)
		�ռ临�Ӷȣ�O(n)
************************************************************************/
#include <stdio.h>
#include <stdlib.h>

/**********************************************************************
���ֲ��ң�(ѭ��ʵ��)

	������int BinSearch( int *Array, int len, int num)
		Array:	�����ҵ���������
		len:	����ĳ���
		num��	�����ҵ�����
	����ֵ��	���ش��������ݵ������ţ������������У��򷵻�-1��
	��ӡֵ��	��
	ʱ�临�Ӷȣ�O(lgn)
	�ռ临�Ӷȣ�O(n)
************************************************************************/
int BinSearch( int *Array, int len, int num)
{
	int low = 0, high = len - 1;
	int mid;
	while( low <= high)
	{
		mid = low + (high - low) / 2;
		if( Array[mid] == num)
			return mid;
		else if( Array[mid] > num)
			high = mid - 1;
		else low = mid + 1;
	}
	return -1;
}

/**********************************************************************
���ֲ��ң�(�ݹ�ʵ��)

	������int Binsearch1( int *Array, int len, int num)
		Array:	�����ҵ���������
		len:	����ĳ���
		num��	�����ҵ�����
	����ֵ��	���ش��������ݵ������ţ������������У��򷵻�-1��
	��ӡֵ��	��	
	ʱ�临�Ӷȣ�O(lgn)
	�ռ临�Ӷȣ�O(n)
************************************************************************/
int BinSearch1( int *Array, int low, int high, int num)
{
	if( low > high)
		return -1;
	int mid = low + (high - low) / 2;
	if( Array[mid] == num)
		return mid;
	else if( Array[mid] > num)
		return BinSearch1(Array, low, mid - 1, num);
	else return BinSearch1(Array, mid + 1, high, num);
}

int main()
{
	printf("hello world\n");
	int Arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
	printf("%d\n", BinSearch1(Arr, 0, 7, 9));
	system("pause");
	return 0;
}
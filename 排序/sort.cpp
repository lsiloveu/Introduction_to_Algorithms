/**********************************************************************
��������
	������void QuickSort(int Array[], int low, int high)
	���ã�������Array����
		ʱ�临�Ӷȣ�O(nlgn)
		�ռ临�Ӷȣ�O(1)

�������������
	������void RandomQuickSort(int Array[], int low, int high)
	���ã�������Array����
		ʱ�临�Ӷȣ�O(nlgn)
		�ռ临�Ӷȣ�O(1)

��������
	������void InsertSort(int Array[], int low, int high)
	���ã�������Array����
		ʱ�临�Ӷȣ�O(n^2)
		�ռ临�Ӷȣ�O(1)

ð������
	������void BubbleSort(int Array[], int low, int high)
	���ã�������Array����
		ʱ�临�Ӷȣ�O(n^2)
		�ռ临�Ӷȣ�O(1)

���ѵ�����
	������void HeapAdjust(int Array[], int i, int nLength)
	���ã�������Array����
		ʱ�临�Ӷȣ�O(lgn)
		�ռ临�Ӷȣ�O(1)

������
	������void HeapSort(int Array[], int length)
	���ã�������Array����
		ʱ�临�Ӷȣ�O(nlgn)
		�ռ临�Ӷȣ�O(1)

ϣ������
	������void ShellSort(int Array[], int length)
	���ã�������Array����
		ʱ�临�Ӷȣ�O(n^2)
		�ռ临�Ӷȣ�O(1)
************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

#define SWAP(a,b) {int temp = a; a = b; b = temp;}

using namespace std;

/**********************************************************************
���������������ݣ�����ʵ�֣���
	������void Swap( int &a, int &b)
		a:	������������
		b:	������������
	����ֵ��	��
	��ӡֵ��	��
	ʱ�临�Ӷȣ�O(1)
	�ռ临�Ӷȣ�O(1)
************************************************************************/
void Swap( int &a, int &b)
{
    int temp = a;

    a = b;

    b = temp;
}

/**********************************************************************
���������������ݣ�ָ��ʵ�֣���
	������void SWap( int &a, int &b)
		a:	������������
		b:	������������
	����ֵ��	��
	��ӡֵ��	��
	ʱ�临�Ӷȣ�O(1)
	�ռ临�Ӷȣ�O(1)
************************************************************************/
void SWap( int *a, int *b)
{
    int temp = *a;

    *a = *b;

    *b = temp;
}

/**********************************************************************
��������
	������void QuickSort(int Array[], int low, int high)
		Array:	�����������
		low:	�������ʼλ��
		high:	����Ľ���λ��
	����ֵ��	��
	��ӡֵ��	��
	ʱ�临�Ӷȣ�O(nlgn)
	�ռ临�Ӷȣ�O(1)
************************************************************************/
void QuickSort(int Array[], int low, int high) //��������
{
    if( low >= high)

        return ;

    int first = low;

    int last = high;

    int key = Array[first];

    while(first < last)
    {
        while( Array[last] >= key && first < last) last--;

        Array[first] = Array[last];

        while( Array[first] <= key && first < last) first++;

        Array[last] = Array[first];
    }

    Array[first] = key;

    QuickSort(Array, low, first - 1);

    QuickSort(Array, last + 1, high);

}

/**********************************************************************
�������������
	������void RandomQuickSort(int Array[], int low, int high)
		Array:	�����������
		low:	�������ʼλ��
		high:	����Ľ���λ��
	����ֵ��	��
	��ӡֵ��	��
	ʱ�临�Ӷȣ�O(nlgn)
	�ռ临�Ӷȣ�O(1)
************************************************************************/
void RandomQuickSort(int Array[], int low, int high) //�������������
{
    if( low >= high)

        return;

    srand(time(0));

    int index = rand() % (high - low) + low;

    int Temp = Array[index];

    Array[index] = Array[high];

    Array[high] = Temp;

    int first = low;

    int last = high;

    int key = Array[last];

    while( first < last)
    {
        while( Array[first] <= key && first < last) first++;

        Array[last] = Array[first];

        while( Array[last] >= key && first < last) last--;

        Array[first] = Array[last];
    }

    Array[first] = key;

    RandomQuickSort(Array, low, first - 1);

    RandomQuickSort(Array, last + 1, high);
}

/**********************************************************************
��������
	������void InsertSort(int Array[], int low, int high)
		Array:	�����������
		low:	�������ʼλ��
		high:	����Ľ���λ��
	����ֵ��	��
	��ӡֵ��	��
	ʱ�临�Ӷȣ�O(n^2)
	�ռ临�Ӷȣ�O(1)
************************************************************************/
void InsertSort(int Array[], int low, int high) //��������
{
    int key;

    int i, j;

    for( j = 1; j <= high; j++)
    {
        key = Array[j];

        i = j - 1;

        while( i >= 0 && Array[i] >= key )
            {
                Array[i+1] = Array[i];

                i--;
            }
        Array[i+1] = key;
    }
}

/**********************************************************************
ð������
	������void BubbleSort(int Array[], int low, int high)
		Array:	�����������
		low:	�������ʼλ��
		high:	����Ľ���λ��
	����ֵ��	��
	��ӡֵ��	��
	ʱ�临�Ӷȣ�O(n^2)
	�ռ临�Ӷȣ�O(1)
************************************************************************/
void BubbleSort(int Array[], int low, int high) //ð������
{
    int i, j;

    for( i = 0; i <= high; i++)

        for( j = high; j >= i+1; j--)
        {
            if(Array[j] < Array[j-1])
            {
                int temp = Array[j];

                Array[j] = Array[j-1];

                Array[j-1] = temp;
            }
        }
}

/**********************************************************************
���ѵ�����
	������void HeapAdjust(int Array[], int i, int nLength)
		Array:		�����������
		i:			���ڵ�����������
		nlength:	����ĳ���
	����ֵ��	��
	��ӡֵ��	��
	ʱ�临�Ӷȣ�O(lgn)
	�ռ临�Ӷȣ�O(1)
************************************************************************/
void HeapAdjust(int Array[], int i, int nLength) //���Ѷѵ���
{
    int nChild;

    int nTemp;

    for( ; 2 * i + 1 < nLength; i = nChild)
    {
        nChild = 2 * i + 1; //���ڵ�λ��Ϊi�����ӽڵ��λ��Ϊ2*i + 1(�����ǰ��������±꣬�׸�λ���±�Ϊ0)

        //�õ��ӽڵ��нϴ�Ľ��
        if(nChild < nLength - 1 && Array[nChild+1] > Array[nChild])

            nChild++;

        //����ϴ�Ľ����ڸ���㣬��ô���ϴ���ӽڵ������ƶ����滻���ĸ����
        if(Array[i] < Array[nChild])
        {
            nTemp = Array[i];

            Array[i] = Array[nChild];

            Array[nChild] = nTemp;
        }
        else break;//�����˳�ѭ��
    }
}

/**********************************************************************
������
	������void HeapSort(int Array[], int length)
		Array:	�����������
		length:	����ĳ���
	����ֵ��	��
	��ӡֵ��	��
	ʱ�临�Ӷȣ�O(nlgn)
	�ռ临�Ӷȣ�O(1)
************************************************************************/
void HeapSort(int Array[], int length) //������
{
    int tmp;
    //�������е�ǰ�벿��Ԫ�أ�������֮���һ��Ԫ�������е�����Ԫ��
    //length/2-1�����һ����Ҷ�ڵ㣬�˴�"/"Ϊ����
    for( int i = length/2 - 1; i >= 0; i--)

        HeapAdjust(Array, i, length);

    for( int i = length - 1; i > 0; i--)
    {
        //�ѵ�һ��Ԫ�غ͵�ǰ�����һ��Ԫ�ؽ���
        //��֤��ǰ�����һ��λ�õ�Ԫ�ض��������������֮������
        tmp = Array[i];

        Array[i] = Array[0];

        Array[0] = tmp;
        //������С����Heap�ķ�Χ��ÿһ�ε�����ϱ�֤��һ��Ԫ���ǵ�ǰ���е����ֵ
        HeapAdjust(Array, 0, i);
    }
}

/**********************************************************************
ϣ������
	������void ShellSort(int Array[], int length)
		Array:	�����������
		length:	����ĳ���
	����ֵ��	��
	��ӡֵ��	��
	ʱ�临�Ӷȣ�O(nlgn)
	�ռ临�Ӷȣ�O(1)
************************************************************************/
void ShellSort(int Array[], int length) //ϣ������
{
    int d = length/2;

    int i,j;

    int temp;

    while(d >= 1)
    {
        for(i = d; i < length; i++)
        {
            temp = Array[i];

            j = i - d;

            while( j >= 0 && Array[j] > temp)
            {
                Array[j + d] = Array[j];

                j = j - d;
            }
            Array[j + d] = temp;
        }
        d /= 2;
    }
}

int
main()
{
    int TempArray[10] = {12, 3, 45, 1, 43, 98, 2, 122, 1, 45};

//    cout << "Please input ten numbers:\n";
//
//    for( int i = 0; i < 10; i++)
//    cin >> TempArray[i];

    //QuickSort(TempArray, 0, 9);

    //InsertSort(TempArray, 0, 9);

    //BubbleSort(TempArray, 0, 9);

    //HeapSort(TempArray, 10);

    //RandomQuickSort(TempArray, 0, 9);

    ShellSort(TempArray, 10);

    cout << "After sort:\n";

    for( int i = 0; i < 10; i++)
        cout << TempArray[i] << " ";

	system("pause");
    return 0;
}

/**********************************************************************
KMP�ַ���ƥ�䣺
	������void KMP_Matcher(const char* T, const char *P)
	���ã����ַ���T��ƥ���ַ���P�������ƥ��λ��
		ʱ�临�Ӷȣ�O(n) + O(m) nΪ�ַ���T�ĳ��� mΪ�ַ���P�ĳ���
		�ռ临�Ӷȣ�O(m)
KMP�ַ���Ԥ����
	������void KMP_GetNext(const char *P, int *next)
	���ã�KMP�ַ���Ԥ�������ַ���PԤ����Ľ������������next��	
		ʱ�临�Ӷȣ�O(m)
		�ռ临�Ӷȣ�O(m)
************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**********************************************************************
KMP�ַ���Ԥ����
	������void KMP_GetNext(const char *P, int *next)
		P:		��������ַ���
		next:	����Ԥ������������
	����ֵ��	��
	��ӡֵ��	��
	ʱ�临�Ӷȣ�O(m)
	�ռ临�Ӷȣ�O(n)
************************************************************************/
void KMP_GetNext(const char *P, int *next)
{
	int m = strlen(P);
	/*
		���������±�仯��KMP�㷨���ַ���ƥ����±��Ǵ�1��ʼ����������±��0��ʼ������Ҫnext[1]=0���next[0]=-1;
		��Ӧ��k��ֵҲ��Ҫ�仯
	*/
	next[0] = -1;
	int k = -1;

	for(int q = 1; q < m; q++)
	{
		while(k > -1 && P[k+1] != P[q])
			k = next[k];
		if(P[k+1] == P[q])
			k += 1;
		next[q] = k;
	}
}

/**********************************************************************
KMP�ַ���Ԥ����
	������void KMP_Matcher(const char* T, const char *P)
		T:		��ƥ����ַ���
		P��		ƥ����ַ���
	����ֵ��	��
	��ӡֵ��	��ӡ��next���飻��ӡ���ַ�����ƥ��λ��
	ʱ�临�Ӷȣ�O(n) + O(m)
	�ռ临�Ӷȣ�O(m)
************************************************************************/
void KMP_Matcher(const char* T, const char *P)
{
	int n = strlen(T);
	int m = strlen(P);

	int *next = (int *)malloc(sizeof(int) * m);

	KMP_GetNext(P, next);

	for( int i = 0; i < m; i++)
		printf("%d ", next[i]);
	printf("\n");

	int q = -1;
	for( int i = 0; i < n; i++)
	{
		while(q > -1 && P[q+1] != T[i])
			q = next[q];

		if(P[q+1] == T[i]) 
			q += 1;

		if(q + 1== m) //���������±�ı仯��q��ֵ���mС1
		{
			printf("Success.\nPattern occurs with shift: %d\n", i - m);
			q = next[q];
		}
	}
}

int main()
{
	char *A = "bacbababababca";
	char *B = "ababababca";
	KMP_Matcher(A, B);
	system("pause");
	return 0;
}
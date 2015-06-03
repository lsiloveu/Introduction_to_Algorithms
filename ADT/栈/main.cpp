#include <iostream>
#include "stack.h"
#include "stack.cpp"

using namespace std;

int main()
{
    Stack<int> MyStack;
    int nSelected;
    bool IsQuit =  false;
    while(!IsQuit)
    {
        cout << "������ջ����ָ��: " << endl;
        cout << "1. ��ӡջ���� " << endl;
        cout << "2. ��ջ���� " << endl;
        cout << "3. ��ջ���� " << endl;
        cout << "4. ���ջ" << endl;
        cout << "5. ȡ��ջ��Ԫ��" << endl;
        cout << "6. �˳� " << endl;

        cin >> nSelected;
        switch(nSelected)
        {
        case 1:
            cout << "ջ��ǰ����Ϊ��" << endl;
            cout << MyStack.Length() << endl;
            break;
        case 2:
            cout << "��������Ҫ��������ݣ�" << endl;
            int new_data;
            cin >> new_data;

            MyStack.Push(new_data);
            break;
        case 3:
            cout << "��ջ" << endl;
            cout << "��ջ����Ϊ��" << MyStack.Pop() << endl;
            break;
        case 4:
            cout << "���ջ" << endl;
            MyStack.MakeEmpty();
            break;
        case 5:
            cout << "ȡ��ջ��Ԫ��" << endl;
            cout << "ջ��Ԫ��Ϊ��" << MyStack.Top() << endl;
            break;
        case 6:
            IsQuit = true;
            break;
        default:
            cout << "�˲�����Ч��������ѡ��" <<endl;
            break;
        }
    }
    return 0;
}

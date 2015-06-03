#include <iostream>
#include "list.h"
#include "list.cpp"

using namespace std;

int main()
{
    List<int> MyList;
    int nSelected;
    bool IsQuit =  false;
    while(!IsQuit)
    {
        cout << "�������������ָ��: " << endl;
        cout << "1. ��ӡ����ڵ��� " << endl;
        cout << "2. ��ӡ�������нڵ����� " << endl;
        cout << "3. ��ָ��ID�Ľڵ�����һ���½ڵ� " << endl;
        cout << "4. ɾ��ָ�������� " << endl;
        cout << "5. ������������һ���½ڵ�" << endl;
        cout << "6. �������" << endl;
        cout << "7. ��������" << endl;
        cout << "8. �˳� " << endl;

        cin >> nSelected;
        switch(nSelected)
        {
        case 1:
            cout << "����ǰ����Ϊ��" << endl;
            cout << MyList.Length() << endl;
            break;
        case 2:
            cout << "����ǰ����Ϊ��" << endl;
            for(int i = 1; i <= MyList.Length(); i++)
            {
                cout << MyList.FindPosition(i) << " ";
            }
            cout << endl;
            break;
        case 3:
            cout << "��������Ҫ�����λ�ã�" << endl;
            int new_position;
            cin >> new_position;

            cout << "��������Ҫ��������ݣ�" << endl;
            int new_data;
            cin >> new_data;

            MyList.Insert(new_data, new_position);
            break;
        case 4:
            cout << "������ɾ�������ݣ�" << endl;
            int del_data;
            cin >> del_data;

            MyList.Delete(del_data);
            break;
        case 5:
            cout << "��������Ҫ������ĩβ��ӵ����ݣ�" << endl;
            int append_data;
            cin >> append_data;

            MyList.Append(append_data);
            break;
        case 6:
            cout << "�������" << endl;
            MyList.MakeEmpty();
            break;
        case 7:
            cout << "��������" << endl;
            MyList.ListSort();
            break;
        case 8:
            IsQuit = true;
            break;
        default:
            cout << "�˲�����Ч��������ѡ��" <<endl;
            break;
        }
    }
    return 0;
}

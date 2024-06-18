// ��ʾ���̵߳�CPP����
// ʹ��������ͬ�Ŀɵ��ö���
#include <iostream>
#include <thread>
using namespace std;

// һ�����⺯��
void foo(int Z)
{
    for (int i = 0; i < Z; i++) {
        cout << "�߳�ʹ�ú���ָ����Ϊ�ɵ��ò���\n";
    }
}

// �ɵ��ö���
class thread_obj {
public:
    void operator()(int x)
    {
        for (int i = 0; i < x; i++)
            cout << "�߳�ʹ�ú���������Ϊ�ɵ��ò���\n";
    }
};

int main()
{
    cout << "�߳� 1 ��2 ��3 "
            "��������" << endl;

    // ����ָ��
    thread th1(foo, 3);

    // ��������
    thread th2(thread_obj(), 3);

    // ���� Lambda ���ʽ
    auto f = [](int x) {
        for (int i = 0; i < x; i++)
            cout << "�߳�ʹ�� lambda ���ʽ��Ϊ�ɵ��ò���\n";
    };

    // �߳�ͨ��ʹ�� lambda ���ʽ��Ϊ�ɵ��õĲ���
    thread th3(f, 3);

    // �ȴ��߳����
    // �ȴ��߳� t1 ���
    th1.join();

    // �ȴ��߳� t2 ���
    th2.join();

    // �ȴ��߳� t3 ���
    th3.join();

    return 0;
}
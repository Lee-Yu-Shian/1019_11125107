#include "1019_11125107.hpp"
#include "1019_11125107f.cpp"

using namespace std;

int main()
{
    const int len=3;
    // 動態分配一個大小為5的Student陣列
    Student *studentArray = new Student[3];

    // 使用動態分配的陣列
    studentArray[0] = Student(1, "Alice");
    studentArray[1] = Student(2, "Bob");
    studentArray[2] = Student(3,"Jack");

    Queue <Student> qe(3);
    for(int i=0;i<3;i++)
    {
        qe.Push(studentArray[i]);
    }
    cout<<"Show the front student:"<<endl;
    qe.Front().Print();
    cout<<"\nShow the rear student:"<<endl;
    qe.Rear().Print();
    qe.Pop();
    cout<<"\nShow the front student:"<<endl;
    qe.Front().Print();

    //註解的部份僅為校驗用
    // int int_list[] ={1,2,3};

    // Queue <int> IntQueue(3);

    // if (IntQueue.IsEmpty())
    // {
    //     cout << "序列(int)為空" << endl;
    // }
    // else
    // {
    //     cout << "序列(int)不為空" << endl;
    // }

    // for(int i=0;i<3;i++)
    // {
    //     IntQueue.Push(int_list[i]);
    // }
    //IntQueue.Push(int_list[0]);//嘗試加爆(狀況1)Passed

    // for(int i=0;i<3;i++)
    // {
    //     IntQueue.Pop();
    // }
    //IntQueue.Pop();//嘗試多扣除(狀況2)Passed

    // for(int i=0;i<3;i++)
    // {
    //     IntQueue.Push(int_list[i]);
    // }
    // IntQueue.Pop();
    // IntQueue.Push(int_list[0]);//當前面還有空格時，排序(狀況3)Passed

    // if (IntQueue.IsEmpty())
    // {
    //     cout << "序列(int)為空" << endl;
    // }
    // else
    // {
    //     cout << "序列(int)不為空" << endl;
    // }

    return 0;
}
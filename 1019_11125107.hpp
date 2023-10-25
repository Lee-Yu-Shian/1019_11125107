#include <iostream>
#include<cstdlib> 
#include<cstring>
#include <typeinfo>

using namespace std;
#pragma once


class Student {
private:
    int ID;
    char* name;

public:
    Student();
    ~Student();
    Student(int stud_id, const char* stud_name);
    int SetID(int stud_id);
    int SetName(char* stud_name);
    int GetID();
    char* GetName();
    void Print();
    void operator=(Student src);//等號(class=class)
};

template<class T>
class Queue {
private:
    T* queue_elements; // 堆疊元素量
    int front; // 堆疊指標(尾端)
    int rear; //堆疊前標(首)
    int capacity; // 堆疊容量

public://add operator +
    Queue();//動態記憶體自動配置
    Queue(int MaxQueueSise);//手動輸入空間值
    ~Queue();//解構子delete[]
    bool IsEmpty();//檢查是否為空，T:為空；F:不為空
    T& Front();//堆疊元素(尾端)
    T& Rear();//堆疊元素(首)
    void Push(T &item);//放入元素
    void Pop();//取出元素
};

template<class T>
Queue<T> :: Queue() : queue_elements(NULL), front(-1), rear(-1), capacity(0) {}

template<class T>
Queue<T> :: Queue(int MaxQueueSise) : front(-1), rear(-1), capacity(MaxQueueSise)
{
    queue_elements = new T[capacity](); // 將所有元素初始化為0
}

template<class T>
Queue<T> :: ~Queue()
{
    delete[] queue_elements;
}

template<class T>
bool Queue<T> :: IsEmpty()
{
    if (front == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template<class T>
T& Queue<T>::Front()
{
    if (front == -1) {
        throw std::runtime_error("Front is empty.");//出現空時報錯
    }
    //cout<<front<<endl;
    return queue_elements[front];//輸出front指標所指的位置
}

template<class T>
T& Queue<T>::Rear()
{
    if (rear == -1) {
        throw std::runtime_error("Rear is empty.");//出現空時報錯
    }
    return queue_elements[rear];//輸出front指標所指的位置
}

template<class T>
void Queue<T>::Push(T &item) {
    int delta_empty;//空格變數
    int counter = front;
    delta_empty = front;//計算空格

    if (rear == (capacity - 1) && (front == 0)) 
    {
        throw std::runtime_error("Stack is full.");//當空間滿時報錯 r=最末端,f前的空格數為0
        return;
    }

    if (rear == capacity-1)//末端
    {
        cout<<"剩餘的空位還剩下"<<delta_empty<<"個\n";
        cout<<"sorting...\n";
        
        while(counter <= rear)
        {
            queue_elements[counter - delta_empty] = queue_elements[++counter];
            //cout<<"rear:"<<rear<<"\tfront:"<<front<<endl;
            //cout<<"r="<<queue_elements[rear]<<"\tf="<<queue_elements[front]<<endl;
            
        }
        front = 0;
        rear -= delta_empty;
        queue_elements[++rear] = item;//新物件加入時，rear值++
        // cout<<"rear:"<<rear<<"\tfront:"<<front<<endl;
        // cout<<"r="<<queue_elements[rear]<<"\tf="<<queue_elements[front]<<endl;
        return;
    }

    if(front == -1)//如果是初值
    {
        front++;
        queue_elements[++rear] = item;//新物件加入時，rear值++
        // cout<<"rear:"<<rear<<"\tfront:"<<front<<endl;
        // cout<<"r="<<queue_elements[rear]<<"\tf="<<queue_elements[front]<<endl;
        return;
    }

    queue_elements[++rear] = item;//新物件加入時，rear值++
    // cout<<"rear:"<<rear<<"\tfront:"<<front<<endl;
    // cout<<"r="<<queue_elements[rear]<<"\tf="<<queue_elements[front]<<endl;
    return;


}

template<class T>
void Queue<T>::Pop() {
    int temp_front = front;
    if (rear == -1) 
    {
        throw std::runtime_error("Stack is empty.");//當內部無值時報錯
        return;
    }

    if (rear == front)//剩下最後一個時
    {
        rear = -1;//初始化
        front = -1;//初始化
        // cout<<"rear:"<<rear<<"\tfront:"<<front<<endl;
        // cout<<"r="<<queue_elements[rear]<<"\tf="<<queue_elements[front]<<endl;
        return;
    }
    
    front++; //物件取出時front值++
    // cout<<"rear:"<<rear<<"\tfront:"<<front<<endl;
    // cout<<"r="<<queue_elements[rear]<<"\tf="<<queue_elements[front]<<endl;
    return;
}
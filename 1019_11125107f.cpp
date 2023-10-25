#include "1019_11125107.hpp"

Student::Student() : ID(0), name(nullptr) {}


Student :: ~Student()
{
    // if (name != NULL)
    // {
    //    delete[] name; 
    // }
    
}

Student::Student(int stud_id, const char* stud_name) {
    ID = stud_id;
    name = new char[strlen(stud_name) + 1];
    strcpy(name, stud_name);
}

int Student :: SetID(int stud_id)
{
    ID = stud_id;
    return 0;
}

int Student :: SetName(char* stud_name)
{
    if (name != stud_name) {
        if (name != nullptr) {
            delete[] name;
        }
        name = new char[strlen(stud_name) + 1];
        strcpy(name, stud_name);
    }
    return 0;
}

int Student :: GetID()
{
    int id_temp = ID;
    return id_temp;
}

char* Student :: GetName()
{
    char* data2pub = new char[strlen(name)+1];
    strcpy(data2pub,name);
    return data2pub;
}

void Student :: Print()
{
    cout << "ID: " << GetID()<<endl<<"Name:";
    for (int i=0;i<strlen(name);i++)
    {
        char* ptr;
        ptr = GetName();
        cout<<ptr[i];
    }
    cout<<endl;
}

void Student::operator=(Student src)//A=B
{
    if (name != NULL)
    {
        delete[] name;//刪除舊資料
        name = NULL;
    }
    
    ID = src.ID;
    name = new char[strlen(src.name)];
    strcpy(name,src.name);
    return;
}
#include <iostream>
#include "..\MyHeader.h"   // 상위 폴더이므로 '..\'를 앞에 붙여줌
#include <string>

using namespace std;

void ShowClass(Student st1)   // 로컬 함수로 만들어줌
{
    cout << "st1.Number : " << st1.number() << "   ";
    cout << "st1.Name : " << st1.name() << "   ";
    cout << "st1.Aag : " << st1.age() << "   ";
    cout << "st1.Kor : " << st1.kor() << "   ";
    cout << "st1.eng : " << st1.eng() << "   ";
    cout << "st1.Tot: " << st1.tot() << "   ";
    cout << "st1.Avg : " << st1.avg() << endl;
}

void swap(int* a, int* b)        // ① 포인터를 사용       // Call-by-reference
{
    int c = *a;                  // *a == a[0] (* == [])
    *a = *b; *b = c;
}

void swapRef(int& a, int& b)     // 레퍼런스(Reference)는 변수명의 별명이다.  // 초기화 이후 변경 불가
{                                // ② 포인터를 사용하지 않음 
    int c = a;
    a = b; b = c;
}

int main()
{
    string fname;     // string == 문자열 ==> object '.' 을 이용
    fname = "C:\\Users\\si129\\Student.csv";
    string nm = "춘향이";
    Student st(0, 80, 76, "춘향이", 15);
    ShowClass(st);
    cout << endl << endl;

    //Student st1(1, 80, 75, "길동이", 15);   // 초기값 : 고유번호, 국어점수, 영어점수, 이름
    //ShowClass(st1);

    int num, age, kor, eng;
    char name[100];
    int count = 0;
    Student* stu[100];       // 포인터 타입으로 배열  // 포인터 : 주소만 있음 (4 byte) = int (4byte)
    //Student* st1[100];     // 실변수 타입으로 배열 ==> 비추
    
    FILE* fp = fopen(fname.c_str(), "r");
    fgets(name, 250, fp);    // 첫 줄 무시 ==> file read pointer를 다음 줄로 이동
    while (1)
    {
        if (fscanf(fp, "%d %s %d %d %d", &num, &name, &age, &kor, &eng) < 1) break;
        stu[count++] = new Student(num, kor, eng, name, age) ;
        ShowClass(*stu[count - 1]);
    }

    cout << "\n\n\n\n";

    //Class sorting
    for (int i = 0; i < count - 1; i++)
    {
        for (int k = i + 1; k < count; k++)
        {
            if (stu[i]->avg() < stu[k]->avg())
            {
                //swap((int*)&stu[i], (int*)&stu[k]);   // a = stu[i], b = stu[k]
                swapRef((int&)stu[i], (int&)stu[k]);
            }
        }
    }
    for (int i = 0; i < count; i++)
    {
        ShowClass(*stu[i]);
    }
}
#include <iostream>

using namespace std;;

void swapValue(int a, int b);  // 함수의 원형(prototype) 선언
void swapRef(int& a, int& b);
void swapRef(int* a, int* b);

class Point
{
private:
    int x;     // 기본 접근 제어 지시자는 private
    int y;     // 이렇게 하면 밑에 main 부분에 x,y 를 못쓰게 되어있음 -> 그래서 Point 부분을 바꿔줌

public:        // 명시적 지시자
    //Point(int x = 0, int y = 0) : x(x), y(y) {}  // 밑에 식과 동일 (짧게 표현)

    Point(int x = 0, int y = 0) : x(x)        // : Point p(10,20)  // 초기화 과정을 명시적으로 확인
    {
        this->y = y;
    }
    int X() { return x; }                     // int x 와 int y를 private: 안에 넣어줬을 때 X(),Y(),SetX,SetY 써줌
    int Y() { return y; }
    void SetX(int x) { this->x = x; }
    void SetY(int y) { this->y = y; }
    double distance(Point p);                 // Point p와의 거리 계산  // 2D -> Point
};

class Point3D : public Point                // 2D Point class 상속
{
private:
    int z;  // z축

public:
    Point3D(int x = 0, int y = 0, int z = 0) : Point(x, y)  //, z(z) <- 밑에 this 안 써줬을 경우
    {
        this->z = z;
    }
    int Z() { return z; }
    void SetZ(int z) { this->z = z; }
    double distance(Point3D p);             // Point3D p와의 거리  // 3D -> Point3D
    };

class Person
{
private:
    int Number;       // 사람을 특정지을 수 있는 고유번호
    char Name[20];    // 사람의 이름을 담을 수 있는 문자열로 들어감 (한글로 10 글자)
    int Age;
public:
    Person(int num, char* str=NULL, int a=0) : Number(num), Age(a)   // Person : class 와 이름 동일
    {
        strcpy(Name, str);   // 변수 대입문
    }
    Person(int num, const char* str = NULL, int a = 0) : Number(num), Age(a)
    {
        strcpy(Name, str);
    }

    int age() { return Age; }          // age : 현재 나이에 해당하는 값을 얻음 (GetAge)
    char* name() { return Name; }      // 현재 이름
    int number() { return Number; }
    void SetAge(int a) { Age = a; }
    void SetName(char* str)            // 기존 방을 비우고(delete) 새 방을 잡자. XXXXXXXXXX

    {
        strcpy(Name, str);
    }
};

class PersonEx
{
private:
    int Number;       // 사람을 특정지을 수 있는 고유번호
    char* Name;       // 포인터 타입으로 표현할 수 있지만, 문자열을 담아 줄 공간이 없음 ==> 이런 경우, malloc 혹은 new 를 이용하여 동적으로 할당 필요
    int Age;

public:
    PersonEx(int num, char* str, int a) : Number(num), Age(a)
    {
        Name = new char[strlen(str)];   // 그냥 Name(str) 이렇게 써줄 수 없음. 그래서 변수 타입으로 선언해줌 ==> Name 변수는 실제 데이터 구조에서 방을 의미 그래서 strcpy를 해줌
        strcpy(Name, str);   // 변수 대입문
    }
    ~PersonEx()   // bye~
    {
        delete[]Name;
    }
    int age() { return Age; }          // age : 현재 나이에 해당하는 값을 얻음 (GetAge)
    char* name() { return Name; }      // 현재 이름
    void SetAge(int a) { Age = a; }
    void SetName(char* str)            // 기존의 방을 비우고(delete) 새 방을 잡아주어야 함
    {
        delete[]Name;
        Name = new char[strlen(str)];
        strcpy(Name, str);
    }
};

class Student : public Person   // 상속
{
private:
    int Kor;
    int Eng;
    int Tot;
    double Avg;
    int Rank;
    void calc()   // 칼크 : 외부에서 호출이 안되도록 해줌 (총점과 평균을 계산하는 함수)
    {
        Tot = Kor + Eng;
        Avg = (double)Tot / 2.0;
    }
public:
    Student(int num, int kor, int eng, char* str=NULL, int age = 0) : Person(num, str, age)      // tot, avg, rank : 초기화에 의해서 값이 셋팅되는게 아니라 값에 의해 나타나기 때문에 안써줌
    {
        this->Kor = kor;
        this->Eng = eng;
        calc();   // 값이 바뀌어도 자동으로 계산 됨
    }
    Student(int num, int kor, int eng, const char* str = NULL, int age = 0) : Person(num, str, age)
    {
        this->Kor = kor;
        this->Eng = eng;
        calc();
    }
    Student(int num, int kor, int eng, string str = NULL, int age = 0) : Person(num, str.c_str(), age)
    {
        this->Kor = kor;
        this->Eng = eng;
        calc();
    }

    int kor() { return Kor; }   // private 에 의한 변수들을 읽어 옴
    int eng() { return Eng; }
    int tot() { return Tot; }
    double avg() { return Avg; }
    int rank() { return Rank; }
    void SetKor(int k) { Kor = k; calc(); }
    void SetEng(int e) { Kor = e; calc(); }
    void SetRank(int r) { Rank = r; }
};
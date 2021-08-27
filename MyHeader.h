#include <iostream>

using namespace std;;

void swapValue(int a, int b);  // �Լ��� ����(prototype) ����
void swapRef(int& a, int& b);
void swapRef(int* a, int* b);

class Point
{
private:
    int x;     // �⺻ ���� ���� �����ڴ� private
    int y;     // �̷��� �ϸ� �ؿ� main �κп� x,y �� ������ �Ǿ����� -> �׷��� Point �κ��� �ٲ���

public:        // ����� ������
    //Point(int x = 0, int y = 0) : x(x), y(y) {}  // �ؿ� �İ� ���� (ª�� ǥ��)

    Point(int x = 0, int y = 0) : x(x)        // : Point p(10,20)  // �ʱ�ȭ ������ ��������� Ȯ��
    {
        this->y = y;
    }
    int X() { return x; }                     // int x �� int y�� private: �ȿ� �־����� �� X(),Y(),SetX,SetY ����
    int Y() { return y; }
    void SetX(int x) { this->x = x; }
    void SetY(int y) { this->y = y; }
    double distance(Point p);                 // Point p���� �Ÿ� ���  // 2D -> Point
};

class Point3D : public Point                // 2D Point class ���
{
private:
    int z;  // z��

public:
    Point3D(int x = 0, int y = 0, int z = 0) : Point(x, y)  //, z(z) <- �ؿ� this �� ������ ���
    {
        this->z = z;
    }
    int Z() { return z; }
    void SetZ(int z) { this->z = z; }
    double distance(Point3D p);             // Point3D p���� �Ÿ�  // 3D -> Point3D
    };

class Person
{
private:
    int Number;       // ����� Ư������ �� �ִ� ������ȣ
    char Name[20];    // ����� �̸��� ���� �� �ִ� ���ڿ��� �� (�ѱ۷� 10 ����)
    int Age;
public:
    Person(int num, char* str=NULL, int a=0) : Number(num), Age(a)   // Person : class �� �̸� ����
    {
        strcpy(Name, str);   // ���� ���Թ�
    }
    Person(int num, const char* str = NULL, int a = 0) : Number(num), Age(a)
    {
        strcpy(Name, str);
    }

    int age() { return Age; }          // age : ���� ���̿� �ش��ϴ� ���� ���� (GetAge)
    char* name() { return Name; }      // ���� �̸�
    int number() { return Number; }
    void SetAge(int a) { Age = a; }
    void SetName(char* str)            // ���� ���� ����(delete) �� ���� ����. XXXXXXXXXX

    {
        strcpy(Name, str);
    }
};

class PersonEx
{
private:
    int Number;       // ����� Ư������ �� �ִ� ������ȣ
    char* Name;       // ������ Ÿ������ ǥ���� �� ������, ���ڿ��� ��� �� ������ ���� ==> �̷� ���, malloc Ȥ�� new �� �̿��Ͽ� �������� �Ҵ� �ʿ�
    int Age;

public:
    PersonEx(int num, char* str, int a) : Number(num), Age(a)
    {
        Name = new char[strlen(str)];   // �׳� Name(str) �̷��� ���� �� ����. �׷��� ���� Ÿ������ �������� ==> Name ������ ���� ������ �������� ���� �ǹ� �׷��� strcpy�� ����
        strcpy(Name, str);   // ���� ���Թ�
    }
    ~PersonEx()   // bye~
    {
        delete[]Name;
    }
    int age() { return Age; }          // age : ���� ���̿� �ش��ϴ� ���� ���� (GetAge)
    char* name() { return Name; }      // ���� �̸�
    void SetAge(int a) { Age = a; }
    void SetName(char* str)            // ������ ���� ����(delete) �� ���� ����־�� ��
    {
        delete[]Name;
        Name = new char[strlen(str)];
        strcpy(Name, str);
    }
};

class Student : public Person   // ���
{
private:
    int Kor;
    int Eng;
    int Tot;
    double Avg;
    int Rank;
    void calc()   // Įũ : �ܺο��� ȣ���� �ȵǵ��� ���� (������ ����� ����ϴ� �Լ�)
    {
        Tot = Kor + Eng;
        Avg = (double)Tot / 2.0;
    }
public:
    Student(int num, int kor, int eng, char* str=NULL, int age = 0) : Person(num, str, age)      // tot, avg, rank : �ʱ�ȭ�� ���ؼ� ���� ���õǴ°� �ƴ϶� ���� ���� ��Ÿ���� ������ �Ƚ���
    {
        this->Kor = kor;
        this->Eng = eng;
        calc();   // ���� �ٲ� �ڵ����� ��� ��
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

    int kor() { return Kor; }   // private �� ���� �������� �о� ��
    int eng() { return Eng; }
    int tot() { return Tot; }
    double avg() { return Avg; }
    int rank() { return Rank; }
    void SetKor(int k) { Kor = k; calc(); }
    void SetEng(int e) { Kor = e; calc(); }
    void SetRank(int r) { Rank = r; }
};
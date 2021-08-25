#include <cstdio>         // stdio.h -> cstdio
#include <iostream>       // 표준 스트림
#include "..\MyHeader.h"  // "": 절대 경로가 필요 -> C:\user\si129\~~~~\Referencetest\MyHeader.h 
                          // .\ : current directory // ..\ : 상위 디렉토리(C:\user\si129\~~~~\MyHeader.h)
using namespace std;      // std::cout 에서 std::를 제외하고 쓸 수 있다.

class Point
{
private:
    int x;     // 기본 접근 제어 지시자는 private
    int y;     // 이렇게 하면 밑에 main 부분에 x,y 를 못쓰게 되어있음 -> 그래서 Point 부분을 바꿔줌

public:        // 명시적 지시자
    //Point(int x = 0, int y = 0) : x(x), y(y) {}  // 밑에 식과 동일 (짧게 표현)

    Point(int x = 0, int y = 0) : x(x)         // : Point p(10,20)  // 초기화 과정을 명시적으로 확인
    {
        this->y = y;
    }
    int X() { return x; }                     // int x 와 int y를 private: 안에 넣어줬을 때 X(),Y(),SetX,SetY 써줌
    int Y() { return y; }
    void SetX(int x) { this->x = x; }
    void SetY(int y) { this->y = y; }

    double distance(Point p)                 // Point p와의 거리 계산  // 2D -> Point
    {
        int x2 = (x - p.x) * (x - p.x);
        int y2 = (y - p.y) * (y - p.y);
        return sqrt(x2 + y2);
    }
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

    double distance(Point3D p)             // Point3D p와의 거리  // 3D -> Point3D
    {
        int x2 = (X() - p.X()) * (X() - p.X());  // 명시적으로 표현
        int y2 = (Y() - p.Y()) * (Y() - p.Y());
        int z2 = (z - p.z) * (z - p.z);
        return sqrt(x2 + y2 + z2);
    }
};

int main()
{
    //cout << "Hello C plus plus World!\n\n";  // 출력
    //
    //int a, b;
    //a = 10;
    //b = 20;
    //cout << "초기값은 a = " << a << ", b = " << b << endl;              // endl : C++에서 줄 바꿈용
    //swapValue(a, b);
    //cout << "결과값(swapValue)은 a = " << a << ", b = " << b << endl;
        //swapRef(a, b);                                                      // reference type 호출 ①
    //printf("결과값(swapRef:ref)은 a = %d, b = %d \n\n", a, b);
       //swapRef(&a, &b);                                                    // pointer type 호출 ②
    //printf("결과값(swapRef:포인터)은 a = %d, b = %d \n\n", a, b);

    Point p1;  // p(0,0)               // 기존 방법 : struct-->typedef-->사용
    Point p2(10,20);
    Point* p3 = new Point(20, 30);     // 동적 할당   // p3는 포인터 타입

    Point3D pp1;
    Point3D pp2(10, 20, 30);
    Point3D* pp3 = new Point3D(40, 50, 60);
    printf("Point3D class 변수의 동적 할당 : p3(%d,%d,%d)\n\n", pp3->X(), pp3->Y(), pp3->Z());  // 포인터 타입이라 '.'이 아니라 '->' 이 기호를 써줌
    printf("두 점 pp1(%d,%d,%d)과 pp2(%d,%d,%d)의 거리는 %f 입니다.\n", // pp1.X(), pp1.Y(), pp1.Z(), pp2.X(), pp2.Y(), pp2.Z(), pp1.distance(pp2));
            pp3->X(), pp3->Y(), pp3->Z(), pp2.X(), pp2.Y(), pp2.Z(), pp2.distance(*pp3));
}
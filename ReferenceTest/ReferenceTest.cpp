#include <cstdio>         // stdio.h -> cstdio
#include <iostream>       // 표준 스트림
#include "..\MyHeader.h"  // "": 절대 경로가 필요 -> C:\user\si129\~~~~\Referencetest\MyHeader.h 
                          // .\ : current directory // ..\ : 상위 디렉토리(C:\user\si129\~~~~\MyHeader.h)
using namespace std;      // std::cout 에서 std::를 제외하고 쓸 수 있다.

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
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

    double distance(Point3D p)              // Point3D p와의 거리  // 3D -> Point3D
    {
        int x2 = (X() - p.X()) * (X() - p.X());  // 명시적으로 표현
        int y2 = (Y() - p.Y()) * (Y() - p.Y());
        int z2 = (z - p.z) * (z - p.z);
        return sqrt(x2 + y2 + z2);
    }
};
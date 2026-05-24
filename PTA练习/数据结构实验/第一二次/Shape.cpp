#include <iostream>
using namespace std;

const float PI = 3.14;

// 抽象基类
class Shape {
public:
    virtual float getArea() const = 0; // 纯虚函数
    virtual ~Shape() {}               // 虚析构函数，保证派生类析构正确
};

// 圆形
class Circle : public Shape {
    float r;
public:
    Circle(float radius) : r(radius) {}
    float getArea() const override {
        return PI * r * r;
    }
};

// 正方形
class Square : public Shape {
    float s;
public:
    Square(float side) : s(side) {}
    float getArea() const override {
        return s * s;
    }
};

// 矩形
class Rectangle : public Shape {
    float r1, r2;
public:
    Rectangle(float a, float b) : r1(a), r2(b) {}
    float getArea() const override {
        return r1 * r2;
    }
};

// 三角形
class Triangle : public Shape {
    float t1, t2;
public:
    Triangle(float base, float height) : t1(base), t2(height) {}
    float getArea() const override {
        return 0.5f * t1 * t2;
    }
};

int main() {
    float r, s, r1, r2, t1, t2;
    cin >> r >> s >> r1 >> r2 >> t1 >> t2;

    // 基类指针数组
    Shape* shapes[4];
    shapes[0] = new Circle(r);
    shapes[1] = new Square(s);
    shapes[2] = new Rectangle(r1, r2);
    shapes[3] = new Triangle(t1, t2);

    float sum = 0;
    for (int i = 0; i < 4; i++) {
        sum += shapes[i]->getArea();
        delete shapes[i]; // 释放内存
    }

    cout << "Total of all areas="<<sum << endl;

    return 0;
}

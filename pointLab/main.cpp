//
//  main.cpp
//  pointLab
//
//  Created by Gabriela Avila on 11/4/25.
//

#include <iostream>
using namespace std;

class Point{
protected:
    double x;
    double y;
    
public:
    Point(double xIn, double yIn){
        x = xIn;
        y = yIn;
    }
    
    double getX() const{
        return x;
    }
    
    double getY() const{
        return y;
    }
    
    double operator-(Point p1){
        double d = sqrt(pow((p1.x) - (this->x), 2) + pow((p1.y) - (this->y), 2));
        return d;
    }
    
    int operator==(Point p1){
        if((this->x == p1.x) && (this->y == p1.y))
        {
            return 1;
        }
        return 0;
    }
    
    int operator!=(Point p1){
        if((this->x != p1.x) && (this->y != p1.y))
        {
            return 1;
        }
        return 0;
    }
    
    Point operator/(Point p1){
        return Point((this->x + p1.x) / 2 , (this->y + p1.y ) / 2);
    }
    
    Point operator++(){
        x++;
        return *this;
    }
    
    Point operator++(int _){
        y++;
        return *this;
    }
    
    Point operator--(){
        x--;
        return *this;
    }
    
    Point operator--(int _){
        y--;
        return *this;
    }
    
    double operator[](int i){
        if (i == 0){
            return x;
        }else if (i == 1){
            return y;
        }
        return 0;
    }
    
    friend istream& operator>>(istream& in, Point& p);
    
    
};

istream& operator>>(istream& in, Point& p){
    in >> p.x >> p.y;
    return in;
}

ostream& operator<<(ostream& out, const Point& p)
{
    out << "(" << p.getX() << ", " << p.getY() << ")" ;
    return out;
}

int main() {
    
    Point p1 = Point(2, 4);
    Point p2 = Point(4, 6);
    Point p3 = Point(3.2, 9.8);
    Point p4 = Point(5.5, -1.2);
    
    cout << "distance (p1 & p2): " << p1 - p2 << endl;
    
    cout << "point 1: " << p1 << endl;
    cout << "point 2: " << p2 << endl;
    cout << "point 3: " << p3 << endl;
    
    cout << "distance (p3 & p4): " << p3 - p4 << endl; // Prints out 11.238
    cout << "same point ? (0 if false 1 if true) " << (p3 == p4) << endl; // Prints out 0 (false)
    cout << "different point ? (0 if false & 1 if true) " << (p3 != p4) << endl; // Prints out 1 (true)
    cout << "midpoint (p3 & p4): " << p3 / p4 << endl;
    ++ p1;
    cout << "point 1: " << p1 << endl;
    p2 ++;
    cout << "point 2: " << p2 << endl;
    -- p3;
    cout << "point 3: " << p3 << endl;
    p3 --;
    cout << "point 3: " << p3 << endl;
    cout << "point 1 x value: " << p1[0] << endl;
    cout << "point 3 y value: " << p3[1] << endl;
    Point p5(0, 0);
    cout << "enter pt: ";
    cin >> p5;
    cout << "point 5: " << p5 << endl;
}

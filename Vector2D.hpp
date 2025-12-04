#pragma once
#include <cmath>

class Vector2D {
protected:                
    double x_, y_;
public:
    Vector2D(double x=0, double y=0);
    double x() const;  double y() const;
    void set_x(double x); void set_y(double y);
    double norm() const;

    Vector2D operator+(const Vector2D& o) const;
    Vector2D operator*(double s) const;
};

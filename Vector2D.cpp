#include "Vector2D.hpp"

Vector2D::Vector2D(double x, double y) : x_(x), y_(y) {}
double Vector2D::x() const { return x_; }
double Vector2D::y() const { return y_; }
void   Vector2D::set_x(double x){ x_ = x; }
void   Vector2D::set_y(double y){ y_ = y; }
double Vector2D::norm() const { return std::sqrt(x_*x_ + y_*y_); }

Vector2D Vector2D::operator+(const Vector2D& o) const { return Vector2D(x_+o.x_, y_+o.y_); }
Vector2D Vector2D::operator*(double s) const { return Vector2D(x_*s, y_*s); }

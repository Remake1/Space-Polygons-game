#include "Vec2.hpp"

Vec2::Vec2() {}

Vec2::Vec2(float xInit, float yInit)
    : x(xInit), y(yInit)
{}

Vec2 Vec2::operator+(const Vec2 &rhs) const {
    return {x + rhs.x, y + rhs.y};
}

Vec2 Vec2::operator-(const Vec2 &rhs) const {
    return {x - rhs.x, y - rhs.y};
}

Vec2 Vec2::operator/(const float val) const {
    return {x / val, y / val};
}

Vec2 Vec2::operator*(const float val) const {
    return {x * val, y * val};
}

void Vec2::operator+=(const Vec2 &rhs) {
    x += rhs.x;
    y += rhs.y;
}

void Vec2::operator-=(const Vec2 &rhs) {
    x -= rhs.x;
    y -= rhs.y;
}

void Vec2::operator*=(const float val) {
    x *= val;
    y *= val;
}

void Vec2::operator/=(const float val) {
    x /= val;
    y /= val;
}

bool Vec2::operator==(const Vec2 &rhs) const {
    if ( x == rhs.x && y == rhs.y ){
        return true;
    } else return false;
}

bool Vec2::operator!=(const Vec2 &rhs) const {
    if ( x == rhs.x && y == rhs.y ){
        return false;
    } else return true;
}

float Vec2::dist(const Vec2 &rhs) const {
    return sqrtf((rhs.x - x) * (rhs.x - x) + (rhs.y - y) * (rhs.y - y));
}

float Vec2::length() const {
    return sqrtf(x * x + y * y);
}

void Vec2::normalize() {
    float len = length();
    x /= len;
    y /= len;
}
#pragma once
#include <fstream>
#include <cassert>

double EPS = 10e-6;

class Angle_t {
    int degrees = 0;
    int minutes = 0;
    int seconds = 0;
public:
    Angle_t(int d, int m, int s) : degrees(d), minutes(m), seconds(s) {
        this->fix();
    }
    Angle_t() {}

    Angle_t fix() {
        long long sum = degrees * 3600 + minutes * 60 + seconds;
        degrees = sum / 3600;
        minutes = (sum - degrees * 3600) / 60;
        seconds = sum % 60;
        return *this; 
    }

    friend std::istream& operator>>(std::istream& stream, Angle_t& val) {
        stream >> val.degrees >> val.minutes >> val.seconds;
        val.fix();
        return stream;
    }
    
    friend std::ostream& operator<<(std::ostream& stream, const Angle_t& val) {
        stream << val.degrees << " " << val.minutes  << " " << val.seconds << " ";
        return stream;
    }

    Angle_t& operator+=(const Angle_t& rhs) {
        seconds += rhs.seconds;
        minutes += (rhs.minutes + seconds / 60);
        seconds = seconds % 60;
        degrees += (rhs.degrees + minutes / 60);
        minutes = minutes % 60;
        return *this;
    }

    Angle_t& operator-=(const Angle_t& rhs) {
        seconds -= rhs.seconds;
        minutes -= (rhs.minutes + seconds / 60);
        seconds = seconds % 60;
        degrees -= (rhs.degrees + minutes / 60);
        minutes = minutes % 60;
        fix();
        return *this;
    }

    Angle_t& operator*=(const double& rhs) {
        double total = 3600 * degrees + 60 * minutes + seconds;
        total *= rhs;
        long long res = round(total);
        degrees = res / 3600;
        minutes = (res - degrees * 3600) / 60;
        seconds = res % 60;
        return *this;
    }

    Angle_t& operator-() {
        *this *= -1;
        return *this;
    }

    double radians() {
        return (degrees * 3600 + minutes * 60 + seconds) * 4.84814e-6;
    }
};

Angle_t operator+(const Angle_t& lhs, const Angle_t& rhs) {
    Angle_t angle = lhs;
    angle += rhs;
    return angle;
}

Angle_t operator-(const Angle_t& lhs, const Angle_t& rhs) {
    Angle_t angle = lhs;
    angle -= rhs;
    return angle;
}

Angle_t operator*(const Angle_t& lhs, double rhs) {
    Angle_t angle = lhs;
    angle *= rhs;
    return angle;
}

Angle_t operator*(double lhs, const Angle_t& rhs) {
    Angle_t angle = rhs;
    angle *= lhs;
    return angle;
}

Angle_t operator/(const Angle_t& lhs, double rhs) {
    assert(rhs > EPS);
    Angle_t angle = lhs;
    angle *= 1/rhs;
    return angle;
}
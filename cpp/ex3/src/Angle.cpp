#include "Angle.h"

#include <cmath>

double Angle::normalize(double rad){

    if(rad < 0){
        while(rad < 0)  rad += 2*M_PI;
    }

    if(rad > 2*M_PI){
        while(rad > 2*M_PI) rad -= 2*M_PI;
    }

    return rad;
}

Angle::Angle(double _radian) : radian(_radian) {}

double Angle::convertDegToRad(double angle){
    return angle*M_PI/180;
}

double Angle::convertRadToDeg(double angle){
    return angle*180/M_PI;
}

Angle Angle::fromRadians(double radian){
    return {normalize(radian)};
}

Angle Angle::fromDegrees(double degrees){
    return {normalize(convertDegToRad(degrees))};
}

void Angle::print() const{
    std::cout << "Angle [rad]: " << radian << std::endl;
}

Angle& Angle::add(const Angle& angle){
    radian = normalize(radian + angle.radian);
    return *this;
}

double Angle::toDeg() const{
    return convertRadToDeg(radian);
}

double Angle::toRad() const{
    return radian;
}

Angle Angle::distance(const Angle& angle1, const Angle& angle2){
    double distance = fabs(angle1.radian - angle2.radian);
    return {distance};
}
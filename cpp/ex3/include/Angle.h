#ifndef ANGLE_H
#define ANGLE_H

#include <iostream>

class Angle{
private:
    double radian;

    //metoda normalizująca kąt do przedziału od 0 do 2 PI
    static double normalize(double rad);

    //konstruktor
    Angle(double _radian);

    //metoda konwertująca stopnie na radiany
    static double convertDegToRad(double angle);

    //metoda konwertująca radiany na stopnie
    static double convertRadToDeg(double angle);
public:
    //metoda fabrykująca kąt z radianów
    static Angle fromRadians(double radian);

    //metoda fabrykująca kąt ze stopni
    static Angle fromDegrees(double degree);

    //metoda wypisująca kąt
    void print() const;

    //metoda dodająca kąty
    Angle& add(const Angle& angle);

    //metoda zwracająca kąt w stopniach
    double toDeg() const;

    //metoda zwracająca kąt w radianach
    double toRad() const;

    //metoda obliczająca odległość (różnicę) między dwoma kątami
    static Angle distance(const Angle& angle1, const Angle& angle2);
};

#endif
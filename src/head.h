#pragma once
#include "include.h"
#define APP_VERSION "0.0.1";

class Athlete
{
public:
    string name, surname;
    string nationality;
};

class Sprinter60 : public Athlete
{
public:
    int skill; // 1 do 100
    double time;
    void sprint();
};

void loadAthletes(string sport);
int randomInt(int a, int b);
double randomDouble(double min, double max);
void colorText(unsigned short color, string text);
double percent(double prc, double num);
vector <Sprinter60> sprinters60;
#include "head.h"
void Sprinter60::sprint()
{
    if (skill < 1)
        skill = 1;
    if (skill > 100)
        skill = 100;

    time = 9.9 + randomDouble(-0.181, 0.181);
    time -= double(skill) / 30.75;

    double time2 = 0;
    for (time2 = 0; time2 < time; time2 += 0.01)
    {
        cout << name << " " << surname << endl
             << endl;
        cout << "Czas: " << time2;
        Sleep(10);
        cls;
    }

    cout << name << " " << surname << endl;
    cout << "Uzyskany czas: " << time << endl;
    Sleep(1000);
}

void loadAthletes(string sport)
{
    string tmp;
    fstream athletesFile;
    if (sport == "60metersSprint")
    {
        Sprinter60 spr;
        athletesFile.open("../athletes/60metersSprint.csv");
        while (getline(athletesFile, spr.name, ','))
        {
            getline(athletesFile, spr.surname, ',');
            getline(athletesFile, spr.nationality, ',');
            getline(athletesFile, tmp);
            spr.skill = stoi(tmp);
            sprinters60.push_back(spr);
        }
    }
}

int randomInt(int a, int b)
{
    /*int r1, r2[3000], r3;
    random_device dev;
    uniform_int_distribution<int> rd(a, b);
    uniform_int_distribution<int> rd1(0, 2999);
    r1 = rd1(dev);
    for (auto rr : r2)
    {
        rr = rd(dev);
    }
    r3 = r2[r1];
    return r3;*/
    random_device dev;
    uniform_int_distribution<int> rd(a, b);
    return rd(dev);
}

double randomDouble(double min, double max)
{
    srand(time(NULL));
    double rr[50];
    int rrr = randomInt(0, 49);
    for (int i = 0; i <= 49; i++)
    {
        rr[i] = ((double)rand() / RAND_MAX) * (max - min) + min;
    }
    return rr[rrr];
}

void colorText(unsigned short color, string text)
{
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hcon, color);
    cout << text;
}

double percent(double prc, double num)
{
    double sum;
    sum = (prc / 100) * num;
    return sum;
}
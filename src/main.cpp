#include "head.cpp"
int main()
{
    char choice;
    cout << "Symulator Lekkoatletyki v" << APP_VERSION;
    cout << endl;
    for (;;)
    {
        cout << "Dost©pne dyscypliny: \n1. Bieg na 60 metrow\n";
        choice = getch();
        switch (choice)
        {
        case '1':
        {
            cls;
            loadAthletes("60metersSprint");
            cout << "Wczytani sprinterzy: " << endl;
            for (auto spr : sprinters60)
            {
                cout << spr.name << " " << spr.surname << " (" << spr.nationality << ")"
                     << " (" << spr.skill << ")" << endl;
            }
            cout << "Aby zaczac wcisnij dowolny klawisz...\n";
            getch();
            for (auto sp : sprinters60)
            {
                sp.sprint();
                cout << "\nAby przejsc do nastepnego zawodnika kliknij dowolny klawisz:\n ";
                getch();
            }
        }
        default:
        {
            cls;
            continue;
        }
        }
    }
    system("pause");
}

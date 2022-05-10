//#include <iostream>
//#include <conio.h>
//#include <windows.h>
//
//using namespace std;
//
//struct FVector2D
//{
//    int X;
//    int Y;
//};
//
//void SetLocation(FVector2D NewLocation);
//
//int main()
//{
//    bool bRunning = true;
//    srand((unsigned int)time(0));
//    int BlankX = rand() % 10 + 1;
//    int BlankY = rand() % 10 + 1;
//    FVector2D PlayerPosition;
//    PlayerPosition.X = 1 + BlankX;
//    PlayerPosition.Y = 1 + BlankY;
//
//    
//        while (bRunning)
//        {
//            int KeyCode = _getch();
//
//            switch (KeyCode)
//            {
//            case 'w':
//            case 'W':
//                PlayerPosition.Y--;
//                break;
//            case 's':
//            case 'S':
//                PlayerPosition.Y++;
//                break;
//            case 'a':
//            case 'A':
//                PlayerPosition.X--;
//                break;
//            case 'd':
//            case 'D':
//                PlayerPosition.X++;
//                break;
//            case 27:
//                bRunning = false;
//                break;
//
//            }
//
//            PlayerPosition.X = PlayerPosition.X < 1 + BlankX ? 1 + BlankX : PlayerPosition.X;
//            PlayerPosition.Y = PlayerPosition.Y < 1 + BlankY ? 1 + BlankY : PlayerPosition.Y;
//            PlayerPosition.X = PlayerPosition.X > 8 + BlankX ? 8 + BlankX : PlayerPosition.X;
//            PlayerPosition.Y = PlayerPosition.Y > 8 + BlankY ? 8 + BlankY : PlayerPosition.Y;
//
//            system("cls");
//
//            for (int i = 0; i < BlankY; i++)
//            {
//                cout << endl;
//            }
//
//            for (int i = 0; i < BlankX; i++)
//            {
//                cout << " ";
//            }
//            cout << "##########" << endl;
//
//            for (int i = 0; i < 8; i++)
//            {
//                for (int i = 0; i < BlankX; i++)
//                {
//                    cout << " ";
//                }
//                cout << "#        #" << endl;
//            }
//
//            for (int i = 0; i < BlankX; i++)
//            {
//                cout << " ";
//            }
//            cout << "##########" << endl;
//
//            SetLocation(PlayerPosition);
//            cout << "P";
//
//        }
//
//    return 0;
//
//    
//
//}
//
//void SetLocation(FVector2D NewLocation)
//{
//    COORD Cur;
//    Cur.X = NewLocation.X;
//    Cur.Y = NewLocation.Y;
//    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
//}

#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

struct FVector2D
{
    int X;
    int Y;
};

char Map[10][10] = {
{'#','#','#','#','#','#','#','#','#','#'},
{'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
{'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
{'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
{'#',' ',' ',' ',' ','#',' ',' ',' ','#'},
{'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
{'#',' ',' ',' ','#',' ',' ',' ',' ','#'},
{'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
{'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
{'#','#','#','#','#','#','#','#','#','#'}
};

void SetLocation(FVector2D NewLocation);

void DrawBG(FVector2D StartPosition)
{
    for (int Y = 0; Y < 10; ++Y)
    {
        for (int X = 0; X < 10; ++X)
        {
            FVector2D Temp;
            Temp.X = X + StartPosition.X;
            Temp.Y = Y + StartPosition.Y;
            SetLocation(Temp);
            cout << Map[Y][X];
        }
    }

}

int main()
{
    bool bRunning = true;
    FVector2D PlayerPosition;
    PlayerPosition.X = 0;
    PlayerPosition.Y = 0;

    
        srand(static_cast<unsigned int>(time(nullptr)));
    FVector2D StartPosition;
    StartPosition.X = rand() % 10 + 1;
    StartPosition.Y = rand() % 10 + 1;

    while (bRunning)
    {
        int KeyCode = _getch();

        switch (KeyCode)
        {
        case 'w':
        case 'W':
            PlayerPosition.Y--;
            break;
        case 's':
        case 'S':
            PlayerPosition.Y++;
            break;
        case 'a':
        case 'A':
            PlayerPosition.X--;
            break;
        case 'd':
        case 'D':
            PlayerPosition.X++;
            break;
        case 27:
            bRunning = false;
            break;

        }

        PlayerPosition.X = PlayerPosition.X < 1 ? 1 : PlayerPosition.X;
        PlayerPosition.Y = PlayerPosition.Y < 1 ? 1 : PlayerPosition.Y;
        PlayerPosition.X = PlayerPosition.X >= 9 ? 8 : PlayerPosition.X;
        PlayerPosition.Y = PlayerPosition.Y >= 9 ? 8 : PlayerPosition.Y;

        if (Map[PlayerPosition.Y][PlayerPosition.X] == '#')
        {
            switch (KeyCode)
            {
            case 'w':
            case 'W':
                PlayerPosition.Y++;
                break;
            case 's':
            case 'S':
                PlayerPosition.Y--;
                break;
            case 'a':
            case 'A':
                PlayerPosition.X++;
                break;
            case 'd':
            case 'D':
                PlayerPosition.X--;
                break;
            case 27:
                bRunning = false;
                break;
            }

            
        }

        system("cls");

        DrawBG(StartPosition);
        FVector2D Temp;
        Temp.X = PlayerPosition.X + StartPosition.X;
        Temp.Y = PlayerPosition.Y + StartPosition.Y;
        SetLocation(Temp);
        cout << "P";
    }

    return 0;

    

}

void SetLocation(FVector2D NewLocation)
{
    COORD Cur;
    Cur.X = NewLocation.X;
    Cur.Y = NewLocation.Y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

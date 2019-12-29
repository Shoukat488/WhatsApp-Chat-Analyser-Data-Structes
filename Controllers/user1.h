#include "../Services/user1.h"
#include "../Screen/user1.h"

template<class T>
void user1( Tree<T> *data  , Tree<T> *date)
{
    clearScreen();

    int choice;
    user1_Options();
    cin >> choice;
    clearScreen();

    while (choice != 6)
    {
        clearScreen();
        
        switch (choice)
        {
            case 1:
                user1_Name(data);
                Pause();
                break;
            case 2:
                CountMessage1(data);
                Pause();
                break;
            case 3:
                MaxFreq1(data);
                Pause();
                break; 
            case 4:
                MostFreqDate1(date);
                Pause();
                break;
            case 5:
                exit(1);
                break;
            default :
                clearScreen();
        }

        clearScreen();
        user1_Options();
        cin>>choice;
        
    }

}

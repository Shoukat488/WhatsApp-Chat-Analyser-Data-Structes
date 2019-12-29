#include "../Services/user1.h"
#include "../Screen/user1.h"
void user1( Tree<string> *data )
{
    clearScreen();

    int choice;
    user1_Options();
    cin >> choice;
    clearScreen();

    while (choice != 5)
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

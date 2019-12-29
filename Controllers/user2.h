#include "../Services/user2.h"
#include "../Screen/user2.h"
template<class T>
void user2( Tree<T> *data , Tree<T> *date)
{
   clearScreen();

    int choice;
    user2_Options();
    cin >> choice;
    clearScreen();
	if(choice == 6)
	{
		cout<<"\t\t\t\t\t   ~~~~~THANK YOU~~~~~";
		exit(1);
	}
    while (choice != 7)
    {
        clearScreen();
        
        switch (choice)
        {
            case 1:
                user2_Name(data);
                Pause();
                break;
            case 2:
                CountMessage2(data);
                Pause();
                break;
            case 3:
                MaxFreq2(data);
                Pause();
                break; 
            case 4:
                MostFreqDate2(date);
                Pause();
                break;
            case 5:
                searchOnDate2(data);
                Pause();
                break;
            case 6:
                exit(1);
                break;
                
            default :
                clearScreen();
        }
        clearScreen();
        user2_Options();
        cin>>choice;
        if(choice == 6)
		{
			cout<<"\t\t\t\t\t   ~~~~~THANK YOU~~~~~";
			exit(1);
		}
        
    }
}

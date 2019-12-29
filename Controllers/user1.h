#include "../Services/user1.h"
#include "../Screen/user1.h"

 // it controlls all functionalities regarding user1
template<class T>
void user1( Tree<T> *data  , Tree<T> *date)
{
    clearScreen();

    int choice; // holds the options for user1
    user1_Options(); // shows options for user1
    cin >> choice;
    clearScreen(); 
	if(choice == 6) // it options is 6 then exit
	{
		cout<<"\t\t\t\t\t   ~~~~~THANK YOU~~~~~";
		exit(1);
	}
    while (choice != 7) // it options is 6 then back
    {
        clearScreen();
        
        switch (choice)
        {
            case 1:
                user1_Name(data); // it provides services to show name
                Pause();
                break;
            case 2:
                CountMessage1(data);// it provides services to count all messages
                Pause();
                break;
            case 3:
                MaxFreq1(data);// it provides services to find all words with maximum frequency
                Pause();
                break; 
            case 4:
                MostFreqDate1(date); // it provides services to find all dates with maximum frequency
                Pause();
                break;
            case 5:
                searchOnDate1(data);// it provides services to find all conversations all particular date
                Pause();
                break;
            case 6:
                exit(1); // exits
                break;

            default :
                clearScreen();
        }

        clearScreen();
        user1_Options(); // show options
        cin>>choice;
        if(choice == 6)
		{
			cout<<"\t\t\t\t\t   ~~~~~THANK YOU~~~~~";
			exit(1);
		}
        
    }

}

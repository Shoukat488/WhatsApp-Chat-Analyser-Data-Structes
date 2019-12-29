#include "../Services/user2.h"
#include "../Screen/user2.h"

 // it controlls all functionalities regarding user2
template<class T>
void user2( Tree<T> *data , Tree<T> *date)
{
   clearScreen();

    int choice;// holds the options for user2
    user2_Options();// shows options for user2
    cin >> choice;
    clearScreen();
	if(choice == 6) // it options is 6 then exit
	{
		cout<<"\t\t\t\t\t   ~~~~~THANK YOU~~~~~";
		exit(1);
	}
    while (choice != 7)// it options is 6 then back
    {
        clearScreen();
        
        switch (choice)
        {
            case 1:
                user2_Name(data);// it provides services to show name
                Pause();
                break;
            case 2:
                CountMessage2(data); // it provides services to count all messages
                Pause();
                break;
            case 3:
                MaxFreq2(data);// it provides services to find all words with maximum frequency
                Pause();
                break; 
            case 4:
                MostFreqDate2(date);// it provides services to find all dates with maximum frequency
                Pause();
                break;
            case 5:
                searchOnDate2(data);// it provides services to find all conversations all particular date
                Pause();
                break;
            case 6:
                exit(1);
                break;
                
            default :
                clearScreen();
        }
        clearScreen();
        user2_Options(); // show options
        cin>>choice;
        if(choice == 6)
		{
			cout<<"\t\t\t\t\t   ~~~~~THANK YOU~~~~~";
			exit(1);
		}
        
    }
}

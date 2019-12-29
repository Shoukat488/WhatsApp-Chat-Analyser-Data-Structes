#include "../Screen/relations.h"
#include "../Services/Family.h"
#include "../Services/Friend.h"
#include "../Services/Student.h"
#include "../Services/Teacher.h"
#include "../Services/AllRelations.h"
template<class T>
void Relations(Tree<T> *chat1 , Tree<T> *chat2)
{
    int choice;
    clearScreen();
    relationsOptions();
    cin>>choice;
	if(choice == 6)
	{
		cout<<"\t\t\t\t\t   ~~~~~THANK YOU~~~~~";
		exit(1);
	}
    while (choice != 7)
    {
        clearScreen();
        switch(choice)
        {
            case 1:
            studentAnalysis(chat1 , chat2);
            Pause();
            break;

            case 2:
            friendAnalysis(chat1 , chat2);
            Pause();
            break;

            case 3:
            homeAnalysis(chat1 , chat2);
            Pause();
            break;

            case 4:
            teacherAnalysis(chat1 , chat2);
            Pause();
            break;

            case 5:
            allRelations(chat1 , chat2);
            Pause();
            break;

            case 6:
            exit(1);
            break;

            default:
            clearScreen();
        }
        clearScreen();
        relationsOptions();
        cin >> choice;
        if(choice == 6)
		{
			cout<<"\t\t\t\t\t   ~~~~~THANK YOU~~~~~";
			exit(1);
		}
    }
}

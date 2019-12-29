#include <string>
#include "./DataStructure/BT.h"
#include "./Analysis/Analysis.h"
#include "./DataExtraction/AnalysisData.h"
#include "./DataExtraction/ChatData.h"
#include "./Screen/Welcome.h"
#include "./Screen/mainOptions.h"
#include "./Extra/Pause.h"
#include "./Extra/clear.h"
#include "./Controllers/user1.h"
#include "./Controllers/user2.h"
#include "./Controllers/relations.h"

int main()
{
    int choice;
    Tree<string> *chatTree1 , *chatTree2 , *dateTree;
    dateTree = new Tree<string>();
    chatTree1 = new Tree<string>();
    chatTree2 = new Tree<string>();
    ifstream file("./data/chat/chat.txt");
    extractChatData(file , chatTree1 , chatTree2 , dateTree);

    WelcomeNote();
    cout<<endl;
    Pause();
    clearScreen();

    mainOptions();
    cin>>choice;

    while (choice != 4)
    {
        switch(choice)
        {
            case 1:
                user1(chatTree1);
                break;
            case 2:
                user2(chatTree2);
                break;
            case 3:
                Relations(chatTree1 , chatTree2);
                break;
            case 4:
                exit(1);
            default:
                clearScreen();
        }

        clearScreen();
        mainOptions();
        cin>>choice;
    }

}
#include <string>
#include "./DataStructure/BT.h"
#include "./Analysis/Analysis.h"
#include "./Analysis/Student.h"
#include "./Analysis/Family.h"
#include "./Analysis/Teacher.h"
#include "./Analysis/Friend.h"
#include "./DataExtraction/AnalysisData.h"
#include "./DataExtraction/ChatData.h"
#include "./Screen/Welcome.h"
#include "./Screen/mainOptions.h"
#include "./Extra/Pause.h"
#include "./Extra/clear.h"
#include "./Controllers/user1.h"
#include "./Controllers/user2.h"

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

                break;
            case 4:
                exit(1);
            default:
            Pause();
        }

        clearScreen();
        mainOptions();
        cin>>choice;
    }



    // cout<<chatTree1->root->user<<endl;
    // cout<<endl;
    // cout<<chatTree2->root->user<<endl;
    // studentAnalysis(chatTree1,chatTree2);
    // friendAnalysis(chatTree1 , chatTree2);
    // homeAnalysis(chatTree1 , chatTree2);
    // teacherAnalysis(chatTree1 , chatTree2 );
}

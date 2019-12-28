#include "./DataStructure/BT.h"
#include "./Analysis/Analysis.h"
#include "./Analysis/Student.h"
#include "./Analysis/Family.h"
#include "./Analysis/Teacher.h"
#include "./Analysis/Friend.h"
#include "./DataExtraction/AnalysisData.h"
#include "./DataExtraction/ChatData.h"
#include "./Screen/Welcome.h"

int main()
{
    WelcomeNote();
    system("PAUSE");
    Tree<string> *chatTree1 , *chatTree2 , *dateTree;
    chatTree1 = new Tree<string>();
    chatTree2 = new Tree<string>();
    dateTree = new Tree<string>();
    ifstream file("./data/chat/chat.txt");
    extractChatData(file , chatTree1 , chatTree2 , dateTree);
    cout<<chatTree1->root->user<<endl;
    cout<<endl;
    cout<<chatTree2->root->user<<endl;
    studentAnalysis(chatTree1,chatTree2);
    friendAnalysis(chatTree1 , chatTree2);
    homeAnalysis(chatTree1 , chatTree2);
    teacherAnalysis(chatTree1 , chatTree2 );
}
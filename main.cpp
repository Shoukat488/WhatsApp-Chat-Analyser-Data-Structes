#include "BT.h"
#include "Extract.h"
#include "Analysis.h"
using namespace std;
int main()
{
    Tree<string> *chatTree1 , *chatTree2 , *dateTree;
    chatTree1 = new Tree<string>();
    chatTree2 = new Tree<string>();
    dateTree = new Tree<string>();
    ifstream file("./data/chat/chat.txt");
    extractChatData(file , chatTree1 , chatTree2 , dateTree);
    // dateTree->BFS();
    cout<<"User 1 : ";
    cout<<chatTree1->root->user<<endl;
    // chatTree1->BFS();
    cout<<"User 2: ";
    cout<<chatTree2->root->user<<endl;
    // chatTree2->BFS()
    cout<<endl;
    AnalysisData(chatTree1, chatTree2);
}

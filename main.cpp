#include "BT.h"
#include "Extract.h"
#include "Analysis.h"
int main()
{
    Tree<string> *chatTree1 , *chatTree2 , *dateTree;
    chatTree1 = new Tree<string>();
    chatTree2 = new Tree<string>();
    dateTree = new Tree<string>();
    ifstream file("./data/chat/chat.txt");
    extractData(file , chatTree1 , chatTree2 , dateTree);
    dateTree->BFS();
    cout<<chatTree1->root->user<<endl;
    chatTree1->BFS();
    cout<<endl;
    cout<<chatTree2->root->user<<endl;
    chatTree2->BFS();
}

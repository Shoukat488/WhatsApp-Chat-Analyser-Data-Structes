
// finds relations on the basis of friend
template<class T>
void friendAnalysis(Tree<T> *chat1 ,Tree<T> *chat2 )
{
    ifstream friendFile("./data/analysis/friendsWords.txt");
    Tree<T> *Friend = new Tree<T>(); 
    extractAnalysisData(Friend , friendFile);

    float percent =  makeAnalysis(chat1 , chat2 , Friend );
    cout <<"\t\t\t\tFriend : "<< percent << "%" << endl<<endl;

    friendFile.close();
}

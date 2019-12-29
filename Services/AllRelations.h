template<class T>
void allRelations(Tree<T> *chat1 , Tree<T>* chat2)
{
    studentAnalysis(chat1,chat2);
    friendAnalysis(chat1 , chat2);
    homeAnalysis(chat1 , chat2);
    teacherAnalysis(chat1 , chat2 ); 
}
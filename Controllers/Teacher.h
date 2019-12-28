template<class T>
void teacherAnalysis(Tree<T> *chat1 ,Tree<T> *chat2 )
{
    ifstream teacherFile("./data/analysis/teacherWords.txt");
    Tree<T> *Teacher = new Tree<T>();
    extractAnalysisData(Teacher , teacherFile);

    float percent =  makeAnalysis(chat1 , chat2 , Teacher );
    cout << "Teacher : "<< percent << "%" << endl;
}
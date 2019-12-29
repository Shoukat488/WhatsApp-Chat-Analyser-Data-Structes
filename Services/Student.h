
template<class T>
void studentAnalysis( Tree<T> *chat1 , Tree<T> *chat2  )
{
    ifstream studentFile("./data/analysis/studentWords.txt");
    Tree<T> *Student = new Tree<T>(); 
    extractAnalysisData(Student , studentFile);
    
    float percent =  makeAnalysis(chat1 , chat2 , Student);
    cout << "Student : "<< percent << "%" << endl;

    studentFile.close();
}

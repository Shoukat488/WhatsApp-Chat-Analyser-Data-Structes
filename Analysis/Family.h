template<class T>
void homeAnalysis(Tree<T> *chat1 ,Tree<T> *chat2 )
{
    ifstream homeFile("./data/analysis/homeWords.txt");
    Tree<T> *Home = new Tree<T>(); 
    extractAnalysisData(Home , homeFile);

    float percent =  makeAnalysis(chat1 , chat2 , Home );
    cout << "Family person : "<< percent << "%" << endl;
    
    homeFile.close();
}

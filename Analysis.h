#include<fstream>

template<class T>
void AnalysisData(Tree<T> *chatTree1 , Tree<T> *chatTree2 )
{
    ifstream friendFile("./data/analysis/friendsWords.txt");
    ifstream homeFile("./data/analysis/homeWords.txt");
    ifstream relativeFile("./data/analysis/relativeWords.txt");
    ifstream studentFile("./data/analysis/studentWords.txt");
    ifstream teacherFile("./data/analysis/teacherWords.txt");

    Tree<T> Friend; 
    Tree<T> Home ; 
    Tree<T> Relative ; 
    Tree<T> Student ; 
    Tree<T> Teacher ;

    extractAnalysisData(&Friend , friendFile);
    extractAnalysisData(&Home , homeFile);
    extractAnalysisData(&Relative , relativeFile);
    extractAnalysisData(&Student , studentFile);
    extractAnalysisData(&Teacher , teacherFile);

    
}

template<class T>
void studentAnalysis(Tree<T> *chat , Tree<T> *data)
{
    
}
template<class T>
void homeAnalysis()
{

}
template<class T>
void friendAnalysis()
{

}
template<class T>
void teacherAnalysis()
{

}
template<class T>
void relativeAnalysis()
{

}
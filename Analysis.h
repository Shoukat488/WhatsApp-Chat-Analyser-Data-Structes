#include<fstream>

template<class T>
void AnalysisData(Tree<T> *chatTree1 , Tree<T> *chatTree2 )
{
    ifstream friendFile("./data/analysis/friendsWords.txt");
    ifstream homeFile("./data/analysis/homeWords.txt");
    ifstream studentFile("./data/analysis/studentWords.txt");
    ifstream teacherFile("./data/analysis/teacherWords.txt");

    Tree<T> *Friend = new Tree<T>(); 
    Tree<T> *Home = new Tree<T>(); 
    Tree<T> *Student = new Tree<T>(); 
    Tree<T> *Teacher = new Tree<T>();

    extractAnalysisData(Friend , friendFile);
    extractAnalysisData(Home , homeFile);
    extractAnalysisData(Student , studentFile);
    extractAnalysisData(Teacher , teacherFile);

    studentAnalysis(chatTree1 , chatTree2 , Student);
    homeAnalysis(chatTree1 , chatTree2 , Home);
    friendAnalysis(chatTree1 , chatTree2 , Friend);
    teacherAnalysis(chatTree1 , chatTree2 , Teacher);


    friendFile.close();
    homeFile.close();
    studentFile.close();
    teacherFile.close();

    
}

template<class T>
void studentAnalysis(Tree<T> *chat1 ,Tree<T> *chat2 , Tree<T> *data)
{
    float percent =  makeAnalysis(chat1 , chat2 , data );
    if(percent < 1)
    percent = 0;
    cout << "Student : "<< percent << "%" << endl;
}

template<class T>
void homeAnalysis(Tree<T> *chat1 ,Tree<T> *chat2 , Tree<T> *data)
{
    float percent =  makeAnalysis(chat1 , chat2 , data );
    if(percent < 1)
    percent = 0;
    cout << "Family person : "<< percent << "%" << endl;
}

template<class T>
void friendAnalysis(Tree<T> *chat1 ,Tree<T> *chat2 , Tree<T> *data)
{
    float percent =  makeAnalysis(chat1 , chat2 , data );
    if(percent < 1)
    percent = 0;
    cout << "Friend : "<< percent << "%" << endl;
}

template<class T>
void teacherAnalysis(Tree<T> *chat1 ,Tree<T> *chat2 , Tree<T> *data)
{
    float percent =  makeAnalysis(chat1 , chat2 , data );
    if(percent < 1)
    percent = 0;
    cout << "Teacher : "<< percent << "%" << endl;
}

template<class T>
float makeAnalysis( Tree<T> *chat1 , Tree<T> *chat2 , Tree<T> *data )
{
    TreeNode<T> *temp = data->getRoot();
    stack<TreeNode<T> *> tempStack;
    TreeNode<T> *foundObj;
    
    long long int findCount = 0;
    long long int freqSum = 0;
    long long int totalFreqSum = 0;

    float freqPercent = 0;
    float wordsPercent = 0;
    float finalPercent = 0;

	while (temp != NULL || !tempStack.empty())
	{
		while (temp != NULL)
		{
            totalFreqSum += temp->frequency;
            foundObj = chat1->search(temp->data);

            if(foundObj)
            {
                (findCount)++;
                freqSum += foundObj->frequency;
            }
            foundObj = chat2->search(temp->data);
            if(foundObj)
            {
                (findCount)++;
                freqSum += foundObj->frequency;
            }

			tempStack.push(temp);
			temp = temp->leftNode;
		}
		if(!tempStack.empty())
		{
			temp = tempStack.top();
			tempStack.pop();
		}
		temp = temp->rightNode;
	}

    freqPercent = ((float)freqSum/totalFreqSum); 
    wordsPercent = (float) findCount/( data->getCount() ) ;
    finalPercent =  ( (float)freqPercent + wordsPercent )   ;
    finalPercent = (float)finalPercent * ( 100 );

    // if(finalPercent < 50)
    // finalPercent += 50;
    // else if(finalPercent < 60)
    // finalPercent += 30;
    return finalPercent;
}

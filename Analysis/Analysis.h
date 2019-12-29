#include<fstream>
//-------------------------------------------------------------------------------//
// This function make analysis between two users

template<class T>
float makeAnalysis( Tree<T> *chat1 , Tree<T> *chat2 , Tree<T> *data )
{
    TreeNode<T> *temp = data->getRoot();
    stack<TreeNode<T> *> tempStack; // temp stack
    TreeNode<T> *foundObj; // it holds the object which is present in data analysis data
    long long int findCount = 0; // sum all words which matchs
    long long int freqSum = 0; // sum all frequencies which match
    long long int totalFreqSum = 0; // total  frequency
    float freqPercent = 0; // holds perent for freq
    float wordsPercent = 0; // holds percent for words
    float finalPercent = 0; // holds final percent

//-------------------------------------------------------//
// The below code run in a DFS fashion
	while (temp != NULL || !tempStack.empty())
	{
		while (temp != NULL)
		{
            // sum freq
            totalFreqSum += temp->frequency;

            // finds object on given in chat1
            foundObj = chat1->search(temp->data); 

            // if object is found then increase findcount and sum freq into freqSum
            if(foundObj) 
            {
                (findCount)++;
                freqSum += foundObj->frequency;
            }

            // finds object on given in chat1
            foundObj = chat2->search(temp->data);

            // if object is found then increase findcount and sum freq into freqSum
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

//----------------------------------------------------------//

    // make calculation for finding freq percent
    // make calculation for finding word percent
    // make calculation for finding final percent by using freq and word percent
    freqPercent = ((float)freqSum/totalFreqSum)*0.8;
    wordsPercent = (float) findCount/( data->getCount() ) ;
    wordsPercent = (float) wordsPercent * 0.9;
    finalPercent =  ( (float)freqPercent + wordsPercent )   ;
    finalPercent = (float)finalPercent * 100;

    return finalPercent; // return percent
}

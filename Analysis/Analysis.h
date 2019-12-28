#include<fstream>

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

    freqPercent = ((float)freqSum/totalFreqSum)*0.8;
    wordsPercent = (float) findCount/( data->getCount() ) ;
    wordsPercent = (float) wordsPercent * 0.9;
    finalPercent =  ( (float)freqPercent + wordsPercent )   ;
    finalPercent = (float)finalPercent * 100;

    // if(finalPercent < 50)
    // finalPercent += 50;
    // else if(finalPercent < 60)
    // finalPercent += 30;
    return finalPercent;
}

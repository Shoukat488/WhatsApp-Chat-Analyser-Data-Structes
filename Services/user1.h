template<class T>
void user1_Name(Tree<T> *data)
{
    cout<<"User1 Name: "<<endl;
    cout<<data->root->user<<endl;
}

template<class T>
void MaxFreq1( Tree<T> *data)
{
    cout<<"Most Repeated Word"<<endl;
    cout<<data->maxFreq()<<endl;
}

template<class T>
void CountMessage1(Tree<T> *data)
{
    cout<<"No. of Messages: "<<endl;
    cout<<data->getCount()<<endl;
}
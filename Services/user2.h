template<class T>
void user2_Name(Tree<T> *data)
{
    cout<<"User2 Name: "<<endl;
    cout<<data->root->user<<endl;
}

template<class T>
void MaxFreq2( Tree<T> *data)
{
    cout<<"Most Repeated Word"<<endl;
    cout<<data->maxFreq()<<endl;
}

template<class T>
void CountMessages2(Tree<T> *data)
{
    cout<<"No. of Messages: "<<endl;
    cout<<data->getCount()<<endl;
}
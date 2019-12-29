template<class T>
void user2_Name(Tree<T> *data)
{
    cout<<"\t\t\t\t\tUser1 Name: "<<endl<<endl;
    cout<<"\t\t\t\t\t"<<data->root->user<<endl;
}

template<class T>
void MaxFreq2( Tree<T> *data)
{
    cout<<"\t\t\t\t\tMost Repeated Word"<<endl<<endl;
    cout<<"\t\t\t\t\t\t";
	data->getFreqWords();
}

template<class T>
void CountMessage2(Tree<T> *data)
{
    cout<<"\t\t\t\t\tNo. of Messages: "<<endl<<endl;
    cout<<"\t\t\t\t\t\t"<<data->getCount()<<endl;
}

template<class T>
void MostFreqDate2(Tree<T> * date)
{
    cout<<"\t\t\t\tMost conversations done by user 1 on : "<<endl<<endl;
    cout<<"\t\t\t\t\t";
    date->getFreqWords();
}

template<class T>
void searchOnDate2(Tree<T> *data  )
{
    string reqDate;
    string reqUser = data->root->user;
    string user1 = "";
    string user2 = "";
    string lastUser = "";
    string element;
    string date;
    bool flag = false;

    ifstream file("./data/chat/chat.txt");
    if(!file)
    cout<<"Failed to open "<<endl;
    cout <<"\t\t\t\t Enter date (e.g 7/8/20) :  ";
    cin >> reqDate;
    cout<<endl<<endl;
    while (file)
    {
        file>>element;
        if(element == "<Media" || element == "omitted>")
        continue;

        if( (element.length() == 9 || element.length() == 8 || element.length() == 7) && (element[1] == '/' || element[2] == '/' ) && (element[4] == '/' || element[5] == '/' || element[3] == '/'))
        {
            date = element.substr(0 , element.length() -1 );
            if(date == reqDate  && lastUser == reqUser )
            cout<<endl;
            for(int i = 0 ; i < 3 ; i++) file>>element;
            lastUser = "";
            file>>element;
            if(element[element.length()-1] != ':')
            {
                lastUser = "";
                while (element[element.length()-1] != ':') 
                {
                    lastUser += element + " ";
                    file>>element;
                }
                lastUser += element.substr(0 , element.length() -1 );
            }
            else
            lastUser = element.substr(0 , element.length() - 1 );
            
            if(user1 == "" && user2 != lastUser)
            {
                user1 = lastUser;
            }
            else if(user2 == "" && user1 != lastUser)
            {
                user2 = lastUser;
            }
        }
        else
        {
            if(lastUser == reqUser && date == reqDate)
            {
                cout<<element<<" ";
                flag = true;
            }
        }
    }

    file.close();
    if(flag == false)
    cout<<"Not Found"<<endl;

}
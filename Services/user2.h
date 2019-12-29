// it provides services to show name
template<class T>
void user2_Name(Tree<T> *data)
{
    cout<<"\t\t\t\t\tUser1 Name: "<<endl<<endl;
    cout<<"\t\t\t\t\t"<<data->root->user<<endl;
}

// it provides services to count all messages
template<class T>
void MaxFreq2( Tree<T> *data)
{
    cout<<"\t\t\t\t\tMost Repeated Word"<<endl<<endl;
    cout<<"\t\t\t\t\t\t";
	data->getFreqWords();
}

// it provides services to find all words with maximum frequency
template<class T>
void CountMessage2(Tree<T> *data)
{
    cout<<"\t\t\t\t\tNo. of Messages: "<<endl<<endl;
    cout<<"\t\t\t\t\t\t"<<data->getCount()<<endl;
}

// it provides services to find all dates with maximum frequency
template<class T>
void MostFreqDate2(Tree<T> * date)
{
    cout<<"\t\t\t\tMost conversations done by user 1 on : "<<endl<<endl;
    cout<<"\t\t\t\t\t";
    date->getFreqWords();
}

// it provides services to find all conversations on particular date
template<class T>
void searchOnDate2(Tree<T> *data  )
{
    string reqDate; // it holds the given date
    string reqUser = data->root->user;
    string user1 = "";// holds user1
    string user2 = "";// holds user2
    string lastUser = ""; // holds last user
    string element; // holds each word
    string date; // holds date
    bool flag = false; // determines status for search

    // opens file containing chat
    ifstream file("./data/chat/chat.txt");
    if(!file)
    cout<<"Failed to open "<<endl;

    //Get date from user
    cout <<"\t\t\t\t Enter date (e.g 7/8/20) :  ";
    cin >> reqDate;
    cout<<endl<<endl;

    while (file)
    {
        file>>element;
        if(element == "<Media" || element == "omitted>")// omit these words
        continue;

        // if below given criteria is meet it means the element is date
        if( (element.length() == 9 || element.length() == 8 || element.length() == 7) && (element[1] == '/' || element[2] == '/' ) && (element[4] == '/' || element[5] == '/' || element[3] == '/'))
        {
            
            date = element.substr(0 , element.length() -1 );// save date
            if(date == reqDate && lastUser == reqUser) //end of line is found
            cout<<endl;

            // leave three words/characters which are time, 'pm' and '-'
            for(int i = 0 ; i < 3 ; i++) file>>element;

            lastUser = "";// reset last user
            file>>element;

            // if name is greater than one word find full name
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
            lastUser = element.substr(0 , element.length() - 1 );// escape ':'

            // if laster user and user2 are not same and user1 is empty then set user1
            if(user1 == "" && user2 != lastUser)
            {
                user1 = lastUser;
            }

            // if laster user and user2 are not same and user1 is empty then set user1
            else if(user2 == "" && user1 != lastUser)
            {
                user2 = lastUser;
            }
        }
        else
        {
            // if lastuser is equal to req user and date is equal to req date then show element
            if(lastUser == reqUser && date == reqDate)
            {
                cout<<element<<" ";
                flag = true;
            }
        }
    }

    cout<<endl;
    if(flag == false)
    cout<<"Not Found"<<endl;
    

}

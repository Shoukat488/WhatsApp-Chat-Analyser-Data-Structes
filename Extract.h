template<class T>
void extractData(ifstream &file , Tree<T> *chatTree1 , Tree<T> *chatTree2 ,  Tree<T> *dataTree)
{
    string user1 = "";
    string user2 = "";
    string lastUser = "";
    string element;
    while (file)
    {
        file>>element;
        if(element == "<Media" || element == "omitted>")
        continue;
        transform(element.begin() ,element.end() , element.begin() , ::tolower);

        if( (element.length() == 9 || element.length() == 8 || element.length() == 7) && (element[1] == '/' || element[2] == '/' ) && (element[4] == '/' || element[5] == '/' || element[3] == '/'))
        {
            string date = element;
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
            dataTree->insert(date , lastUser);
        }
        else if (element.length() > 1 || (element == "i" || element == "?") )
        {
            if(lastUser == user1)
            chatTree1->insert(element , user1);
            else
            chatTree2->insert(element , user2);
        }
    }
    

}
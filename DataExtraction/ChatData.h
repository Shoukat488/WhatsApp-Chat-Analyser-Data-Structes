
// this function extract from conversation
template<class T>
void extractChatData(ifstream &file , Tree<T> *chatTree1 , Tree<T> *chatTree2 ,  Tree<T> *dataTree)
{

    string user1 = ""; // holds user1
    string user2 = ""; // holds user2
    string lastUser = ""; // holds last user
    string element; // holds each word

    while (file)
    {
        file>>element; 
        if(element == "<Media" || element == "omitted>")// omit these words
        continue;
        transform(element.begin() ,element.end() , element.begin() , ::tolower); // convert into lower case

        // if below given criteria is meet it means the element is date
        if( (element.length() == 9 || element.length() == 8 || element.length() == 7) && (element[1] == '/' || element[2] == '/' ) && (element[4] == '/' || element[5] == '/' || element[3] == '/'))
        {
            string date = element; // save date
            for(int i = 0 ; i < 3 ; i++) file>>element; // leave three words/characters which are time, 'pm' and '-'
            lastUser = ""; // reset last user
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
            lastUser = element.substr(0 , element.length() - 1 ); // escape ':'
            
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
            dataTree->insert(date , lastUser); // insert date and username into date tree structure
        }

        // it pust all others word except the given conditions
        else if (element.length() > 1 || (element == "i" || element == "?") )
        {
            // if lastuser is equal to user1 then insert data into chat tree 1
            if(lastUser == user1) 
            chatTree1->insert(element , user1);
            // if lastuser is equal to user2 then insert data into chat tree 2
            else 
            chatTree2->insert(element , user2);
        }
    }
}
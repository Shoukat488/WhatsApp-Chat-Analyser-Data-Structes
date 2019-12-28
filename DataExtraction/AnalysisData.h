template<class T>
void extractAnalysisData(Tree<T> *emptyObj , ifstream &file)
{
    string element;
    while (file)
    {
        file>>element;
        transform(element.begin() ,element.end() , element.begin() , ::tolower);
        emptyObj->insert(element);
    }
}

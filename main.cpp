#include <iostream> //Line 1
#include "arrayListType.h" //Line 2
using namespace std;
#include <vector>

template<class Type>
int recSeqSearch(const vector<Type> &a, const Type &x, const int size)
{
    //we will start from the back of the list
    //if we have found it, return where we found it
    if(a[size]== x)
    {
        return size;
    }

    //if we haven't found it but have more items to search, call the function again from the next  item down on the list
    else if ((a[size]!= x) && (size!=0))
    {

        recSeqSearch(a,x, size-1);
    }

    //if we have reached the first item in the vector list, then there is no more to search, so the item is not in the list
    //return -1 to let the user and main function know that the search was unsuccessful
    else if ((a[size]!=x) && (size==0))
    {
        return -1;
    }

}

template <class Type>
int sequentialSearch(const vector<Type> &a, const Type &x)
{
    //call the recursive sequential search function
    return recSeqSearch(a,x,a.size()-1);
}



using namespace std; //Line 3
int main() //Line 4
{ //Line 5
    arrayListType<int> list; //Line 6
    int num; //Line 7
    cout << "Line 8: Enter numbers ending with -999"<< endl; //Line 8
    cin >> num; //Line 9
    while (num != -999) //Line 10
    {
        list.insert(num);
        cin >> num;
    }
    cout << "list before sorting:" << endl; //Line 15
    list.print(); //Line 16
    cout << endl; //Line 17
    list.quickSort(); //Line 18
    cout << "Line 19: The list after sorting:" << endl; //Line 19
    list.print(); //Line 20
    cout << endl; //Line 21
    //create a vector list
    vector<int> intList;
    //user will enter the vector list
    int entry;
    //we will iterate throught the vector list
    vector<int>::iterator index;
    //prompt user to enter data
    cout << endl<<"We will now create a vector. Enter numbers ending with -999"<< endl; //Line 8
    cin >> entry;
    //enter data into vector
    while (entry != -999)
    {
        intList.push_back(entry);
        cin >> entry;
    }

    //let's check we have the vector list by printing to the screen
    cout<<endl<<"Okay here is your vector list: ";
    index=intList.begin();
    for(index=intList.begin(); index!=intList.end(); index++)
    {
        cout<<*index<<" ";
    }

    //now we search for an item for the user
    cout<<endl<<"Okay, what should we search for?";
    int searchItem;
    cin>>searchItem;

    //call the recursive sequential search function
    int found = sequentialSearch(intList, searchItem);

    //let the user know if the item was found or not.
    if(found!=-1)
        cout<<"It's in the list at position"<<found+1;
    else
        cout<<"It is not in the list.";



return 0; //Line 22
}

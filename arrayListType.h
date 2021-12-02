#ifndef ARRAYLISTTYPE_H
#define ARRAYLISTTYPE_H
#include <iostream>
using namespace std;
#include <cassert>


template <class elemType>
class arrayListType
{
    public:
        const arrayListType<elemType>& operator=(const arrayListType<elemType>&);
        bool isEmpty() const;
        bool isFull() const;
        int listSize() const;
        int maxListSize() const;
        void print() const;
        bool isItemAtEqual(int location, const elemType& item) const;
        void insertAt(int location, const elemType& insertItem);
        void insertEnd(const elemType& insertItem);
        void removeAt(int location);
        void retrieveAt(int location, elemType& retItem) const;
        void replaceAt(int location, const elemType& repItem);
        void clearList();
        int seqSearch(const elemType& item) const;
        void insert(const elemType& insertItem);
//        void orderedArrayListType<elemType>::insertOrd(const elemType& item);
        void remove(const elemType& removeItem);
        arrayListType(int size = 100);
        arrayListType(const arrayListType<elemType>& otherList);
        ~arrayListType();
        void selectionSort();
        void insertionSort();
//        void shellSort();
        int partition(int first, int last);
        void recQuickSort(int first, int last);
        void quickSort();



    protected:
        elemType *list; //array to hold the list elements
        int length; //to store the length of the list
        int maxSize; //to store the maximum size of the list

    private:
        int minLocation(int first, int last);
        void swap(int first, int second);
};
template <class elemType>
void arrayListType<elemType>::quickSort()
{
    recQuickSort(0, length -1);
}
template <class elemType>
int arrayListType<elemType>::partition(int first, int last)
{
    elemType pivot;
    int index, smallIndex;
    swap(first, (first + last) / 2);
    pivot = list[first];
    smallIndex = first;
    for (index = first + 1; index <= last; index++)
        if (list[index] < pivot)
        {
            smallIndex++;
            swap(smallIndex, index);
        }
    swap(first, smallIndex);
return smallIndex;
}

template <class elemType>
void arrayListType<elemType>::recQuickSort(int first, int last)
{
    int pivotLocation;
    if (first < last)
    {
        print();
        pivotLocation = partition(first, last);
        recQuickSort(first, pivotLocation - 1);
        recQuickSort(pivotLocation + 1, last);
    }
}

template <class elemType>
void arrayListType<elemType>::insertionSort()
{
    int firstOutOfOrder, location;
    elemType temp;
    for (firstOutOfOrder = 1; firstOutOfOrder < length; firstOutOfOrder++)
    {
    print();
        if (list[firstOutOfOrder] < list[firstOutOfOrder - 1])
        {
            temp = list[firstOutOfOrder];
            location = firstOutOfOrder;
            do
            {
                list[location] = list[location - 1];
                location--;
            }
            while (location > 0 && list[location - 1] > temp);
            list[location] = temp;
        }
    }

} //end insertionSort


template <class elemType>
void arrayListType<elemType>::selectionSort()
{
    int minIndex;
    for (int loc = 0; loc < length - 1; loc++)
    {
        cout<<"The list is now: "<<endl;
        print();
        minIndex = minLocation(loc, length - 1);
        swap(loc, minIndex);
    }
}

template <class elemType>
void arrayListType<elemType>::swap(int first, int second)
{
    elemType temp;
    temp = list[first];
    list[first] = list[second];
    list[second] = temp;
}


template <class elemType>
int arrayListType<elemType>::minLocation(int first, int last)
{
    int minIndex;
    minIndex = first;
    for (int loc = first + 1; loc <= last; loc++)
        if( list[loc] < list[minIndex])
            minIndex = loc;
    return minIndex;
} //end minLocation

template <class elemType>
bool arrayListType<elemType>::isEmpty() const
{
    return (length == 0);
}

template <class elemType>
bool arrayListType<elemType>::isFull() const
{
    return (length == maxSize);
}

template <class elemType>
int arrayListType<elemType>::listSize() const
{
    return length;
}

template <class elemType>
int arrayListType<elemType>::maxListSize() const
{
    return maxSize;
}

template <class elemType>
void arrayListType<elemType>::print() const
{
    for (int i = 0; i < length; i++)
        cout << list[i] << " ";
        cout << endl;
}

template <class elemType>
bool arrayListType<elemType>::isItemAtEqual
(int location, const elemType& item) const
{
    return(list[location] == item);
}

template <class elemType>
void arrayListType<elemType>::insertAt
(int location, const elemType& insertItem)
{
    if (location < 0 || location >= maxSize)
        cerr << "The position of the item to be inserted "
        << "is out of range" << endl;

    else
        if (length >= maxSize) //list is full
            cerr << "Cannot insert in a full list" << endl;
        else
            {
                for (int i = length; i > location; i--)
                    list[i] = list[i - 1]; //move the elements down
                list[location] = insertItem; //insert the item at the
                    //specified position
                length++; //increment the length
            }
} //end insertAt

template <class elemType>
void arrayListType<elemType>::insertEnd(const elemType& insertItem)
{
    if (length >= maxSize) //the list is full
        cerr << "Cannot insert in a full list" << endl;
    else
        {
            list[length] = insertItem; //insert the item at the end
            length++; //increment the length
        }
} //end insertEnd

template <class elemType>
void arrayListType<elemType>::removeAt(int location)
{
    if (location < 0 || location >= length)
        cerr << "The location of the item to be removed "
        << "is out of range" << endl;
    else
        {
            for (int i = location; i < length - 1; i++)
                list[i] = list[i+1];
            length--;
        }
} //end removeAt

template <class elemType>
void arrayListType<elemType>::retrieveAt
(int location, elemType& retItem) const
{
    if (location < 0 || location >= length)
        cerr << "The location of the item to be retrieved is "
        << "out of range." << endl;
    else
        retItem = list[location];
} //end retrieveAt

template <class elemType>
void arrayListType<elemType>::replaceAt
(int location, const elemType& repItem)
{
    if (location < 0 || location >= length)
            cerr << "The location of the item to be replaced is "
            << "out of range." << endl;
    else
        list[location] = repItem;
} //end replaceAt

template <class elemType>
void arrayListType<elemType>::clearList()
{
    length = 0;
} //end clearList

template <class elemType>
arrayListType<elemType>::arrayListType(int size)
{
    if (size < 0)
    {
        cerr << "The array size must be positive. Creating "
            << "an array of size 100. " << endl;
        maxSize = 100;
    }
    else
        maxSize = size;
        length = 0;
        list = new elemType[maxSize];
        assert(list != NULL);
}

template <class elemType>
arrayListType<elemType>::~arrayListType()
{
    delete [] list;
}

template <class elemType>
arrayListType<elemType>::arrayListType
            (const arrayListType<elemType>& otherList)
{
        maxSize = otherList.maxSize;
        length = otherList.length;
        list = new elemType[maxSize]; //create the array
        assert(list != NULL); //terminate if unable to allocate
                            //memory space
        for (int j = 0; j < length; j++) //copy otherList
            list [j] = otherList.list[j];
} //end copy constructor

template <class elemType>
const arrayListType<elemType>& arrayListType<elemType>::operator=
(const arrayListType<elemType>& otherList)
{
    if (this != &otherList) //avoid self-assignment
    {
        delete [] list;
        maxSize = otherList.maxSize;
        length = otherList.length;
        list = new elemType[maxSize]; //create the array
        assert(list != NULL); //if unable to allocate memory
        //space, terminate the program
        for (int i = 0; i < length; i++)
            list[i] = otherList.list[i];
    }
return *this;
}

template <class elemType>
int arrayListType<elemType>::seqSearch(const elemType& item) const
{
    int loc;
    bool found = false;
    for (loc = 0; loc < length; loc++)
    if (list[loc] == item)
    {
        found = true;
        break;
    }
    if (found)
        return loc;
    else
        return -1;
} //end seqSearch

template <class elemType>
void arrayListType<elemType>::insert(const elemType& insertItem)
{
    int loc;
    if (length == 0) //list is empty
        list[length++] = insertItem; //insert the item and
        //increment the length
    else if (length == maxSize)
        cerr << "Cannot insert in a full list." << endl;
    else
    {
        loc = seqSearch(insertItem);
        if (loc == -1) //the item to be inserted
        //does not exist in the list
            list[length++] = insertItem;
        else
            cerr << "the item to be inserted is already in "
            << "the list. No duplicates are allowed." << endl;
    }
} //end insert

template<class elemType>
void arrayListType<elemType>::remove(const elemType& removeItem)
{
    int loc;
    if (length == 0)
        cerr << "Cannot delete from an empty list." << endl;
    else
    {
        loc = seqSearch(removeItem);
        if (loc != -1)
            removeAt(loc);
        else
            cout << "The item to be deleted is not in the list."
            << endl;
    }
} //end remove

/*template <class elemType>
void orderedArrayListType<elemType>::insertOrd(const elemType& item)
{
    int first = 0;
    int last = length - 1;
    int mid;
    bool found = false;
    if (length == 0) //the list is empty
    {
        list[0] = item;
        length++;
    }
    else if (length == maxSize)
        cerr << "Cannot insert into a full list." << endl;
    else
    {
        while (first <= last && !found)
        {
            mid = (first + last) / 2;
            if (list[mid] == item)
                found = true;
            else if (list[mid] > item)
                last = mid - 1;
            else
                first = mid + 1;
        }//end while
        if (found)
            cerr << "The insert item is already in the list. "<< "Duplicates are not allowed." << endl;
        else
            {
                if (list[mid] < item)
                    mid++;
                    insertAt(mid, item);
            }
    }
}//end insertOrd*/
#endif // ARRAYLISTTYPE_H

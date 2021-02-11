//LinkedListTest.h
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
using namespace std;

template<class T>
class LinkedList {
    private:
        Node<T> *front, *rear;                       // pointers pointing to the head and the end of the LinkedList
        Node<T> *prevPtr, *currPtr;                  // cursor pointers pointing to the current position and the previous position, updated by the inserting and deleting operations
        int size;                                    // the number of Nodes in the LinkedList
        int position;                                // the position of the current cursor
        
        Node<T>* GetNode( const T &item, Node<T> *ptrNext=NULL ); // generate a new Node. the data is 'item' and the next pointer is 'ptrNext'
        
        void FreeNode( Node<T> *p );                 // free one node
        
        void CopyList( const LinkedList<T> &L );     // copy the LinkedList L into the current LinkedList object, used by the copy constructor and the operator '='
        
    public:
        LinkedList();                                // constructor
        LinkedList( const LinkedList<T> &L );        // copy constructor
        ~LinkedList();                               // destructor
        LinkedList<T> & operator= (const LinkedList<T> &L);  // overloaded assignment operator '='
        LinkedList<T> operator- (LinkedList<T>& L);
        LinkedList<T> operator+ (LinkedList<T>& L);
        int ListSize() const;                        // return the number of nodes in the current LinkedList
        bool ListEmpty() const;                      // if the current LinkedList is empty
        
        void Reset( int pos=0 );                     // reset the position of the cursor
        void Next();                                 // move the cursor to the next node
        bool EndOfList() const;                      // if the cursor is at the end of the list
        int CurrentPosition(void) const;             // return the current position of the cursor
        
        void InsertFront( const T &item );           // insert data at the head of the list
        void InsertRear( const T &item );            // insert data at the end of the list
        void InsertAt( const T &item );              // insert data before the current node
        void InsertAfter( const T &item );           // insert data after the current node
        
        T DeleteFront();                             // delete the node at the head and return its data
        void DeleteAt();                             // delete the current node
        
        T& Data();                                   // return the reference to the data in current node

        void ClearList();                            // clear the LinkedList and free all the memory space, called by destructor
};


template <class T>
Node<T> *LinkedList<T>::GetNode(const T& item, Node<T>* ptrNext) //insert a node to the end of list
{
    Node<T>* newPtr = new Node<T>(item, ptrNext);
    return newPtr;
}

template <class T>
void LinkedList<T>::FreeNode(Node<T> *p)
{
    delete *p;
}

template <class T>
void LinkedList<T>::CopyList(const LinkedList<T>& L)
{

}


template <class T>
LinkedList<T>::LinkedList(void): front(NULL), rear(NULL),
      prevPtr(NULL),currPtr(NULL), size(0), position(-1)
{
// nothing to do here
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& L) //copy constructor
{

}

template <class T>
void LinkedList<T>::ClearList(void)
{

}

template <class T>
LinkedList<T>::~LinkedList(void)
{
    // already implemented
    // nothing to do here
    ClearList();
}

template <class T>
LinkedList<T>& LinkedList<T>::operator= 
               (const LinkedList<T>& L)
{


}

template <class T>
int LinkedList<T>::ListSize(void) const
{
    return size;
}
                      
template <class T>
bool LinkedList<T>::ListEmpty(void) const
{
    if(front == NULL && rear == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
void LinkedList<T>::Next(void)
{
    position = position + 1;
    if(prevPtr == NULL)
    {
        prevPtr == currPtr;
        currPtr == currPtr->NextNode();
    }
    else if(position == 1)
    {
        prevPtr = front;
        currPtr = front->NextNode();
    }
    else if(currPtr == NULL)
    {
    }
    else
    {
        prevPtr = prevPtr->NextNode();
        currPtr = currPtr->NextNode();
    }
}

template <class T>
bool LinkedList<T>::EndOfList(void) const
{
    if(currPtr == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
int LinkedList<T>::CurrentPosition(void) const
{
    return position;
}

template <class T>
void LinkedList<T>::Reset(int pos)
{
    position = pos;
    int prevPtrPosition = position - 1;
    if(prevPtrPosition < 0)
    {
        prevPtr = NULL;
        currPtr = front;
    }
    else if(prevPtrPosition == 0)
    {
        prevPtr = front;
        currPtr = front->NextNode();
    }
    else
    {
        Node<T>* tempPrevPtr = front;
        for(int i = 0; i < prevPtrPosition; i++)
        {
            tempPrevPtr = tempPrevPtr->NextNode();
        }
        prevPtr = tempPrevPtr;
        currPtr = front->NextNode();
    }
}

template <class T>
T& LinkedList<T>::Data(void)
{
    //return currPtr->data;
}

template <class T>
void LinkedList<T>::InsertFront(const T& item)
{
    if(size == 0)
    {
        front = new Node<T>(item, NULL);
        rear = front;
        currPtr = front;
        prevPtr = NULL;
        size = 1;
        position = 0;
    }
    else
    {
        Node<T>* tempPtr = new Node<T>(item, front); //step1
        front = tempPtr;
        size = size + 1;
        position = position + 1;
    }
}

template <class T>
void LinkedList<T>::InsertRear(const T& item)
{
    if(size == 0)
    {
        front = new Node<T>(item, NULL);
        rear = front;
        currPtr = front;
        prevPtr = NULL;
        size = 1;
        position = 0;
    }
    else
    {
        Node<T>* tempPtr = new Node<T>(item, NULL); //step1
        rear->InsertAfter(tempPtr); //step 2
        rear = tempPtr; //step 3
        size = size + 1;
    }
}

template <class T>
void LinkedList<T>::InsertAt(const T& item)
{
    if(size == 0)
    {
        front = new Node<T>(item, NULL);
        rear = front;
        currPtr = front;
        prevPtr = NULL;
        size = 1;
        position = 0;
    }
    else
    {
        if(currPtr != front)
        {
            Node<T>* tempPtr = new Node<T>(item, currPtr); //step1
            prevPtr->next = tempPtr; //step 2
            size = size + 1; //step 3
            position = position + 1; //step 4
        }
        if(currPtr == front)
        {
            Node<T>* tempPtr = new Node<T>(item, currPtr); //1
            prevPtr = tempPtr; //2
            front = tempPtr; //3
            size = size + 1; //4
            position = position + 1; //5
        }
    }
}

template <class T>
void LinkedList<T>::InsertAfter(const T& item)
{
    if(size == 0)
    {
        front = new Node<T>(item, NULL);
        rear = front;
        currPtr = front;
        prevPtr = NULL;
        size = 1;
        position = 0;
    }
    if(size == 1)
    {
        Node<T>* newNode = new Node<T>(item, NULL);
        rear = newNode;
        size = 2;
    }
    else
    {
        if(currPtr == rear)
        {
            Node<T>* tempPtr = new Node<T>(item, NULL); //step1
            rear->next = tempPtr; //step2
            rear = tempPtr; //3
            size = size + 1; //4
        }
        else if(currPtr != rear)
        {
            Node<T>* tempPtr = new Node<T>(item, currPtr->next); //1
            currPtr->next = tempPtr; //2
            size = size + 1;
        }
    }
}

template <class T>
T LinkedList<T>::DeleteFront(void) //1
{
    T dataToReturn = front->data;
    if(front == rear) //situation 1
    {
        delete front;
        front = NULL;
        rear = NULL;
        prevPtr = NULL;
        currPtr = NULL;
        size = 0;
        position = -1;
    }
    if(front != rear)
    {
        Node<T>* tempPtr = front;
        if(front == prevPtr)
        {
            prevPtr = NULL;
        }
        if(front == currPtr)
        {
            currPtr = tempPtr->NextNode();
            position = position + 1; //position is already 0, so it'd turn position to 1 temporarily, then would be corrected back to 0 at end of func
        }
        front = front->NextNode();
        delete front;
        size = size - 1;
        position = position - 1;
    }

    return dataToReturn;
}

template <class T>
void LinkedList<T>::DeleteAt(void)
{
    if(currPtr == front) //situation 1
    {
        DeleteFront();
    }
    else if(currPtr == rear) //situation 2 (we delete rear)
    {
        Node<T>* tempPtr = rear; //1
        rear = prevPtr; //2
        currPtr = prevPtr;//3
        size = size - 1; //4
        position = position - 1; //5
        int prevPtrPosition = position - 1; //position prevPtr should be (right before currPtr)
        if(prevPtrPosition < 0) //6
        {
            prevPtr = NULL;
        }
        else if(prevPtrPosition == 0) //7
        {
            prevPtr = front;
        }
        else //8
        {
            Node<T>* tempPrevPtr = front;
            for(int i = 0; i < prevPtrPosition; i++)
            {
                tempPrevPtr = tempPrevPtr->next;
            }
            prevPtr = tempPrevPtr;
        }
        delete tempPtr;
        rear->next = NULL;
    }
    else
    {
        Node<T>* toDelete = currPtr;//1
        Node<T>* nextPtr = currPtr->next;//2
        currPtr = nextPtr; //3
        prevPtr->next = nextPtr; //4
        delete toDelete;//5
        //position stays the same
        size = size - 1; //6
    }
}

template <class T>
LinkedList<T> LinkedList<T>::operator+
               (LinkedList<T>& L)
{

}


template <class T>
LinkedList<T> LinkedList<T>::operator-
               (LinkedList<T>& L)
{

}

#endif
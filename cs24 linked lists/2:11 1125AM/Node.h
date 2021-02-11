//9-5.h
#ifndef NODE_H
#define NODE_H
#include <iostream>


// Node class
template<class T>
class Node {
    private:
        Node<T>* next;                                // the pointer pointing to the next node
    public:
        T data;                                       // data area
        
        Node( const T &data, Node<T> *ptrnext = NULL );       // constructor
        void InsertAfter( Node<T> *p );               // insert a Node p after the current node
        Node<T> *DeleteAfter();                       // "delete" the next node and return its address
        Node<T> *NextNode() const;              // return the address of the next node
};


template <class T> //constructor
Node<T>::Node(const T& item, Node<T>* ptrnext) : data(item), next(ptrnext)
{}
  
template <class T>
Node<T> *Node<T>::NextNode(void) const
{
    return next;
}

template <class T>
void Node<T>::InsertAfter(Node<T> *p)
{
    p->next = next;
    next = p;           
}

template <class T>
Node<T> *Node<T>::DeleteAfter(void)
{
Node<T> *tempPtr = next;  // save the target in tempPtr

    if (next == NULL)  // return NULL if is no next node
        return NULL;
        
    next = tempPtr->next;  //move the pointer to the next node.
    return tempPtr;  
}

#endif  // NODE_CLASS

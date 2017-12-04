#include <iostream>         
 
template <class ItemType>
class StackListType
{
public:
    StackListType();
          /*   Function: constructor initializes class variables 
               Precondition: none
               Postcondition: defines private variables */
    bool IsEmpty();
          /*   Function: Determines whether the stack is empty
               Precondition: Stack has been initialized
               Postcondition: Function value = (stack is empty) */
    bool IsFull();
          /*   Function: Determines whether the stack is full
               Precondition: Stack has been initialized
               Postcondition: Function value = (stack is full) */
    int Size();
          /*   Function: Return the current size of the stack
               Precondition: Stack has been initialized
               Postcondition: If (stack is full) exception FullStack is thrown
                                   else newItem is at the top of the stack */
    void MakeEmpty();
          /*   Function: Empties the stack
               Precondition: Stack has been initialized
               Postcondition: Stack is empty */
    void Push(ItemType newItem);
          /*   Function: Adds newItem to the top of the stack
               Precondition: Stack has been initialized
               Postcondition: If (stack is full) exception FullStack is thrown
                                   else newItem is at the top of the stack */
    ItemType Pop();
          /*   Function: Returns & then removes top item from the stack
               Precondition: Stack has been initialized
               Postcondition: If (stack is empty) exception EmptyStack is thrown
                                else top element has been removed from the stack */
    ItemType Top();
          /*   Function: Returns the top item from the stack
               Precondition: Stack has been initialized
               Postcondition: If (stack is empty) exception EmptyStack is thrown
                                   else top element has been removed from the stack */
    ~StackListType();
          /*   Function: destructor deallocates class variables 
               Precondition: none
               Postcondition: deallocates private variables */
 
private:
    struct NodeType
    {
          ItemType currentItem;  // Variable which hold all the incoming currentItem
          NodeType* next; // Creates a pointer that points to the next node in the list.
    };
    int size;          // Indicates the size of the stack	
    ItemType junk;
    NodeType* headPtr; // Creates a head pointer that will point to the begining of the list.
};
 
//=========================  Implementation  ================================//
 
template<class ItemType>
StackListType<ItemType>::StackListType()
{
    size = 0;
    headPtr = NULL;
}//     End of StackListType
 
template<class ItemType>
bool StackListType<ItemType>::IsEmpty()
{
    return (headPtr == NULL);
}//     End of IsEmpty
 
template<class ItemType>
bool StackListType<ItemType>::IsFull()
{    
    try
    {
        NodeType* tempPtr = new NodeType;
        delete tempPtr;
        return false;
    }
    catch(std::bad_alloc&)
    {
        return true;
    }
}//     End of IsFull
 
template<class ItemType>
int StackListType<ItemType>::Size()
{
    if(IsEmpty())
    {
        std::cout<<"nSTACK EMPTYn";
    }
    return size;
}//     End of Size
 
template<class ItemType>
void StackListType<ItemType>::MakeEmpty()
{
    size = 0;    
	
    if (!IsEmpty())
	{
		while (!IsEmpty())
		{
			NodeType* tempPtr = headPtr;
			//std::cout << tempPtr-> currentItem << 'n';
			headPtr = headPtr-> next;
			delete tempPtr;
		}
	}     
}//     End of MakeEmpty
 
template<class ItemType>
void StackListType<ItemType>::Push(ItemType newItem)
{
    if(IsFull())
    {
        std::cout<<"nSTACK FULLn";
        return;
    }
    NodeType* tempPtr = new NodeType;
    tempPtr-> currentItem = newItem;
    tempPtr-> next = headPtr;
    headPtr = tempPtr;
    ++size;
}//     End of Push
 
template<class ItemType>
ItemType StackListType<ItemType>::Pop()
{
    if(IsEmpty())
    {
        std::cout<<"nSTACK EMPTYn";
        return junk;
    }
    else
    {  
        ItemType data = headPtr-> currentItem;  
        NodeType* tempPtr = headPtr;
        headPtr = headPtr-> next;
        delete tempPtr;
        --size;
        return data;
    }
}//     End of Pop
 
template<class ItemType>
ItemType StackListType<ItemType>::Top()
{
    if(IsEmpty())
    {
        std::cout<<"nSTACK EMPTYn";
        return junk;
    }
    else
    { 
        return headPtr-> currentItem;
    }
}//     End of Top
 
template<class ItemType>
StackListType<ItemType>::~StackListType()
{
    MakeEmpty();   
}

//end of stack header file

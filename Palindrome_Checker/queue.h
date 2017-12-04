#include <iostream>

template <class ItemType>
class SingleQueue
{
public:
	SingleQueue();
		/*   Function: Constructor initializes queue
			Precondition: None
			Postcondition: Defines private variables */
	bool IsEmpty();
		/*   Function: Determines whether queue is empty
			Precondition: Queue has been created
			Postcondition: The function = true if the queue is empty and the
							 function = false if queue is not empty */
	bool  IsFull();
		/*   Function: Determines whether queue is full
			Precondition: Queue has been created
			Postcondition: The function = true if the queue is full and the
							 function = false if queue is not full */
	void EnQueue(ItemType item);
		/*   Function: Adds new item to the back of the queue
			Precondition:  Queue has been created and is not full
			Postcondition: Item is in the queue */
	ItemType DeQueue();
		/*   Function: Returns and then deletes the first item in the queue
			Precondition:  Queue has been created and is not empty
			Postcondition: The first item in the queue has been removed and the queue
								order is maintained */
	ItemType Front();
		/*   Function: Returns (but does not delete) the first item in the queue
			Precondition:  Queue has been created and is not empty
			Postcondition: The first item in the queue has been returned and the queue
								order is maintained */
	ItemType Rear();
		/*   Function: Returns (but does not delete) the last item in the queue
			Precondition:  Queue has been created and is not empty
			Postcondition: The last item in the queue has been returned and the queue
								order is maintained */
	int Size();
          /*   Function: Return the current size of the queue
               Precondition: Queue has been initialized
               Postcondition: The size of the queue is returned */
	void MakeEmpty();
		/*   Function: Initializes queue to an empty state
			Precondition: Queue has been created
			Postcondition: Queue no longer exists */
	~SingleQueue();
		/*   Function: Removes the queue
			Precondition: Queue has been declared
			Postcondition: Queue no longer exists */
private:
	struct  NodeType
	{
		ItemType currentItem;
		NodeType* next;
	};
	NodeType* head;	// front of queue
	int size;
};

//=========================  Implementation  ================================//

template<class ItemType>
SingleQueue<ItemType>::SingleQueue()
{
	head = NULL;
	size = 0;
}/* end of SingleQueue */

template<class ItemType>
bool SingleQueue<ItemType>::IsEmpty()
{
	return (head == NULL);
}/* end of IsEmpty */

template<class ItemType>
bool SingleQueue<ItemType>::IsFull()
{
	try
	{
		NodeType* location = new NodeType;
		delete location;
		return false;
	}
	catch(std::bad_alloc&)
	{
		return true;
	}
}/* end of IsFull */

template<class ItemType>
void SingleQueue<ItemType>::EnQueue(ItemType newItem)
{
	if(IsFull())
	{
		std::cout<<"nQUEUE FULLn";
	}
	else
	{
		NodeType* newNode = new NodeType;  // adds new node
		newNode-> currentItem = newItem;
		newNode-> next = NULL;

		if(IsEmpty())
		{
			head = newNode;
		}
		else
		{
			NodeType* tempPtr = head;
			while(tempPtr-> next != NULL)
			{
				tempPtr = tempPtr-> next;
			}
			tempPtr-> next = newNode;
		}
		++size;
	}
}/* end of EnQueue */

template<class ItemType>
ItemType SingleQueue<ItemType>::DeQueue()
{
    if(IsEmpty())
    {
        std::cout<<"nQUEUE EMPTYn";
    }
    else
    {
        NodeType* tempPtr = head;  // temporary pointer

        ItemType item = head-> currentItem;
        head = head-> next;
        delete tempPtr;
        --size;
        return item;
    }
}/* end of DeQueue */

template<class ItemType>
ItemType SingleQueue<ItemType>::Front()
{
    if(IsEmpty())
    {
        std::cout<<"nQUEUE EMPTYn";
    }
    else
    {
        ItemType item = head-> currentItem;
        return item;
    }
}/* end of Front */

template<class ItemType>
ItemType SingleQueue<ItemType>::Rear()
{
    if(IsEmpty())
    {
        std::cout<<"nQUEUE EMPTYn";
    }
    else
    {
        NodeType* tempPtr = head;  // temporary pointer

        while(tempPtr->next != NULL)
        {
                tempPtr = tempPtr-> next;
        }
        ItemType item = tempPtr-> currentItem;
        return item;
    }
}/* end of Rear */

template<class ItemType>
int SingleQueue<ItemType>::Size()
{
    if(IsEmpty())
    {
        std::cout<<"nQUEUE EMPTYn";
    }
    return size;
}/* end of Size */

template<class ItemType>
void SingleQueue<ItemType>::MakeEmpty()
{
    if(!IsEmpty())
    {
        while(!IsEmpty())
        {
            NodeType* tempPtr = head;
            //std::cout << tempPtr-> currentItem << 'n';
            head = head-> next;
            delete tempPtr;
        }
        size = 0;
    }
}/* end of MakeEmpty */

template<class ItemType>
SingleQueue<ItemType>::~SingleQueue()
{
	MakeEmpty();
}

//end of queue header file

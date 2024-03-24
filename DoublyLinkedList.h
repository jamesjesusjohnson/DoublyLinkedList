#pragma once
#include <iostream>

template <typename T>
class DoublyLinkedList
{
private:
	struct ListNode
	{
		T* appData;
		ListNode* next;
		ListNode* prev;

		ListNode(T* appDataSrc = nullptr, ListNode* nextSrc = nullptr, ListNode* prevSrc = nullptr)
			: appData{ appDataSrc }, next{ nextSrc }, prev{ prevSrc }
		{}
	};

	ListNode* head;
	ListNode* tail;

public:
	DoublyLinkedList(ListNode* headSrc = nullptr, ListNode* tailSrc = nullptr)
		: head{ headSrc }, tail{ tailSrc }
	{}

	bool listIsEmpty()
	{
		return ((head == nullptr) && (tail == nullptr)) ? true : false;
	}

	void printList()
	{
		if (listIsEmpty())
		{
			// Do Nothing
			std::cout << "List is empty" << std::endl;
		}
		else
		{
			ListNode* trav = head;

			std::cout << "Current List" << std::endl;
			std::cout << "[ ";
			while (trav != nullptr)
			{
				std::cout << *trav->appData << " ";
				trav = trav->next;
			}
			std::cout << ']';
			std::cout << std::endl;
		}
	}

	T valueAtIndex(int index)
	{
		ListNode* trav{ head };
		int counter{ 0 };

		if (listIsEmpty())
		{
			return NULL;
		}

		while (trav != nullptr && counter < index)
		{
			trav = trav->next;
			counter++;
		}

		if (trav == nullptr)
		{
			return NULL;
		}

		return *trav->appData;
	}

	void insertNodeAtTail(T& valToInsert)
	{
		ListNode* newNode = new ListNode();
		newNode->appData = &valToInsert;

		if (listIsEmpty())
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}


		return;
	}

	void deleteNodeAtTail()
	{
		ListNode* trav = tail;

		if (listIsEmpty())
		{
			std::cout << "List is empty. No nodes to delete." << std::endl;
			return;
		}

		//std::cout << "Deleting " << *(trav->appData) << std::endl;

		if (head == tail)
		{
			delete trav;
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			tail = trav->prev;
			tail->next = nullptr;

			delete trav;
		}
	}

	~DoublyLinkedList()
	{
		while (head != nullptr)
		{
			deleteNodeAtTail();
		}
	}

	DoublyLinkedList& operator=(const DoublyLinkedList& src)
	{
		ListNode* srcPtr = src.head;
		ListNode* prevDestNodePtr;
		ListNode* currDestNodePtr;

		if (this != &src)
		{
			if (srcPtr == nullptr)
			{
				return *this;
			}

			// Set up head
			currDestNodePtr = new ListNode();
			currDestNodePtr->appData = srcPtr->appData;
			this->head = currDestNodePtr;
			srcPtr = srcPtr->next;

			//Construct list until finding tail
			while (srcPtr != nullptr)
			{
				prevDestNodePtr = currDestNodePtr;
				currDestNodePtr = new ListNode();
				prevDestNodePtr->next = currDestNodePtr;
				currDestNodePtr->prev = prevDestNodePtr;
				currDestNodePtr->appData = srcPtr->appData;
				srcPtr = srcPtr->next;
			}

			// Assign tail to last created node
			this->tail = currDestNodePtr;
		}

		return *this;
	}

	DoublyLinkedList(const DoublyLinkedList& src)
	{
		*this = src;
		return;
	}

	DoublyLinkedList& operator=(DoublyLinkedList&& src) noexcept
	{
		if (this != &src)
		{
			delete this;
			this->head = src.head;
			this->tail = src.tail;

			src.head = nullptr;
			src.tail = nullptr;
		}
		return *this;
	}

	DoublyLinkedList(DoublyLinkedList&& src) noexcept
	{
		*this = src;
	}
};


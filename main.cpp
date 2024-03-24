#include <iostream>
#include <string>
#include <vector>
#include "DoublyLinkedList.h"


void unitTestSuite();
bool unitTest_listIsEmpty_int_empty(bool expected);
bool unitTest_listIsEmpty_int_notEmpty(bool expected);
bool unitTest_valueAtIndex_int_match(int expected);
bool unitTest_insertNodeAtTail_int_match(int expected);
bool unitTest_deleteNodeAtTail_int_match(int expected);
bool unitTest_copyConstructorAssignmentOperator_int_match();


int main()
{
	unitTestSuite();

	return 0;
}




void unitTestSuite()
{
	std::vector<bool> results{};
	bool success{ true };
	size_t i{ 0 };

	results.push_back(unitTest_listIsEmpty_int_empty(true));
	results.push_back(unitTest_listIsEmpty_int_notEmpty(false));
	results.push_back(unitTest_valueAtIndex_int_match(3));
	results.push_back(unitTest_insertNodeAtTail_int_match(5));
	results.push_back(unitTest_deleteNodeAtTail_int_match(999));
	results.push_back(unitTest_copyConstructorAssignmentOperator_int_match());

	while (success && i < results.size())
	{
		success = results[i];
		i++;
	}

	if (success)
	{
		std::cout << "All Unit Tests Passed" << std::endl;
	}
	else
	{
		std::cout << "One or more unit tests have failed. Here is the Results Vector:" << std::endl;
		std::cout << "[ ";
		for (size_t j{ 0 }; j < results.size(); j++)
		{
			std::cout << results[j] << " ";
		}
		std::cout << "]" << std::endl;
	}
}


bool unitTest_listIsEmpty_int_empty(bool expected)
{
	DoublyLinkedList<int> list;

	bool actual = list.listIsEmpty();

	if (expected == actual)
	{
		std::cout << "unitTest_listIsEmpty_int_empty\n - Expected: " << expected << ". Actual: " << actual << " - PASSED" << std::endl;
	}
	else
	{
		std::cout << "unitTest_listIsEmpty_int_empty\n - Expected: " << expected << ". Actual: " << actual << " - FAILED" << std::endl;
	}
	std::cout << std::endl;


	return (expected == actual);
}

bool unitTest_listIsEmpty_int_notEmpty(bool expected)
{
	DoublyLinkedList<int> list;

	int temp{ 1 };

	list.insertNodeAtTail(temp);

	bool actual = list.listIsEmpty();

	if (expected == actual)
	{
		std::cout << "unitTest_listIsEmpty_int_notEmpty\n - Expected: " << expected << ". Actual: " << actual << " - PASSED" << std::endl;
	}
	else
	{
		std::cout << "unitTest_listIsEmpty_int_notEmpty\n - Expected: " << expected << ". Actual: " << actual << " - FAILED" << std::endl;
	}
	std::cout << std::endl;


	return (expected == actual);
}

bool unitTest_valueAtIndex_int_match(int expected)
{
	DoublyLinkedList<int> list;

	int temp[]{ 0,1,2,3,4,5 };

	for (int i{ 0 }; i < 6; i++)
	{
		list.insertNodeAtTail(temp[i]);
	}

	int actual = list.valueAtIndex(3);

	if (expected == actual)
	{
		std::cout << "unitTest_valueAtIndex_int_match\n - Expected: " << expected << ". Actual: " << actual << " - PASSED" << std::endl;
	}
	else
	{
		std::cout << "unitTest_valueAtIndex_int_match\n - Expected: " << expected << ". Actual: " << actual << " - FAILED" << std::endl;
	}
	std::cout << std::endl;

	return (expected == actual);
}

bool unitTest_insertNodeAtTail_int_match(int expected)
{
	DoublyLinkedList<int> list;
	int temp[]{ 0,5 };

	for (int i{ 0 }; i < 2; i++)
		list.insertNodeAtTail(temp[i]);

	int actual = list.valueAtIndex(1);

	if (expected == actual)
	{
		std::cout << "unitTest_insertNodeAtTail_int_match\n - Expected: " << expected << ". Actual: " << actual << " - PASSED" << std::endl;
	}
	else
	{
		std::cout << "unitTest_insertNodeAtTail_int_match\n - Expected: " << expected << ". Actual: " << actual << " - FAILED" << std::endl;
	}
	std::cout << std::endl;


	return (expected == actual);
}

bool unitTest_deleteNodeAtTail_int_match(int expected)
{
	DoublyLinkedList<int> list;

	int temp[]{ 0,1,2,3,4,5 };

	for (int i{ 0 }; i < 6; i++)
	{
		list.insertNodeAtTail(temp[i]);
	}

	list.deleteNodeAtTail();

	int newVal{ 999 };

	list.insertNodeAtTail(newVal);

	int actual = list.valueAtIndex(5);

	if (expected == actual)
	{
		std::cout << "unitTest_deleteNodeAtTail_int_match\n - Expected: " << expected << ". Actual: " << actual << " - PASSED" << std::endl;
	}
	else
	{
		std::cout << "unitTest_deleteNodeAtTail_int_match\n - Expected: " << expected << ". Actual: " << actual << " - FAILED" << std::endl;
	}
	std::cout << std::endl;


	return (expected == actual);
}


bool unitTest_copyConstructorAssignmentOperator_int_match()
{
	DoublyLinkedList<int> list1{};

	int tempArr[]{ 0,1,2,3,4,5,6,7,8,9 };

	for (int i{ 0 }; i < 10; i++)
	{
		list1.insertNodeAtTail(tempArr[i]);
	}

	DoublyLinkedList<int> list2{ list1 };

	list2.deleteNodeAtTail();

	int newVal{ 999 };
	list2.insertNodeAtTail(newVal);

	if (list1.valueAtIndex(9) != list2.valueAtIndex(9))
	{
		std::cout << "unitTest_copyConstructorAssignmentOperator_int_match\n - PASSED" << std::endl;
	}
	else
	{
		std::cout << "unitTest_copyConstructorAssignmentOperator_int_match\n - FAILED" << std::endl;
	}
	std::cout << std::endl;


	return (list1.valueAtIndex(9) != list2.valueAtIndex(9));
}
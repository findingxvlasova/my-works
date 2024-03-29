#include <iostream>

using namespace std;

template<class whateverUWant>
class List
{
public:
	List();
	~List();

	int getSize() { return size; }
	whateverUWant& operator[](const int index);

	void pushFront(whateverUWant data);//вщ
	void pushBack(whateverUWant data);
	void popFront();
	void popBack();
	void insert(whateverUWant val, int idx);

	void removeAt(int idx);
	void clear();


private:
	template<class whateverUWant>

	class Node
	{
	public:
		Node* pNext;
		whateverUWant data;

		Node(whateverUWant data = whateverUWant(), Node *pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

	int size;
	Node<whateverUWant>* head;
};

template<class whateverUWant>
List<whateverUWant>::List()
{
	size = 0;
	head = nullptr;
}

template<class whateverUWant>
List<whateverUWant>::~List()
{
	clear();
}


template<class whateverUWant>
void List<whateverUWant>::pushFront(whateverUWant data)
{
	
}

template<class whateverUWant>
void List<whateverUWant>::insert(whateverUWant val, int idx)
{
	if (idx == 0)
	{
		pushFront(val);
	}
	else
	{
		Node<whateverUWant>* previous = this->head;
		for (int i = 0; i < idx - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<whateverUWant>* newNode = new Node<whateverUWant>(val, previous->pNext);
		previous->pNext = newNode;
		size++;

	}
}

template<class whateverUWant>
void List<whateverUWant>::removeAt(int idx)
{
	if (idx == 0)
	{
		popFront();
	}
	else
	{
		Node<whateverUWant>* previous = this->head;
		for (int i = 0; i < idx - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<whateverUWant>* toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		delete toDelete;
		size--;

	}

}

template<class whateverUWant>
void List<whateverUWant>::pushBack(whateverUWant data)
{
	if (head == nullptr)
	{
		head = new Node< whateverUWant>(data);
	}
	else
	{
		Node< whateverUWant>* current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node< whateverUWant>(data);
	}
	size++;
}


template<class whateverUWant>
void List<whateverUWant>::popFront()
{
	Node< whateverUWant>* temp = head;
	head = head->pNext;
	delete temp;

	size--;


}

template<class whateverUWant>
void List<whateverUWant>::popBack()
{
	removeAt(size - 1);
}

template<class whateverUWant>
void List<whateverUWant>::clear()
{
	while (size)
	{
		popFront();
	}
}


template<class whateverUWant>
whateverUWant& List<whateverUWant>::operator[](const int index)
{
	int counter = 0;
	Node< whateverUWant>* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

int main()
{
	List<int> lst;
	
	for (int i = 0; i < 5; i++)
	{
		lst.pushFront(rand() % 10);
	}

	cout << "after push front:\n";
	for (int i = 0; i < lst.getSize(); i++)
	{
		cout << lst[i] << " ";
	}

	lst.popFront();

	cout << "\nafter one pop front:\n";
	for (int i = 0; i < lst.getSize(); i++)
	{
		cout << lst[i] << " ";
	}


	for (int i = 0; i < 5; i++)
	{
		lst.pushBack(rand() % 10);
	}

	cout << "\nafter push back:\n";
	for (int i = 0; i < lst.getSize(); i++)
	{
		cout << lst[i] << " ";
	}

	lst.popBack();

	cout << "\nafter one pop back:\n";
	for (int i = 0; i < lst.getSize(); i++)
	{
		cout << lst[i] << " ";
	}

}

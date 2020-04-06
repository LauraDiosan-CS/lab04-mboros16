#pragma once
template<class T>
struct Node
{
public:
	Node * previous = nullptr;
	Node * next = nullptr;

	T * Data;

};

template<class T>
class List
{
public:
	List()
	{
		Count = 0;
	}

	/*List(const List<T> &List) // needs to be implemented
	{
		Node<T> * node = List.Root;
		while (node)
		{
			this->Add(node->Data);
			node = node->next;
		}
	}*/

	~List()
	{
		//clear();
	}
private:
	Node<T> *	Root;
	int			Count;
public:
	int		getCount() { return Count; }

	void clear()//Need to fix
	{
		Node <T> * End = Last();
		while (End != nullptr)
		{
			if(End->previous)
				End->previous->next = nullptr;
			delete End;
			End = Last();
		}
		Count = 0;
	}
	Node<T> * Last()
	{
		Node<T> * node = Root;
		if (!node)
			return node;
		while (node->next)
			node = node->next;
		return node;
	}

	void Add(T * Data)
	{

		Node<T> * node = Root;
		if(node == nullptr)
		{
			Root = new Node<T>;
			Root->Data = Data;
		}
		else
		{
			while (node->next != nullptr)
				node = node->next;
			node->next = new Node<T>;
			node->next->Data = Data;
			node->next->previous = node;
		}
		Count++;
	}

	void Remove(T * Data)
	{
		Node<T> * node = Root;
		while (node != nullptr)
		{
			if (node->Data == Data)
			{
				if (node->next)
				{
					if (node->previous)
						node->previous->next = node->next;
					else
						Root = node->next;
					node->next->previous = node->previous;
				}
				else
				{
					if(node->previous)
						node->previous->next = nullptr;
				}
				delete node;
				Count--;
				break;
			}
			node = node->next;
		}	
	}

	void Remove(int Pos)
	{
		Node<T> node = Root;
		for (int i = 0; i < Pos; i++)
		{
			node = node->next;
		}
		if (node->next)
		{
			node->previous->next = node->next;
			node->next->previous = node->previous;
		}
		else
		{
			node->previous->next = nullptr;
		}
		delete node;
	}

	T * Begin()
	{
		return Root->Data;
	}

	T * End()
	{
		Node<T> * node = Root;
		while (node->next)
			node = node->next;
		return node->Data;
	}

	T * operator[](int Pos)
	{
		Node<T> * node = Root;
		for (int i = 0; i < Pos; i++)
		{
			node = node->next;
		}
		return node->Data;
	}

	void SwapData(Node<T> * current, Node<T> * next)
	{
		T * Aux = current->Data;
		current->Data = next->Data;
		next->Data = Aux;
	}

	template <class C>
	void Sort(C* c, bool (T::*func)(T *, T *))
	{
		bool sorted = false;
		while (sorted == false)
		{
			sorted = true;
			Node<T> * node = Root;
			for (int i = 0; i < Count -1; i++)
			{
				if (c->func(node->Data, node->next->Data))
				{
					SwapData(node, node->next);
					sorted = false;
				}
				node = node->next;
			}
		}
	}
	
	void Sort(bool(*func)(T *, T *))
	{
		bool sorted = false;
		while (sorted == false)
		{
			sorted = true;
			Node<T> * node = Root;
			for (int i = 0; i < Count -1; i++)
			{
				if (func(node->Data, node->next->Data))
				{
					SwapData(node, node->next);
					sorted = false;
				}
				node = node->next;
			}
		}
	}
};
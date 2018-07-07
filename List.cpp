#include<iostream>

using namespace std;

template<typename T>
struct Node
{
	Node(T start_data, Node<T> * start_next)
		: data(start_data), next(start_next) {}
	T data;
	Node<T> *next;
};

template<class T>
class KajList
{
public:
	KajList() : first(nullptr) {}

	~KajList()
	{
		Node<T> *next = first;

		while (next)
		{
			Node<T> *temp1 = next;
			next = next->next;
			delete temp1;
		}
	}

private:
	Node<T> *first;
	Node<T> *beforelast;
public:

	void insert(T k)
	{
		Node<T> *newNode = new Node<T>(k, first);
		first = newNode;


		if (first->next == nullptr)
		{
			beforelast = first;

		}
		else
		{
			Node<T> *aac = first;
			while (aac->next->next != nullptr)
			{
				aac = aac->next;
			}
			beforelast = aac;
		}
	}

	void removeFirst()
	{
		Node<T> *temp = first;
		first = temp->next;
		delete temp;
		if (first->next == nullptr || first->next->next == nullptr)
		{
			beforelast = first;
		}
	}
	void removeLast()
	{

		delete beforelast->next;
		beforelast->next = nullptr;

		if (first->next == nullptr)
		{
			beforelast = first;

		}
		else
		{
			Node<T> * aad = first;
			while (aad->next->next != nullptr)
			{
				aad = aac->next;
			}
			beforelast = aad;

		}
	}
	void display()
	{
		Node<T> * temp = first;
		while (temp != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->next;

		}
		cout << endl;
		delete temp;
	}
};
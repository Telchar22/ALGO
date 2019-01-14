#include<iostream>
#include <stdlib.h>
//OPERACJE NA STOSIE(LISTA JEDNOKIERUNKOWA)

template<typename T>
struct Node {
	Node(T startData, Node<T>* startNext)
		: data(startData), next(startNext) {
	}
	T data;
	Node<T> *next;
};

template<class T>
class KajList {
public:
	KajList() : first(nullptr) {}

	~KajList() {
		Node<T> *next = first;

		while (next) {
			Node<T> *temp1 = next;
			next = next->next;
			delete temp1;
		}
	}

private:
	Node<T> *first;
	Node<T> *beforelast; 
public:

	void insert(T k) {
		Node<T> *newNode = new Node<T>(k, first);
		first = newNode;


		if (first->next == nullptr) {
			beforelast = first;

		}
		else {
			Node<T> * aac = first;
			while (aac->next->next != nullptr) {
				aac = aac->next;
			}
			beforelast = aac;
		}
	}

	void remove_first() {
		if (first == nullptr)
		{
			return;
		}
		Node<T>* temp = first;
		first = first->next;
		delete temp;
		
	}
	void remove_last() {

		delete beforelast->next;
		beforelast->next = nullptr;

		if (first->next == nullptr) {
			beforelast = first;

		}
		else {
			Node<T> * aad = first;
			while (aad->next->next != nullptr) {
				aad = aac->next;
			}
			beforelast = aad;

		}
	}

	void sum() {
		if (first->next == nullptr){
			return;
		}
		Node<T> *temp = first->next;
		temp->data = temp->data + first->data;
		remove_first();
	}

	void swap(){
		Node<T> *temp = first;
		if (first->next == nullptr){
			return;
		}
		first = first->next;
		temp->next = first->next;
		first->next = temp;
	}

	void rToRn() {
		const int n = first->data;
		remove_first();
		if (first == nullptr || first->next == nullptr || n == 1 || n == 0){
			return;
		}
		Node<T>* temp = first;
		Node<T>* temp2 = first;
		for (int i = 0; i <= n - 2; ++i){
			temp2 = temp2->next;
		}
		if (temp2 == nullptr){
			return;
		}
		first = first->next;
		temp->next = temp2->next;
		temp2->next = temp;
	}

	void display() const{
		Node<T> * temp = first;
		while (temp != nullptr) {
			std::cout << temp->data << " ";
			temp = temp->next;

		}
		std::cout <<"\n";
		delete temp;
		}


	};


	int main() {

		
		int n = 0;
		char subprog;
		KajList<int> *first = new KajList<int>();

		while (true){
			std::cin >> std::ws;  //biale znaki
			if (('a' <= std::cin.peek() && std::cin.peek() <= 'z') || std::cin.peek() == '+'){
				if ('q' == std::cin.peek()) {
					std::cin >> subprog;
					delete first;
					break;
				}

				std::cin >> subprog;

				switch (subprog) {
				case 'p':					//wypisanie stosu (od wierzcho³ka do spodu)
					first->display();
					break;
				case 's':					//zamiana miejscami dwóch liczb na szczycie stosu
					first->swap();
					break;
				case 'x':					//usuniêcie elementu ze szczytu stosu
					first->remove_first();
					break;
				case '+':					//zdjêcie dwóch liczb ze stosu i w³o¿enie na stos ich sumy
					first->sum();
					break;
				case'r':					//zdjêcie ze stosu liczby n, przeniesienie liczby z wierzcho³ka stosu na n-te miejsce licz¹c od wierzcho³ka
					first->rToRn();
					break;

				default: 
					break;
				}
			}
			else{
				std::cin >> n;
				first->insert(n);
			}
		}
		return 0;
}

	


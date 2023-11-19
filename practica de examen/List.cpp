#include "List.h"

List::List()
{
}

Node* List::getHead()
{
	return head;
}

void List::insertOrdered(int data)
{
	Node* aux = new Node(data);
	if (!head) {
		head = new Node;
	}
	else if (!head->getNext()) {
		if (head->getData()<data) {
			aux = head;
			head = new Node (data);
		 }
		else {
			//aux = new Node(data);
			head->setNext(aux);
			aux->setPrev(head);
		}
	}
	else if(head->getData()<data){
		//aux = new Node(data);//NOTE: eliminar codigo muerto
		head->setPrev(aux);
		aux->setNext(head);
		head = aux;
	}
	else {
		Node* current = head;
		while (current) {
			//NOTE: codigo muy anidado
			if (current->getData() < data) {
				current->getPrev()->setNext(aux);
				aux->setPrev(current->getPrev());
				aux->setNext(current);
				current->setPrev(aux);
				break;
			}
			current = current->getNext();
		}
		if (current->getData() > data) {
			current->setNext(aux);
		}
	}
}

void List::print()
{
	if (head) {
		Node* current = head;
		while (current) {
			cout << current->getData();
			current = current->getNext();
		}
	}
	
}

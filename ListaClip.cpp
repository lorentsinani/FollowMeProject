#include <stdlib.h>
#include <time.h>
#include "ListaClipHeader.h"

// nuk perdoret namespace std per shkak te fjaleve te njejta te cilat behen "ambigious"
Clip* executeActionHelper(Clip* head, int action, int length);
enum actions { none, any, other, next, previous };
actions actionOption(std::string word);

ListaClip::ListaClip() 
{
	head = nullptr;
	length = 0;
}

Clip* ListaClip::getHead() 
{
	return this->head;
}

Clip* ListaClip::exists(std::string name) 
{
	if (head == nullptr) {
		std::cout << "List is empty " << std::endl;
	}
	else {
		Clip* temp = head;
		do {
			if (temp->getName() == name) 
			{
				return temp;
			}
			temp = temp->next;
		} while (temp != head);
	}
	return nullptr;
}

void ListaClip::addClip(Clip* clip) 
{
	if (head == nullptr) 
	{
		head = clip;
		head->next = head;
		head->previous = head;
		length++;
	}
	else {
		Clip* position = exists(clip->getName());
		if (position == nullptr) 
		{
			Clip* temp = head;
			temp = temp->previous;
			temp->next = clip;
			clip->previous = temp;
			clip->next = head;
			head->previous = clip;
			length++;
		}
		else 
		{
			position->previous->next = clip;
			position->next->previous = clip;
			clip->next = position->next;
			clip->previous = position->previous;
			delete position;
		}
	}
}

void ListaClip::display() 
{
	if (head == nullptr) 
	{
		std::cout << "List is empty " << std::endl;
	}
	else 
	{
		Clip* temp = head;
		do 
		{
			std::cout << "Name: " << temp->getName() << "\t";
			std::cout << "Ticks to play: " << temp->getTicksToPlay();
			std::cout << std::endl;
			temp = temp->next;
		} while (temp != head);
	}
}

void ListaClip::executeAction(float p1, float p2) 
{
	int action;
	action = head->chooseAction(p1, p2);
	head = executeActionHelper(this->head, action, this->length);
}

void ListaClip::executeAction() 
{
	int action;
	action = head->chooseAction(); // TO DO
	head = executeActionHelper(this->head, action, this->length);
}

Clip* executeActionHelper(Clip* head, int action, int length) 
{
	int cont;
	actions option;
	srand(time(nullptr));
	if (action == 1)
		option = actionOption(head->getAction1());
	else
		option = actionOption(head->getAction2());

	if (option == any) // "any" merr nje "random" clip ta luaj!
	{ 
		Clip* temp = head;
		cont = rand() % length + 1;
		while (cont < length) {
			head = temp->next;
			cont++;
		}
	}
	else if (option == other) { // "other" njejt sikurse any!
		Clip* temp = head;
		cont = rand() % length;
		while (cont < length) {
			head = temp->next;
			cont++;
		}
	}
	else if (option == next) // "next" luan tingullin e radhes!
	{ 
		head = head->next;
	}
	else if (option == previous) // "previous" luan tingullin paraprak!
	{
		head = head->previous;
	}
	else // none
		head = head;
	return head;
}

actions actionOption(std::string word) 
{
	if (word == "any")
		return any;
	else if (word == "other")
		return other;
	else if (word == "next")
		return next;
	else if (word == "previous")
		return previous;
	else
		return none;
}
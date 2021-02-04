#ifndef LISTACLIPHEADER_H
#define LISTACLIPHEADER_H
#include <iostream>
#include "ClipHeader.h"

	// Klasa "ListaClip". Struktura e te dhenave qe permban listen e klipeve.

class ListaClip 
{
public:
	ListaClip(); //konstruktori i randomt
	
	 // funksioni per te nderfutur klipe
	 
	void addClip(Clip* c);
	
	//  kthen ne poziten ekzistuese ( nese ekziston )
	
	Clip* exists(std::string);
	/*
	 *  Gets stored head pointer
	 *  @return pointer to Clip list
	 */
	Clip* getHead();
	
	// shfaq listen e klipeve
	
	void display();
	/*
	 *  ekzekuton aksionin varesisht nga probabiliteti
	 *  varesisht se a eshte jap numer random apo i determinuar
	 */
	void executeAction();
	void executeAction(float, float);

private:
	Clip* head; // pointer - per te derguar ne krye
	int length; // gjatesia e listes
};
#endif LISTACLIPHEADER_H

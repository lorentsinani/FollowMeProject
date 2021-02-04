#ifndef LISTACLIPHEADER_H
#define LISTACLIPHEADER_H
#include <iostream>
#include "ClipHeader.h"

class ListaClip        // Klasa "ListaClip". Struktura e te dhenave qe permban listen e klipeve.
{
public:
	ListaClip(); //konstruktori i randomt
	
	void addClip(Clip* c);  // funksioni per te nderfutur klipe te reja
	
	Clip* exists(std::string);   //  kthen ne poziten ekzistuese ( nese ekziston )
	
	Clip* getHead();
	
	void display(); // shfaq listen e klipeve
	
	void executeAction();        // ekzekuton aksionin varesisht nga probabiliteti
	
	void executeAction(float, float);    // varesisht se a eshte jap numer random apo i determinuar

private:
	Clip* head; // pointer - per te derguar ne krye
	int length; // gjatesia e listes
};
#endif LISTACLIPHEADER_H

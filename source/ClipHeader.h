#ifndef CLIPHEADER_H
#define CLIPHEADER_H
#include <iostream>

class Clip       // Klasa Clip. Struktura e datave e cila mban informacionin e qdo klipi.
{
public:
	Clip(); // konstruktor pa parametra - default
	Clip(const std::string, const int, const float, const float,
		const std::string, const std::string);        // konstruktor me parametra 
	
	// marrja e atributeve te nevojshme per projekt
	 
	const std::string getName();
	const std::string getAction1();
	const std::string getAction2();
	const int getTicksToPlay();
	
	// Selekton aksionin per tu ekzekutuar

	const int chooseAction(); // pa parametra - default
	const int chooseAction(const float&, const float&);  // me parametra
	
	//lidhja e konektoreve apo ne kete rast aksioneve me klasen Clip*

	Clip* next;
	Clip* previous;
	Clip* other;
	Clip* any;
	
private:    // klasa private 
	std::string name; // name of the clip // emri
	int ticksToPlay; // times to reproduce clip // sa here te riprodhohet
	float chance1; // chances to execute action 1 // shanset te egzekutohet aksioni 1
	float chance2; // chances to execute action 2 // ~~||~~ aksioni 2
	std::string action1; // action1 to be executed // egzekutimi i aksionit 1
	std::string action2; // action2 to be executed // egzekutimi i aksionit 2
};

#endif LISTACLIP_H

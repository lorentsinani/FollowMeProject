#include <stdlib.h>
#include <time.h>
#include "ClipHeader.h"
using namespace std;

// perdorimi i libraris stdlib.h(standard library) eshte per random numbers, konvertim etj.

Clip::Clip() 
{
	this->name = "";
	this->ticksToPlay = 0;
	this->chance1 = 0;
	this->chance2 = 0;
	this->action1 = "";
	this->action2 = "";
	this->next = nullptr;
	this->previous = nullptr;
}

Clip::Clip(const string name, const int ticks, const float c1,
	const float c2, const string a1, const string a2)
{
	this->name = name;
	this->ticksToPlay = ticks;
	this->chance1 = c1;
	this->chance2 = c2;
	this->action1 = a1;
	this->action2 = a2;
}

const string Clip::getName() 
{
	return this->name;
}

const string Clip::getAction1() 
{
	return this->action1;
}

const string Clip::getAction2() 
{
	return this->action2;
}

const int Clip::getTicksToPlay() 
{
	return this->ticksToPlay;
}
const int Clip::chooseAction()  // // per pjesen e shanseve do te perdorim random numbers // numra te rastesishem
{
	float sum, p1, random;
	sum = this->chance1 + this->chance2;
	p1 = this->chance1 / sum; // 0.1
	srand(time(nullptr));
	random = ((double)rand() / (RAND_MAX));
	if (random < p1) // p1 ->0.1
		return 1;
	else // random > p1
		return 2;
}

const int Clip::chooseAction(const float& n1, const float& n2)
{
	float p1, p2;
	p1 = this->chance1 * n1;
	p2 = this->chance2 * n2;
	if (p1 > p2)
		return chance1;
	else
		return chance2;
}

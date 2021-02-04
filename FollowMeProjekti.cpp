#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "ListaClipHeader.h"
#include "ClipHeader.h"
using namespace std;

//   Programi per luajtjen e tingujve

void play(ListaClip* clips, int mTicks, const vector<float>& points);

void manuali();

// *************************************************************************

int main(int argc, char* argv[])
{
	// Krijimi i listave per te ruajtur klipet

	ListaClip* clips = new ListaClip();
	string keyword = "";
	string name, act1, act2, line;
	int ticks, mTicks{}; // {} prapa Ticks jane perdorur per sshkak te uninitialized "mTicks"!
	float prob1, prob2, point;
	vector<float> points;
	manuali();
	
	// Perseritje per te lexuar te dhena hyrese nga tastiera

	while (keyword != "ticks")
	{
		cin >> keyword;
		if (keyword == "clip")
		{
			cin >> name >> ticks >> prob1 >> prob2 >> act1 >> act2;
			// klip i ri te shtohet ne liste
			Clip* temp = new Clip(name, ticks, prob1, prob2, act1, act2);
			clips->addClip(temp);
		}
		else if (keyword == "ticks")
		{
			// shkas per te filluar listen e degjimit
			cin >> mTicks;
			// Lista opsionale e numrave te tipit float(te ruajtura ne nje vektor)
			getline(cin, line);
			if (!line.empty())
			{
				istringstream stream(line);
				while (stream >> point)
				{
					points.push_back(point);
				}
			}
		}
		else
		{
			cout << "Incorrect input. Exit program." << endl;
			return 0;
		}
	}
	play(clips, mTicks, points);
	delete clips;
	return 0;
}

void play(ListaClip* clips, int mTicks, const vector<float>& points)
{
	int numri = 0;
	int numri2 = 0;
	Clip* ptr;

	// Perseritjet per te luajtur klipet
	while (numri < mTicks)
	{
		ptr = clips->getHead();
		// Nese jo numra te tipit float,numra te rastesishem
		if (points.empty())
		{
			// Perseritjet per te luajtur ticks (bazuar ne ticks te jepur per tu luajtur)
			while (numri2 < ptr->getTicksToPlay())
			{
				cout << ptr->getName() << endl;
				numri2++;
				numri++;
				if (numri >= mTicks)
					return;
			}
			// Metoda per te ekzekutuar aksionin e ardhshem
			clips->executeAction();
			numri2 = 0;
		}
		else
		{
			cout << ptr->getName() << endl;
			clips->executeAction(points[numri * 2], points[numri * 2 + 1]);
			numri++;
		}
	}
}
void manuali()
{
	cout << ">>> DETYRA 3 - Follow Me <<<" << endl << endl;
	cout << "*******************************************************************************************************************" << endl << endl;
	cout << "Instruksionet per te ekzekutuar programin // Instruction for running the program: " << endl;
	cout << "-For inserting clips, type 'clip <name> <ticks to play> <follow chance 1> <follow chance 2> <action 1> <action 2>'. " << endl;
	cout << "-For inserting ticks, type 'ticks <ticks to play> <...optional list of floating point numbers.' " << endl;
	cout << "-If your type is incorrect program will end.Tap any keybind to exit!" << endl << endl;
	cout << "*******************************************************************************************************************" << endl;
}
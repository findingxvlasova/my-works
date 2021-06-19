#include <iostream>
#include <fstream>
#pragma warning(disable: 4996)
using namespace std;

class IdGenerator
{

public:

	static int GenerateId()
	{
		ID++;
		return ID;
	}
	static void ShowId()
	{
		cout << "ID is " << ID << "\n";
	}

private:
	static int ID;

};

int IdGenerator::ID = 13;


int main()
{
	IdGenerator::GenerateId();
	IdGenerator::ShowId();

	IdGenerator first;
	cout << "first: " << first.GenerateId() << "\n";

	IdGenerator second;
	cout << "second: " << second.GenerateId() << "\n";

	IdGenerator third;
	cout << "third: " << third.GenerateId() << "\n";

	IdGenerator::GenerateId();
	IdGenerator::ShowId();
}




	ЗАДАНИЕ 2
После выполнения, ответьте на вопрос - нужны ли вам экземпляры этого класса, для того, чтобы работать с ним?

Для статических не обязательно



задание 3

#include <iostream>
#include <fstream>

using namespace std;


class Planet
{
public:
	Planet(); //ctor
	Planet(char nameOfObject[]); //ctor2
	
	static Planet* CreateSolarSystem()
	{
		if (solarSystemDone == false)
		{
			solarSystemDone = true;
			

			char nameOfObject[100] = "Sun";
			Planet* Sun = new Planet(nameOfObject);
			Planet* planets = new Planet[8];

			char mercury[] = "Mercury";
			planets[0] = Planet(mercury);

			char venus[] = "Venus";
			planets[1] = Planet(venus);

			char earth[] = "Earth";
			planets[2] = Planet(earth);
			Planet* earthSattelite = new Planet[1];
			char moon[] = "Moon";
			earthSattelite[0] = Planet(moon);
			planets[2].addSatellite(earthSattelite, 1);



			char mars[] = "Mars";
			planets[3] = Planet(mars);
			Planet* marsSattelite = new Planet[2];
			char fobos[] = "Fobos";
			char deimos[] = "Deimos";
			marsSattelite[0] = Planet(fobos);
			marsSattelite[1] = Planet(deimos);
			planets[3].addSatellite(marsSattelite, 2);


			char jupiter[] = "Jupiter";
			planets[4] = Planet(jupiter);
			Planet* jupiterSattellites = new Planet[79];
			planets[4].addSatellite(jupiterSattellites, 79);

			char saturn[] = "Saturn";
			planets[5] = Planet(saturn);
			Planet* saturnSattellites = new Planet[82];
			planets[5].addSatellite(saturnSattellites, 82);


			char uran[] = "Uranus";
			planets[6] = Planet(uran);
			Planet* uranusSattellites = new Planet[27];
			planets[6].addSatellite(uranusSattellites, 27);
			
			
			char neptun[] = "Neptune";
			planets[7] = Planet(neptun);
			Planet* neptuneSattellites = new Planet[14];
			planets[7].addSatellite(neptuneSattellites, 14);
			Sun->setOrbit(planets);
			
			return Sun;

		}
	}



	static void getCenterName()
	{
		if (solarSystemDone == true)
			cout << "Sun\n";
		
	}

	static void destroySolarSystem(Planet*& Sun)
	{
		if (solarSystemDone == true)
		{
			Sun->Delete();
			delete Sun;
		}
	}


private:

	void setOrbit(Planet* toSystem)
	{
		delete[]objectsOnOrbit;
		objectsOnOrbit = toSystem;
		planetCounter = 8;
	}

	void addSatellite(Planet* newSattelite, int satellitesNums)
	{
		delete[]sattelite;
		sattelite = newSattelite;
		satteliteCounter = satellitesNums;
	}
	void Delete()
	{
		for (int i = planetCounter - 1; i >= 0; i--)
		{
			if (satteliteCounter > 0)
			{
				delete[]sattelite;
			}
		}
		delete[] objectsOnOrbit;
	}


	char planetName[100];
	int planetCounter;
	Planet* sattelite;
	Planet* objectsOnOrbit;
	int satteliteCounter;
	static bool solarSystemDone;
};


bool Planet::solarSystemDone = false;




Planet::Planet()
{
	char nameOfObject[] = "planetName";
	strcpy(planetName, nameOfObject);
	sattelite = nullptr;
	planetCounter = 0;
	satteliteCounter = 0;
}
Planet::Planet(char nameOfObject[]) //ctor2
{
	strcpy(planetName, nameOfObject);
	sattelite = nullptr;
	planetCounter = 0;
	satteliteCounter = 0;
}



int main()
{
	Planet* solarSystem;
	solarSystem = Planet::CreateSolarSystem();
	Planet::destroySolarSystem(solarSystem);
}


задание 4

:((просрочка


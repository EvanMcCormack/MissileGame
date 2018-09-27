//Author: Evan McCormack
//Date: 23/09/2018
//

#include<iostream>
#include<ctime>
#include<string>

using namespace std;

typedef struct Position
{
	int x;
	int y;

	void print()
	{
		cout << x << "," << y << endl;
	}

}Coordinates;

enum WarHead { EXPLOSIVE, NUCLEAR };

typedef struct Enemy {
	Coordinates coordinates;
}Target;

struct Missile {
	WarHead payload;
	
	Coordinates coordinates;

	Target target;

	bool armed;

	void arm()
	{
		if (armed)
			armed = false;
		else
			armed = true;
	}

	void update() {
		coordinates.x += 1;
		coordinates.y += 2;
	}
};

void gameplay();
void warheadChoice(Missile &rocket);
void acquireTarget(Missile &rocket);
void launchcodes();
void arming(Missile &rocket);
void movement(Missile &rocket);
void endscreen(Missile &rocket);

int main()
{

	std::srand(static_cast<unsigned>(NULL));

	std::string carryon = "YES";

	std::cout << "If you don't want to continue enter, NO" << std::endl;
	std::cin >> carryon;

	if (carryon == "YES")
	{
		gameplay();
	}
	system("PAUSE");

}

void gameplay()
{
	Missile rocket;

	warheadChoice(rocket);

	acquireTarget(rocket);

	launchcodes();
	
	arming(rocket);

	movement(rocket);
}

void warheadChoice(Missile &rocket)
{
	int choice{ 0 };
	std::cout << "Choose which warhead you want?" << std::endl;
	std::cout << "1: Explosive" << std::endl << "2: Nuclear" << std::endl;
	std::cin >> choice;

	if (choice == 1)
	{
		rocket.payload = WarHead::EXPLOSIVE;
	}
	else if (choice == 2)
	{
		rocket.payload = WarHead::NUCLEAR;
	}
	else
	{
		std::cout << "Sorry that is not an option" << std::endl;
	}

}

void acquireTarget(Missile &rocket)
{

	rocket.target.coordinates.x = rand() % 20 + 1;
	rocket.target.coordinates.y = rand() % 20 + 1;

}

void launchcodes()
{
	int codes = {0};
	int launch = {1};
	bool entered = false;

	std::cout << "Launch Codes:" << std::endl;

	codes = rand() % 99999;
	std::cout << codes << std::endl;

	while (entered != true)
	{
		std::cout << "Please input the launch codes" << std::endl;
		std::cin >> launch;

		if (launch == codes)
		{
			entered = true;
		}
		else
		{
			std::cout << "incorrect" << std::endl;
		}
	}

}

void arming(Missile &rocket)
{
	rocket.armed;

	std::cout << "Missile Armed" << std::endl;
}

void movement(Missile &rocket)
{
	bool hit = false;
	bool missed = false;

	rocket.coordinates.x = 0;
	rocket.coordinates.y = 0;

	while (hit != true)
	{
		rocket.update();

		if ((rocket.coordinates.x == rocket.target.coordinates.x) && (rocket.coordinates.y == rocket.target.coordinates.y))
		{
			hit = true;
			endscreen(rocket);
		}
		else if ((rocket.coordinates.x > rocket.target.coordinates.x) || (rocket.coordinates.y > rocket.target.coordinates.y))
		{
			hit = true;
			missed = true;
			std::cout << "The missile missed the target, try again" << std::endl;
			main();
		}
	}
}

void endscreen(Missile &rocket)
{
	if (rocket.payload == EXPLOSIVE)
	{
		std::cout << "Congrats you blew up the target" << std::endl;
	}
	else if (rocket.payload == NUCLEAR)
	{
		std::cout << "You vapourised your target undeneath a mushroom cloud" << std::endl;
	}
}
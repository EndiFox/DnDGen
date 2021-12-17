#include <random>
#include <iostream>
#include <string>

using namespace std;

int Dice(int dicemin, int dicemax)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(dicemin, dicemax);
	return dist(gen);
}

class corridors
{
	std::string mass[12] = { "Small Corridor", "Mid Corridor", "Huge Corridor", "Turn Right", "Turn Left", "Metro Line", "Metro Station", "Destroyed metro station", "Destroyed metro line on the left", "Destroyed metro line on the right", "Destroyed metro line", "Crossroads" };
public:

	string Generate()
	{
		std::string f;
		int res = Dice(1, 12);

		for (int i = 1; i < res; i++)
		{
			if (i = res)
			{
				f = mass[i];
				if (f == "Small Corridor")
				{
					cout << "Dist: " << Dice(10, 50) << endl;
				}
				if (f == "Mid Corridor")
				{
					cout << "Dist: " << Dice(51, 100) << endl;
				}
				if (f == "Huge Corridor")
				{
					cout << "Dist: " << Dice(101, 300) << endl;
				}
				return f;
			}
		}

	}

	int doors()
	{
		return Dice(1, 10);
	}
};

class funcrooms
{
	string rooms[20] = { "Teleport", "Computer Room", "Recieption", "Recieption Elevator", "Fabric with mob", "Fabric", "Barraks", "Command Centre", "Battery", "Warehouse", "Golem", "Armory", "Blacksmithery", "Lab", "Prison", "Coliseum", "Repair Hangar", "Negotitations Room", "Hospital", "Cryogen cameras" };

public:

	string Generate()
	{
		string f;
		int res = Dice(1, 20);

		for (int i = 1; i < res; i++)
		{
			if (i = res)
			{
				f = rooms[i];
				int res2 = Dice(1, 3);
				if (res2 == 1)
				{
					cout << "Size: " << Dice(10, 50) << " on " << Dice(10, 50) << endl;
				}
				if (res2 == 2)
				{
					cout << "Size: " << Dice(10, 50) << " on " << Dice(10, 80) << endl;
				}
				if (res2 == 3)
				{
					cout << "Size: " << Dice(10, 100) << " on " << Dice(10, 100) << endl;
				}
				return f;
			}
		}
	}
};

class mobs 
{
	//int moblen = 0;
	float difficulty = 0;
	//string mob[7]{"henchman", "solider", "hoplit", "hard solider", "shooter", "hypershooter", "small golem"};
	string input;
public:
	
	string Generate() 
	{
		input = "";
		cin >> input;
		if (input == "henchman") 
		{
			difficulty += 1;
		}
		if (input == "solider") 
		{
			difficulty += 2;
		}
		if (input == "hoplit") 
		{
			difficulty += 1.5f;
		}
		if (input == "hard solider") 
		{
			difficulty += 3;
		}
		if (input == "shooter") 
		{
			difficulty += 3;
		}
		if (input == "hypershooter") 
		{
			difficulty += 4;
		}
		if (input == "small golem") 
		{
			difficulty += 10;
		}
		return input;
	}

	float GetDiff(int number, int level) 
	{
		return difficulty * number / level;
	}
};

int main()
{
	char endprog;
	int level;
	int mobcount;
	int s = 0;

	cout << "Players Level:" << endl;
	cin >> level;
	cout << "Mobs number:" << endl;
	cin >> mobcount;
	cout << "" << endl;
	

	corridors cor = corridors();
	funcrooms func = funcrooms();
	mobs mob = mobs();

	int number = cor.doors();
	
	string *rooms = new string[number];
	string *mobs = new string[mobcount];

	cout << cor.Generate() << endl;
	cout << number << endl;
	cout << "" << endl;

	for (int i = 0; i < number; i++) 
	{
		string local = func.Generate();
		cout << local << endl;
		cout << "" << endl;
		rooms[i] = local;
	}
	
	for (int i = 0; i < mobcount; i++) 
	{
		string local = mob.Generate();
		mobs[i] = local;
	}

	cout << "" << endl;

	for (int i = 0; i < mobcount; i++) 
	{
		cout << mobs[i] << ' ';		
	}

	cout << "" << endl;
	cout << mob.GetDiff(mobcount, level) << endl;

	cin >> endprog;
	delete[] rooms;
	delete[] mobs;
	return 0;
}


//float Generate(int level)
//{
//	cin >> input;
//	if (moblen == len)
//	{
//		return difficulty * len / level;
//	}
//	if (input == "henchman")
//	{
//		difficulty += 1;
//		mob[moblen] += "henchman";
//		moblen += 1;
//	}
//	if (input == "solider")
//	{
//		difficulty += 2;
//		mob[moblen] += "solider";
//		moblen += 1;
//	}
//	if (input == "hoplit")
//	{
//		difficulty += 2;
//		mob[moblen] += "solider";
//		moblen += 1;
//	}
//	if (input == "hard solider")
//	{
//		difficulty += 5;
//		mob[moblen] += "hard solider";
//		moblen += 1;
//	}
//	if (input == "shooter")
//	{
//		difficulty += 3;
//		mob[moblen] += "shooter";
//		moblen += 1;
//	}
//	if (input == "hypershooter")
//	{
//		difficulty += 6;
//		mob[moblen] += "hypershooter";
//		moblen += 1;
//	}
//	if (input == "small golem")
//	{
//		difficulty += 10;
//		mob[moblen] += "small golem";
//		moblen += 1;
//	}
//	return difficulty * len / level;
//}
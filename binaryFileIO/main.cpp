#include <string>
#include <iostream>
#include <sys/stat.h>
#include <fstream>
#include <vector>

using namespace std;

class Item
{
public:
	Item();
	void setItem(string _itemName);
	void setValue(int _value);
	void setWeight(float _weight);

	string getItem() const;
	int getValue() const;
	float getWeight() const;
private:
	string itemName;
	int value;
	float weight;
};
Item::Item()
{
	itemName  = "";
	value = 0;
	weight = 0.0f;
}
void Item::setItem(string _itemName)
{
	itemName = _itemName;
}
void Item::setValue(int _value)
{
	value = _value;
}
void Item::setWeight(float _weight)
{
	weight = _weight;
}
string Item::getItem() const
{
	return itemName;
}
int Item::getValue() const
{
	return value;
}
float Item::getWeight() const
{
	return weight;
}

class Hero 
{
public:
	//Constructors
	Hero();
	~Hero() {};
	//****Mutators*****
	void setName(string _name);
	void setStr(unsigned int _strVal);
	void setInt(unsigned int _intVal);
	void setAgi(unsigned int _agiVal);
	void setCurrHP(unsigned int _currHP);
	void setMaxHP(unsigned int _maxHP);
	void setPhysAC(float _physAC);
	void setMagAC(float _magAC);
	void setInvCount(unsigned int _invCount);
	void setItemName(string _itemName);
	void setItemVal(int _itemVal);
	void setItemWeight(float _itemWeight);
	//****Accessors
	string getName() const;
	unsigned int getStr() const;
	unsigned int getInt() const;
	unsigned int getAgi() const;
	unsigned int getCurrHP() const;
	unsigned int getMaxHP() const;
	float getPhysAC() const;
	float getMagAC() const;
	unsigned int getInvCount() const;
	string getItemName() const;
	unsigned int getItemVal() const;
	float getItemWeight() const;

private:
	string name;
	unsigned int strVal;
	unsigned int intVal;
	unsigned int agiVal;
	unsigned int currHP;
	unsigned int maxHP;
	float physAC;
	float magAC;
	unsigned int invCount;
	string itemName;
	unsigned int itemVal;
	float itemWeight;
	vector<Item> inventory;
};



Hero::Hero()
{
	name = "";
	strVal = 0;
	intVal = 0;
	agiVal = 0;
	currHP = 0;
	maxHP = 0;
	physAC = 0.00f;
	magAC = 0.00f;
	invCount = 0;
	itemName = "";
	itemVal = 0;
	itemWeight = 0.00f;
}

void Hero::setName(string _name)
{
	name = _name;
}
void Hero::setStr(unsigned int _strVal)
{
	strVal = _strVal;
}
void Hero::setInt(unsigned int _intVal)
{
	intVal = _intVal;
}
void Hero::setAgi(unsigned int _agiVal)
{
	agiVal = _agiVal;
}
void Hero::setCurrHP(unsigned int _currHP)
{
	currHP = _currHP;
}
void Hero::setMaxHP(unsigned int _maxHP)
{
	maxHP = _maxHP;
}
void Hero::setPhysAC(float _physAC)
{
	physAC = _physAC;
}
void Hero::setMagAC(float _magAC)
{
	magAC = _magAC;
}
void Hero::setInvCount(unsigned int _invCount)
{
	invCount = _invCount;
}
void Hero::setItemName(string _itemName)
{
	itemName = _itemName;
}
void Hero::setItemVal(int _itemVal) 
{
	itemVal = _itemVal;
}
void Hero::setItemWeight(float _itemWeight)
{
	itemWeight = _itemWeight;
}
string Hero::getName() const
{
	return name;
}
unsigned int Hero::getStr() const
{
	return strVal;
}
unsigned int Hero::getInt() const
{
	return intVal;
}
unsigned int Hero::getAgi() const
{
	return agiVal;
}
unsigned int Hero::getCurrHP() const
{
	return currHP;
}
unsigned int Hero::getMaxHP() const
{
	return maxHP;
}
float Hero::getPhysAC() const
{
	return physAC;
}
float Hero::getMagAC() const
{
	return magAC;
}
unsigned int Hero::getInvCount() const
{
	return invCount;
}
string Hero::getItemName() const
{
	return itemName;
}
unsigned int Hero::getItemVal() const
{
	return itemVal;
}
float Hero::getItemWeight() const
{
	return itemWeight;
}

void heroInputData(char* block, vector<Hero> &heroes)
{
	
	Hero* hero = new Hero;
	
}
void heroCollection(string filename, vector<Hero> &heroes)
{


	ifstream myfile;
	myfile.open(filename, ios::in | ios::binary); //calls in a new file in binary state and points to the EOF
	if (myfile.is_open())
	{
	
		//unsigned int counter = 1;
		unsigned int size;
		myfile.read((char*)&size, 4);
		for (size_t i = 0; i < size; i++)
		{
			Hero* character = new Hero;
			
			unsigned int nameSize;
			myfile.read((char*)&nameSize, 4);

			string tempString = "";
			char tempChar;
			unsigned int counter = 0;
			do
			{
				myfile.read((char*)&tempChar, 1);
				counter++;
				tempString += tempChar;
			} while (counter < nameSize);
			character->setName(tempString);
			
			unsigned int stats;
			myfile.read((char*)&stats, 2);
			character->setStr(stats);
			myfile.read((char*)&stats, 2);
			character->setInt(stats);
			myfile.read((char*)&stats, 2);
			character->setAgi(stats);
			myfile.read((char*)&stats, 4);

			character->setCurrHP(stats);
			myfile.read((char*)&stats, 4);
			character->setMaxHP(stats);

			float AC;
			myfile.read((char*)&AC, 4);
			character->setPhysAC(AC);
			myfile.read((char*)&AC, 4);
			character->setMagAC(AC);

			unsigned int numItems;
			myfile.read((char*)&numItems, 4);
			
			
			vector<Item> inventory;
			for (size_t i = 0; i < numItems; i++)
			{
				Item* item = new Item;
				unsigned int nameSz;
				myfile.read((char*)&nameSz, 4);

				string tempStr = "";
				char tempChr;
				unsigned int count = 0;
				do
				{
					myfile.read((char*)&tempChr, 1);
					count++;
					tempStr += tempChr;
				} while (count < nameSz);
				item->setItem(tempStr);
				
				unsigned int val;
				myfile.read((char*)&val, 4);
				item->setItem(tempStr);
				float wt;
				myfile.read((char*)&wt, 4);

				inventory.push_back(*item);
			}
			heroes.push_back(*character);
		}
		
		myfile.close();		

	}	
	
}


int main()
{
	cout << "Which file(s) to open?\n";
	cout << "1. fantasyheroes.dat" << endl;
	cout << "2. superheroes.dat" << endl;
	cout << "3. Both files" << endl;
	int option;
	cin >> option;

	vector<Hero> heroes;

	if (option == 1)
	{
		heroCollection("fantasyheroes.dat", heroes);

	}
	else if (option == 2)
	{
		heroCollection("superheroes.dat", heroes);
	}
	else 
	{
		heroCollection("fantasyheroes.dat", heroes);
		heroCollection("superheroes.dat", heroes);
	}

	cout << "1. Print all heroes" << endl;
	for (size_t i = 0; i < heroes.size(); i++)
	{

	}
	cout << "2. Hero with the most items" << endl;
	cout << "3. Strongest hero" << endl;
	cout << "4. Heroes with greater than 18 intelligence" << endl;
	cout << "5. 2 clumsiest heroes" << endl;
	cout << "6. Hero with the most valuable stuff" << endl << endl;

	cin >> option;

	/* Work your magic here */

	return 0;
}
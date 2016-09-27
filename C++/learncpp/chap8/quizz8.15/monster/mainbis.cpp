#include <iostream>
#include <string>

class Monster
{
public:
	enum MonsterType
	{
		Dragon,
		Goblin,
		Ogre,
		Orc,
		Skeleton,
		Troll,
		Vampire,
		Zombie,
		MAX_MONSTER_TYPES
	};

private:

	MonsterType m_type;
	std::string m_name;
	std::string m_roar;
	int m_hitPoints;

public:
	Monster(MonsterType type, std::string name, std::string roar, int hitPoints)
		: m_type(type), m_name(name), m_roar(roar), m_hitPoints(hitPoints)
	{

	}

	std::string getTypeString()
	{
		switch (m_type)
		{
		case Dragon: return "dragon";
		case Goblin: return "goblin";
		case Ogre: return "ogre";
		case Orc: return "orc";
		case Skeleton: return "skeleton";
		case Troll: return "troll";
		case Vampire: return "vampire";
		case Zombie: return "zombie";
		}

		return "???";
	}

	void print()
	{
		std::cout << m_name << " the " << getTypeString() << " has " << m_hitPoints << " hit points and says " << m_roar << '\n';
	}
};

class MonsterGenerator
{
public:
	static Monster generateMonster()
	{
		return Monster(Monster::Skeleton, "Bones", "*rattle*", 4);
	}
};

int main()
{
	Monster m = MonsterGenerator::generateMonster();
	m.print();

    return 0;
}

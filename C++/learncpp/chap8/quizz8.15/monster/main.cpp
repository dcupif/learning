#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

class Monster
{
public:
    enum class MonsterType
    {
        DRAGON,
        GOBLIN,
        OGRE,
        ORC,
        SKELETON,
        TROLL,
        VAMPIRE,
        ZOMBIE,
        MAX_MONSTER_TYPES
    };

private:
    MonsterType m_type;
    std::string m_name;
    std::string m_roar;
    int m_hitPoints;

public:
    Monster(MonsterType type, std::string name, std::string roar, int hitPoints)
        : m_type{type}, m_name{name}, m_roar{roar}, m_hitPoints{hitPoints}
    {}

    std::string getTypeString()
    {
        switch (m_type) {
            case MonsterType::DRAGON:   return "dragon";
            case MonsterType::GOBLIN:   return "goblin";
            case MonsterType::OGRE:     return "ogre";
            case MonsterType::ORC:      return "orc";
            case MonsterType::SKELETON: return "skeleton";
            case MonsterType::TROLL:    return "troll";
            case MonsterType::VAMPIRE:  return "vampire";
            case MonsterType::ZOMBIE:   return "zombie";
            default:                    return "getTypeString(): Unhandled Monster Type";
        }
    }

    void print()
    {
        std::cout << m_name << " the " << getTypeString() << " has " <<
            m_hitPoints << " hit points and says " << m_roar << '\n';
    }

};

class MonsterGenerator
{
public:
    static Monster generateMonster()
    {
        Monster::MonsterType type =
            static_cast<Monster::MonsterType>(
                getRandomNumber(
                    0,
                    static_cast<int>(
                        Monster::MonsterType::MAX_MONSTER_TYPES
                    ) - 1
                )
            );

        int hitPoints = getRandomNumber(1, 100);

        static std::string s_names[6]{ "Blarg", "Moog", "Pksh", "Tyrn", "Mort", "Hans" };
		static std::string s_roars[6]{ "*ROAR*", "*peep*", "*squeal*", "*whine*", "*hum*", "*burp*"};

        return Monster(
            type,
            s_names[getRandomNumber(0, 5)],
            s_roars[getRandomNumber(0, 5)],
            hitPoints
        );
    }

    // Generate a random number between min and max (inclusive)
	// Assumes srand() has already been called
	static int getRandomNumber(int min, int max)
	{
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
		// evenly distribute the random number across our range
		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	}
};

int main()
{
    // set initial seed value to system clock
	srand(static_cast<unsigned int>(time(0)));
    rand();

	Monster m = MonsterGenerator::generateMonster();
	m.print();

    return 0;
}

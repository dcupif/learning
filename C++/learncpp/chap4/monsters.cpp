#include <iostream>
#include <string>

enum class MonsterType
{
    OGRE,
    DRAGON,
    ORC,
    GIANT_SPIDER,
    SLIME
};

struct Monster
{
    MonsterType type;
    std::string name;
    int health;
};

std::string getMonsterType(Monster monster)
{
    switch (monster.type) {
        case MonsterType::OGRE:
            return "Ogre";
            break;
        case MonsterType::DRAGON:
            return "Dragon";
            break;
        case MonsterType::ORC:
            return "Orc";
            break;
        case MonsterType::GIANT_SPIDER:
            return "Giant Spider";
            break;
        case MonsterType::SLIME:
            return "Slime";
            break;
        default:
            return "Unknown Monster";
            break;
    }
}

void printMonster(Monster monster)
{
    std::cout << "This " << getMonsterType(monster) << " is named " <<
        monster.name << " and has " << monster.health << " health.\n";
}

int main(int argc, char const *argv[])
{
    Monster ogre = { MonsterType::OGRE, "Torg", 145 };
    Monster slime = { MonsterType::SLIME, "Blurp", 23 };
    printMonster(ogre);
    printMonster(slime);
    return 0;
}

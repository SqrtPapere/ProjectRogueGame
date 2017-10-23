

#include "CharacterFactory.hpp"

Character* CharacterFactory::makeCharacter(CharacterFactory::CharacterType type, int x, int y, int id, int life, int atk, std::string addr) {
    Character *ch;
    switch (type) {
        case CharacterFactory::Elfo:
            
            ch = new Elf(x, y, id, life, atk, addr);
            break;
        case CharacterFactory::Druido:
            ch = new Druid(x, y, id, life, atk, addr);
            break;
        case CharacterFactory::Paladino:
            ch = new Paladin(x, y, id, life, atk, addr);
            break;
        case CharacterFactory::Poke:
            ch = new Monster::Monster(x, y, id, life, atk, addr);
            break;
        default:
            ch = new Monster::Monster(x, y, id, life, atk, addr);
            break;
    }
    return ch;
}

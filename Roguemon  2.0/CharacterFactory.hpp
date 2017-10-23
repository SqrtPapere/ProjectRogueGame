

#ifndef CharacterFactory_hpp
#define CharacterFactory_hpp

#include <stdio.h>

#include "Character.hpp"
#include "Elf.hpp"
#include "Druid.hpp"
#include "Paladin.hpp"
#include "Monster.hpp"


class CharacterFactory {
public:
    enum CharacterType {Elfo, Druido, Paladino, Poke};
    
    static Character* makeCharacter(CharacterFactory::CharacterType type, int x, int y , int id, int life, int atk, std::string addr);
};

#endif /* CharacterFactory_hpp */

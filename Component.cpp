//
// Created by kacper on 18.10.2019.
//

#include "Component.h"
#include <iostream>

Deck::Deck(std::string const &str, int i)
{
    name=str;
    id=i;
    std::cout<<name;
}

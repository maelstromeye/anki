#include <iostream>
#include "Component.h"
int main()
{

    std::set<Component*, alpha> data;
    Component *d1 = new Deck(*new std::string("baaa"), 1), *d2 = new Deck(*new std::string("ba"), 1), *d3 = new Deck(*new std::string("aaaa"), 1);
    Component *d4 = new Deck(*new std::string(">0"), 1), *d5 = new Deck(*new std::string(">>"), 1), *d6 = new Deck(*new std::string("zzz"), 1);
    Component *f1 = new Folder(*new std::string("jjayjoker")), *f2 = new Folder(*new std::string("jjay")), *f3 = new Folder(*new std::string("aa."));
    data.insert(d3);
    data.insert(f2);
    data.insert(d4);
    data.insert(d1);
    data.insert(f1);
    data.insert(d2);
    data.insert(d6);
    data.insert(d5);
    data.insert(f3);
    f3->insert(d5);
    f3->insert(d2);
    f3->insert(d1);
    f3->insert(f2);
    auto it = data.begin();
    while(it!=data.end())
    {
        std::cout<<*(*it)->getname()<<std::endl;
        it++;
    }
    for(int i = 0; i<5; i++)
    {
        std::cout << *((*f3)[i])->getname() << std::endl;
    }
    return 0;
}
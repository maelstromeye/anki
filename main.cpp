#include <iostream>
#include "Component.h"
#include <set>
#include <cctype>
int main()
{
    struct alpha
    {
        bool operator() (Component* const& cmp1, Component* const& cmp2)
        {
            const std::string* str1 = cmp1->getname();
            const std::string* str2 = cmp2->getname();
            char c1 = str1->front();
            char c2 = str2->front();
            int i = 0;
            return c1<c2;
            do
            {
                if(std::isalpha(c1))
                {
                    if(std::isalpha(c2))
                    {
                        if(c1==c2)
                        {
                            ++i;
                            if(i<str1->size()) c1 = str1->at(i);
                            else return true;
                            if(i<str2->size()) c2 = str2->at(i);
                            else return false;
                            continue;
                        }
                    }
                    else return true;
                }
                else if(std::isalpha(c2)) return false;
                else
                {
                    ++i;
                    if(i<str1->size()) c1 = str1->at(i);
                    else return true;
                    if(i<str2->size()) c2 = str2->at(i);
                    else return false;
                    continue;
                }
            }
            while(true);
        }
    };
    std::set<Component*, alpha> data;
    Component *d1 = new Deck(*new std::string("ahaaa"), 1), *d2 = new Deck(*new std::string("ba"), 1), *d3 = new Deck(*new std::string("aaaa"), 1);
    Component *d4 = new Deck(*new std::string(";;"), 1), *d5 = new Deck(*new std::string(";!"), 1), *d6 = new Deck(*new std::string("zzz"), 1);
    std::cout<<d1->getname();
    data.insert(d1);
    data.insert(d2);
    data.insert(d6);
    data.insert(d4);
    data.insert(d3);
    data.insert(d5);
    std::set<Component*, alpha>::iterator it = data.begin();
    while(it!=data.end())
    {
        std::cout<<(*it)->getname()<<'/n';
        it++;
    }

    return 0;
}
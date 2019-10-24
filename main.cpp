#include <iostream>
#include "Component.h"
#include <sstream>


void save(Component* comp);
int main()
{

    std::set<Component*, alpha> data;
    Component *d1 = new Deck(*new std::string("baaa"), 1), *d2 = new Deck(*new std::string("ba"), 1), *d3 = new Deck(*new std::string("aaaa"), 1);
    Component *d4 = new Deck(*new std::string(">0"), 1), *d5 = new Deck(*new std::string(">>"), 1), *d6 = new Deck(*new std::string("zzz"), 1);
    Component *f1 = new Folder(*new std::string("jjayjoker")), *f2 = new Folder(*new std::string("jjay")), *f3 = new Folder(*new std::string("aa."));
    Deck newd2;
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
    d1->add("dare", "him");
    d1->add("hora", "jojo");
    d1->add("spirited", "away");
    d1->add("your", "name");
    d1->add("tenki no", "ko");
    d1->add("owaru", "made mo");


    for(int i=0; i<6; i++)
    {
       // std::cout<<d1->at(i)->getqst()<<std::endl<<d1->at(i)->getans()<<std::endl<<std::endl;
    }
    auto it = data.begin();
    while(it!=data.end())
    {
        std::cout<<*(*it)->getname()<<std::endl;
        it++;
    }
//    for(int i = 0; i<5; i++)
//    {
//        std::cout << *((*f3)[i])->getname() << std::endl;
//    }
    Deck dek("yossha", 69);
    dek.add("eto", "ne");
    dek.add("yahari", "suki");
    dek.add("gun", "gan");
    {std::ofstream of("ra.txt");
    boost::archive::text_oarchive oa(of);
    oa << dek;}
    {std::ifstream ifs("ra.txt");
    boost::archive::text_iarchive ia(ifs);
    ia>>newd2;}
    std::cout<<"------------------";
    std::cout<<*newd2.getname();
    for(int i=0; i<3; i++)
    {
         std::cout<<dek.at(i)->getqst()<<std::endl<<dek.at(i)->getans()<<std::endl<<std::endl;
    }
    return 0;
}
void save(Component* comp)
{
    if(!comp) return;
    std::ofstream ofs(*comp->getname());
    boost::archive::text_oarchive oa(ofs);
    oa<<comp;
}
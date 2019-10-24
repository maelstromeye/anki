//
// Created by kacper on 18.10.2019.
//

#ifndef ANKI_COMPONENT_H
#define ANKI_COMPONENT_H
#include <vector>
#include <string>
#include <set>
#include <cctype>
#include <fstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>


    class Card
    {
    private:
        std::string qst;
        std::string ans;
        int id;
    public:
        Card(std::string const& qst, std::string const& ans, int i)
        {
            this->qst = qst;
            this->ans = ans;
            id = i;
        }
        std::string getqst(){return qst;}
        std::string getans(){return ans;}
        int getid(){return id;}
        void setqst(std::string &str){qst=str;}
        void setans(std::string &str){ans=str;}
        void setid(int i){id=i;}

    };
    class Component
    {
        private:
            friend class boost::serialization::access;
            template<class Archive>
            void serialize(Archive & ar, const unsigned int& i){};
        public:
            virtual const std::string* getname() const{return nullptr;};
            virtual void setname(std::string &str){};
            virtual void insert(Component* comp){};
            virtual const Component* operator[](int i) const {return nullptr;};
            virtual ~Component() = default;
            virtual void save() const{};
            virtual void add(std::string const& qst, std::string const& ans){};
            virtual Card* at(int i){};
    };
    struct alpha
    {
        bool operator() (Component* const& cmp1, Component* const& cmp2)
        {
            const std::string* str1 = cmp1->getname();
            const std::string* str2 = cmp2->getname();
            auto it1 = str1->begin();
            auto it2 = str2->begin();
            do
            {
                if(std::isalpha(*it1))
                {
                    if(std::isalpha(*it2))
                    {
                        if(*it1==*it2) continue;
                        else return toupper(*it1)<toupper(*it2);
                    }
                    else return true;
                }
                else if(std::isalpha(*it2)) return false;
                else
                {
                    if(*it1==*it2) continue;
                    else return *it1<*it2;
                }
            }
            while(it1++!=str1->end()&&it2++!=str2->end());
            return str1->size()<str2->size();
        }
    };
    class Deck: public Component
    {
        private:
            friend class boost::serialization::access;
            std::string name;
            int id;
            std::vector<Card*> cards;
            template<class Archive>
            void serialize(Archive & ar, const unsigned int& i)
            {
                ar & name;
                ar & id;
                //ar & cards;
            }
        public:

            const std::string* getname() const override{return &name;}
            void add(std::string const& qst, std::string const& ans)
            {
                cards.push_back(new Card(qst, ans, cards.size()));
            }
            Card* at(int i)
            {
                if(i>=cards.size()||i<0) return nullptr;
                return cards.at(i);
            }
            Deck()=delete;
            Deck( std::string const &str, int i)
            {
                name=str;
                id=i;
            }

    };
    class Folder: public Component
    {
        private:
            std::set<Component*, alpha> children;
            std::string name;
            friend class boost::serialization::access;
            template<class Archive>
            void serialize(Archive & ar, const unsigned int& i)
            {
                ar & name;
                if(children.empty()) return;
                //for(auto it : children) it->serialize(ar, i);
            }
        public:
            Folder()=delete;
            const std::string* getname() const override{return &name;}
            explicit Folder(std::string &str){name=str;}
            void insert(Component* comp) override{if(comp!=this) children.insert(comp);}
            const Component* operator[](int i) const override
            {
                if(i>=children.size()||i<0) return nullptr;
                auto it = children.begin();
                for(int j = 0; j<i; j++, it++);
                return *it;
            }

    };
#endif //ANKI_COMPONENT_H

//
// Created by kacper on 18.10.2019.
//

#ifndef ANKI_COMPONENT_H
#define ANKI_COMPONENT_H
#include <vector>
#include <string>
    class Card
    {
        private:
            std::string qst;
            std::string ans;
            int id;
        public:
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

        public:
            virtual const std::string* getname() const{return nullptr;};
            virtual void setname(std::string &str){};
            virtual ~Component()= default;
    };
    class Deck: public Component
    {
        private:
            std::string name;
            int id;
            std::vector<Card> cards;
        public:
            const std::string* getname() const{return &name;}
            Deck()=delete;
            Deck( std::string const&str, int i);
    };
    class Folder: public Component
    {
        private:
            std::vector<Deck> children;
            std::string name;
        public:
            Folder()=delete;
            explicit Folder(std::string &str){name=str;}
    };
#endif //ANKI_COMPONENT_H

#ifndef FAMILYTREE_H_
#define FAMILYTREE_H_
#include <string>

namespace family
{
class Person;
class Tree;
enum Gender
{
    male,
    female,
    unknown
};
} // namespace family

class family::Person
{
public:
    std::string name;
    Person *father;
    Person *mother;
    Gender gender;
    Person(std::string name, Gender gender = Gender::unknown);
};

class family::Tree
{
public:
    Person *root;

    Tree(std::string name);
    ~Tree();
    Tree addFather(std::string son, std::string father);
    Tree addMother(std::string son, std::string mother);
    std::string relation(std::string name);
    std::string find(std::string relation);
    void display();
    void remove(std::string name);
    Person *search_person_by_name(Person *root, std::string name);
    Person* search_person_by_name(std::string name);
};

#endif
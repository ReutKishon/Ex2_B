#include "FamilyTree.hpp"
#include <iostream>
#include <string>
#include <exception>
using namespace family;
using namespace std;

struct Trunk
{
    Trunk *prev;
    string str;

    Trunk(Trunk *prev, string str)
    {
        this->prev = prev;
        this->str = str;
    }
};

// Helper function to print branches of the binary tree
void showTrunks(Trunk *p)
{
    if (p == nullptr)
        return;

    showTrunks(p->prev);

    cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void printTree(Person *root, Trunk *prev, bool isLeft)
{
    if (root == nullptr)
        return;

    string prev_str = "    ";
    Trunk *trunk = new Trunk(prev, prev_str);

    printTree(root->father, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isLeft)
    {
        trunk->str = ".---";
        prev_str = "   |";
    }
    else
    {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->name << endl;

    if (prev)
        prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->mother, trunk, false);

    delete trunk;
}

Person::Person(string name, Gender gender)
{
    this->name = name;
    this->father = nullptr;
    this->mother = nullptr;
    this->gender = gender;
}

Tree::Tree(string name)
{

    this->root = new Person(name);
}

struct FindPersonException : std::exception
{
    const char *what() const noexcept { return "Can not find the person!\n"; }
};
struct RemoveRootException : std::exception
{
    const char *what() const noexcept { return "you can't remove the root!\n"; }
};

struct AddParentException : public exception
{
private:
    // string target_word;
    string *result_str;

public:
    AddParentException() : result_str(new string("Can not add parent"))
    {
    }
    const char *what() const throw()
    {
        return this->result_str->c_str();
    }

    ~AddParentException()
    {
        delete this->result_str;
    }
};

Person *Tree::search_person_by_name(string name)
{
    return search_person_by_name(this->root, name);
}

Person *Tree::search_person_by_name(Person *root, string name)
{

    if (root == NULL)
        return nullptr;

    // cout << "Searching for " << name << " from: " << root->name << endl;

    if (root->name.compare(name) == 0)
        return root;

    auto res1 = search_person_by_name(root->father, name);

    if (res1 != nullptr)
        return res1;

    auto res2 = search_person_by_name(root->mother, name);

    return res2;
}

Tree Tree::addFather(string son_name, string father_name)
{
    auto son = search_person_by_name(this->root, son_name);
    if (son == NULL)
    {
        throw("can't add to NULL");
    }
    
    if (son->father != NULL)
    {
        throw AddParentException();
    }

    son->father = new Person(father_name, Gender::male);
    // cout << son->father->name << "\n";

    return *this;
}

Tree Tree::addMother(string son_name, string mother_name)
{
    auto son = search_person_by_name(this->root, son_name);

    if (son == NULL)
    {
        throw("can't add to NULL");
    }
    
    if (son->mother != NULL)
    {
        throw AddParentException();
    }

    son->mother = new Person(mother_name, Gender::female);
    // cout << son->mother->name << "\n";

    return *this;
}

int get_person_distance(Person *root, string target_person_name)
{
    if (root == NULL)
    {
        return -1;
    }

    if (root->name.compare(target_person_name) == 0)
    {
        return 0;
    }
    auto dist_mother = get_person_distance(root->mother, target_person_name);

    if (dist_mother != -1)
    {
        return 1 + dist_mother;
    }

    auto dist_father = get_person_distance(root->father, target_person_name);

    if (dist_father != -1)
    {
        return 1 + dist_father;
    }

    return -1;
}

int get_person_distance_and_set_gender(Person *root, string target_person_name, Gender *result_gender)
{
    if (root == NULL)
    {
        return -1;
    }

    if (root->name.compare(target_person_name) == 0)
    {
        *result_gender = root->gender;
        return 0;
    }
    auto dist_mother = get_person_distance_and_set_gender(root->mother, target_person_name, result_gender);

    if (dist_mother != -1)
    {
        return 1 + dist_mother;
    }

    auto dist_father = get_person_distance_and_set_gender(root->father, target_person_name, result_gender);

    if (dist_father != -1)
    {
        return 1 + dist_father;
    }

    return -1;
}

Person *get_person_by_gender_and_distance(Person *root, int dist, Gender gender)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (dist == 0 && root->gender == gender)
    {
        return root;
    }

    auto result = get_person_by_gender_and_distance(root->mother, dist - 1, gender);

    if (result == NULL)
    {
        result = get_person_by_gender_and_distance(root->father, dist - 1, gender);
    }

    return result;
}

string Tree::relation(string name)
{

    Gender result_gender = Gender::unknown;
    auto dist = get_person_distance_and_set_gender(this->root, name, &result_gender);
    if (dist == -1)
    {
        return "unrelated";
    }
    if (dist == 0)
    {

        return "me";
    }
    string result = result_gender == Gender::male ? "father" : "mother";

    if (dist > 1)
    {
        result = "grand" + result;
    }

    for (size_t i = 1; i < dist - 1; i++)
    {
        result = "great-" + result;
    }
    return result;
}

int count_word_occurences(string str, string word)
{
    int occurrences = 0;
    string::size_type pos = 0;
    while ((pos = str.find(word, pos)) != string::npos)
    {
        ++occurrences;
        pos += word.length();
    }

    return occurrences;
}

bool check_relation_valid(string relation)
{

    // father or mother is needed or it is Me!

    if (count_word_occurences(relation, "father") == 1 && count_word_occurences(relation, "mother") == 0 && count_word_occurences(relation, "me") == 0)
    {
        if (count_word_occurences(relation, "grandfather") == 1)
        {
            if (count_word_occurences(relation, "great") > 0)
            {
                if (count_word_occurences(relation, "-") == 0)
                {
                    return false;
                }

                if (count_word_occurences(relation, "great-") == count_word_occurences(relation, "-"))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
        else if (count_word_occurences(relation, "grandfather") > 1)
        {
            return false;
        }
        return true;
    }
    else
    {
        if (count_word_occurences(relation, "mother") == 1 && count_word_occurences(relation, "father") == 0 && count_word_occurences(relation, "me") == 0)
        {
            if (count_word_occurences(relation, "grandmother") == 1)
            {
                if (count_word_occurences(relation, "great") > 0)
                {

                    if (count_word_occurences(relation, "-") == 0)
                    {
                        return false;
                    }
                    if (count_word_occurences(relation, "great-") == count_word_occurences(relation, "-"))
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            else if (count_word_occurences(relation, "grandmother") > 1)
            {
                return false;
            }
            return true;
        }

        else
        {
            if (count_word_occurences(relation, "me") == 1)
            {
                return true;
            }
        }
    }
    return false;
}

string Tree::find(string relation)
{
    bool relation_is_valid = check_relation_valid(relation);
    if (relation_is_valid == false)
    {
        throw("invalid relation!");
    }

    string name_result = "";

    Gender target_gender = Gender::unknown;
    int target_dist = 1;

    if (count_word_occurences(relation, "father") == 1)
    {
        target_gender = Gender::male;
    }
    if (count_word_occurences(relation, "mother") == 1)
    {
        target_gender = Gender::female;
    }

    if (target_gender == Gender::unknown)
    {
        // cout << "Found person: " << this->root->name << " dist: " << target_dist << " gender: " << target_gender << endl;

        return this->root->name;
    }

    if (count_word_occurences(relation, "grand") == 1)
    {
        target_dist++;
    }

    target_dist += count_word_occurences(relation, "great");

    auto person = get_person_by_gender_and_distance(this->root, target_dist, target_gender);

    // cout << "Found person: " << person->name << " dist: " << target_dist << " gender: " << target_gender << endl;
    if (person != NULL)
    {
        return person->name;
    }
    throw("Not find person!");
}

void free_person_family_tree(Person *person)
{

    if (person == NULL)
        return;
    if (person->father == NULL && person->mother == NULL)
    {
        delete (person);
    }

    free_person_family_tree(person->father);
    free_person_family_tree(person->mother);
    delete person;
}

Person *remove_person_from_tree(Person *root, string person_name)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->name.compare(person_name) == 0)
    {
        free_person_family_tree(root);
        return NULL;
    }

    root->mother = remove_person_from_tree(root->mother, person_name);
    root->father = remove_person_from_tree(root->father, person_name); //

    return root;
}

void Tree::remove(string name)
{
    auto dist = get_person_distance(this->root, name);

    if (dist == 0)
    {
        throw RemoveRootException();
    }

    if (dist == -1)
    {
        throw FindPersonException();
    }

    this->root = remove_person_from_tree(this->root, name); //
}

void Tree::display()
{

    printTree(this->root, nullptr, false);
}



Tree::~Tree() {
    free_person_family_tree(this->root);
}
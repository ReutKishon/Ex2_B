#include "doctest.h"

#include <string>
#include "FamilyTree.hpp"

using namespace std;
using namespace family;

// TEST_CASE("check add father:")
// {
//     Tree tree("Yossi");

//     tree.addFather("Yossi", "Ben").addFather("Ben", "Shalom").addFather("Shalom", "Yaacov").addFather("Yaacov", "Jack").addFather("Jack", "Joe").addFather("Joe", "Nick").addFather("Nick", "Bill").addFather("Bill", "David").addFather("David", "Malo");
//     CHECK((tree.root->father->name).compare("Ben") == 0);
//     CHECK((tree.root->father->father->name).compare("Shalom") == 0);
//     CHECK((tree.root->father->father->father->name).compare("Yaacov") == 0);
//     CHECK((tree.root->father->father->father->father->name).compare("Jack") == 0);
//     CHECK((tree.root->father->father->father->father->father->name).compare("Joe") == 0);
//     CHECK((tree.root->father->father->father->father->father->father->name).compare("Nick") == 0);
//     CHECK((tree.root->father->father->father->father->father->father->father->name).compare("Bill") == 0);
//     CHECK((tree.root->father->father->father->father->father->father->father->father->name).compare("David") == 0);
//     CHECK((tree.root->father->father->father->father->father->father->father->father->father->name).compare("Malo") == 0);
// }

// TEST_CASE("check add mother:")
// {
//     Tree tree("Reut");

//     tree.addMother("Reut", "Shira").addMother("Shira", "Shoshi").addMother("Shoshi", "Yaara").addMother("Yaara", "Janny").addMother("Janny", "Joli").addMother("Joli", "Nina").addMother("Nina", "Tali").addMother("Tali", "Dana").addMother("Dana", "Miley");
//     CHECK((tree.root->mother->name).compare("Shira") == 0);
//     CHECK((tree.root->mother->mother->name).compare("Shoshi") == 0);
//     CHECK((tree.root->mother->mother->mother->name).compare("Yaara") == 0);
//     CHECK((tree.root->mother->mother->mother->mother->name).compare("Janny") == 0);
//     CHECK((tree.root->mother->mother->mother->mother->mother->name).compare("Joli") == 0);
//     CHECK((tree.root->mother->mother->mother->mother->mother->mother->name).compare("Nina") == 0);
//     CHECK((tree.root->mother->mother->mother->mother->mother->mother->mother->name).compare("Tali") == 0);
//     CHECK((tree.root->mother->mother->mother->mother->mother->mother->mother->mother->name).compare("Dana") == 0);
//     CHECK((tree.root->mother->mother->mother->mother->mother->mother->mother->mother->mother->name).compare("Miley") == 0);
// }

// TEST_CASE("check the method 'relation': find a relation by name")
// {
//     Tree T("Yossi");
//     T.addFather("Yossi", "Ben").addFather("Ben", "Shalom").addMother("Ben", "Rivka").addFather("Shalom", "Yaacov").addMother("Shalom", "Lea").addMother("Yossi", "Shira").addMother("Shira", "Ruti").addFather("Shira", "Jack").addMother("Ruti", "Nina").addFather("Ruti", "Joe");
//     CHECK(T.relation("Ben").compare("father") == 0);
//     CHECK(T.relation("Shira").compare("mother") == 0);
//     CHECK(T.relation("Shalom").compare("grandfather") == 0);
//     CHECK(T.relation("Rivka").compare("grandmother") == 0);
//     CHECK(T.relation("Lea").compare("great-grandmother") == 0);
//     CHECK(T.relation("Yaacov").compare("great-grandfather") == 0);
//     CHECK(T.relation("Ruti").compare("grandmother") == 0);
//     CHECK(T.relation("Jack").compare("grandfather") == 0);
//     CHECK(T.relation("Nina").compare("great-grandmother") == 0);
//     CHECK(T.relation("Joe").compare("great-grandfather") == 0);
// }

// TEST_CASE("check the method 'find': find a person by relation")
// {
//     Tree T("Yossi");
//     T.addFather("Yossi", "Ben").addFather("Ben", "Shalom").addMother("Ben", "Rivka").addFather("Shalom", "Yaacov").addMother("Shalom", "Lea").addMother("Yossi", "Shira").addMother("Shira", "Ruti").addFather("Shira", "Jack").addMother("Ruti", "Nina").addFather("Ruti", "Joe").addFather("Yaacov", "Beny").addFather("Beny", "Tom").addFather("Joe", "Germy").addFather("Germy", "Danny").addMother("Lea", "Pninit").addMother("Pninit", "Nofar").addMother("Nina", "Liron").addMother("Liron", "Noa");

//     CHECK(T.find("mother") == "Shira");
//     CHECK(T.find("father") == "Ben");
//     CHECK((T.find("grandfather") == "Shalom" || T.find("grandfather") == "Jack"));
//     CHECK((T.find("grandmother") == "Rivka" || T.find("grandmother") == "Ruti"));
//     CHECK((T.find("great-grandmother") == "Lea" || T.find("great-grandmother") == "Nina"));
//     CHECK((T.find("great-grandfather") == "Yaacov" || T.find("great-grandfather") == "Joe"));
//     CHECK((T.find("great-great-grandfather") == "Beny" || T.find("great-great-grandfather") == "Germy"));
//     CHECK((T.find("great-great-great-grandfather") == "Tom" || T.find("great-great-great-grandfather") == "Danny"));
//     CHECK((T.find("great-great-grandmother") == "Pninit" || T.find("great-great-grandmother") == "Liron"));
//     CHECK((T.find("great-great-great-grandmother") == "Nofar" || T.find("great-great-great-grandmother") == "Noa"));
// }

// TEST_CASE("check remove:")
// {
//     Tree T("Yossi");
//     T.addFather("Yossi", "Ben").addFather("Ben", "Shalom").addMother("Ben", "Rivka").addFather("Shalom", "Yaacov").addMother("Shalom", "Lea").addMother("Yossi", "Shira").addMother("Shira", "Ruti").addFather("Shira", "Jack").addMother("Ruti", "Nina").addFather("Ruti", "Joe").addFather("Yaacov", "Beny").addFather("Beny", "Tom").addFather("Joe", "Germy").addFather("Germy", "Danny").addMother("Lea", "Pninit").addMother("Pninit", "Nofar").addMother("Nina", "Liron").addMother("Liron", "Noa");

//     T.remove("Shalom");
//     CHECK(T.relation("Shalom") == "unrelated");
//     CHECK(T.relation("Yaccov") == "unrelated");
//     CHECK(T.relation("Beny") == "unrelated");
//     CHECK(T.relation("Tom") == "unrelated");
//     CHECK(T.relation("Lea") == "unrelated");
//     CHECK(T.relation("Pninit") == "unrelated");
//     CHECK(T.relation("Nofar") == "unrelated");
//     T.remove("Shira");
//     CHECK(T.relation("Shira") == "unrelated");
//     CHECK(T.relation("Ruti") == "unrelated");
//     CHECK(T.relation("Jack") == "unrelated");
//     CHECK(T.relation("Joe") == "unrelated");
//     CHECK(T.relation("Nina") == "unrelated");
//     CHECK(T.relation("Gremy") == "unrelated");
//     CHECK(T.relation("Liron") == "unrelated");
//     CHECK(T.relation("Dany") == "unrelated");
//     CHECK(T.relation("Noa") == "unrelated");
// }

// TEST_CASE("Test tree 1 : check all the functions:")
// {
//     Tree tree("reut");
//     tree.addFather("reut", "shraga");
//     tree.addMother("reut", "haidi");
//     tree.addFather("shraga", "shmuel");
//     tree.addMother("shraga", "pnina");
//     tree.addFather("shmuel", "haim");
//     tree.addMother("shmuel", "ester");
//     tree.addMother("pnina", "rachel");

//     tree.display();

//     CHECK(tree.relation("shraga").compare("father") == 0);
//     CHECK(tree.relation("haidi").compare("mother") == 0);
//     CHECK(tree.relation("shmuel").compare("grandfather") == 0);
//     CHECK(tree.relation("pnina").compare("grandmother") == 0);
//     CHECK(tree.relation("ester").compare("great-grandmother") == 0);
//     CHECK(tree.relation("rachel").compare("great-grandmother") == 0);
//     CHECK(tree.relation("haim").compare("great-grandfather") == 0);
//     CHECK(tree.relation("reut").compare("Me") == 0);
//     CHECK(tree.find("father") == "shraga");
//     CHECK(tree.find("mother") == "haidi");
//     CHECK(tree.find("grandfather") == "shmuel");
//     CHECK(tree.find("great-grandfather") == "haim");
//     CHECK(tree.find("grandmother") == "pnina");
//     CHECK((tree.find("great-grandmother") == "rachel" || tree.find("great-grandmother") == "ester"));
//     CHECK(tree.find("Me") == "reut");
//     tree.remove("shraga");
//     CHECK(tree.relation("shraga") == "unrelated");
//     CHECK(tree.relation("shmuel") == "unrelated");
//     CHECK(tree.relation("pnina") == "unrelated");
//     CHECK(tree.relation("haim") == "unrelated");
//     CHECK(tree.relation("ester") == "unrelated");
//     CHECK(tree.relation("rachel") == "unrelated");
//     tree.addFather("reut", "shalom");
//     CHECK(tree.find("father") == "shalom");
// }

// TEST_CASE("Test tree 2 : check all the functions:")
// {
//     Tree tree("reut");
//     tree.addFather("reut", "shraga");
//     tree.addMother("reut", "haidi");
//     tree.addFather("haidi", "yehuda");
//     tree.addMother("haidi", "tzipi");
//     tree.addFather("yehuda", "shimshon");
//     tree.addMother("yehuda", "malca");
//     tree.addMother("tzipi", "eva");

//     tree.display();

//     CHECK(tree.relation("shraga").compare("father") == 0);
//     CHECK(tree.relation("haidi").compare("mother") == 0);
//     CHECK(tree.relation("yehuda").compare("grandfather") == 0);
//     CHECK(tree.relation("tzipi").compare("grandmother") == 0);
//     CHECK(tree.relation("malca").compare("great-grandmother") == 0);
//     CHECK(tree.relation("eva").compare("great-grandmother") == 0);
//     CHECK(tree.relation("shimshon").compare("great-grandfather") == 0);
//     CHECK(tree.relation("reut").compare("Me") == 0);
//     CHECK(tree.find("father") == "shraga");
//     CHECK(tree.find("mother") == "haidi");
//     CHECK(tree.find("grandfather") == "yehuda");
//     CHECK(tree.find("great-grandfather") == "shimshon");
//     CHECK(tree.find("grandmother") == "tzipi");
//     CHECK((tree.find("great-grandmother") == "eva" || tree.find("great-grandmother") == "malca"));
//     CHECK(tree.find("Me") == "reut");
//     tree.remove("haidi");
//     CHECK(tree.relation("haidi") == "unrelated");
//     CHECK(tree.relation("yehuda") == "unrelated");
//     CHECK(tree.relation("tzipi") == "unrelated");
//     CHECK(tree.relation("shimshon") == "unrelated");
//     CHECK(tree.relation("malca") == "unrelated");
//     CHECK(tree.relation("eva") == "unrelated");
//     tree.addMother("reut", "sara");
//     CHECK(tree.find("mother") == "sara");
// }

// TEST_CASE("Test tree 3 : check all the functions:")
// {
//     Tree tree("amit");
//     tree.addFather("amit", "gabi");
//     tree.addMother("amit", "tzvia");
//     // tree.addFather("amit", "gabiiii");

//     tree.addFather("tzvia", "shmuel");
//     tree.addMother("tzvia", "pnina");
//     tree.addFather("shmuel", "haim");
//     tree.addMother("shmuel", "ester");
//     tree.addMother("gabi", "mirela");
//     tree.addMother("pnina", "rachel");
//     tree.addFather("pnina", "gabi");
//     tree.display();

//     CHECK_THROWS(tree.addFather("amit", "Yaakov"));
//     CHECK_THROWS(tree.addMother("amit", "Rivka"));

//     CHECK_THROWS(tree.remove("amit"));
//     // tree.remove("amit");

//     CHECK((tree.relation("gabi").compare("father") == 0 || tree.relation("gabi").compare("great-grandfather") == 0));
//     CHECK(tree.relation("tzvia").compare("mother") == 0);
//     CHECK(tree.relation("shmuel").compare("grandfather") == 0);
//     CHECK(tree.relation("pnina").compare("grandmother") == 0);
//     CHECK(tree.relation("ester").compare("great-grandmother") == 0);
//     CHECK(tree.relation("mirela").compare("grandmother") == 0);
//     CHECK(tree.relation("rachel").compare("great-grandmother") == 0);
//     CHECK(tree.relation("haim").compare("great-grandfather") == 0);

//     CHECK(tree.relation("amit").compare("Me") == 0);

//     CHECK(tree.find("father") == "gabi");
//     CHECK(tree.find("mother") == "tzvia");
//     CHECK(tree.find("grandfather") == "shmuel");
//     CHECK((tree.find("great-grandfather") == "haim" || tree.find("great-grandfather") == "gabi"));
//     CHECK(tree.find("grandmother") == "pnina");
//     CHECK((tree.find("great-grandmother") == "rachel" || tree.find("great-grandmother") == "ester"));
//     CHECK(tree.find("Me") == "amit");
//     tree.remove("tzvia");
//     CHECK(tree.relation("tzvia") == "unrelated");
//     CHECK(tree.relation("shmuel") == "unrelated");
//     CHECK(tree.relation("pnina") == "unrelated");
//     CHECK(tree.relation("eliezer") == "unrelated");
//     CHECK(tree.relation("ester") == "unrelated");
//     CHECK(tree.relation("rachel") == "unrelated");

//     tree.display();
//     tree.remove("gabi");
//     CHECK(tree.relation("gabi") == "unrelated");
//     CHECK(tree.relation("mirela") == "unrelated");
//     tree.display();

//     tree.addMother("amit", "sara");
//     CHECK(tree.find("mother") == "sara");
//     tree.display();
//     // tree.addMother("amit", "Nina");
//     // CHECK(tree.find("mother") == "Nina");
//     // tree.display();
// }

// TEST_CASE("check some unusual cases:")
// {

//     Tree tree("amit");
//     tree.addFather("amit", "gabi");
//     tree.addMother("amit", "tzvia");

//     tree.addFather("tzvia", "shmuel");
//     tree.addMother("tzvia", "pnina");
//     tree.addFather("shmuel", "haim");
//     tree.addMother("shmuel", "ester");
//     tree.addMother("gabi", "mirela");
//     tree.addMother("pnina", "rachel");
//     tree.addFather("pnina", "gabi");
//     tree.display();
//     CHECK(tree.relation(" ") == string("unrelated"));

//     // CHECK(tree.find("greatf-grandfather") == "haim");
// }

// TEST_CASE("Yosef Tree case")
// {
//     // Add test case
//     family::Tree T("Yosef");
//     T.addFather("Yosef", "Yaakov");
//     T.addMother("Yosef", "Rachel");
//     T.addFather("Yaakov", "Isaac");
//     T.addMother("Yaakov", "Rivka");
//     T.addFather("Rachel", "Avi");
//     T.addMother("Rachel", "Ruti");
//     T.addFather("Isaac", "Avraham");
//     T.addMother("Isaac", "Ruti");
//     T.addFather("Avraham", "Yosi");
//     T.addMother("Avraham", "Shelly");
//     T.addFather("Avi", "Israel");
//     T.addMother("Avi", "Sara");

//     T.display();

    // Relation test case
    // CHECK(T.relation("Yaakov") == string("father"));
    // CHECK(T.relation("Rachel") == string("mother"));
    // CHECK(T.relation("Isaac") == string("grandfather"));
    // CHECK(T.relation("Rivka") == string("grandmother"));
    // CHECK(T.relation("Avi") == string("grandfather"));
    // CHECK((T.relation("Ruti") == string("grandmother") || T.relation("Ruti") == string("great-grandmother")));
    // CHECK(T.relation("Avraham") == string("great-grandfather"));
    // CHECK((T.relation("Ruti") == string("grandmother") || T.relation("Ruti") == string("great-grandmother")));
    // CHECK(T.relation("Israel") == string("great-grandfather"));
    // CHECK(T.relation("Sara") == string("great-grandmother"));
    // CHECK(T.relation("Yosi") == string("great-great-grandfather"));
    // CHECK(T.relation("Shelly") == string("great-great-grandmother"));

    // CHECK(T.relation("xyz") == string("unrelated"));
    // CHECK(T.relation("Omer") == string("unrelated"));
    // CHECK(T.relation("Ariel") == string("unrelated"));
    // CHECK(T.relation(" ") == string("unrelated"));
    // CHECK(T.relation("  Ariel") == string("unrelated"));

    // // // Find test case
    // CHECK(T.find("father") == string("Yaakov"));
    // CHECK(T.find("mother") == string("Rachel"));
    // CHECK((T.find("grandfather") == string("Isaac") || T.find("grandfather") == string("Avi")));
    // CHECK((T.find("grandmother") == string("Rivka") || T.find("grandmother") == string("Ruti")));
    // CHECK((T.find("great-grandmother") == string("Sara") || T.find("great-grandmother") == string("Ruti")));
    // CHECK((T.find("great-grandfather") == string("Avraham") || T.find("great-grandfather") == string("Israel")));
    // CHECK(T.find("great-great-grandfather") == string("Yosi"));
    // CHECK(T.find("great-great-grandmother") == string("Shelly"));

    // CHECK_THROWS(T.find("grandfatrher"));
    // CHECK_THROWS(T.find("great"));
    // CHECK_THROWS(T.find(" "));
    // CHECK_THROWS(T.find("   great"));
    // CHECK_THROWS(T.find("grandfatrher   "));
    // CHECK_THROWS(T.find("great,great,grandmother"));
    // CHECK_THROWS(T.find("great?grandmother"));
    // CHECK_THROWS(T.find("great grandmother"));

//     // Remove test case
//     CHECK_THROWS(T.remove("Yosef")); // removing the root is an error
//     CHECK_THROWS(T.remove(" "));     // removing a non-existent person
//     CHECK_THROWS(T.remove("xyz"));
//     CHECK_THROWS(T.remove("Ariel"));
//     CHECK_THROWS(T.remove("  Rivka"));

//     T.remove("Yosi");
//     CHECK_THROWS(T.find("great-great-grandfather")); // A removed relation does not exist
//     T.addFather("Avraham", "Ido");                   // Add a new father after removal
//     T.remove("Avi");
//     CHECK_THROWS(T.addFather("Avi", "Israel")); // add to a removed person
//     T.addFather("Rachel", "Shmual");
//     T.remove("Isaac");
//     T.remove("Rivka");
//     T.remove("Ruti");
//     CHECK_THROWS(T.find("grandmother"));
//     CHECK_THROWS(T.addFather("Isaac", "Avraham"));
//     CHECK_THROWS(T.addMother("Isaac", "Ruti"));
//     CHECK_THROWS(T.addFather("Rivka", "Israel"));
//     CHECK_THROWS(T.addMother("Rivka", "Sara"));
//     T.remove("Yaakov"); // remove father
//     T.remove("Rachel"); // remove mother
//     CHECK_THROWS(T.find("father"));
//     CHECK_THROWS(T.find("mother"));
//     CHECK_THROWS(T.addFather("Yaakov", "Avraham")); // add to non-existent person
//     CHECK_THROWS(T.addMother("Yaakov", "Ruti"));    // add to non-existent person
//     CHECK_THROWS(T.addFather("Rachel", "Avraham")); // add to non-existent person
//     CHECK_THROWS(T.addMother("Rachel", "Ruti"));    // add to non-existent person
// }

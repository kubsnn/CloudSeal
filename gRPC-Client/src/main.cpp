#include <nlohmann/json.hpp>
#include <string>
#include <utils/utils.hpp>
#include <iostream>
using json = nlohmann::json;

class Base {
private:
    int id;

public:
    Base(int id = 0) : id(id) {}
    int get_id() const { return id; }
    void set_id(int v) { id = v; }

    // prywatne pole = trzeba użyć intrusive
    MY_JSON_INTRUSIVE_WITH_BASE(void, Base, id)
};

class Person : public Base {
private:
    std::string name;
    int age;

public:
    Person(std::string n = "", int a = 0, int id = 0)
        : Base(id), name(std::move(n)), age(a) {}

    MY_JSON_INTRUSIVE_WITH_BASE(Base, Person, name, age)
}; 
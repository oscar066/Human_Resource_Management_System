
#include <iostream>
#include <string>
using namespace std;

class Father{
    private:
        string first_name;
        string last_name;
        string middle_name;
        Father *next_father;
    public:
        Father(string first_name, string last_name, string middle_name, Father *next_father);
        void set_first_name(string first_name);
        string get_first_name();
        void set_last_name(string last_name);
        string get_last_name();
        void set_middle_name(string middle_name);
        string get_middle_name();
        void set_next_father(Father *next_father);
        Father* get_next_father();
};

Father::Father(string first_name, string last_name, string middle_name, Father *next_father) {
    this->first_name = first_name;
    this->last_name = last_name;
    this->middle_name = middle_name;
    this->next_father = next_father;
}

void Father::set_first_name(string first_name) {
    this->first_name = first_name;
}

string Father::get_first_name() {
    return first_name;
}

void Father::set_last_name(string last_name) {
    this->last_name = last_name;
}

string Father::get_last_name() {
    return last_name;
}

void Father::set_middle_name(string middle_name) {
    this->middle_name = middle_name;
}

string Father::get_middle_name() {
    return middle_name;
}

void Father::set_next_father(Father *next_father) {
    this->next_father = next_father;
}

Father* Father::get_next_father() {
    return next_father;
}

class Son : public Father {
    private:
        string first_name;
        string last_name;
        string middle_name;
        Son *next_son;
    public:
        Son(string first_name, string last_name, string middle_name, Son *next_son);
        void set_first_name(string first_name);
        string get_first_name();
        void set_last_name(string last_name);
        string get_last_name();
        void set_middle_name(string middle_name);
        string get_middle_name();
        void set_next_son(Son *next_son);
        Son* get_next_son();
};

Son::Son(string first_name, string last_name, string middle_name, Son *next_son) : Father(first_name, last_name, middle_name, next_son) {
    this->first_name = first_name;
    this->last_name = last_name;
    this->middle_name = middle_name;
    this->next_son = next_son;
}

void Son::set_first_name(string first_name) {
    this->first_name = first_name;
}

string Son::get_first_name() {
    return first_name;
}

void Son::set_last_name(string last_name) {
    this->last_name = last_name;
}

string Son::get_last_name() {
    return last_name;
}

void Son::set_middle_name(string middle_name) {
    this->middle_name = middle_name;
}

string Son::get_middle_name() {
    return middle_name;
}

void Son::set_next_son(Son *next_son) {
    this->next_son = next_son;
}

Son* Son::get_next_son() {
    return next_son;
}

int main(){
    Father * fatherlist = new Father("John", "Doe", "Jr.", NULL);
    fatherlist->set_next_father(new Father("John", "Doe", "Sr.", NULL));

    Son * sonlist = new Son("John", "Doe", "III", NULL);
    sonlist->set_next_son(new Son("John", "Doe", "II", NULL));
    sonlist->get_next_son()->set_next_son(new Son("John", "Doe", "I", NULL));
}
#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal{
private:
    std::string name;
    int age;
    std::string sound;
public:
    //konstruktor domyślny
    Animal();
    //konstruktor z listą inicjalizacyjną dla name, age i sound
    Animal(const std::string& _name, int _age, const std::string& _sound);

    void print() const;
    int getAge() const;
    const std::string& getName() const;

};

void addAnimal(Animal*& animals, int& size, const Animal& newAnimal);
void removeAnimal(Animal*& animals, int& size, const std::string& name);
bool compare(Animal& a, Animal& b);
void sortAnimals(Animal* animals, int size);

#endif
#include "Animal.h"

#include <iostream>
#include <string>
#include <algorithm>

Animal::Animal() : name("Unknown"), age(0), sound("Unknown") {}

Animal::Animal(const std::string& _name, int _age, const std::string& _sound)
            : name(_name), age(_age), sound(_sound){}


void Animal::print() const{
    std::cout << "Imię: " << name << ", Wiek: " << age <<", Dźwięk: " << sound << std::endl;
}

int Animal::getAge() const{
    return age;
}
const std::string& Animal::getName() const{
    return name;
}

void addAnimal(Animal*& animals, int& size, const Animal& newAnimal){
    Animal* farm = new Animal[size + 1];

    for(int i = 0; i < size; i++){
        farm[i] = animals[i];
    }

    farm[size] = newAnimal;

    delete [] animals;

    animals = farm;
    ++size;

}

void removeAnimal(Animal*& animals, int& size, const std::string& name){
    Animal* newFarm = new Animal[size - 1];
    int i = 0, j = 0;
    while(i != size){
        if(animals[i].getName() != name){
            newFarm[j] = animals[i];
            j++;
        }
        i++;
    }

    delete [] animals;
    animals = newFarm;
    --size;
}

bool compare(Animal& a, Animal& b) {return a.getAge() < b.getAge();}

void sortAnimals(Animal* animals, int size){
    std::sort(animals, animals + size, compare);
}
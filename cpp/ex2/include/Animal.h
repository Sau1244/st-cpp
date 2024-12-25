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

    //metoda wyświetlająca dane zwierząt
    void print() const;
    //funkcja zwracająca wiek
    int getAge() const;
    //funkcja zwracająca nazwe zwierzęcia
    const std::string& getName() const;

};

//metoda dodająca zwierzę do farmy
void addAnimal(Animal*& animals, int& size, const Animal& newAnimal);
//metoda usuwająca zwierzę z farmy
void removeAnimal(Animal*& animals, int& size, const std::string& name);
//komparator względem wieku
bool compare(Animal& a, Animal& b);
//metoda sortująca względem wieku
void sortAnimals(Animal* animals, int size);

#endif
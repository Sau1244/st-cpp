// Twoim zadaniem jest napisanie programu modelującego zwierzęta na farmie.
// Program ma wykorzystywać dynamiczną tablicę obiektów oraz wprowadzać
// zaawansowaną obsługę pamięci dynamicznej w C++.
//
// Celem zadania jest:
// - Przećwiczenie dynamicznej alokacji pamięci i operacji na dynamicznych tablicach,
// - Organizacja kodu w plikach `.h` i `.cpp`,
// - Użycie funkcji sortowania i operacji na tablicach,
// - Wprowadzenie poprawnego użycia `const` i referencji.
//
// Wymagania:
// 1. Klasa `Animal` powinna:
//    - Zawierać pola: `std::string name`, `int age`, `std::string sound`,
//    - Posiadać konstruktor z parametrami domyślnymi oraz destruktor,
//    - Udostępniać metody:
//      - `void print() const` – wypisująca dane o zwierzęciu,
//      - `int getAge() const` – zwracająca wiek zwierzęcia,
//      - `const std::string& getName() const` – zwracająca nazwę zwierzęcia.
// 2. Dynamiczna tablica obiektów:
//    - Program powinien przechowywać dane o zwierzętach w dynamicznej tablicy,
//    - Powinna istnieć możliwość:
//      - Dodania nowego zwierzęcia do tablicy,
//      - Usunięcia zwierzęcia po imieniu (realokacja pamięci),
//      - Posortowania tablicy według wieku w porządku rosnącym.
// 3. Modułowość:
//    - Kod klasy `Animal` musi znajdować się w osobnych plikach `.h` i `.cpp`.
// 4. Funkcje pomocnicze:
//    - `void addAnimal(Animal*& animals, int& size, const Animal& newAnimal)`,
//    - `void removeAnimal(Animal*& animals, int& size, const std::string& name)`,
//    - `void sortAnimals(Animal* animals, int size)`.
//
// UWAGA:
// * Plik `main.cpp` pozostaje nienaruszony. Cała implementacja znajduje się w plikach `Animal.h` i `Animal.cpp`.
// * Ostateczny program powinien być czytelny i zgodny z zasadą DRY (Don't Repeat Yourself).
//
// Przykładowe dane wejściowe/wyjściowe są przedstawione poniżej.


#include <iostream>
#include <string>
#include "Animal.h"

int main() {
    int size = 0;
    Animal* farm = nullptr;

    // Dodawanie zwierząt
    addAnimal(farm, size, Animal("Burek", 8, "Hau!"));
    addAnimal(farm, size, Animal("Kicia", 3, "Miau!"));
    addAnimal(farm, size, Animal("Azor", 5, "Hau!"));

    // Wyświetlenie zwierząt
    std::cout << "Lista zwierząt na farmie:\n";
    for (int i = 0; i < size; ++i)
        farm[i].print();

    // Usunięcie zwierzęcia
    std::cout << "\nUsuwanie zwierzęcia: Kicia\n";
    removeAnimal(farm, size, "Kicia");

    // Wyświetlenie po usunięciu
    std::cout << "Lista zwierząt po usunięciu:\n";
    for (int i = 0; i < size; ++i)
        farm[i].print();

    // Sortowanie
    std::cout << "\nSortowanie zwierząt według wieku:\n";
    sortAnimals(farm, size);

    // Wyświetlenie po sortowaniu
    for (int i = 0; i < size; ++i)
        farm[i].print();

    // Zwolnienie pamięci
    delete[] farm;

    return 0;
}


// Spodziewany output:
// Lista zwierząt na farmie:
// Imię: Burek, Wiek: 5, Dźwięk: Hau!
// Imię: Kicia, Wiek: 3, Dźwięk: Miau!
// Imię: Azor, Wiek: 8, Dźwięk: Hau!

// Usuwanie zwierzęcia: Kicia
// Lista zwierząt po usunięciu:
// Imię: Burek, Wiek: 5, Dźwięk: Hau!
// Imię: Azor, Wiek: 8, Dźwięk: Hau!

// Sortowanie zwierząt według wieku:
// Imię: Burek, Wiek: 5, Dźwięk: Hau!
// Imię: Azor, Wiek: 8, Dźwięk: Hau!

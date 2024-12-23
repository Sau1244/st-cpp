// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal się
// a wynik jego dzialania byl taki sam jak podany na końcu tego pliku

// Ostateczny program powinien byc przyjazny dla programisty
// (miec czytelny i dobrze napisany kod, bez powielania kodu - D.R.Y)

// Cel zadania:
//     Utwórz pliki nagłówkowe i źródłowe:
//         functions.h – zawierający deklaracje funkcji addValue(int &number) i counter().
//         functions.cpp – zawierający implementacje:
//             void addValue(int &number); – funkcja przyjmująca liczbę przez referencję i zwiększająca ją o wartość globalValue.
//             int counter(); – funkcja zliczająca liczbę wywołań od uruchomienia programu przy użyciu statycznej zmiennej lokalnej callCount.
//         globals.h – zawierający deklarację extern int globalValue.
//         globals.cpp – zawierający definicję globalValue z wartością początkową 5.

//     Instrukcja CMake i kompilacja:
//     Studenci mogą korzystać z wcześniej przygotowanego pliku CMakeLists.txt, aby skompilować projekt.

//     Uruchomienie i testowanie:
//     Po kompilacji, program powinien wczytać liczbę, zmodyfikować ją przez addValue(), a następnie trzykrotnie wywołać counter() i wyświetlić globalValue.


// Przy wykonaniu zadania nie wolno korzystać z internetu, notatek,
// ani żadnych innych materialow (w tym własnych wczesniej
// przygotowanych plikow oprócz CMakeLists.txt, chyba że polecenie stanowi inaczej)

// Kody źródłowe muszą znajdować się w katalogu do którego nikt oprócz
// właściciela nie ma praw dostępu.
// Rozwiazanie (czyli katalog z plikami i Main.cpp należy wgrać do UPEL jako archiwum tar.gz
// UWAGA:
// * pliku Main.cpp w końcowym rozwiazaniu powinien być nie zmieniony
// * archiwum tar.gz nie powinno zawierać katalogu build/
// * brak wysłanego rozwiązania (bez względu na jego ukończenie),
//   jest tożsame z brakiem obecności na zajęciach.



#include <iostream>
#include "functions.h"
#include "globals.h"

// Program, który demonstruje użycie referencji, zmiennych statycznych oraz zmiennych globalnych
int main() {
    int number;
    std::cout << "Podaj liczbę: ";
    std::cin >> number;

    addValue(number);
    std::cout << "Nowa wartość liczby po modyfikacji: " << number << std::endl;

    for (int i = 0; i < 3; ++i) {
        std::cout << "Counter call " << i + 1 << ": " << counter() << std::endl;
        std::cout << "Wartość globalValue: " << globalValue << std::endl;
    }

    return 0;
}

// Spodziewany output:

// "Podaj liczbę: "
// 5 (może być inna)
// Nowa wartość liczby po modyfikacji: 10
// Counter call 1: 1
// Wartość globalValue: 5
// Counter call 2: 2
// Wartość globalValue: 5
// Counter call 3: 3
// Wartość globalValue: 5

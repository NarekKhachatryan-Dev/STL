#ifndef ZOO_H
#define ZOO_H

#include "animals.h"
#include <set>
#include <initializer_list>
#include <unordered_set>

class zoo {
private:
    Animal** m_animals;
    int m_animalCount;
    int m_currentIndex;

public:
    zoo(int animalCount = 100);
    void addAnimal(Animal* animal);
    void makeAllSounds() const;
    Animal* getAnimal(int index) const;
    int getAnimalCount() const;

    ~zoo();
};

class animalset {
    public:

    std::set<Animal*> setter(const zoo& animals) {
        std::set<Animal*> animal_set;
        for (int i = 0; i < animals.getAnimalCount(); ++i) {
            animal_set.insert(animals.getAnimal(i));
        }
        return animal_set;
    }

    std::unordered_set<Animal*> unordered_setter(const zoo& animals) {
        std::unordered_set<Animal*> animal_unordered_set;
        for (int i = 0; i < animals.getAnimalCount(); ++i) {
            animal_unordered_set.insert(animals.getAnimal(i));
        }
        return animal_unordered_set;
    }
};

#endif
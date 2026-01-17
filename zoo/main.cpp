#include <iostream>
#include "zoo.h"

int main() {
    zoo myZoo;

    myZoo.addAnimal(new Dog("Buddy", "Golden Retriever", "Golden", 60.0, 30.0, 3));
    myZoo.addAnimal(new Cat("Whiskers", "Siamese", "Cream", 25.0, 5.0, 2));
    myZoo.addAnimal(new Bird("Tweety", "Canary", "Yellow", 15.0, 0.2, 1));
    myZoo.addAnimal(new Fish("Nemo", "Clownfish", "Orange", 10.0, 0.5, 1));
    myZoo.addAnimal(new Horse("Star", "Arabian", "Brown", 160.0, 400.0, 5));
    myZoo.addAnimal(new Snake("Slither", "Python", "Green", 200.0, 50.0, 4));

    myZoo.makeAllSounds();
    checkifanimal(myZoo.getAnimal(0));
    std::cout << std::endl;

    animalset set;
    std::set<Animal*> animalsSet = set.setter(myZoo);

    for(const auto& animal : animalsSet) {
        std::cout << animal->getName() << " is in the set." << std::endl;
    }
    std::cout << std::endl;

    auto animalsUnorderedSet = set.unordered_setter(myZoo);
    for(const auto& animal : animalsUnorderedSet) {
        std::cout << animal->getName() << " is in the unordered set." << std::endl;
    }

    return 0;
}
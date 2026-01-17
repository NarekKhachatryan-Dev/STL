#include "zoo.h"

zoo::zoo(int animalCount) : m_animalCount(animalCount), m_currentIndex(0) {
    m_animals = new Animal*[m_animalCount];
}

void zoo::addAnimal(Animal* animal) {
    if(m_currentIndex < m_animalCount) {
        m_animals[m_currentIndex++] = animal;
    }
}

void zoo::makeAllSounds() const {
    for(int i = 0; i < m_currentIndex; ++i) {
        m_animals[i]->makeSound();
    }
}

Animal* zoo::getAnimal(int index) const {
    if(index >= 0 && index < m_currentIndex) {
        return m_animals[index];
    }
    return nullptr;
}

int zoo::getAnimalCount() const {
    return m_currentIndex;
}

zoo::~zoo() {
    for(int i = 0; i < m_currentIndex; ++i) {
        delete m_animals[i];
    }
    delete[] m_animals;
}
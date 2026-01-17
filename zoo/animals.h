#ifndef ANIMALS_H
#define ANIMALS_H

#include <string>
#include <iostream>

class Animal {
protected:
    std::string m_name;
    double m_weight;
public:
    Animal() = default;
    Animal(const std::string& name, double weight);
    virtual ~Animal() = default;
    Animal(Animal&& other) noexcept;

    virtual void makeSound() const = 0;
    std::string getName() const;
    double getWeight() const;
    
    Animal& operator= (Animal&& other) noexcept;
    bool operator< (const Animal& other) const;
    bool operator== (const Animal& other) const;
    bool operator> (const Animal& other) const;
};

void checkifanimal(Animal *obj);

class swimmer {
    public:
    virtual void swim() const = 0;
    virtual ~swimmer() = default;
};

class flyer {
    public:
    virtual void fly() const = 0;
    virtual ~flyer() = default;
};

class walker {
    public:
    virtual void walk() const = 0;
    virtual ~walker() = default;
};

class Dog : public Animal {
private:
    std::string m_breed;
    std::string m_color;
    double m_height;
    int m_age;
    std::string sound;
public:
    Dog(const std::string& name, const std::string& breed, const std::string& color,
        double height, double weight, int age);
    void makeSound() const override;
};

class Cat : public Animal {
private:
    std::string m_breed;
    std::string m_color;
    double m_height;
    int m_age;
    std::string sound;
public:
    Cat(const std::string& name, const std::string& breed, const std::string& color,
        double height, double weight, int age);
    void makeSound() const override;
};

class Bird : public Animal {
private:
    std::string m_breed;
    std::string m_color;
    double m_height;
    int m_age;
    std::string sound;
public:
    Bird(const std::string& name, const std::string& breed, const std::string& color,
        double height, double weight, int age);
    void makeSound() const override;
};

class Fish : public Animal {
private:
    std::string m_breed;
    std::string m_color;
    double m_height;
    int m_age;
    std::string sound;
public:
    Fish(const std::string& name, const std::string& breed, const std::string& color,
        double height, double weight, int age);
    void makeSound() const override;
};

class Horse : public Animal {
private:
    std::string m_breed;
    std::string m_color;
    double m_height;
    int m_age;
    std::string sound;
public:
    Horse(const std::string& name, const std::string& breed, const std::string& color,
        double height, double weight, int age);
    void makeSound() const override;
};

class Snake : public Animal {
private:
    std::string m_breed;
    std::string m_color;
    double m_height;
    int m_age;
    std::string sound;
public:
    Snake(const std::string& name, const std::string& breed, const std::string& color,
        double height, double weight, int age);
    void makeSound() const override;
};

#endif
#include <string>
#include <functional>
#include "vector/vector.hpp"
#include "list/list.hpp"
#include "pair/pair.hpp"

class HashTable {
private:
    static const size_t TABLE_SIZE = 101;
    My::vector<My::list<My::pair<std::string, int>>> table;

    size_t hashFunction(const std::string& key) const {
        size_t hash = 0;
        for (char ch : key) {
            hash = (hash * 31 + ch) % TABLE_SIZE;
        }
        return hash;
    }

public:
    HashTable() : table(TABLE_SIZE) {}

    void insert(const std::string& key, int value) {
        size_t index = hashFunction(key);
        for(auto& pair : table[index]) {
            if (pair.first == key) {
                pair.second = value;
                return;
            }
        }
        table[index].push_back(My::pair<std::string,int>(key, value));
    }

    bool find(const std::string& key, int& value) const {
        size_t index = hashFunction(key);
        for (const auto& pair : table[index]) {
            if (pair.first == key) {
                value = pair.second;
                return true;
            }
        }
        return false;
    }

    void remove(const std::string& key) {
        size_t index = hashFunction(key);
        auto& cell = table[index];
        cell.remove_if([&key](const My::pair<std::string,int>& p) {
            return p.first == key;
        });
    }

    void debugPrint() const {
    for (size_t i = 0; i < TABLE_SIZE; ++i) {
        std::cout << i << ": ";
        for (const auto& p : table[i]) {
            std::cout << "(" << p.first << "," << p.second << ") ";
        }
        std::cout << "\n";
    }
    }

    int& operator[] (const std::string& key) {
        size_t index = hashFunction(key);
        for (auto& pair : table[index]) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        My::pair<std::string,int> newPair(key, int());
        table[index].push_back(newPair);
        for (auto& pair : table[index]) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        return table[index].back().second;
    }
    ~HashTable() = default;
};
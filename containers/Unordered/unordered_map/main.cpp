#include "unordered_map.hpp"

#include <iostream>
#include <string>

int main() {
    My::unordered_map<std::string, int> scores;

    scores["alice"] = 95;
    scores["bob"] = 88;
    scores.insert({"carol", 91});
    scores.emplace("dave", 84);

    std::cout << "size: " << scores.size() << '\n';
    std::cout << "bucket_count: " << scores.bucket_count() << '\n';
    std::cout << "load_factor: " << scores.load_factor() << '\n';

    if (scores.contains("alice")) {
        std::cout << "alice: " << scores.at("alice") << '\n';
    }

    if (auto* value = scores.find("bob"); value != nullptr) {
        std::cout << "bob: " << *value << '\n';
    }

    scores.erase("dave");
    std::cout << "size after erase: " << scores.size() << '\n';

    scores.rehash(32);
    std::cout << "bucket_count after rehash: " << scores.bucket_count() << '\n';

    return 0;
}

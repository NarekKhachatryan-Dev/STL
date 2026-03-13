#include "unordered_set.hpp"

#include <iostream>
#include <string>

int main() {
    My::unordered_set<std::string> tags;

    tags.insert("cpp");
    tags.insert("stl");
    tags.emplace("hash");
    tags.insert("cpp");

    std::cout << "size: " << tags.size() << '\n';
    std::cout << "contains cpp: " << (tags.contains("cpp") ? "yes" : "no") << '\n';
    std::cout << "contains rust: " << (tags.contains("rust") ? "yes" : "no") << '\n';

    tags.erase("stl");
    std::cout << "size after erase: " << tags.size() << '\n';

    tags.rehash(32);
    std::cout << "bucket_count after rehash: " << tags.bucket_count() << '\n';

    return 0;
}

#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    for (auto v: vec) 
        std::cout << v << " ";
}

/*
По аналогии распечатайте числа от 1 до 5, используя auto и initializer_list.
*/
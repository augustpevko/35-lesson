#include <iostream>
#include <vector>
#include <unordered_set>
#include <memory>

int main()
{
    std::vector<int> vec = {1, 1, 1, 2, 2, 3, 4, 4, 4, 5, 5, 6, 7, 7, 7};
    auto f_makeVecUnique = [](std::vector<int>& vec) {
        std::unordered_set<int> unSet(vec.begin(), vec.end());
        return std::make_unique<std::vector<int>>(unSet.begin(), unSet.end());
    };

    auto uniqPtr_vec = f_makeVecUnique(vec);

    for (const auto &v: *uniqPtr_vec) 
        std::cout << v << " ";

}

/*
Так как std::unordered_set позволяет нам быстро определять, 
есть ли указанный ключ в контейнере, мы можем использовать его для фильтрации уникальных чисел.
Создайте лямбда-выражение, принимающее на вход std::vector<int>, 
в котором содержатся числа, которые могут повторяться. 
Внутри лямбды создайте unordered_set и при помощи него определяйте, 
сколько раз текущее число вам встречалось раньше. В результате 
верните std::unique_ptr<std::vector<int>>, содержащий числа без 
повторов. При проходе по контейнеру используйте новый формат цикла for и ключевое слово auto. 
*/
#include <iostream>
#include <vector>
#include <string>
#include <filesystem>



int main() {
    std::cout << "Input path: ";
    std::filesystem::path path;
    std::cin >> path;
    
    std::string extension;
    std::cout << "Input extension of file: ";
    std::cin >> extension;

    auto recursiveGetFileNamesByExtension =
        [](std::filesystem::path inPath, const std::string inExtension) {
            std::vector<std::string> vecFiles;
            for(auto &p: std::filesystem::recursive_directory_iterator(inPath)) {
                if (p.is_regular_file()) {
                    if (!(p.path().extension().compare(inExtension))) {
                        vecFiles.push_back(p.path().filename());
                    }
                }
            }
            return vecFiles;
    };

    auto v_FilesInDir = recursiveGetFileNamesByExtension(path, extension);

    for (const auto &v: v_FilesInDir) 
        std::cout << v << std::endl;
}

/*
Определить, файл это или каталог при помощи метода is_regular_file().
Получить расширение для обычного файла при помощи метода extension().
Создайте лямбда-функцию, которая принимает на вход путь в файловой 
системе и искомое расширение в виде строки, а 
возвращает список имён файлов, которые имеют данное расширение().
*/
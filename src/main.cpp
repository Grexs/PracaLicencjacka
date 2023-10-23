#include <iostream>
#include <Algorithms/KthElement.hpp>

template<typename Container>
void print(const Container& container)
{
    for (const auto& elem : container)
        std::cout << elem << " ";
    std::cout << std::endl;
}

template<typename Container>
void printK(const Container& container, const int x)
{
    auto it = algorithms::kthElement(container.begin(), container.end(), x);
    if (it == container.end())
        std::cout << "Out of range!" << std::endl;
    else
        std::cout << "index = " << std::distance(container.begin(), it) << "; value = " << *it << std::endl;
}

int main()
{
    std::vector<int> v{31,1,40,54,95,87,4,78,82,37,48,51,15,36,47,60,34,22,64,83,69,14,94,18,61,11,98,62,58,2,12,67,76,26,5,73,46,27,50,63,88,38,80,43,53,49,68,30,3,97,52,70,86,100,25,92,19,10,66,20,16,13,23,91,24,41,44,81,85,65,32,45,72,79,33,9,96,84,90,6,56,8,29,89,39,57,77,7,99,75,71,28,42,17,93,21,59,35,74,55};
    print(v);

    printK(v, 12);
    printK(v, 20);
    printK(v, 100);
    printK(v, 30);
    printK(v, 54);
    printK(v, 83);
    printK(v, 0);

    return 0;
}

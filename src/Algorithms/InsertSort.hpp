//
// Created by grchrzan on 09/10/2023.
//

#include <functional>

#pragma once

namespace algorithms
{

template<typename Iterator, typename Comparator = std::less<>>
void insertSort(Iterator first, Iterator last, Comparator comparator = Comparator{})
{
    for (auto layerIt = first; layerIt < last; ++layerIt)
    {
        auto currentIt = layerIt;
        while (currentIt > first && !comparator(*std::prev(currentIt), *currentIt))
        {
            std::iter_swap(std::prev(currentIt), currentIt);
            currentIt = std::prev(currentIt);
        }
    }
}

}  // namespace algorithms

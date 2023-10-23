//
// Created by grchrzan on 09/10/2023.
//

#include <cinttypes>
#include <iterator>

#include <boost/range/adaptors.hpp>
#include <boost/range/iterator_range.hpp>

#include <Common/ViewRange.hpp>

#include <Algorithms/InsertSort.hpp>

#pragma once

namespace algorithms
{
namespace detail
{
constexpr uint32_t MIN_NO_OF_ELEMENTS_FOR_RECURSION = 10u;
constexpr uint32_t NO_OF_ELEMENTS_IN_BUCKET = 5u;

template<typename T, typename Size, typename Comparator>
common::View<T> kthElementSafe(common::ViewRange<T> range, const Size k, const Comparator comparator)
{
    auto compareViews = [comparator](auto viewLhs, auto viewRhs){ return comparator(*viewLhs, *viewRhs); };

    if (range.size() < detail::MIN_NO_OF_ELEMENTS_FOR_RECURSION)
    {
        insertSort(range.begin(), range.end(), compareViews);
        return *(range.begin() + k);
    }

    auto pivotRange = common::ViewRange<T>();
    for (auto bucketIt = range.begin(); bucketIt < range.end(); bucketIt += detail::NO_OF_ELEMENTS_IN_BUCKET)
    {
        auto bucket =
            common::ViewRange<T>(bucketIt, std::min(bucketIt + detail::NO_OF_ELEMENTS_IN_BUCKET, range.end()));
        auto bucketMedian = kthElementSafe(bucket, bucket.size() / 2, comparator);

        pivotRange.push_back(bucketMedian);
    }

    auto pivot = kthElementSafe(pivotRange, pivotRange.size() / 2, comparator);
    auto partitionPointIt =
        std::partition(range.begin(), range.end(), [&](auto elem){ return compareViews(elem, pivot); });
    auto noOfElementsLhs = std::distance(range.begin(), partitionPointIt);

    return k < noOfElementsLhs ?
        kthElementSafe(common::ViewRange<T>(range.begin(), partitionPointIt), k, comparator) :
        kthElementSafe(common::ViewRange<T>(partitionPointIt, range.end()), k - noOfElementsLhs, comparator);
}

}  // namespace detail

template<typename Iterator, typename Size, typename Comparator = std::less<>>
Iterator kthElement(Iterator first, Iterator last, const Size k, const Comparator comparator = Comparator{})
{
    using value_type = typename Iterator::value_type;

    if (first > last)
    {
        return last;
    }

    if (k >= std::distance(first, last))
    {
        return last;
    }

    auto range = boost::copy_range<common::ViewRange<value_type>>(
        boost::make_iterator_range(first, last) |
        boost::adaptors::transformed([](const auto& value){ return common::View<value_type>(value); }));

    auto kthValue = detail::kthElementSafe(std::move(range), k, comparator);
    return std::find(first, last, *kthValue);
}

}  // namespace algorithms

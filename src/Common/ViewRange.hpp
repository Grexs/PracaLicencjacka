//
// Created by grchrzan on 11/10/2023.
//

#pragma once

#include <vector>

#include <Common/View.hpp>

namespace common
{
template<typename T>
using ViewRange = std::vector<View<T>>;

}  // namespace common

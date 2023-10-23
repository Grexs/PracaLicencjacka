//
// Created by grchrzan on 11/10/2023.
//

#pragma once

#include <stdexcept>

namespace common
{

template<typename T>
class View
{
public:
    explicit View(const T& data) : data_(&data)
    {
    }

    const T& operator*() const
    {
        if (!data_)
        {
            throw std::runtime_error("View is not valid anymore!");
        }
        return *data_;
    }

private:
    const T* data_;
};

}  // namespace common

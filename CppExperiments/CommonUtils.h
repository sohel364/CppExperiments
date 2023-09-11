#pragma once
#include <string>
#include <iostream>
#include <map>

namespace
{
    template <typename T> static constexpr T quietNAN{ std::numeric_limits<T>::quiet_NaN() };
    static constexpr double dNaN{ quietNAN<double> };
    static constexpr float fNaN{ quietNAN<float> };
}

/// <summary>Prints the given value.</summary>
/// <typeparam name="T">Generic type parameter.</typeparam>
/// <param name="value">The value. </param>
template<typename T>
void Print(T value)
{
    std::cout << value << std::endl;
}

template<typename K, typename V>
bool ContainsInMap(const std::map<K, V>& map, const K key)
{
    return map.contains(key);
}

/// <summary>A common utilities.</summary>
class CommonUtils
{
    
};


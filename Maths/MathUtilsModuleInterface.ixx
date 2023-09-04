export module MathUtilsModuleInterface;

import <string>;
import <numeric>;
import <vector>;
import <concepts>; // c++ 20 concepts

export std::string MyFunc();

/// <summary>Calcualte avrg.</summary>
/// <typeparam name="T">Generic type parameter.</typeparam>
/// <param name="vec">The vector.</param>
/// <returns>A double.</returns>
export template<typename T>
requires std::integral<T> || std::same_as<T, double>
constexpr double CalcualteAvrg(std::vector<T> const& vec)
{
	const double sum = std::accumulate(vec.begin(), vec.end(), 0.0);
	return sum / vec.size();
	return sum / vec.size();
}

// A function template that accepts two arguments of the same type
export template <std::same_as<int> T>
bool CheckSameAs(T x, T y) {
	return true;
}


std::string MyFunc()
{
	return "My function from the module is called";
}
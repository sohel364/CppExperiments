#pragma once

/// <summary>List of s.</summary>
/// <typeparam name="T">Generic type parameter.</typeparam>
/// <typeparam name="Size">Type of the size.</typeparam>
template<typename T, int Size>
class SArray
{
public:
	T m_sArray[Size];	
	int GetSize() const
	{
		return Size;
	}
};


#pragma once
#include "MyBase.h"

/// <summary>A child.</summary>
/// <seealso cref="MyBase{Child}"/>
class Child :
    public MyBase<Child>
{
public:
    std::string m_localStr = "child local string";

public:
    std::string FileName() const
    {
        return m_fileName;
    }

private:
    std::string m_fileName{ "testFileChild.txt" };
};



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
    void Test() override;
};



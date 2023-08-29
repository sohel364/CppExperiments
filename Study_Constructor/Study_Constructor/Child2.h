#pragma once
#include "MyBase.h"

class Child2 :
    public MyBase<Child2>
{
public:
    std::string m_Localstr = "child2 local string";

public:
    void Test() override;
};


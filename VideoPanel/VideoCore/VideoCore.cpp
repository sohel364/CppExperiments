#include "pch.h"
#include "VideoCore.h"

int VideoCore::SimpleAdd(int a, int b)
{
    return a * b;
}

std::wstring VideoCore::Message()
{
  return L"Simple message from core " + std::to_wstring(m_count++);
}


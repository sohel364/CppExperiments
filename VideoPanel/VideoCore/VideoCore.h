#pragma once
#include <string>

class VideoCore
{
public:
  // MHAS :: this is ust a simple example function for testing the connection between C++ and C#
  int SimpleAdd(int a, int b);
  std::wstring Message();
  int m_count{ 0 };
};


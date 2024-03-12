#pragma once
#include "MyViewModel.g.h"
#include "BindableBase.h"
#include "VideoCore.h"

namespace winrt::RuntimeComponentWrapper::implementation
{
  struct MyViewModel : MyViewModelT<MyViewModel, RuntimeComponentWrapper::implementation::BindableBase>
  {
    MyViewModel();

    int32_t Input1() const;
    void Input1(int32_t value);

    int32_t Input2() const;
    void Input2(int32_t value);

    hstring Output() const;
    void Output(hstring value);
    
    hstring Message() const;;
    void Message(hstring msg);

    void CalculateOutput();

  private:
    int32_t m_input1{ 0 };
    int32_t m_input2{ 0 };
    hstring m_output{ 0 };
    hstring m_message;
    VideoCore* m_videoCore{ nullptr };
  };
}

namespace winrt::RuntimeComponentWrapper::factory_implementation
{
  struct MyViewModel : MyViewModelT<MyViewModel, implementation::MyViewModel> {};
}

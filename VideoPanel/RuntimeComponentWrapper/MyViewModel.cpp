#include "pch.h"
#include "MyViewModel.h"
#include "MyViewModel.g.cpp"
#include "VideoCore.h"


using namespace winrt::Microsoft::UI::Xaml::Data;

namespace winrt::RuntimeComponentWrapper::implementation
{
  MyViewModel::MyViewModel()
  {
    m_videoCore = new VideoCore();
  }

  int32_t MyViewModel::Input1() const { return m_input1; }
  void MyViewModel::Input1(int32_t value)
  {
    __super::SetProperty(m_input1, value, L"Input1");
  }

  int32_t MyViewModel::Input2() const { return m_input2; }
  void MyViewModel::Input2(int32_t value)
  {
    __super::SetProperty(m_input2, value, L"Input2");
  }

  hstring MyViewModel::Output() const { return m_output; }
  void MyViewModel::Output(hstring value)
  {
    __super::SetProperty(m_output, value, L"Output");
  }

  hstring MyViewModel::Message() const { return m_message; }
  void MyViewModel::Message(hstring msg) { __super::SetProperty(m_message, msg, L"Message"); }

  void MyViewModel::CalculateOutput()
  {
    if (m_videoCore)
    {
      Output(to_hstring(m_videoCore->SimpleAdd(Input1(), Input2())) + L" Hz");
      Message(m_videoCore->Message().c_str());
    }
  }
}

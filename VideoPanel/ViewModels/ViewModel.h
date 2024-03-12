#pragma once

#include "ViewModel.g.h"

namespace winrt::ViewModels::implementation
{
    struct ViewModel : ViewModelT<ViewModel>
    {
        ViewModel() = default;
        
        int32_t Input1() const { return m_input1; };
        void Input1(int32_t value) { m_input1 = value; };

        int32_t Input2() const { return m_input2; };
        void Input2(int32_t value) { m_input2 = value; };

        int32_t Output() const { return m_output; };
        void Output(int32_t value) { m_output = value; };

        void CalculateOutput();
        hstring Status();

    private:
        int32_t m_input1{ 0 };
        int32_t m_input2{ 0 };
        int32_t m_output{ 0 };
    };
}

namespace winrt::ViewModels::factory_implementation
{
    struct ViewModel : ViewModelT<ViewModel, implementation::ViewModel>
    {
    };
}

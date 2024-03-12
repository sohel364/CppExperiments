#include "pch.h"
#include "ViewModel.h"
#include "ViewModel.g.cpp"

namespace winrt::ViewModels::implementation
{    
    void ViewModel::CalculateOutput()
    {
        // Perform calculation and set Output
        Output(Input1() + Input2());
    }
    hstring ViewModel::Status()
    {
        return L"Calculation completed successfully.";
    }
}

#include "pch.h"
#include "BindableBase.h"
#if __has_include("BindableBase.g.cpp")
#include "BindableBase.g.cpp"
#endif

using namespace winrt::Microsoft::UI::Xaml::Data;

namespace winrt::RuntimeComponentWrapper::implementation
{
	void BindableBase::RaisePropertyChanged(hstring const& propertyName)
	{
		m_propertyChanged(*this, PropertyChangedEventArgs(propertyName));
	}

	winrt::event_token BindableBase::PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
	{
		return m_propertyChanged.add(handler);
	}

	void BindableBase::PropertyChanged(winrt::event_token const& token)
	{
		m_propertyChanged.remove(token);
	}
}
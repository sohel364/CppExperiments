#pragma once

#include "BindableBase.g.h"

namespace winrt::RuntimeComponentWrapper::implementation
{
	struct BindableBase : BindableBaseT<BindableBase, Microsoft::UI::Xaml::DependencyObject>
	{
		BindableBase() = default;

		void RaisePropertyChanged(hstring const& propertyName);
		winrt::event_token PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
		void PropertyChanged(winrt::event_token const& token);

	protected:
		template<typename T>
		bool SetProperty(T& storage, const T& value, const hstring& propertyName)
		{
			if (storage == value)
				return false;
			storage = value;
			RaisePropertyChanged(propertyName);
			return true;
		}

	private:
		event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;
	};
}

namespace winrt::RuntimeComponentWrapper::factory_implementation
{
	struct BindableBase : BindableBaseT<BindableBase, implementation::BindableBase> {};
}




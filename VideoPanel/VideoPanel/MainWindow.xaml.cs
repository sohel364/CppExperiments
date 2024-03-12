using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Microsoft.UI.Xaml;
using Microsoft.UI.Xaml.Controls;
using Microsoft.UI.Xaml.Controls.Primitives;
using Microsoft.UI.Xaml.Data;
using Microsoft.UI.Xaml.Input;
using Microsoft.UI.Xaml.Media;
using Microsoft.UI.Xaml.Navigation;
using Windows.Foundation;

using RuntimeComponentWrapper;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace VideoPanel
{

	/// <summary>
	/// An empty window that can be used on its own or navigated to within a Frame.
	/// </summary>
	public sealed partial class MainWindow : Window
    {
		public MyViewModel VidewModel = new();

		public MainWindow()
        {
            InitializeComponent();			
		}

		private bool _isPanelVisible = true;

		private void ToggleButton_Click(object sender, RoutedEventArgs e)
		{
			_isPanelVisible = !_isPanelVisible;

			ControllerColumn.Width = _isPanelVisible
				? new GridLength(300)
				: new GridLength(0);

			ToggleButton.Content = _isPanelVisible ? "->" : "<-";
		}

		private void Button_Click(object sender, RoutedEventArgs e)
		{
			VidewModel.CalculateOutput();
		}
	}
}

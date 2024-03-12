#include <Wt/WApplication.h>
#include <Wt/WBreak.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>

class HelloApplication : public Wt::WApplication
{
public:
  HelloApplication(const Wt::WEnvironment& env);

private:
  Wt::WLineEdit* nameEdit_;
  Wt::WText* greeting_;
};

HelloApplication::HelloApplication(const Wt::WEnvironment& env)
  : Wt::WApplication(env)
{
  setTitle("Hello world");

  root()->addNew<Wt::WText>("Your name, please? ");
  nameEdit_ = root()->addNew<Wt::WLineEdit>();
  Wt::WPushButton* button = root()->addNew<Wt::WPushButton>("Greet me.");
  root()->addNew<Wt::WBreak>();
  greeting_ = root()->addNew<Wt::WText>();
  auto greet = [this] {
    greeting_->setText("Hello there, " + nameEdit_->text());
    };
  button->clicked().connect(greet);
}

int main(int argc, char** argv)
{
  return Wt::WRun(argc, argv, [](const Wt::WEnvironment& env) {
    return std::make_unique<HelloApplication>(env);
    });
}

//#include <Wt/WApplication.h>
//#include <Wt/WContainerWidget.h>
//#include <Wt/WTable.h>
//#include <Wt/WText.h>
//
//class WittyTable : public Wt::WApplication {
//public:
//  WittyTable(const Wt::WEnvironment& env) : Wt::WApplication(env) {
//    root()->resize(400, 200); // Set the size of the container
//
//    // Create a container widget with fixed size
//    auto tableContainer = std::make_unique<Wt::WContainerWidget>();
//    tableContainer->resize(400, 200); // Same size as root container
//    tableContainer->setOverflow(Wt::Overflow::Auto); // Enable scrolling
//
//    auto table = tableContainer->addWidget(std::make_unique<Wt::WTable>());
//    table->setWidth(Wt::WLength("100%"));
//
//    // Add table headers
//    table->elementAt(0, 0)->addWidget(std::make_unique<Wt::WText>("Name"));
//    table->elementAt(0, 1)->addWidget(std::make_unique<Wt::WText>("Age"));
//    table->elementAt(0, 2)->addWidget(std::make_unique<Wt::WText>("Country"));
//
//    // Add table data
//    table->elementAt(1, 0)->addWidget(std::make_unique<Wt::WText>("John Doe"));
//    table->elementAt(1, 1)->addWidget(std::make_unique<Wt::WText>("30"));
//    table->elementAt(1, 2)->addWidget(std::make_unique<Wt::WText>("USA"));
//
//    table->elementAt(2, 0)->addWidget(std::make_unique<Wt::WText>("Jane Smith"));
//    table->elementAt(2, 1)->addWidget(std::make_unique<Wt::WText>("25"));
//    table->elementAt(2, 2)->addWidget(std::make_unique<Wt::WText>("Canada"));
//
//    root()->addWidget(std::move(tableContainer));
//  }
//};
//
//int main(int argc, char** argv) {
//  return Wt::WRun(argc, argv, [](const Wt::WEnvironment& env) {
//    return std::make_unique<WittyTable>(env);
//    });
//}
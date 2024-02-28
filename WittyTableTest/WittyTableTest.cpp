#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WTable.h>
#include <Wt/WText.h>
#include <Wt/WEvent.h>

class WittyTableTest : public Wt::WApplication {
public:
  WittyTableTest(const Wt::WEnvironment& env) : Wt::WApplication(env) {
    root()->resize(400, 200); // Set the size of the container

    // Create a container widget with fixed size
    auto tableContainer = std::make_unique<Wt::WContainerWidget>();
    tableContainer->resize(400, 300); // Same size as root container
    tableContainer->setOverflow(Wt::Overflow::Scroll); // Enable scrolling

    tableContainer->mouseWheel().connect([&](Wt::WMouseEvent event) {      
      if (event.wheelDelta() > 0)
        //Wt::log("info") << "Scrolled down by " << event.viewportHeight() << " pixels";
        Wt::log("info") << "Scrolled up";
      else
        Wt::log("info") << "Scrolled down";
      });

    auto table = tableContainer->addWidget(std::make_unique<Wt::WTable>());
    table->setWidth(Wt::WLength("100%"));

    // Add table headers
    table->elementAt(0, 0)->addWidget(std::make_unique<Wt::WText>("Name"));
    table->elementAt(0, 1)->addWidget(std::make_unique<Wt::WText>("Age"));
    table->elementAt(0, 2)->addWidget(std::make_unique<Wt::WText>("Country"));

    // Add table data
    for (int i = 1; i < 20; i++)
    {
      table->elementAt(i, 0)->addWidget(std::make_unique<Wt::WText>("John Doe"));
      table->elementAt(i, 1)->addWidget(std::make_unique<Wt::WText>("30"));
      table->elementAt(i, 2)->addWidget(std::make_unique<Wt::WText>("USA"));

    /*  table->elementAt(2, 0)->addWidget(std::make_unique<Wt::WText>("Jane Smith"));
      table->elementAt(2, 1)->addWidget(std::make_unique<Wt::WText>("25"));
      table->elementAt(2, 2)->addWidget(std::make_unique<Wt::WText>("Canada"));*/
    }
    root()->addWidget(std::move(tableContainer));
  }
};

int main(int argc, char** argv)
{
  return Wt::WRun(argc, argv, [](const Wt::WEnvironment& env) {
    return std::make_unique<WittyTableTest>(env);
    });
}
#include "../Common/Graphics.h"
#include "../Common/EventEngine.h"
#include "../Controls/Panel.h"
#include "../Controls/Button.h"

Panel *mainPanel;

Border *border = new Border();

int main(int argc, char** argv)
{

  	mainPanel = new Panel(0, 0, 2, 3+2, border, Color::White, Color::Blue);
    mainPanel->setName("Console GUI Application");
	
	Button okButton(1, 5, 10, nullptr, Color::White, Color::Red, "OK");
    mainPanel->addControl(&okButton);

	EventEngine e;
	e.run(*mainPanel);

}
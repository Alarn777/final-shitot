#include "../Common/Graphics.h"
#include "../Common/EventEngine.h"
#include "../Controls/Panel.h"
#include "../Controls/Button.h"
#include "../Controls/TextBox.h"

Panel *mainPanel;

Border *border = new Border();
int main_width = 150;
int main_height = 45;

int main(int argc, char** argv)
{

  	mainPanel = new Panel(0, 0, main_width, main_height, border, Color::White, Color::Blue);
    mainPanel->setName("Console GUI Application");
	
	Button okButton(2, 5, 10, nullptr, Color::White, Color::Red, "OK");
    mainPanel->addControl(&okButton);

	TextBox textBox(2, 10, 35, Color::White, Color::Cyan, "textBox here",30);
    mainPanel->addControl(&textBox);

	EventEngine e;
	e.run(*mainPanel);

}
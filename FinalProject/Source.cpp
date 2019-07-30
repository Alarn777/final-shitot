#include "../Common/Graphics.h"
#include "../Common/EventEngine.h"
#include "../Controls/Panel.h"
#include "../Controls/Button.h"
#include "../Controls/TextBox.h"
#include "../Controls/CheckBox.h"
#include "../Controls/Label.h"
#include "../Controls/MessageBox_My.h"


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

	CheckBox myCheckBox(3, 3, Color::White, Color::Blue, false, Label("Press"));
	mainPanel->addControl(&myCheckBox);

	Label titleLabel("This is a demo application made with love by Michael Rokitko, Amit Levy, Eran Maron & Evgeny Alterman",
						 0, main_height - 3);
	mainPanel->addControl(&titleLabel);

    MessageBox_My message(2,20,50,10,Color::White,Color::Cyan,"This pop-up was created by the button, proceed?");
    mainPanel->addControl(&message);


    EventEngine e;
	e.run(*mainPanel);

}
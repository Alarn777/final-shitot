#include "../Common/Graphics.h"
#include "../Common/EventEngine.h"
#include "../Controls/Panel.h"
#include "../Controls/Button.h"
#include "../Controls/TextBox.h"
#include "../Controls/CheckBox.h"
#include "../Controls/Label.h"
#include "../Controls/MessageBox_My.h"
#include "../Controls/CheckList.h"
#include "../Controls/Radio.h"
#include "../Controls/RadioBox.h"

Panel *mainPanel;
Panel *middleTopPanel;
Panel *middleMidPanel;
Panel *middleBottomPanel;
Panel *leftPanel;

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



	Label titleLabel("This is a demo application made with love by Michael Rokitko, Amit Levy, Eran Maron & Evgeny Alterman",
						 0, main_height - 3);
	mainPanel->addControl(&titleLabel);

    MessageBox_My message(2,20,50,10,Color::White,Color::Cyan,"This pop-up was created by the button, proceed?");
    mainPanel->addControl(&message);



    int mid_panel_height = main_height / 3-3;
    middleTopPanel = new Panel(83, 1, 50, mid_panel_height, border, Color::White, Color::Green);
    middleTopPanel->setName("Middle Top");

    middleMidPanel = new Panel(83, 3 + mid_panel_height, 50, mid_panel_height, border, Color::White, Color::Green);
    middleMidPanel->setName("Middle Mid");

    middleBottomPanel = new Panel(83, 5 + 2 * mid_panel_height, 50, mid_panel_height, border, Color::White,
                                  Color::Green);
    middleBottomPanel->setName("Middle Bottom");

    CheckBox box(3, 3, Color::White, Color::Blue, false, Label("Press"));
    CheckBox box1(3, 6, Color::White, Color::Blue, false, Label("Press2"));

    CheckList checkList(1, 1, 15, 8, Color::White, Color::Blue, "Checklist");
    checkList.addCheckBox(&box);
    checkList.addCheckBox(&box1);
    middleTopPanel->addControl(&checkList);

    Radio rad(3, 3, Color::White, Color::Red, false, Label("Choose me"));
    Radio rad0(3, 5, Color::White, Color::Red, false, Label("Or choose me"));
    Radio rad01(3, 7, Color::White, Color::Red, false, Label("Or me"));
    RadioBox listBox(20, 4, 25, 10, Color::White, Color::Blue, "Radio List");

    listBox.addRadio(&rad);
    listBox.addRadio(&rad0);
    listBox.addRadio(&rad01);
    leftPanel->addControl(&listBox);

    mainPanel->addControl(leftPanel);
    mainPanel->addControl(middleTopPanel);
    mainPanel->addControl(middleMidPanel);
    mainPanel->addControl(middleBottomPanel);

	EventEngine e;
	e.run(*mainPanel);
}
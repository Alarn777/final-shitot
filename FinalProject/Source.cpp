#include "../Controls/ComboBox.h"
#include "../Common/Graphics.h"
#include "../Common/EventEngine.h"
#include "../Controls/Panel.h"
#include "../Controls/Button.h"
#include "../Controls/CheckBox.h"
#include "../Controls/CheckList.h"
#include "../Controls/Radio.h"
#include "../Controls/RadioBox.h"
#include "../Controls/NumericBox.h"
#include "../Controls/TextBox.h"
#include "../Controls/MessageBox_My.h"

Panel *mainPanel;
Panel *leftPanel;
Panel *middleTopPanel;
Panel *middleMidPanel;
Panel *middleBottomPanel;
Panel *rightPanel;

auto message =  MessageBox_My(2,20,50,10,Color::White,Color::Cyan,"This pop-up was created by the button, proceed?");

string myfunction() {
    std::cout << "Function of a button" << std::endl;
    leftPanel->addControl(&message);
    return "Done";
}

Border *border = new Border();
int main_width = 180;
int main_height = 45;

int main(int argc, char **argv) {

    mainPanel = new Panel(0, 0, main_width, main_height+2, border, Color::White, Color::Blue);
    mainPanel->setName("Console GUI Application");

    Label mainPanelLabel("This is a demo application made by Michael Rokitko, Amit Levy, Eran Maron, Evgeny Alterman",
                         0, main_height - 3);
    Label mainPanelExplanationLabel("Use TAB to move between panels, Mouse and keyboard are active only if the focus is on panel",
                                    0, main_height - 1);
    mainPanel->addControl(&mainPanelLabel);
    mainPanel->addControl(&mainPanelExplanationLabel);

    leftPanel = new Panel(1, 1, 77, main_height - 5, border, Color::White, Color::Purple);
    leftPanel->setName("Left");

    Button messageButton(55, 5, 12, nullptr, Color::White, Color::Red, "Create Popup");
    messageButton.addOnClick(myfunction);
    leftPanel->addControl(&messageButton);


    int mid_panel_height = main_height / 3-3;
    middleTopPanel = new Panel(83, 1, 50, mid_panel_height, border, Color::White, Color::Green);
    middleTopPanel->setName("Middle Top");

    middleMidPanel = new Panel(83, 3 + mid_panel_height, 50, mid_panel_height, border, Color::White, Color::Green);
    middleMidPanel->setName("Middle Mid");

    middleBottomPanel = new Panel(83, 5 + 2 * mid_panel_height, 50, mid_panel_height, border, Color::White,
                                  Color::Green);
    middleBottomPanel->setName("Middle Bottom");

    rightPanel = new Panel(137, 1, main_width - 140, main_height - 5, border, Color::White, Color::Green);
    rightPanel->setName("Left");

    CheckBox box(3, 3, Color::White, Color::Blue, false, Label("Press"));
    CheckBox box1(3, 6, Color::White, Color::Blue, false, Label("Press2"));

    CheckList checkList(1, 1, 15, 8, Color::White, Color::Blue, "Checklist");
    checkList.addCheckBox(&box);
    checkList.addCheckBox(&box1);
    middleTopPanel->addControl(&checkList);

    Button okButton(1, 5, 10, nullptr, Color::White, Color::Red, "OK");
    leftPanel->addControl(&okButton);

    Button cancelButton(1, 10, 10, nullptr, Color::White, Color::Red, "Cancel");
    leftPanel->addControl(&cancelButton);

    Radio rad(3, 3, Color::White, Color::Red, false, Label("Choose me"));
    Radio rad0(3, 5, Color::White, Color::Red, false, Label("Or choose me"));
    Radio rad01(3, 7, Color::White, Color::Red, false, Label("Or me"));
    RadioBox listBox(20, 4, 25, 10, Color::White, Color::Blue, "Radio List");
    listBox.addRadio(&rad);
    listBox.addRadio(&rad0);
    listBox.addRadio(&rad01);
    leftPanel->addControl(&listBox);

    vector<string> valuesForCombo;
    valuesForCombo.emplace_back("Dog");
    valuesForCombo.emplace_back("Cat");
    valuesForCombo.emplace_back("Python");
    valuesForCombo.emplace_back("Rabbit");
    ComboBox combo(1, 1, 35, 30, Color::White, Color::Cyan, "Combo here", valuesForCombo);
    rightPanel->addControl(&combo);

    NumericBox numBox(1, 1, Color::White, Color::Cyan, "Numeric here", 0, 1000);
    middleMidPanel->addControl(&numBox);

    TextBox textBox(1, 1, 35, Color::White, Color::Cyan, "textBox here",30);
    middleBottomPanel->addControl(&textBox);

    mainPanel->addControl(leftPanel);
    mainPanel->addControl(middleTopPanel);
    mainPanel->addControl(middleMidPanel);
    mainPanel->addControl(middleBottomPanel);
    mainPanel->addControl(rightPanel);

    EventEngine e;
    e.run(*mainPanel);
}


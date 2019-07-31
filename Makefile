CXX = i686-w64-mingw32-g++
CPPFLAGS = -std=c++1z -static -g
OBJS += Common/Control.o Common/EventEngine.o Common/Graphics.o FinalProject/Source.o Controls/Label.o Common/Border/Border.o Controls/Button.o Controls/Panel.o Controls/CheckBox.o Controls/CheckList.o Controls/RadioBox.o Controls/Radio.o Controls/MessageBox_My.o Controls/ComboBox.o Controls/Combo.o Controls/NumericBox.o Controls/TextBox.o

%.o: %.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

all: $(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o final.exe
clean:
	rm -f $(OBJS)
	rm -f *.exe



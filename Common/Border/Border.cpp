#include "Border.h"
#include "../../utils/utils.h"



Border::Border() {
    topLeft = TOP_LEFT_CORNER_DOUBLE_LINE;
    topRight = TOP_RIGHT_CORNER_DOUBLE_LINE;
    bottomLeft = BOTTOM_LEFT_CORNER_DOUBLE_LINE;
    bottomRight = BOTTOM_RIGHT_CORNER_DOUBLE_LINE;
    horizontal = HORIZONTAL_DOUBLE_LINE;
    vertical = VERTICAL_DOUBLE_LINE;
}

Border::Border(int i) {
    topLeft =  TOP_LEFT_CORNER;
    topRight = TOP_RIGHT_CORNER;
    bottomLeft = BOTTOM_LEFT_CORNER;
    bottomRight = BOTTOM_RIGHT_CORNER;
    vertical = VERTICAL_LINE;
    horizontal =  HORIZONTAL_LINE;
}
Border::~Border() {}

void Border::drawBorder(Graphics& g, short left, short top, short width, short height) {
    string line(width, horizontal);
    string space(width, ' ');

    g.moveTo(left, top);
    g.write(string(1,topLeft));
    g.write(line);
    g.write(string(1,topRight));
    for(int i = 1; i < height - 1; ++i) {
        g.moveTo(left, top + i);
        g.write(string(1,vertical));
        g.write(space);
        g.write(string(1,vertical));
    }
    g.moveTo(left, top + height - 1);
    g.write(string(1,bottomLeft));
    g.write(line);
    g.write(string(1,bottomRight));
}

#include "iostream"
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

struct Rect {
    int x, y;
    bool color; // false = black, true = white;
};

struct Pattern {
    int rectWidth, rectHeight;
    vector<Rect> rects;// list of rects
};

Pattern* calculatePattern(int pWidth, int pHeight) {

    auto* pattern = new Pattern();

    // calculate size of rectangle
    pattern->rectWidth = (pWidth - 10) * 28 / 940;
    pattern->rectHeight = pHeight * 32 / 800;

    int amountRectsWidth = pWidth/ pattern->rectWidth;
    int amountRectsHeight = pHeight / pattern->rectHeight;

    float angle = 0, offset, PiByTwo = M_PI /2;
    int yRect;
    // -> 1   n = amountRectsHeight + amountRectsWidth
    for(int row = 0; row < amountRectsHeight; ++row) { // 

        offset = sin(angle) * 10;
        yRect = row * pattern->rectHeight;

        for(int column = 0; column < amountRectsWidth; ++column) {
            Rect newRect;

            newRect.y = yRect;
            newRect.x = column * pattern->rectWidth + offset;
            newRect.color = column % 2 != 0;

            pattern->rects.push_back(newRect);
        }

        angle += PiByTwo;
    }

    return pattern;
}

void printPattern(Pattern* pattern){

    cout << "\nw: " << pattern->rectWidth << endl;
    cout << "h: " << pattern->rectHeight << endl;

    for(auto i = pattern->rects.begin(); i < pattern->rects.end(); i++){
        cout << "\nx: " << i->x << endl;
        cout << "y: " << i->y << endl;
        cout << "c: " << i->color << endl;
    }
}

string* generateStringForProcessing(Pattern* pattern){

    stringstream ss;

    ss << pattern->rectWidth << ",";
    ss << pattern->rectHeight << ";";

    for(auto i = pattern->rects.begin(); i < pattern->rects.end(); i++){

        ss << i->x << "," << i->y << "," << i->color ;

        if((i+1) != pattern->rects.end()) ss << ";";

    }

    return new string(ss.str());
}

int main(){

    Pattern* pattern = calculatePattern(900, 800);
    printPattern(pattern);

    //string* json = generateStringForProcessing(pattern);
    //cout << *json << endl;
    //delete json;

    // cleaning
    delete pattern;

    return 0;
}

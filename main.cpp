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

    for(int row = 0; row < amountRectsHeight; ++row) {

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

// should return a string
string* generateJson(Pattern* pattern){
    stringstream ss;

    ss << "{\n\"rectWidth\": " << pattern->rectWidth << "," << endl;
    ss << "\"rectHeight\": " << pattern->rectHeight << "," << endl;
    ss << "\"rects\": [" << endl;

    for(auto i = pattern->rects.begin(); i < pattern->rects.end(); i++){

        ss << "{\n\"x\": " << i->x << "," << endl;
        ss << "\"y\": " << i->y << "," << endl;
        ss << "\"color\": " << i->color << "\n}" << endl;

        if((i+1) != pattern->rects.end()) ss << "," << endl;
    }

    ss << "]\n}" << endl;

    return new string(ss.str());
}

int main(){

    Pattern* pattern = calculatePattern(500, 500);
    //printPattern(pattern);

    string* json = generateJson(pattern);
    cout << *json << endl;

    // cleaning
    delete pattern;
    delete json;

    return 0;
}
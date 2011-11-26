#pragma once
#include "ofMain.h"
#include "Tools.h"
#include "Tweenable2D.h"

class Title : public Tweenable2D
{
public:
    Title(float scale, int xPos, int yPos, string group_line1, string group_line2, string project_line1, string project_line2);
    void update();
    void draw();
    
    void draw_line(float x, float y, string line);
    
    ofPoint _location;
    float _scale;
    string _group_line1;
    string _group_line2;
    string _project_line1;
    string _project_line2;
    
    int _padding;
    float _font_size;
    float _light_font_size;
    
    ofTrueTypeFont _font;
    ofTrueTypeFont _light_font;
};

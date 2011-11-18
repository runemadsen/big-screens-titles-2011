#include "Title.h"

Title::Title(float scale, int xPos, int yPos, string group, string project_line1, string project_line2)
{
    if (ofGetWidth() != 3840) 
    {
        float percent = ofGetWidth() / 3840.0;
        scale = scale * percent;
        xPos = xPos * percent;
        yPos = yPos * percent;
    }
    
    _scale = scale;
    pos.set(xPos,yPos,0);
    _group = group;
    _project_line1 = Tools::toUpperCase(project_line1);
    _project_line2 = Tools::toUpperCase(project_line2);
    
    _padding = 10 * _scale;
    _font_size = 80 * _scale;
    _light_font_size = 30 * _scale;
    
    _font.loadFont("Gotham-Medium.ttf", _font_size);
    _light_font.loadFont("Gotham-Light.ttf", _light_font_size);
    _font.setLetterSpacing(0.92);
}

void Title::update()
{
    
}

void Title::draw()
{
    ofEnableAlphaBlending();
    
    int y = pos.y;
    
    draw_line(pos.x, y, _project_line1);
    
    // draw line 2
    if(_project_line2 != "NULL")
    {
        y += _font_size + (2 * _padding) + (_font_size / 3);
        draw_line(pos.x, y, _project_line2);
    }
    
    ofSetColor(255, 255, 255, alpha);
    y += _font_size * 2;
    _light_font.drawString(_group, pos.x, y);
    
    ofDisableAlphaBlending();
}

void Title::draw_line(float x, float y, string line)
{
    // draw box
    ofSetColor(255, 255, 255, alpha);
    ofRect(x - _padding, y - _padding, _font.stringWidth(line) + (2 * _padding) + (_font_size / 8), _font_size + (2 * _padding));
    
    // draw line 1
    ofSetColor(0, 0, 0);
    _font.drawString(line, x, y + (_font_size - (_font_size / 40)));
}
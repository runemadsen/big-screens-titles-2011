#pragma once
#include "ofMain.h"
#include "Tools.h"
#include "Tweenable2D.h"

class Lanterns : public Tweenable2D
{
public:
    Lanterns(string video_name);
    void update();
    void draw();
    
    ofVideoPlayer vid;
};

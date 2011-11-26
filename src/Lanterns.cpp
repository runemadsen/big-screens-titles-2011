#include "Lanterns.h"

Lanterns::Lanterns(string video_name)
{
    vid.loadMovie(video_name);
    vid.play();
}

void Lanterns::update()
{
    vid.idleMovie();
}

void Lanterns::draw()
{
    ofEnableAlphaBlending();
    ofSetColor(255, 255, 255, alpha);
    vid.draw(0, 0, ofGetWidth(), ofGetHeight());
    ofDisableAlphaBlending();
}


#include "testApp.h"

/*  Setup
__________________________________________________________ */

void testApp::setup()
{
	ofSetWindowTitle("template project");
	ofSetFrameRate(60);
    
    loadXML();
    
    title = new Title(scale, xPos, yPos, group, project_line1, project_line2);
    title->alpha = 255;    
    vid.loadMovie(video_name);
    vid.play();
    
    //ofToggleFullscreen();
}

void testApp::loadXML()
{
    XML.loadFile("pinata_settings_R.xml");

    scale = XML.getValue("root:title:scale", 1.0);
	xPos = XML.getValue("root:title:xpos", 0);
	yPos = XML.getValue("root:title:ypos", 0);
    group = XML.getValue("root:title:group", "Default Group");
    project_line1 = XML.getValue("root:title:project_line1", "null");
    project_line2 = XML.getValue("root:title:project_line2", "null");
    video_name = XML.getValue("root:video:name", "null");
}

/*  Update
__________________________________________________________ */

void testApp::update()
{
    vid.idleMovie();
}

/*  Draw
__________________________________________________________ */

void testApp::draw()
{
	ofBackground(0, 0, 0);	
    vid.draw(0, 0, ofGetWidth(), ofGetHeight());
    title->draw();
}

/*  Events
__________________________________________________________ */

void testApp::keyPressed  (int key){

    if(key == 'i')
    {
        title->tweenPosTo(xPos + 200, yPos,	0.6, EasingEquations::EASE_OUT_QUAD);
        title->tweenAlphaTo(255, 0.6,  EasingEquations::EASE_IN_QUAD);
    }
    else if(key == 'o')
    {
        title->tweenPosTo(xPos + 400, yPos,	0.6, EasingEquations::EASE_IN_QUAD);
        title->tweenAlphaTo(0, 0.6,  EasingEquations::EASE_OUT_QUAD);
    }

}
void testApp::keyReleased(int key){}
void testApp::mouseMoved(int x, int y ){}
void testApp::mouseDragged(int x, int y, int button){}
void testApp::mousePressed(int x, int y, int button){}
void testApp::mouseReleased(int x, int y, int button){}
void testApp::windowResized(int w, int h){}
void testApp::gotMessage(ofMessage msg){}
void testApp::dragEvent(ofDragInfo dragInfo){}
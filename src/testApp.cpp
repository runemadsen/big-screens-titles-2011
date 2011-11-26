#include "testApp.h"

/*  Setup
__________________________________________________________ */

void testApp::setup()
{
	ofSetWindowTitle("template project");
	ofSetFrameRate(60);
    
    loadXML();
    
    lanterns = new Lanterns(video_name);
    lanterns->alpha = 0;
    lanterns->tweenAlphaTo(255, 4, EasingEquations::EASE_INOUT_CUBIC);
    
    title = new Title(scale, xPos, yPos, group_line1, group_line2, project_line1, project_line2);
    title->alpha = 0;
    title->tweenAlphaTo(255, 3, EasingEquations::EASE_INOUT_CUBIC, 3);
    
    if (ofGetWidth() == 3840) 
    {
        ofToggleFullscreen();
    }
}

void testApp::loadXML()
{
    XML.loadFile("conditions_settings_R.xml");

    scale = XML.getValue("root:title:scale", 1.0);
	xPos = XML.getValue("root:title:xpos", 0);
	yPos = XML.getValue("root:title:ypos", 0);
    group_line1 = XML.getValue("root:title:group_line1", "null");
    group_line2 = XML.getValue("root:title:group_line2", "null");
    project_line1 = XML.getValue("root:title:project_line1", "null");
    project_line2 = XML.getValue("root:title:project_line2", "null");
    video_name = XML.getValue("root:video:name", "null");
}

/*  Update
__________________________________________________________ */

void testApp::update()
{
    lanterns->update();
}

/*  Draw
__________________________________________________________ */

void testApp::draw()
{
	ofBackground(0, 0, 0);	
    
    lanterns->draw();
    title->draw();
}

/*  Events
__________________________________________________________ */

void testApp::keyPressed  (int key){

   /* if(key == 'i')
    {
        title->tweenPosTo(xPos + 200, yPos,	0.6, EasingEquations::EASE_OUT_QUAD);
        title->tweenAlphaTo(255, 0.6,  EasingEquations::EASE_IN_QUAD);
    }
    else if(key == 'o')
    {
        title->tweenPosTo(xPos + 400, yPos,	0.6, EasingEquations::EASE_IN_QUAD);
        title->tweenAlphaTo(0, 0.6,  EasingEquations::EASE_OUT_QUAD);
    }*/

}
void testApp::keyReleased(int key){}
void testApp::mouseMoved(int x, int y ){}
void testApp::mouseDragged(int x, int y, int button){}
void testApp::mousePressed(int x, int y, int button){}
void testApp::mouseReleased(int x, int y, int button){}
void testApp::windowResized(int w, int h){}
void testApp::gotMessage(ofMessage msg){}
void testApp::dragEvent(ofDragInfo dragInfo){}
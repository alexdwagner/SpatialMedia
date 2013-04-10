#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetFrameRate(24);
    ofBackground(0);
    
    bDrawWireframe = false;
    
    // Load the font
    string filename = "planet_kosmos.ttf";
    int fontSize = 90;
    bool bAntiAliased = false;
    bool bFullCharacterSet = true;
    bool makeContours = true;
    float simplifyAmt = 30; // uses ofPolyline::simplify
    font.loadFont(filename, fontSize, bAntiAliased, bFullCharacterSet, makeContours, simplifyAmt);
    font.setLineHeight(fontSize+10);
    
    // Get the bounding box of the text
    text = "Spatial\nMedia";
    bb = font.getStringBoundingBox(text, 0, 0);

    
    // Create a bunch of Letter objects
    vector<ofPath> letterPaths = font.getStringAsPoints(text);
    for(int i=0; i<letterPaths.size(); i++)
    {
        Letter l;
        l.setup(letterPaths[i], 40);
        letters.push_back(l);
    }
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackgroundGradient(ofColor::white, ofColor::black);

    glEnable(GL_DEPTH_TEST);
    ofPushMatrix();
    {
        ofTranslate((ofGetWidth()/2.0)-(bb.getWidth()/2.0), ofGetHeight()/2.0);
        ofRotateX(ofGetFrameNum() *3);
        ofTranslate(0, -50);
        
        for(int i=0; i<letters.size(); i++)
        {
            ofSetColor(200, 0, 100);
            letters[i].front.draw();
            
            ofSetColor(255);
            letters[i].side.draw();
            
            if(bDrawWireframe){
                ofSetColor(0);
                letters[i].side.drawWireframe();
            }

            ofSetColor(50, 100, 100);
            letters[i].back.draw();
        }
    }
    ofPopMatrix();
    glDisable(GL_DEPTH_TEST);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    if(key=='w') {
        bDrawWireframe = !bDrawWireframe;
    }
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
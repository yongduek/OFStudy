#include "ofApp.h"

const int width=720;
const int height=480;
unsigned char ptr[width*height*3];

ofImage image;
//--------------------------------------------------------------
void ofApp::setup(){
    image.setFromPixels (ptr, width, height, OF_IMAGE_COLOR);

}

//--------------------------------------------------------------
void ofApp::update(){
    ofBackground(255);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    
    ofPixels & pixels = image.getPixels();
    for (int y=10; y<100; y++)
        for (int x=20; x<200; x++) {
            int index = 3*(y*width + x);
            unsigned char cur = pixels[index];
            pixels[index] = 0;
            pixels[index+1] = 0;
            pixels[index+2] = 255;
        }
    
    image.update(); // update the chage to the graphic output, otherwise the change will not be shown
    image.draw(0,0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

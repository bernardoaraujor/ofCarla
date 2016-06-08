#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);

	width1 = 1920;
	height1 = 1080;

	width2 = 1024;
	height2 = 960;

	xCenter1 = width1 / 2;
	yCenter1 = height1 / 2;

	xCenter2 = width1 + width2 / 2;
	yCenter2 = height2 / 2;	

	ofSetFrameRate(55);
	video.load("a.mov");
}

//--------------------------------------------------------------
void ofApp::update(){
	video.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetRectMode(OF_RECTMODE_CENTER);
	video.draw(xCenter1, yCenter1);
	

	stringstream ss;
	ss << "x:  " << xMouse << "y: " << yMouse;
	//ofDrawBitmapString(ss.str(), 100, 100);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == OF_KEY_LEFT) {
		video.play();
	}
	if (key == OF_KEY_RIGHT) {
		video.stop();
	}
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
	xMouse = x;
	yMouse = y;
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

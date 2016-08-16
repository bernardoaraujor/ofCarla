#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
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
	video.loadMovie("b.mov");

	if (serial.setup("COM6", 9600)) {
		cout << "serial is setup!" << endl;
	}
	send = true;
	readTime = 0;
}

//--------------------------------------------------------------
void ofApp::update() {
	if (send) {
		serial.writeByte('a');
		send = false;
		readTime = ofGetElapsedTimeMillis();		
	}else if ((serial.available()) && (ofGetElapsedTimeMillis() - readTime > 100)){
		unsigned char bytes[6];
		int result = serial.readBytes(&bytes[0], 6);

		// check for error code
		if (result == OF_SERIAL_ERROR){
			// something bad happened
			ofLog(OF_LOG_ERROR, "unrecoverable error reading from serial");
		}else if (result == OF_SERIAL_NO_DATA){
			// nothing was read, try again
			ofLog(OF_LOG_ERROR, "read nothing");
		}
		
		sensor1 = bytes[0];
		sensor2 = bytes[2];
		sensor3 = bytes[4];

		cout << sensor1 << endl;
		send = true;
	}	

	video.update();
}		

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetRectMode(OF_RECTMODE_CENTER);
	video.draw(xCenter1, yCenter1);

	stringstream s;
	s << "sensor 1: " << sensor1 << "cm \nsensor 2: " << sensor2 << "cm \nsensor 3: " << sensor3 << "cm";
	ofDrawBitmapString(s.str(), 0, 10);
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

//-------------------------------------------------//-------------
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

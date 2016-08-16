#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	ofBackground(0);

	//PROVISORIO
	width1 = ofGetWidth()/3;
	height1 = ofGetHeight();

	width2 = ofGetWidth()/3;
	height2 = ofGetHeight();

	width3 = ofGetWidth()/3;
	height3 = ofGetHeight();

	xCenter1 = width1 / 2;
	yCenter1 = height1 / 2;

	xCenter2 = width1 + width2 / 2;
	yCenter2 = height2 / 2;	

	xCenter3 = width1 + width2 + width3 / 2;
	yCenter3 = height3 / 2;

	distThreshold = 30;

	ofSetFrameRate(55);

	video1.loadMovie("b.mov");
	video2.loadMovie("b.mov");
	video3.loadMovie("b.mov");

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
	}else if ((serial.available()) && (ofGetElapsedTimeMillis() - readTime > 500)){
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
		
		cout << "sensor1: " << sensor1 << ", sensor2: " << sensor2 << ", sensor3: " << sensor3 << endl;
		sensor1 = bytes[0];
		sensor2 = bytes[2];
		sensor3 = bytes[4];

		send = true;
	}

	if (sensor1 > 0) {
		queue1.push(sensor1);
		if (queue1.size() > 5)
			queue1.pop();
	}
	if (sensor2 > 0) {
		queue2.push(sensor2);
		if (queue2.size() > 5)
			queue2.pop();
	}
	if (sensor3 > 0) {
		queue3.push(sensor3);
		if (queue3.size() > 5)
			queue3.pop();
	}	

	if (queue1.size() > 0) {
		avg1 = 0;
		for (int i = 0; i < queue1.size(); i++) {
			int l = queue1.front();

			queue1.pop();
			queue1.push(l);

			avg1 += l;
		}
		avg1 /= queue1.size();
	}
	if (queue2.size() > 0) {
		avg2 = 0;
		for (int i = 0; i < queue2.size(); i++) {
			int l = queue2.front();

			queue2.pop();
			queue2.push(l);

			avg2 += l;
		}
		avg2 /= queue2.size();
	}
	if (queue3.size() > 0) {
		avg3 = 0;
		for (int i = 0; i < queue1.size(); i++) {
			int l = queue3.front();

			queue3.pop();
			queue3.push(l);

			avg3 += l;
		}
		avg3 /= queue3.size();
	}

	if (avg1 < distThreshold)
		play1 = true;
	else
		play1 = false;
	if (avg2 < distThreshold)
		play2 = true;
	else
		play2 = false;
	if (avg3 < distThreshold)
		play3 = true;
	else
		play3 = false;

	video1.update();
	video2.update();
	video3.update();
}		

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetRectMode(OF_RECTMODE_CENTER);
	video1.draw(xCenter1, yCenter1);
	video2.draw(xCenter2, yCenter2);
	video3.draw(xCenter3, yCenter3);

	stringstream s;
	s << "sensor 1: " << sensor1 << "cm \nsensor 2: " << sensor2 << "cm \nsensor 3: " << sensor3 << "cm" << endl;
	s << "queue1: " << avg1 << endl;
	s << "queue2: " << avg2 << endl;
	s << "queue3: " << avg3 << endl;
	ofDrawBitmapString(s.str(), 0, 10);

	if (play1)
		video1.play();
	if (play2)
		video2.play();
	if (play3)
		video3.play();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
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

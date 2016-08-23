#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	ofBackground(0);

	width1 = 1366;
	height1 = 768;

	width3 = 1024;
	height3 = 768;

	xCenter1 = width1 / 2;
	yCenter1 = height1 / 2;

	xCenter2 = width1 + width3 / 2;
	yCenter2 = height3 / 2;	

	distThreshold = 50;

	ofSetFrameRate(55);

	dirAmer = ofDirectory("/america/");
	dirAmer.listDir();
	//dirAsia = ofDirectory("/asia/");
	//dirAsia.listDir();
	dirEurasia = ofDirectory("/eurasia/");
	dirEurasia.listDir();
	dirTest = ofDirectory("/test/");
	dirTest.listDir();

	video1.setLoop(false);
	video2.setLoop(false);
	video3.setLoop(false);

	play1 = false;
	play2 = false;
	play3 = false;

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
		//cout << "aqui" << endl;
		sensor1 = serial.readByte();
		sensor2 = serial.readByte();
		sensor3 = serial.readByte();

		// check for error code
		if ((sensor1 == OF_SERIAL_ERROR) || (sensor2 == OF_SERIAL_ERROR)){
			// something bad happened
			ofLog(OF_LOG_ERROR, "unrecoverable error reading from serial");
		}else if ((sensor1 == OF_SERIAL_NO_DATA) || (sensor2 == OF_SERIAL_NO_DATA)){
			// nothing was read, try again
			ofLog(OF_LOG_ERROR, "read nothing");
		}
		
		cout << "sensor1: " << sensor1 << ", sensor2: " << sensor2 << ", sensor3: " << sensor3 << endl;
		send = true;
	}	

	if (sensor1 == 48) {
		if (play1 == false)
			video1.loadMovie(dirAmer.getPath(ofRandom(0, dirAmer.size()-1)));
			//video1.loadMovie(dirTest.getPath(ofRandom(0, dirTest.size())));
		play1 = true;
	}
	
	if (sensor2 == 48) {
		if (play2 == false)
			//video2.loadMovie(dirEurasia.getPath(ofRandom(0, dirAsia.size())));
			//video2.loadMovie(dirTest.getPath(ofRandom(0, dirTest.size())));
		play2 = true;
	}

	if (sensor3 == 48) {
		if (play3 == false)
			video3.loadMovie(dirEurasia.getPath(ofRandom(0, dirEurasia.size()-1)));
			//video3.loadMovie(dirTest.getPath(ofRandom(0, dirTest.size())));
		play3 = true;
	}

	if (video1.getPosition() > video1.getDuration() - 0.5)
		play1 = false;
	if (video2.getPosition() > video2.getDuration() - 0.5)
		play2 = false;
	if (video3.getPosition() > video3.getDuration() - 0.5)
		play3 = false;
}		

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetRectMode(OF_RECTMODE_CENTER);

	if (play1) {
		video1.draw(xCenter1, yCenter1);
		video1.play();
	}
	if (play2) {
		video2.draw(xCenter2, yCenter2);
		video2.play();
	}
	if (play3) {
		video3.draw(xCenter2, yCenter2);
		video3.play();
	}			

	stringstream s;
	s << "sensor 1: " << sensor1 << " \nsensor 2: " << sensor2 << " \nsensor 3: " << sensor3 << endl;
	s << "position 1: " << video1.getPosition() << ", duration 1:" << video1.getDuration() << endl;
	s << "position 3: " << video3.getPosition() << ", duration 3:" << video3.getDuration() << endl;
	ofDrawBitmapString(s.str(), 0, 10);
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

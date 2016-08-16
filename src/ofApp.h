#pragma once

#include "ofMain.h"
#include "ofxWMFVideoPlayer.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		int xMouse, yMouse;
		int width1, height1, xCenter1, yCenter1;
		int width2, height2, xCenter2, yCenter2;
		int width3, height3, xCenter3, yCenter3;

		ofxWMFVideoPlayer video1;
		ofxWMFVideoPlayer video2;
		ofxWMFVideoPlayer video3;
		queue<int> queue1, queue2, queue3;
		bool play1, play2, play3;

		ofSerial serial;

		float readTime;
		bool send;

		int sensor1, sensor2, sensor3;
		float avg1, avg2, avg3;

		int distThreshold;
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};

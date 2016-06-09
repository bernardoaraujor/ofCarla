#include "ofMain.h"
#include "ofApp.h"
#include "ofAppGLFWWindow.h"  

//========================================================================  
int main() {
	ofAppGLFWWindow window;
	window.setMultiDisplayFullscreen(true);
	ofSetupOpenGL(&window, 1024, 768, OF_WINDOW); 			// <-------- setup the GL context  
	ofRunApp(new ofApp);
}
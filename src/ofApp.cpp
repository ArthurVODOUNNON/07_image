#include "ofApp.h"

ofColor ofApp::filter(ofColor color, int effectP,float P) {
	float r = color.r;
	float g = color.g;
	float b = color.b;
	float luminance = 0.299f * r + 0.587f * g + 0.114f * b;
	if (effectP == 1) {
		ofColor inverseColor = ofColor(255 - r, 255 - g, 255 - b);
		return inverseColor;
	} else if (effectP == 2) {
		float gray = (r + g + b) / 3;
        ofColor greyColor=ofColor(gray, gray, gray);
		return greyColor;

	} else if (effectP == 3){

		ofColor greyColor = ofColor(luminance, luminance, luminance);
		return greyColor;
	} else if (effectP == 4) {
		float K = (P - 0.5f) * 256;
		int newR = ofClamp(r + K, 0, 255);
		int newG = ofClamp(g + K, 0, 255);
		int newB = ofClamp(b + K, 0, 255);
		ofColor brightnessColor = ofColor(newR, newG, newB);
		return brightnessColor;
	
     } else if (effectP == 5) {
		float k = P * 3;
		 int newR = ofClamp((r-128)*k + 128, 0, 255);
		 int newG = ofClamp((g-128)*k + 128, 0, 255);
		 int newB = ofClamp((b-128)*k + 128, 0, 255);
		 ofColor contrastColor = ofColor(newR, newG, newB);
		return contrastColor;
	 } else if (effectP == 6) {
		 int newR = ofClamp(0.393*r + 0.769*g + 0.189*b, 0, 255);
		 int newG = ofClamp(0.349 * r + 0.686 * g + 0.168 * b, 0, 255);
		 int newB = ofClamp(0.272 * r + 0.534 * g + 0.131 * b, 0, 255);
		 ofColor sepiaColor = ofColor(newR, newG, newB);
		 return sepiaColor;
		
	 }
	 else
	{
		 return color;
	 }
	
}

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowShape(639,342);
	bool loadingOk = imgSource.load("pandaroux.jpg");
	if (!loadingOk) {
		ofLogError() << "Image trouvée!";
	}
	imgResult.allocate(imgSource.getWidth(), imgSource.getHeight(), OF_IMAGE_COLOR);
}

//--------------------------------------------------------------
void ofApp::update(){
	/*
	int px = ofClamp(mouseX, 0, imgSource.getWidth() - 1);
	int py = ofClamp(mouseY, 0, imgSource.getHeight() - 1);
	currentColor = imgSource.getColor(px, py);
	*/

	float power = mouseX/ (float)ofGetWidth();
	for (int y = 0; y < imgSource.getHeight(); y++) {
		for (int x = 0; x < imgSource.getWidth(); x++) {
			ofColor transfereColor = imgSource.getColor(x, y);
			ofColor modifiedColor = filter(transfereColor, effect, power);
			imgResult.setColor(x, y, modifiedColor);
		}
	}
	imgResult.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255,255,255);
	imgSource.draw(0, 0);
	ofSetColor(currentColor);
	ofDrawRectangle(mouseX+10 ,mouseY+10, 50, 50);
	imgResult.draw(0,0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == OF_KEY_RIGHT) {
		effect++;
		effect = (effect+numberEffect) % numberEffect;
	}
	if (key == OF_KEY_LEFT) {
		effect--;
		effect = (effect+numberEffect) % numberEffect;
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

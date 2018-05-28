#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(39);
	ofSetWindowTitle("Insta");

	ofNoFill();
	ofSetLineWidth(2);
	ofSetColor(239);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);

	int deg_span = 3;
	for (int i = 0; i < 8; i++) {
		
		ofRotate(45);
		for (int start_deg = 0; start_deg < 180; start_deg += deg_span) {

			float noise_value = ofNoise(start_deg * 0.05 + ofGetFrameNum() * 0.03);
			if (noise_value < 0.65) {

				continue;
			}

			int end_deg = start_deg + deg_span;

			vector<ofPoint> vertices;
			for (int deg = start_deg; deg <= end_deg; deg += 1) {

				vertices.push_back(ofPoint(300 * cos(deg * DEG_TO_RAD), 300 * sin(deg * DEG_TO_RAD)));
			}

			for (int deg = 360 - end_deg; deg <= 360 - start_deg; deg += 1) {

				vertices.push_back(ofPoint(300 * cos(deg * DEG_TO_RAD), 300 * sin(deg * DEG_TO_RAD)));
			}

			ofBeginShape();
			ofVertices(vertices);
			ofEndShape(true);
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}
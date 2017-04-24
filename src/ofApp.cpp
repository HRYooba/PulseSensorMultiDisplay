#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    for (int i = 0; i < PLAYER_COUNT; i ++) {
        serial[i].setup("/dev/cu.usbmodem142" + ofToString(i + 1) + "1", 115200);
        serial[i].startContinuousRead();
        ofAddListener(serial[i].NEW_MESSAGE,this,&ofApp::onNewMessage);
    }
    
    countFont.load("/System/Library/Fonts/Avenir Next.ttc", 100, true, true);
    countFont.setLetterSpacing(0.9);
    
    ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::onNewMessage(string &message) {
           cout << "onNewMessage, message: " << message << "\n";
    
    vector<string> input = ofSplitString(message, ",");
    
    if (input.size() < 2) {
        cout << "Error : input.size() < 2" << endl;
        return;
    }
    
    switch (ofToInt(input[0])) {
        case 0:
            BPM[0] = ofToInt(input[1]);
            break;
        case 1:
            BPM[1] = ofToInt(input[1]);
            break;
        case 2:
            BPM[2] = ofToInt(input[1]);
            break;
        case 3:
            BPM[3] = ofToInt(input[1]);
            break;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    float w = ofGetWidth() / 2;
    float h = ofGetHeight() / 2;
    ofSetColor(194, 73, 103);
    ofDrawRectangle(0, 0, w, h);
    ofSetColor(76, 159, 235);
    ofDrawRectangle(w, 0, w, h);
    ofSetColor(230, 180, 90);
    ofDrawRectangle(0, h, w, h);
    ofSetColor(87, 190, 56);
    ofDrawRectangle(w, h, w, h);
    
    ofSetColor(255);
    string bpm0 = ofToString(BPM[0]);
    countFont.drawString(bpm0, (w - countFont.stringWidth(bpm0)) / 2, (h + countFont.stringHeight(bpm0)) / 2);
    string bpm1 = ofToString(BPM[1]);
    countFont.drawString(bpm1, (w - countFont.stringWidth(bpm1)) / 2 + w, (h + countFont.stringHeight(bpm1)) / 2);
    string bpm2 = ofToString(BPM[2]);
    countFont.drawString(bpm2, (w - countFont.stringWidth(bpm2)) / 2, (h + countFont.stringHeight(bpm2)) / 2 + h);
    string bpm3 = ofToString(BPM[3]);
    countFont.drawString(bpm3, (w - countFont.stringWidth(bpm3)) / 2 + w, (h + countFont.stringHeight(bpm3)) / 2 + h);
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

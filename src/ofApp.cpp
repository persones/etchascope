#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSoundStreamSetup(2, 2, 44100, bufferSize, 4);
  vizBuf = new float[2 * bufferSize];
  
  
  lines.push_back(Line(ofPoint(-0.5, -0.5), ofPoint(0.5, -0.5)));
  lines.push_back(Line(ofPoint(0.5, -0.5), ofPoint(0.5, 0.5)));
  lines.push_back(Line(ofPoint(0.5, 0.5), ofPoint(-0.5, 0.5)));
  lines.push_back(Line(ofPoint(-0.5, 0.5), ofPoint(-0.5, -0.5)));
  
  points.push_back(ofPoint(-0.75, -0.75));
  points.push_back(ofPoint(0.75, -0.75));
  points.push_back(ofPoint(-0.75, 0.75));
  points.push_back(ofPoint(0.75, 0.75));
  
                  
}

void ofApp::audioOut(float * output, int bufferSize, int nChannels) {

  float samplesPerElements = bufferSize / (points.size() + lines.size());
  float lineSamples = samplesPerElements * lines.size();

  vector<ofPoint>::iterator currentPoint = points.begin();
  int sampleInPoint = 0;
  
  for (int i = 0; i < lineSamples; ++i) {
    vizBuf [i * 2] = output[i * 2] = currentPoint->x;
    vizBuf [i * 2 + 1] = output[i * 2 + 1] = currentPoint->y;
    if (sampleInPoint++ > samplesPerElements) {
      currentPoint++;
      sampleInPoint = 0;
    }
  }
  
  int lineIndex = 0;
  int sampleInLine = 0;
  
  vector<Line>::iterator currentLine = lines.begin();
  float lineFrac;
  ofPoint pointOnLine;
  
  for (int i = lineSamples; i < bufferSize; ++i) {
    lineFrac = sampleInLine++ / samplesPerElements;
    pointOnLine = currentLine->get(lineFrac);
    vizBuf [i * 2] = output[i * 2] = pointOnLine.x;
    vizBuf [i * 2 + 1] = output[i * 2 + 1] = pointOnLine.y;
    if (sampleInLine > samplesPerElements) {
      currentLine++;
      sampleInLine = 0;
    }
  }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
  ofSetColor(ofColor::black);
  ofDrawRectangle(0, 0, 500, 500);
  ofSetColor(ofColor::green);
  for (int i = 0; i < bufferSize; ++i ) {
    ofDrawCircle(vizBuf[i * 2] * 250 + 250, vizBuf[i * 2 + 1] * 250 + 250, 1);
    
  }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
//
//  line.cpp
//  scope
//
//  Created by Eyal Shahar on 9/29/17.
//
//

#include "line.h"
#include "ofApp.h"

Line::Line(ofPoint _a, ofPoint _b) {
  a = _a;
  b = _b;
}

ofPoint Line::get(float f) {
  return ofPoint(ofLerp(a.x, b.x, f), ofLerp(a.y, b.y, f));
}

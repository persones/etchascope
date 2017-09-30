//
//  line.hpp
//  scope
//
//  Created by Eyal Shahar on 9/29/17.
//
//

#ifndef line_h
#define line_h

#include <stdio.h>
#include "ofPoint.h"

class Line {
public:
  Line(ofPoint _a, ofPoint _b);
  ofPoint get(float f);
private:
  ofPoint a;
  ofPoint b;
  
};
#endif /* line_hpp */

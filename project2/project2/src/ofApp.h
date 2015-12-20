#pragma once

#include "ofMain.h"
#include "CirclesWoman.h"
#include "SquigglyLine.h"
#include "LittleSquares.h"
#include "bigCirclesDress.h"
#include "spiral.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    vector <CirclesWoman> smallCircles;
    int numSmallCircles;
    int numLines;
    int numLittleSquares;
    int numBigCirclesDress;
    int numSpirals;
    vector <ofColor> colors;
    vector <ofPoint> circlePositions;
    vector <ofPoint> circlePositionsBottom;
    vector <LittleSquares> dressSquares;
    vector <SquigglyLine> lines;
    vector <bigCirclesDress> bigCircles;
    vector <spiral> spirals;
    CirclesWoman tempCircle;
    ofImage greenCircle;
    ofImage arm;
    ofImage orangeBackground;
    ofImage heads;
    ofImage spiralBackground;
    ofImage background;
    ofImage man;
    Boolean grabbed;
    int thingGrabbed;
};

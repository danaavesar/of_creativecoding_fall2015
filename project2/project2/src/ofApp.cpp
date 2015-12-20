#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    numSmallCircles = 41; //11 purple, 7 blue, 5 top right, 11 sleave, 7 but, 14 bottom
    grabbed = false;
    
    
    ofColor purple (161, 99, 128);
    ofColor pink (214, 73, 89);  // 1 pink
    ofColor lightPink (147,131,17);  //2 light pink
    ofColor yellow (212,179,14);  //3 yellow
    ofColor black (44,53,71);  //4 middle black
    ofColor blue (47,96,137);//5 blue
    ofColor green (28,124,92);//6 green
    ofColor orange (228,95,79);//7 orange bottom circles
    ofColor moreYellow (204, 155, 82);
    ofColor orangeLighter (232,105,92);
    ofColor darkBlue (38,81,126);
    
    //purple circle positions 0-11
    circlePositions.push_back(ofPoint(436, 342)); //0
    circlePositions.push_back(ofPoint(446, 358)); //1
    circlePositions.push_back(ofPoint(438, 385)); //2
    circlePositions.push_back(ofPoint(414,352)); //3
    circlePositions.push_back(ofPoint(429, 369)); //4
    circlePositions.push_back(ofPoint(423, 385)); //5
    circlePositions.push_back(ofPoint(425, 395)); //6
    circlePositions.push_back(ofPoint(402,337)); //7
    circlePositions.push_back(ofPoint(403, 376)); //8
    circlePositions.push_back(ofPoint(389, 392)); //9
    circlePositions.push_back(ofPoint(381, 348)); //10
     circlePositions.push_back(ofPoint(382, 365)); //11

    
    for(int i=0; i<11; i++){
       CirclesWoman tempCircle;
        smallCircles.push_back(tempCircle);
    }
    int width = ofRandom(20,30);
    int height = ofRandom(10,20);
    
    smallCircles[1].setup(width, height, pink, lightPink, black, circlePositions[1]);
    smallCircles[2].setup(width, height, purple, yellow, black, circlePositions[2]);
    smallCircles[3].setup(width, height, yellow, pink, black, circlePositions[3]);
    smallCircles[4].setup(width, height, pink, lightPink, black, circlePositions[4]);
    smallCircles[5].setup(width, height, purple, yellow, black, circlePositions[5]);
    smallCircles[6].setup(width, height, yellow, lightPink, black, circlePositions[6]);
    smallCircles[7].setup(width, height, pink, yellow, yellow, circlePositions[7]);
    smallCircles[8].setup(width, height, pink, yellow, black, circlePositions[8]);
    smallCircles[9].setup(width, height, blue, green, green, circlePositions[9]);
    smallCircles[10].setup(width, height, pink, purple, black, circlePositions[10]);
    smallCircles[11].setup(width, height, purple, yellow, black, circlePositions[11]);
    
    //blue circles
    for(int i=11; i<19; i++){
        CirclesWoman tempBlueCircle;
        tempBlueCircle.randomSetup("blue");
         smallCircles.push_back(tempBlueCircle);
        
    }
    //        setup(int _width, int _height, ofColor color1, ofColor color2, ofColor color3 , ofPoint _position)
    
    for(int i=19; i<26; i++){
        CirclesWoman tempButtCircle;
        tempButtCircle.randomSetup("butt");
        smallCircles.push_back(tempButtCircle);
        
    }
    
    for(int i=26; i<41; i++){
        CirclesWoman tempBottomCircle;
        smallCircles.push_back(tempBottomCircle);
    }
    
    smallCircles[26].setup(13.33, 9.33, orange, moreYellow, moreYellow, ofPoint(447,727));
    smallCircles[27].setup(17.33, 18.833, orange, moreYellow, moreYellow, ofPoint(447,738.5));
    smallCircles[28].setup(17.33, 15.75, orange, moreYellow, green, ofPoint(450,753));
    smallCircles[29].setup(16, 11.875, orange, moreYellow, moreYellow, ofPoint(442,769));
    smallCircles[30].setup(17.33, 14.542, orange, moreYellow, green, ofPoint(429,722));
    smallCircles[31].setup(18.267, 14.751, orange, moreYellow, moreYellow, ofPoint(430,733));
    smallCircles[32].setup(24.99, 18.17, orange, orangeLighter, black, ofPoint(430,748));
    smallCircles[33].setup(19.313, 15.34, darkBlue, darkBlue, black, ofPoint(418,762.566));
    smallCircles[34].setup(18.3, 13.602, orange, moreYellow, moreYellow, ofPoint(415.33,720));
    smallCircles[35].setup(23.54, 16.605, orange, orangeLighter, black, ofPoint(408,736));
    smallCircles[36].setup(22, 14, darkBlue, darkBlue, black, ofPoint(389,722));
    smallCircles[37].setup(21, 14, orange, yellow, yellow, ofPoint(385,740));
    smallCircles[38].setup(21, 14, orange, orangeLighter, black, ofPoint(395,750));
    smallCircles[39].setup(21, 18, orange, moreYellow, moreYellow, ofPoint(382,763));
    smallCircles[40].setup(21, 17, orange, moreYellow, moreYellow, ofPoint(404,765));

    
//<-------------- squiggly lines dress ---------------->
    numLines = 30;
    int startingX = 332;
    int endingX = 500;
    int interval = (endingX-startingX)/numLines;
    for(int i=0; i<numLines; i++){
        SquigglyLine tempSquiggle;
        tempSquiggle.setup(startingX + interval*i);
        lines.push_back(tempSquiggle);
    }
    
//<-------------- images ---------------->
    arm.loadImage("arm.png");
    greenCircle.loadImage("green_circle.png");
    orangeBackground.loadImage("orange_background.jpg");
    heads.loadImage("heads.png");
    spiralBackground.loadImage("under_spirals.png");
    background.loadImage("background.jpg");
    man.loadImage("man.png");
    
//<-------------- little squares dress ---------------->
    numLittleSquares = 120;
    for(int i=0; i<numLittleSquares; i++){
        LittleSquares tempSquare;
        tempSquare.setup();
        dressSquares.push_back(tempSquare);
    }
//<-------------- big circles dress ---------------->
    numBigCirclesDress = 10;
//    for(int i=0; i<numBigCirclesDress; i++){
//        bigCirclesDress tempBigCircle;
//        tempBigCircle.setup();
//        bigCircles.push_back(tempBigCircle);
//        
//        
//    }
//
    for(int i=0; i<numBigCirclesDress; i++){
        bigCirclesDress tempBigCircle;
        bigCircles.push_back(tempBigCircle);
    }

    bigCircles[0].setupFixed(ofPoint(411,488),22,16);
    bigCircles[1].setupFixed(ofPoint(412,637),20,16);
    bigCircles[2].setupFixed(ofPoint(457,330),22,14);
    bigCircles[3].setupFixed(ofPoint(417,543),21,15);
    bigCircles[4].setupFixed(ofPoint(342,500),18,11);
    bigCircles[5].setupFixed(ofPoint(377,519),18,13);
    bigCircles[6].setupFixed(ofPoint(449,548),22,16);
    bigCircles[7].setupFixed(ofPoint(388,590),21,15);
    bigCircles[8].setupFixed(ofPoint(392,649),15,11);
    bigCircles[9].setupFixed(ofPoint(465,726),19,15);
    
    //<-------------- spirals ---------------->
    numSpirals = 12;
    
    for(int i=0; i<numSpirals; i++){
        spiral tempSpiral;
        spirals.push_back(tempSpiral);
        //spirals[i].setupRandom();
    }
    
    spirals[0].setup(ofPoint(495,373), 35,35, 4);
    spirals[1].setup(ofPoint(537,355), 52,52, 4);
    spirals[2].setup(ofPoint(560, 506), 40, 38, 4);
    spirals[3].setup(ofPoint(499, 473), 60, 55, 5);
    spirals[4].setup(ofPoint(520, 438), 35, 32, 4);
    spirals[5].setup(ofPoint(553, 414), 29, 29, 3);
    spirals[6].setup(ofPoint(483, 598), 50, 45, 4);
    spirals[7].setup(ofPoint(540, 619), 40, 35, 4);
     spirals[8].setup(ofPoint(595, 554), 34, 32, 3);
     spirals[9].setup(ofPoint(479, 414), 45, 40, 4);
     spirals[10].setup(ofPoint(534, 537), 54, 44, 6);
     spirals[11].setup(ofPoint(490, 530), 36, 31, 4);
//    int posX = 495;
//    float radius = 35;
//    for(var i=0; i<numSpirals; i++){
//        if(posX < 650){
//            posX += numSpirals[i-1].radius/2
//        }
//        spirals[i].setup(ofPoint());
//    }
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i=0; i<numLines; i++){
        lines[i].update(mouseX, mouseY);
    }
    for(int i=0; i<numLittleSquares; i++){
        dressSquares[i].update(ofGetMouseX(), ofGetMouseY());
    }
    
    for(int i=0; i<numSpirals; i++){
        spirals[i].update(mouseX, mouseY);
    }
    
        if(grabbed){
            smallCircles[thingGrabbed].position.x = mouseX;
            smallCircles[thingGrabbed].position.y = mouseY;
        }
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(235, 180, 68);
    ofSetColor(255);
    background.draw(-165, -8);
    ofSetColor(255);
    orangeBackground.draw(273,221);
    
 
   
    for(int i=0; i<numLines; i++){
        lines[i].draw();
    }
    for(int i=0; i<numLittleSquares; i++){
        dressSquares[i].draw();
    }
    //image of green circle on dress
    ofSetColor(255);
    ofEnableAlphaBlending();
    greenCircle.draw(376.496,333);

    for(int i=0; i<numSmallCircles; i++){
        smallCircles[i].draw();
    }
    for(int i=0; i<numBigCirclesDress; i++){
        //check to see if they have overlapped
        bigCircles[i].draw();
    }
        ofBeginShape();
        ofVertex(132,213);
        ofBezierVertex(132,213,137,172,137,163);
        ofBezierVertex(136,154,124,87,133,73);
        ofBezierVertex(142,58,159,27,166,26);
        ofBezierVertex(174,24,180,22,183,20);
        ofBezierVertex(186,18,189,15,212,9);
        ofBezierVertex(236,3,261,-2,267,-3);
        ofBezierVertex(273,-3,294,-9,303,-9);
        ofBezierVertex(312,-9,364,-9,388,-8);
        ofBezierVertex(413,-7,450,0,462,5);
        ofBezierVertex(474,9,506,31,515,45);
        ofBezierVertex(524,58,534,67,536,75);
        ofBezierVertex(538,83,541,90,545,96);
        ofBezierVertex(549,102,555,133,555,133);
        ofBezierVertex(555,133,555,159,554,163);
        ofBezierVertex(554,167,544,195,540,207);
        ofBezierVertex(536,219,531,239,532,245);
        ofBezierVertex(534,251,543,295,550,311);
        ofBezierVertex(558,327,572,369,576,373);
        ofBezierVertex(580,378,582,397,584,401);
        ofBezierVertex(585,406,594,451,594,457);
        ofBezierVertex(594,464,592,488,592,495);
        ofBezierVertex(593,501,597,527,603,537);
        ofBezierVertex(609,546,616,564,616,568);
        ofBezierVertex(616,572,613,583,622,593);
        ofBezierVertex(632,602,624,615,624,619);
        ofBezierVertex(625,623,631,635,629,641);
        ofBezierVertex(627,648,618,662,618,668);
        ofBezierVertex(618,674,625,692,632,700);
        ofBezierVertex(638,708,637,739,637,739);
        ofBezierVertex(637,739,610,738,585,752);
        ofBezierVertex(559,765,531,789,516,794);
        ofBezierVertex(501,798,490,792,486,798);
        ofBezierVertex(481,804,462,824,451,830);
        ofBezierVertex(441,836,361,858,352,855);
        ofBezierVertex(343,852,321,860,306,861);
        ofBezierVertex(291,863,264,870,250,863);
        ofBezierVertex(237,855,229,849,220,849);
        ofBezierVertex(211,849,190,849,183,840);
        ofBezierVertex(175,831,168,797,166,788);
        ofBezierVertex(165,779,145,734,145,720);
        ofBezierVertex(145,707,138,687,138,677);
        ofBezierVertex(138,666,133,659,133,648);
        ofBezierVertex(133,638,130,620,130,620);
        ofBezierVertex(130,620,131,599,131,594);
        ofBezierVertex(130,589,126,571,126,565);
        ofBezierVertex(126,560,127,544,127,544);
        ofBezierVertex(127,544,123,528,123,523);
        ofBezierVertex(123,517,125,481,125,470);
        ofBezierVertex(125,459,118,406,119,386);
        ofBezierVertex(121,365,127,246,127,238);
        ofBezierVertex(128,230,132,213,132,213);

        
        ofNextContour(true);
        //beginning point
        ofFill();
   
        ofVertex(471,309);
        ofBezierVertex(471,309,435,309,412,309);
        ofBezierVertex(389,309,334,298,334,298);
        ofBezierVertex(334,298,328,314,325,330);
        ofBezierVertex(322,346,333,372,333,387);
        ofBezierVertex(333,402,331,416,331,426);
        ofBezierVertex(331,436,350,493,358,510);
        ofBezierVertex(366,527,381,560,385,568);
        ofBezierVertex(389,576,381,613,381,627);
        ofBezierVertex(381,641,398,662,400,675);
        ofBezierVertex(402,688,386,739,382,753);
        ofBezierVertex(378,767,380,798,380,798);
        ofVertex(472,796);
        ofBezierVertex(472,796,472,752,473,740);
        ofBezierVertex(474,728,460,681,455,673);
        ofBezierVertex(450,665,446,652,446,644);
        ofBezierVertex(446,636,464,598,466,587);
        ofBezierVertex(468,576,463,548,459,536);
        ofBezierVertex(455,524,448,496,450,487);
        ofBezierVertex(452,478,472,382,475,366);
        ofBezierVertex(478,350,475,309,475,309);
        ofVertex(471,309);
        ofEndShape();

      
    //image of arm
    ofSetColor(255);
    ofEnableAlphaBlending();
    arm.draw(329, 274);
    //image of under spirals
    ofSetColor(255);
    ofEnableAlphaBlending();
    spiralBackground.draw(424,203,291, 820);
    
    //heads image
    ofSetColor(255);
    heads.draw(210,-5);
    
    //spiral
    for(int i=0; i<numSpirals; i++){
        spirals[i].draw();
    }
    
//    ofPushMatrix();
//    ofTranslate(100,300,0);
//    ofSetHexColor(0xff2220);
//    ofFill();
//    ofSetPolyMode(OF_POLY_WINDING_ODD);
//    ofBeginShape();
//    float angleStep 	= TWO_PI/(100.0f + sin(ofGetElapsedTimef()/5.0f) * 60);
//    float radiusAdder 	= 0.5f;
//    float radius 		= 0;
//    for (int i = 0; i < 200; i++){
//        float anglef = (i) * angleStep;
//        float x = radius * cos(anglef);
//        float y = radius * sin(anglef);
//        ofVertex(x,y);
//        radius 	+= radiusAdder;
//    }
//    ofEndShape();
//    ofPopMatrix();
 
// guy image
    ofSetColor(255);
    ofEnableAlphaBlending();
    man.draw(-165, -8);
    
   
    
    
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
    for(int i=0; i<numSpirals; i++){
        spirals[i].mouseDragged(x, y);
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
        if(!grabbed){
    
            for(int i=0; i< numSmallCircles; i++){
    
                int minX = (smallCircles[i].position.x - smallCircles[i].width/2);
    
                int maxX = (smallCircles[i].position.x + smallCircles[i].width/2);
    
                int minY = (smallCircles[i].position.y - smallCircles[i].height/2);
    
                int maxY = (smallCircles[i].position.y + smallCircles[i].height/2);
    
    
    
                //if my mouse is on a thing when I click it
    
                if (mouseX >= minX && mouseX <= maxX && mouseY >= minY && mouseY <= maxY) {
    
                    //I've grabbed a thing!
    
                    grabbed= true;
    
                    thingGrabbed = i;
    
                    cout << "I grabbed thing [";
    
                    cout << thingGrabbed;
    
                    cout << "]";
    
                }
    
            }
    
        }
    

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    //when you release your mouse, set haveIgrabbed a thing back to false, so that you don't keep moving the thing
    grabbed = false;
    cout << "thing [";
    cout << thingGrabbed;
    cout << "] released!" << endl;
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

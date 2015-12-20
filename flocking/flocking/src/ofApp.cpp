#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    numBirds = 100;
    //create all my birds
    for(int i=0; i<numBirds; i++){
        Bird tempBird; //create a temporary bird
        tempBird.setup(); //give it life
        myBirds.push_back(tempBird); //stick it in the vector
    } //tempBird is no more
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i=0; i<myBirds.size(); i++){//loop through every bird
        ofPoint tempAcc; //create a temporary acceleration, and 3 sub accelerations that will soon be calculated and added to the
        ofPoint a1 = accTowardsCenterOfMass(i);
        ofPoint a2 = accAwayFromNearbyBirds(i);
        ofPoint a3 = accInDirectionOfNearbyBirdMovement(i);
        //A1 = the bird wanting to move towards the middle of all other birds
        //A2 = the bird wanting to move away from fellow birds that are too close
        //A3 = birds wanting to move the same speed as nearby friends
        tempAcc = a1 + a2 + a3;//A = A1+A2+A3 ...  find my total influence of sub-intentions
        myBirds[i].acc = tempAcc; //myBirds.acc = A
    }
    
    
    
        
    for(int i=0; i<myBirds.size(); i++){
        myBirds[i].update();
    } //tempBird is no more
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i=0; i<myBirds.size(); i++){
        myBirds[i].draw();
    } //tempBird is no more

}


//--------------------------------------------------------------
ofPoint ofApp:: accTowardsCenterOfMass(int birdNumber){
    ofPoint myValue;
    //find center of position of all other birds, not including ourself
    //create a normalized vector that is the difference between our position and the center position
    ofPoint megaPosition = ofPoint(0,0,0);
    for(int i=0; i<myBirds.size(); i++){
        if(i != birdNumber){
            megaPosition += myBirds[i].pos; //add all the positions together into megaPosition
        }

    }
    megaPosition = megaPosition/(myBirds.size()- 1); //then divideMegaPosition by birds.size -1
    
    //myValue is the difference between current birds position and megaPosition
    myValue = megaPosition - myBirds[birdNumber].pos; //so its the difference between the current bird and the mass
    myValue = myValue.normalize();
    
    cout << "megaPosition :" ;
    cout << megaPosition << endl;
    
    return myValue;
}
//--------------------------------------------------------------
ofPoint ofApp:: accAwayFromNearbyBirds(int birdNumber){
    ofPoint myValue;
    
    
    return ofPoint(0,0,0);
}
//--------------------------------------------------------------
ofPoint ofApp:: accInDirectionOfNearbyBirdMovement(int birdNumber){
    ofPoint myValue;
    
    return ofPoint(0,0,0);
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

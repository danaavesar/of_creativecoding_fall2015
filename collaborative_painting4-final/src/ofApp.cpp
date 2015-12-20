#include "ofApp.h"
//INK SIM INCLUDES
#include "ofxInkSim.h"
#include "ofxInkSim.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetLogLevel(OF_LOG_VERBOSE);
    
    // enable depth->video image calibration
    kinect.setRegistration(true);
    
    kinect.init();
    //kinect.init(true); // shows infrared instead of RGB video image
    //kinect.init(false, false); // disable video image (faster fps)
    
    kinect.open();		// opens first available kinect
    //kinect.open(1);	// open a kinect by id, starting with 0 (sorted by serial # lexicographically))
    //kinect.open("A00362A08602047A");	// open a kinect using it's unique serial #
    
    // print the intrinsic IR sensor values
    if(kinect.isConnected()) {
        ofLogNotice() << "sensor-emitter dist: " << kinect.getSensorEmitterDistance() << "cm";
        ofLogNotice() << "sensor-camera dist:  " << kinect.getSensorCameraDistance() << "cm";
        ofLogNotice() << "zero plane pixel size: " << kinect.getZeroPlanePixelSize() << "mm";
        ofLogNotice() << "zero plane dist: " << kinect.getZeroPlaneDistance() << "mm";
    }
    
    
    colorImg.allocate(kinect.width, kinect.height);
    grayImage.allocate(kinect.width, kinect.height); //white closest and black farther away
    grayThreshNear.allocate(kinect.width, kinect.height);
    grayThreshFar.allocate(kinect.width, kinect.height);
    
    nearThreshold = 230;
    farThreshold = 132;
    bThreshWithOpenCV = true;
    
    ofSetFrameRate(60);
    
    // zero the tilt on startup
    angle = 18;
    kinect.setCameraTiltAngle(angle);
    
    // start from the front
    bDrawPointCloud = false;
    
    timeOfLastImportantMomemt = 0;
    posed = false;
    check = true;
    
    //-----INK STUFF
    //    inkSim.setup();
    //    gui.setup(inkSim.getUniformInfo());
    //     moodmachine.setSpeed(1.0);
    //-----INK FILL STUFF
    inkSim.setup();
    inkSim.setDrawMode(ofxInkSim::INKFIX);
    gui.setup(inkSim.getUniformInfo());
    
    fbo.allocate(ofGetWidth(), ofGetHeight());
    
    ofSetWindowTitle("first window");
    
    // the arguments for the second window are its initial x and y position,
    // and its width and height. the last argument is whether the window
    // should be undecorated, i.e. title bar is visible. setting it to
    // true removes the title bar.
    
    secondWindow.setup("second window", 50, 50, 1024, 768, false);
    
    
    
}

//--------------------------------------------------------------
void ofApp::update() {
    
    ofBackground(100, 100, 100);
    
    kinect.update();
    
    // there is a new frame and we are connected
    if(kinect.isFrameNew()) {
        
        // load grayscale depth image from the kinect source
        grayImage.setFromPixels(kinect.getDepthPixels(), kinect.width, kinect.height);
        
        // we do two thresholds - one for the far plane and one for the near plane
        // we then do a cvAnd to get the pixels which are a union of the two thresholds
        if(bThreshWithOpenCV) {
            grayThreshNear = grayImage;
            grayThreshFar = grayImage;
            grayThreshNear.threshold(nearThreshold, true);
            grayThreshFar.threshold(farThreshold);
            cvAnd(grayThreshNear.getCvImage(), grayThreshFar.getCvImage(), grayImage.getCvImage(), NULL);
        } else {
            
            // or we do it ourselves - show people how they can work with the pixels
            unsigned char * pix = grayImage.getPixels();
            
            int numPixels = grayImage.getWidth() * grayImage.getHeight();
            for(int i = 0; i < numPixels; i++) {
                if(pix[i] < nearThreshold && pix[i] > farThreshold) {
                    pix[i] = 255;
                } else {
                    pix[i] = 0;
                }
            }
        }
        
        // update the cv images
        grayImage.flagImageChanged();
        
        // find contours which are between the size of 20 pixels and 1/3 the w*h pixels.
        // also, find holes is set to true so we will get interior contours as well....
        contourFinder.findContours(grayImage, 5000, (kinect.width*kinect.height)/3, 20,false);
        // (kinect.width*kinect.height)/2  = 153600
        
        
        bool pose = contourFinder.checkForChange();
        if(pose){
            cout << "pose" <<endl;
            posed = true;
            //                check = false; //then wait a little before you check again
            fillPoints();
            
        }
        
        
        if(ofGetElapsedTimeMillis() - timeOfLastImportantMomemt > 30000){
            contourFinder.poses.clear();
            inkSim.clear();
            timeOfLastImportantMomemt = ofGetElapsedTimeMillis();
        }
        
        
        
        
    }
    //
    if(posed){
        //----INK STUFF
        //        inkSim.update();
        //-----INK FILL STUFF
        inkSim.update();
    }
    
    
    
    
    
}
//--------------------------------------------------------------
void drawWithNormals(const ofPolyline& polyline) {
    for(int i=0; i< (int) polyline.size(); i++ ) {
        //        ofPoint firstPoint = polyline[i];
        //        ofPolyline.curveTo(polyline[i]);
        //        bool repeatNext = i == (int)polyline.size() - 1;
        //
        //        const ofPoint& cur = polyline[i];
        //        const ofPoint& next = repeatNext ? polyline[0] : polyline[i + 1];
        //
        //        float angle = atan2f(next.y - cur.y, next.x - cur.x) * RAD_TO_DEG;
        //        float distance = cur.distance(next);
        //
        //        if(repeatNext) {
        //            ofSetColor(255, 0, 255);
        //        }
        //        glPushMatrix();
        //        glTranslatef(cur.x, cur.y, 0);
        //        ofRotate(angle);
        //        ofLine(0, 0, 0, distance);
        //        ofLine(0, 0, distance, 0);
        //        glPopMatrix();
    }
}


//--------------------------------------------------------------
void ofApp::draw() {
    
    ofSetColor(255, 255, 255);
    
    if(bDrawPointCloud) {
        easyCam.begin();
        drawPointCloud();
        easyCam.end();
    } else {
        // draw from the live kinect
        //        kinect.drawDepth(10, 10, 400, 300);
        //        kinect.draw(420, 10, 400, 300);
        //
        
        
        
        
        if(posed){
            
            // --INK STUFF
            //            inkSim.draw();
            //             gui.draw();
            
            // --INK FILL STUFF
            ofPushMatrix();
            
            ofScale(2.0,2.0);
            ofTranslate(-10,-38);
            inkSim.draw();
            ofPopMatrix();
            
//            gui.draw();
            
//            ofDrawBitmapStringHighlight("press 'f' or 't' to fill buffer", 10, ofGetHeight() - 60);
//            ofDrawBitmapStringHighlight("press 'c' to clear buffer", 10, ofGetHeight() - 40);
//            ofDrawBitmapStringHighlight("press ' ' to hide gui", 10, ofGetHeight() - 20);
            
            //--REGULAR SHAPES
            
            ofFill();
            
            //            for( int i=0; i<(int)contourFinder.poses.size(); i++ ) {
            //                for( int j=0; j< contourFinder.poses[i].nPts; j++ ) {
            //                    int x = contourFinder.poses[i].pts[j].x;
            //                    int y =contourFinder.poses[i].pts[j].y;
            //
            //                    path->lineTo(x,y,0, ofFloatColor(0), ofGetFrameNum(), 0);
            //                }
            //            }
            
            for( int i=0; i<(int)contourFinder.poses.size(); i++ ) {
                //                int Rcolor = 235 - i*2;
                //                int Gcolor = 76;
                //                int Bcolor = 89;
                //                ofSetColor(Rcolor, Gcolor, Bcolor);
                ofPushMatrix();
                
                ofScale(2.0,2.0);
                ofTranslate(-10,-38);
                /* ofBeginShape();
                 
                 //                ofTranslate(<#float x#>, <#float y#>)
                 for( int j=0; j< contourFinder.poses[i].nPts; j++ ) {
                 ofVertex(  contourFinder.poses[i].pts[j].x,  contourFinder.poses[i].pts[j].y );
                 }
                 
                 ofEndShape();*/
                outline = ofPolyline(contourFinder.poses[i].pts);
                outlineSmooth = outline.getSmoothed(5,1);
                //                drawWithNormals(outlineSmooth);
                
                outlineSmooth.draw();
                
                ofPopMatrix();
            }
            
            
        }
        
        
     
        
        // draw the second window
        secondWindow.begin();
        ofBackground(255);
        grayImage.draw(10, 320, 400, 300);
           contourFinder.draw(10, 320, 400, 300);
        
        ofDrawBitmapString("this is the\nsecond window", 30, 65);
        gui.draw();
        secondWindow.end();
        
    }
    
    // draw instructions
    ofSetColor(255, 255, 255);
    stringstream reportStream;
    
    if(kinect.hasAccelControl()) {
        //        reportStream << "accel is: " << ofToString(kinect.getMksAccel().x, 2) << " / "
        //        << ofToString(kinect.getMksAccel().y, 2) << " / "
        //        << ofToString(kinect.getMksAccel().z, 2) << endl;
    } else {
        //        reportStream << "Note: this is a newer Xbox Kinect or Kinect For Windows device," << endl
        //        << "motor / led / accel controls are not currently supported" << endl << endl;
    }
    
    //    reportStream << "press p to switch between images and point cloud, rotate the point cloud with the mouse" << endl
    //    << "using opencv threshold = " << bThreshWithOpenCV <<" (press spacebar)" << endl
    //    << "set near threshold " << nearThreshold << " (press: + -)" << endl
    //    << "set far threshold " << farThreshold << " (press: < >) num blobs found " << contourFinder.nBlobs
    //    << ", fps: " << ofGetFrameRate() << endl
    //    << "press c to close the connection and o to open it again, connection is: " << kinect.isConnected() << endl;
    
    if(kinect.hasCamTiltControl()) {
        //        reportStream << "press UP and DOWN to change the tilt angle: " << angle << " degrees" << endl
        //        << "press 1-5 & 0 to change the led mode" << endl;
    }
    
    //    ofDrawBitmapString(reportStream.str(), 20, 652);
    
    
    
    
}

void ofApp::fillPoints() {
    //INK OUTLINE
    //    for(int i=0; i< contourFinder.newPoses.size(); i++){
    //        outline = ofPolyline(contourFinder.newPoses[i].pts);
    //        outlineSmooth = outline.getSmoothed(5,1);
    //        vector<ofPoint>vertices = outlineSmooth.getVertices();
    //        for(int i=0; i< vertices.size(); i++){
    //            float x = vertices[i].x;
    //            float y = vertices[i].y;
    //            mouseDragged(x, y,0 );
    //        }
    //
    //
    //         mouseReleased(0, 0, 0); //stop the stroke, the numbers dont matter
    //    }
    
    //INK FILL STUFF
    
    //
    //
    int angRange = ofRandom(100, 200);
    int angMin = ofRandom(260);
    
    fbo.begin();
    ofClear(0);
    
    int ang = ofRandom(angMin, angRange);
    if (ang > 360)
        ang -= 360;
    
    float depth = 255;//ofMap(rad, 2, 10, 255, 200, true);
    ofColor c = getInkColor(ang, 255, depth);
    ofPushStyle();
    ofSetColor(c);
    for(int i=0; i< contourFinder.newPoses.size(); i++){
        if(i%2 == 0){
            outline = ofPolyline(contourFinder.newPoses[i].pts);
        }
        outlineSmooth = outline.getSmoothed(5,1);
        outlineSmooth.close();
        outlineSmooth.draw();
        
    }
    
    
    ofPopStyle();
    //
    
    fbo.end();
    inkSim.begin();
    fbo.draw(0, 0);
    inkSim.end();
    
}

void ofApp::drawPointCloud() {
    int w = 640;
    int h = 480;
    ofMesh mesh;
    mesh.setMode(OF_PRIMITIVE_POINTS);
    int step = 2;
    for(int y = 0; y < h; y += step) {
        for(int x = 0; x < w; x += step) {
            if(kinect.getDistanceAt(x, y) > 0) {
                mesh.addColor(kinect.getColorAt(x,y));
                mesh.addVertex(kinect.getWorldCoordinateAt(x, y));
            }
        }
    }
    glPointSize(3);
    ofPushMatrix();
    // the projected points are 'upside down' and 'backwards'
    ofScale(1, -1, -1);
    ofTranslate(0, 0, -1000); // center the points a bit
    ofEnableDepthTest();
    mesh.drawVertices();
    ofDisableDepthTest();
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::exit() {
    
    //
    //    kinect.setCameraTiltAngle(0); // zero the tilt on exit
    kinect.close();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed (int key) {
    switch (key) {
        case ' ':
            bThreshWithOpenCV = !bThreshWithOpenCV;
            break;
            
        case'p':
            bDrawPointCloud = !bDrawPointCloud;
            break;
            
        case '>':
        case '.':
            farThreshold ++;
            if (farThreshold > 255) farThreshold = 255;
            break;
            
        case '<':
        case ',':
            farThreshold --;
            if (farThreshold < 0) farThreshold = 0;
            break;
            
        case '+':
        case '=':
            nearThreshold ++;
            if (nearThreshold > 255) nearThreshold = 255;
            break;
            
        case '-':
            nearThreshold --;
            if (nearThreshold < 0) nearThreshold = 0;
            break;
            
        case 'w':
            kinect.enableDepthNearValueWhite(!kinect.isDepthNearValueWhite());
            break;
            
        case 'o':
            kinect.setCameraTiltAngle(angle); // go back to prev tilt
            kinect.open();
            break;
            
        case 'c':
            kinect.setCameraTiltAngle(0); // zero the tilt
            kinect.close();
            break;
            
        case '1':
            kinect.setLed(ofxKinect::LED_GREEN);
            break;
            
        case '2':
            kinect.setLed(ofxKinect::LED_YELLOW);
            break;
            
        case '3':
            kinect.setLed(ofxKinect::LED_RED);
            break;
            
        case '4':
            kinect.setLed(ofxKinect::LED_BLINK_GREEN);
            break;
            
        case '5':
            kinect.setLed(ofxKinect::LED_BLINK_YELLOW_RED);
            break;
            
        case '0':
            kinect.setLed(ofxKinect::LED_OFF);
            break;
            
        case OF_KEY_UP:
            angle++;
            if(angle>30) angle=30;
            kinect.setCameraTiltAngle(angle);
            break;
            
        case OF_KEY_DOWN:
            angle--;
            if(angle<-30) angle=-30;
            kinect.setCameraTiltAngle(angle);
            break;
    }
    
    //-----INK STUFF
    
    if (key == '1')
    {
        inkSim.setDrawMode(ofxInkSim::INKFIX);
    }
    else if (key == '2')
    {
        inkSim.setDrawMode(ofxInkSim::INKSURF);
    }
    else if (key == '3')
    {
        inkSim.setDrawMode(ofxInkSim::INKFLOW);
    }
    else if (key == '4')
    {
        inkSim.setDrawMode(ofxInkSim::WATERFLOW);
    }
    else if (key == 'd')
    {
        inkSim.toggleDebug();
    }
    else if (key == ' ')
    {
        gui.toggleVisible();
    }
    else if (key == 'r')
    {
        gui.resetToDefault();
    }
    else if (key == 'c')
    {
        inkSim.clear();
    }
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    cout << "mouseDragged initiated" << endl;
    //---INK STUFF
    ofColor c = moodmachine;
    inkSim.stroke(&brush, x, y, getInkColor(c.getHueAngle(), 255, 10));
    
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
    //INK STUFF
    inkSim.stopStroke(&brush);
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{}

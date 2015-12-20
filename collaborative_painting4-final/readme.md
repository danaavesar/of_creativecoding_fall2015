#Collaborative Painting 
##Make strokes with your body movement!

This uses ofxKinect and ofxOpenCv for the contour tracking. What I do is check if the bounding width on the "blobs" have changed severely between frames. If so that means the user has stuck a pose, and the contour of that pose gets pushed into another array. I then draw the contour by making it an ofPolyline and use ofxInkSim to make the watercolor strokes. 

This is using openFrameworks v0.8.0. The openCV files are edited and I included them in my upload. They should replace your own openCV files in your addons for this to work. 

Here are some pictures and the video is coming soon!

![Alternate text](IMG_20151217_21244.jpg)

![Alternate text](VID_20151217_212035.jpg)


![Alternate text](VID_20151217_230842.jpg)

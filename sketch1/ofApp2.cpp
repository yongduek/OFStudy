#include "ofApp.h"
#include "opencv2/opencv.hpp"

const int width=720;
const int height=480;
unsigned char ptr[width*height*3];

// Defined in $OF/graphics/ofImage.h
// typedef ofImage_<unsigned char> ofImage;
ofImage image;
ofImage bikersImage;

bool flag = true;
cv::Mat cvImg;
cv::Mat_<cv::Vec3b> cvImg_;
//--------------------------------------------------------------
void ofApp::setup(){
    image.setFromPixels (ptr, width, height, OF_IMAGE_COLOR);

    bikersImage.load("bikers.jpg"); // $project_folder/bin/data is the default folder
    if (bikersImage.isAllocated())
        cerr << "> image loaded: bikers.jpg" << endl;
    else
        cerr << "bikers.jpg not found." << endl;
    
    // following makes cvImg and bikersImage share the same memory of the image
    // see http://docs.opencv.org/3.1.0/d3/d63/classcv_1_1Mat.html
    cvImg = cv::Mat(bikersImage.getHeight(), // rows
                    bikersImage.getWidth(),  // cols
                    CV_8UC3,                 // type
                    bikersImage.getPixels().getData() // void *data
                    );
    cvImg_ = cv::Mat_<cv::Vec3b> ( cvImg );
}

//--------------------------------------------------------------
void ofApp::update(){
    ofBackground(255);
    
    if (flag) {
        cv::blur(cvImg, cvImg, cv::Size(10,10));
        flag = false;
    }
    
    for (int r=100; r<300; r++)
        for (int c=50; c<150; c++)
            cvImg_(r,c) = cv::Vec3b (255,0,0);
    
    // dont forget to update() if cvImg has been under an image processing.
    bikersImage.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    
    // you may see the valus in pixels, pixels2, pixels3 in debug window.
    
    ofPixels & pixels1 = image.getPixels(); // pixels is the reference to class ofImage { ofPixels pixels }
    unsigned char* pixels3 = image.getPixels(); // this is a depricated method. Don't use.
    unsigned char *pixels = image.getPixels().getData(); // pixels2 is the pointer to pixels in ofPixels defined in ofImage
    /*
     typedef ofPixels_<unsigned char> ofPixels;
     
     class ofPixels_ {
     ...
     /// \brief Retrieves pixel data from the ofPixel object.
     ///
     /// \returns A raw pointer to the pixel data.
     PixelType * getData();
     const PixelType * getData() const;
     }
     */
    
    for (int y=10; y<100; y++)
        for (int x=20; x<200; x++) {
            int index = 3*(y*width + x);
            unsigned char cur = pixels[index];
            pixels[index] = 0;
            pixels[index+1] = 0;
            pixels[index+2] = 255;
        }
    
    image.update(); // update the chage to the graphic output, otherwise the change will not be shown
    image.draw(0,0);
    
    bikersImage.draw(0,image.getHeight()+10);
}


#include "CppAcfDetect.h"

int main(int argc, char** argv) 
{
	Mat image;
   Detector d;

   //call to read the detector file
   d.readDetectorModel(DETECTOR_FILE);

   BoundingBox* bbs = d.acfDetect(image);

   return a.exec();
}
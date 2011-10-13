/*
 * =====================================================================================
 *
 *       Filename:  dcmtk.cpp
 *
 *    Description:  testing
 *
 *        Version:  1.0
 *        Created:  10/13/2011 15:18:14
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */


#include <dcmtk/config/osconfig.h>
#include <dcmtk/dcmimgle/dcmimage.h>
#include <iostream>

int main(int argc, const char *argv[])
{
    DicomImage *image = new DicomImage("~/Desktop/brain/brain_001.dcm") ;
    double min, max ;
    std::cout << DicomImage::getString(image->getStatus()) << std::endl ;
    image->getMinMaxValues(min, max) ;
    std::cout << "min value is: " << min << " max value is: " << max << std::endl ;
    /*  

    if (image->getStatus() == EIS_Normal) {
        Uint8 *pixelData = (Uint8 *)(image->getOutputData(8)) ;
        if (pixelData != NULL) {
            // do something
            image->getMinMaxValues(min, max) ;
        }
        else {
            std::cerr << "Error bitch" << std::endl ; 
        }
    }
    */
    return 0;
}

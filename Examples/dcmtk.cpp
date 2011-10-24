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
#include <dcmtk/dcmimage/diregist.h>
#include <iostream>

int main(int argc, const char *argv[])
{
    DicomImage *image = new DicomImage("~/Desktop/SciVis-Project/Examples/00001.dcm") ;
    double min, max ;

    if (image->getStatus() == EIS_Normal) {
        std::cout << "Success!" << std::endl ;
        }
    else {
        std::cerr << "Error bitch" << std::endl ; 
    }

    return 0;
}


#include <iostream>
#include <gdcm-2.0/gdcmImageReader.h>
#include <gdcm-2.0/gdcmReader.h>
#include <gdcm-2.0/gdcmFile.h>
#include <gdcm-2.0/gdcmImage.h>
#include <string>

using namespace gdcm ;

int main(int argc, const char *argv[])
{
    const std::string str = "~/Desktop/brain/brain_001.dcm" ;
    ImageReader reader ;
    reader.SetFileName(str.c_str()) ;
    Image &image = reader.GetImage() ;
    unsigned int ndim = image.GetNumberOfDimensions() ;
    std::cout << ndim << std::endl ;

    if(!reader.Read()) {
        std::cerr << "Error Bitch" << std::endl ;
        return 1 ;
    }
    return 0;
}

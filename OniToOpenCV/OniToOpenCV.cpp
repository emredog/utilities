//------------------------------------------------
// STL Header
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

// OpenNI Header
#include <ni/XnCppWrapper.h>

// OpenCV
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <stdlib.h>
/**
 * @brief Function similar to printf returning C++ style string
 * @param message
 * @return
 */
inline std::string printfstring(const char *message, ...)
{
    static char buf[8*1024];

    va_list va;
    va_start(va, message);
    vsprintf(buf, message, va);
    va_end(va);

    std::string str(buf);
    return str;
}

/// convert depth map to OpenCV
void xdepth2opencv(xn::DepthMetaData &xDepthMap, cv::Mat &im, int verbose=0)
{
    int h=xDepthMap.YRes();
    int w=xDepthMap.XRes();

    if (verbose)
        printf("xdepth2opencv: w %d, h %d\n", w, h);

    const cv::Mat tmp(h, w, CV_16U, ( void *)xDepthMap.Data());
    tmp.copyTo(im);

}

/// convert image map to OpenCV
void ximage2opencv(xn::ImageMetaData &xImageMap, cv::Mat &im, int verbose=0)
{
    int h=xImageMap.YRes();
    int w=xImageMap.XRes();

    if (verbose)
        printf("ximage2opencv: w %d, h %d\n", w, h);

    const XnRGB24Pixel * xx=xImageMap.RGB24Data();
    const cv::Mat tmp(h, w, CV_8UC3, ( void *)xx);
    tmp.copyTo(im);
}


int main( int argc, char** argv )
{
    int verbose=1;

    if( argc == 1 ) {
        cout << "Please give an ONI file to open" << std::endl;
        return 1;
    }

    std::string outputdir = "./";
    if (argc>2)
        outputdir = argv[2];

    // Initial OpenNI Context
    xn::Context xContext;
    xContext.Init();

    // open ONI file
    xn::Player xPlayer;
    xContext.OpenFileRecording( argv[1], xPlayer );
    xPlayer.SetRepeat( false );

    // Create depth generator
    xn::DepthGenerator xDepthGenerator;
    xDepthGenerator.Create( xContext );

    xn::ImageGenerator xImageGenerator;
    xImageGenerator.Create( xContext );
    xImageGenerator.SetPixelFormat(XN_PIXEL_FORMAT_RGB24 );

    // get total frame number
    XnUInt32 uFrames;
    xPlayer.GetNumFrames( xDepthGenerator.GetName(), uFrames );
    if (verbose)
        cout << "Total " << uFrames << " frames, outputdir " << outputdir << endl;

    // Start
    xContext.StartGeneratingAll();

    // main loop
    for( unsigned int i = 0; i < uFrames; ++ i )
    {
        xDepthGenerator.WaitAndUpdateData();
        xImageGenerator.WaitAndUpdateData();

        if (verbose && (i%10==0))
            cout << i << "/" << uFrames << endl;

        // get depth value
        xn::DepthMetaData xDepthMap;
        xDepthGenerator.GetMetaData( xDepthMap );

        cv::Mat dim;
        xdepth2opencv(xDepthMap, dim);
        std::string doutfile = outputdir + "/" +  printfstring("depth%06d.png", i);
        cv::imwrite(doutfile.c_str(), dim );

        // get image value
        xn::ImageMetaData xImageMap;
        xImageGenerator.GetMetaData( xImageMap );

        cv::Mat im;
        ximage2opencv(xImageMap, im);

        std::string outfile = outputdir + "/" + printfstring("image%06d.png", i);
        cv::imwrite(outfile.c_str(), im );
    }

    // stop
    xContext.StopGeneratingAll();

    // release resource
    xContext.Release();

    return 0;
}

//------------------------------------------------

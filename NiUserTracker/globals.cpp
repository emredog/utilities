#include "globals.h"

xn::Context* g_Context = new xn::Context();

XnBool g_bNeedPose = FALSE;
XnChar g_strPose[20] = "";
XnBool g_bDrawBackground = TRUE;
XnBool g_bDrawPixels = TRUE;
XnBool g_bDrawSkeleton = TRUE;
XnBool g_bPrintID = TRUE;
XnBool g_bPrintState = TRUE;

XnBool g_bPrintFrameID = FALSE;
XnBool g_bMarkJoints = FALSE;

//xn::DepthGenerator* getDepthGenerator()
//{
//    return g_DepthGenerator.IsValid() ? &g_DepthGenerator : NULL;
//}
//xn::ImageGenerator* getImageGenerator()
//{
//    return g_ImageGenerator.IsValid() ? &g_ImageGenerator : NULL;
//}
//xn::IRGenerator* getIRGenerator()
//{
//    return g_IRGenerator.IsValid() ? &g_IRGenerator : NULL;
//}

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>

#include <QDir>
#include <QFile>
#include <QString>

int main(int argc, char *argv[])
{

    float subtractMe = 3.3309495161 / -0.0030711016;

    if (argc != 2)
    {
        std::cout << "Usage: MetersToRawDepth <folder to process>\n";
        return -1;
    }

    QDir srcFolder(QString::fromStdString(argv[1]));
    if (!srcFolder.exists())
    {
        std::cout << "Invalid folder: " << argv[1]  << std::endl;
    }

    QStringList filters;
    filters << "depth000*.png";

    QStringList depthFiles = srcFolder.entryList(filters, QDir::Files | QDir::NoDotAndDotDot);

    int length = depthFiles.length();
    std::cout << "Found " << length << " images.\n";


    int counter = 0;
    foreach(QString depthFile, depthFiles)
    {
        counter++;

        if (counter % 10 == 0)
            std::cout << counter << " / " << length << std::endl;

        cv::Mat depth = cv::imread(srcFolder.absoluteFilePath(depthFile).toStdString(), CV_LOAD_IMAGE_UNCHANGED);
        cv::Mat temp;
        cv::Mat rawDepthMat(depth.rows, depth.cols, CV_16UC1);
        rawDepthMat = cv::Scalar(0);

        depth.convertTo(temp, CV_16UC1);
        depth.release();
        temp.assignTo(depth);
        temp.release();

        int channels = depth.channels();

        int nRows = depth.rows;
        int nCols = depth.cols * channels;

        if (depth.isContinuous())
        {
            nCols *= nRows;
            nRows = 1;
        }

        int i,j;


        unsigned short* pSource, *pTarget;



        for( i = 0; i < nRows; ++i)
        {
            pSource = depth.ptr<unsigned short>(i);
            pTarget = rawDepthMat.ptr<unsigned short>(i);
            for ( j = 0; j < nCols; ++j)
            {
                unsigned short depthInMM = pSource[j];
                float depthInM = float(depthInMM) / 1000.0;
                if( depthInM < 0.3002  ||  depthInM > 533.2248 )
                {
                    pTarget[j] = (unsigned short)2047;
                }
                else
                {
                    unsigned short rawDepth;
                    rawDepth = (unsigned short)round(((1.0 / (depthInM * -0.0030711016)) - subtractMe));
                    if (rawDepth > 0 && rawDepth < 2047)
                    {
                        pTarget[j] = rawDepth;
                    }
                }


            }
        }

        cv::imwrite(srcFolder.absoluteFilePath(QString("raw_%1").arg(depthFile)).toStdString(), rawDepthMat);

    }
}

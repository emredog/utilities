#include <QCoreApplication>
#include <QDir>
#include <QFile>
#include <iostream>
#include <QTextStream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDir folderToRename("/home/emredog/research-data/LIRIS-data/20141117_test_with_static_cam/KS/test_BOW_with_K-Means_s100K_k4000");
    QFile referenceFile("/home/emredog/research-data/LIRIS-data/20141117_test_with_static_cam/KS/ListOfStationaryTestTracklets.txt");

    QStringList filters; filters << "*.out.BoW";

    QStringList entryList = folderToRename.entryList(filters, QDir::Files | QDir::NoDotAndDotDot, QDir::Name);

    QTextStream txtStream(&referenceFile);

    if (!referenceFile.open(QFile::ReadOnly))
    {
        cout << "CAN'T OPEN FILE FOR READING: " << referenceFile.fileName().toStdString() << endl;
    }

    QStringList staticTracks;

    while (!txtStream.atEnd())
        staticTracks.append(txtStream.readLine());


    for (int i=0; i<entryList.length(); i++)
    {
        QString line = entryList[i]; //vid0002_1_discussion_1-41Union.track
        //line = line.left(line.length() - 11); //vid0002_1_discussion_1-41

        QString trackName = line.split(".").first();
        if (!staticTracks.contains(trackName))
        {
            QFile(folderToRename.absoluteFilePath(entryList[i])).remove();
//            QString newName = line.replace("(", "");
//            newName = newName.replace(")", "");

//            cout << "Renaming:\t" << entryList[i].toStdString() << endl
//                 << "into\t" << newName.toStdString() << endl << endl;

//            QFile::rename(folderToRename.absoluteFilePath(entryList[i]), folderToRename.absoluteFilePath(newName));
        }
//        else
//        {
//            QFile(folderToRename.absoluteFilePath(entryList[i])).remove();
//            cout << "Removed: " << entryList[i].toStdString();
//        }

        //
    }



    return a.exec();
}

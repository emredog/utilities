#include <QDir>
#include <QProcess>

#include <iostream>


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: ImageComparison <folder to parse>" << std::endl;
        return -1;
    }

    QDir detectionsFolder(QString::fromStdString(argv[1]));
    QDir outputFolder(QString("%1/%2").arg(QString::fromStdString(argv[1])).arg("/comparison"));

    if (!detectionsFolder.exists())
    {
        std::cout << "Folder does not exists: " << detectionsFolder.absolutePath().toStdString();
        return -1;
    }

    QStringList filters;
    filters << "*-*";

    QStringList subFolders = detectionsFolder.entryList(filters, QDir::Dirs);

    QList<QStringList> fileNamesInSubDirs;

    filters.empty();
    filters << "*.*";

    int fileCount = -1;

    foreach(QString subFol, subFolders)
    {
        QDir subFolder(detectionsFolder.absoluteFilePath(subFol));
        filters.empty();

        QStringList files = subFolder.entryList(filters, QDir::Files);

        if (fileCount < 0)
        {
            fileCount = files.count();
        }
        else if (fileCount != files.count())
        {
            std::cout << "ERROR --- Obtained file count (" << files.count() << ") is different than previously obtained files (" << fileCount << ")" << std::endl
                      << subFolder.absolutePath().toStdString() << std::endl;
            return -1;
        }

        QStringList filesWithPaths;
        foreach (QString f, files)
            filesWithPaths.append(subFolder.absoluteFilePath(f));

        fileNamesInSubDirs.append(filesWithPaths);
    }

    std::cout << "Files fetched. Creating montages...\n";

    for (int fileIndex=0; fileIndex<fileCount; fileIndex++)
    {
        QStringList args;

        //add files to arguments
        for (int folderIndex = 0; folderIndex < fileNamesInSubDirs.count(); folderIndex++)
        {
            args << fileNamesInSubDirs[folderIndex][fileIndex];
        }

        //add other arguments
        args << "-geometry";
        args << "+2+2";

        //add output file
        QString fileIndexStr = QString("%1").arg(fileIndex + 1, 3, 10, QChar('0'));
        args << outputFolder.absoluteFilePath(QString("%1.jpg").arg(fileIndexStr));
        //std::cout << args.join(' ').toStdString() << std::endl;

        QProcess::execute("montage", args);
    }

    std::cout << "Completed.\n\n";


}

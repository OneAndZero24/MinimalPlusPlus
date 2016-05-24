//Minimal++ source code
//Jan Miksa

#ifndef FILE_HANDLING_HPP
#define FILE_HANDLING_HPP

#include "includes.hpp"
//Qt Libraries

#include "../Status_Vars/status_vars.hpp"
//Important vars

//==================================================================

namespace File_Handling
{
    QFile* OpenCurrFile(QStatusBar*(*bar)(), QStringList(*openFileBrowser)());             //Opens file using file browser
    void setCEditorText(QString value);              //Sets code editor text
    void addFileToTree(QFile *file, void(*addFile)(QString,  QTreeWidgetItem*)); //Adds file to file tree
    void addDirToTree(QString name, QTreeWidgetItem*(*addDir)(QString)); //Adds dir to file tree
    bool closeFile(QFile *file);                     //Closes file
    bool deleteFile(QFile *file);                    //Deletes file
    bool saveFile(QFile *file);                      //Saves specified file
};
//Namespace for files displayment and overall handling

//==================================================================
//File_Handling namespace declaration

#endif

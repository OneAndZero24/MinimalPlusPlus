//Minimal++ source code
//Jan Miksa

#ifndef FILE_HANDLING_HPP
#define FILE_HANDLING_HPP

//{

#include <QTreeWidgetItem>
//Tree widget for tree file view

#include <QFile>
//Files handling

//{
#include "../../window.hpp"
//Main window

#include "../Status_Vars/status_vars.hpp"
//Important vars

//}
//Minimal++ libraries

//}
//Libraries

class Window;

//==================================================================
namespace File_Handling
{
    QFile* OpenCurrFile(Window *window);             //Opens file using file browser
    void setCEditorText(QString value);              //Sets code editor text
    void addFileToTree(QFile *file, Window *window); //Adds file to file tree
    void addDirToTree(QString name, Window *window); //Adds dir to file tree
    bool closeFile(QFile *file);                     //Closes file
    bool deleteFile(QFile *file);                    //Deletes file
    bool saveFile(QFile *file);                      //Saves specified file
};
//Namespace for files displayment and overall handling

//==================================================================
//File_Handling namespace declaration

#endif

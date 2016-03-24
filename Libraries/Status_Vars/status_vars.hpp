//Minimal++ source code
//Jan Miksa

#ifndef STATUS_VARS_HPP
#define STATUS_VARS_HPP

//{
#include <QFileDialog>
//File browser

#include <QToolBar>
//Toolbar

#include <QTreeWidgetItem>
//Tree widget for tree file view

#include <QTextBrowser>
//Qt text browser for terminal output

#include <QFile>
//Files handling

//{
#include "../Editor/editor.hpp"
//Code editor

//}
//Minimal++ libraries

//}
//Libraries

//==================================================================
namespace FlagsAndStatus_Vars
{    
	QToolBar *tools;                    //Customizable toolbar

    QTreeWidget *tree;                  //Files tree

    QTextBrowser *output;               //Text browser for terminal and IDE output

    CodeEditor *editor;                 //Editor

    QFile *currentfile;                 //Currenly opened file
    
    QTreeWidgetItem *currentdir = NULL; //Currently opened dir

    QString projectname = "Untitled";        //Important var for handling project name
    QString compileroutput = "setthislater"; //Important var for handling compiler output file
    QString stdfont = "Ubuntu";              //Important var for handling standard font
    
    int fontsize = 10;                       //Important var for handling standard font size

    bool projectcreated = false;             //Important var for hanfling if project is created
};
//Namespace for handling important IDE-wide flags and variables

//==================================================================
//FlagsAndStatus_Vars namespace declaration

#endif

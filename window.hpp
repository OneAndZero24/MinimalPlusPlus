//Minimal++ source code
//Jan Miksa

#ifndef WINDOW_HPP
#define WINDOW_HPP

//{
#include <QApplication>
//Main Qt application parts

#include <QMainWindow>
//Qt window

#include <QPushButton>
//Buttons

#include <QMenu>
//Menus

#include <QMenuBar>
//Menubar

#include <QStatusBar>
//Statusbar

#include <QAction>
//Actions in menus in menubar

#include <QtGui>
//Qt GUI

#include <QtCore>
//Core Qt functions

#include <QGridLayout>
//Qt grid layout

#include <QWidget>
//Qt widget

#include <QObject>
//Qt object

#include <QMessageBox>
//Popups

//{
#include "Libraries/Editor/editor.hpp"
//Code editor

#include "Libraries/Highlighter/highlighter.hpp"
//Syntax highlighter

#include "Libraries/Status_Vars/status_vars.hpp"
//Important vars

#include "Libraries/File_Handling/file_handling.hpp"
//Files handling

//}
//Minimal++ libraries

//}
//Libraries

//==================================================================
class Window : public QMainWindow
{
Q_OBJECT

private:
    QGridLayout *layout; //Window's grid layout
    QWidget *lhandler;   //Layout's handler widget

    QMenu *fileMenu;     //File menu of program
    QMenu *settingsMenu; //Settings menu of program
    QMenu *contactMenu;  //Contact menu of program
    QMenu *editMenu;     //Menu of text editor
    QMenu *buildMenu;    //Menu of build

    QAction *save;        //Save current file
    QAction *saveAll;     //Save all files
    QAction *saveAs;      //Save current file as
    QAction *newFile;     //Create new file
    QAction *newProject;  //Create new project
    QAction *openFile;    //Open file and add to current project, if no project popup error
    QAction *openProject; //Open project file
    QAction *deleteFile;  //Delete current file

    QAction *copy;  //Copy text
    QAction *paste; //Paste text
    QAction *cut;   //Cut text
    QAction *undo;  //Undo changes in text
    QAction *redo;  //Redo changes in text

    QAction *compileProj; //Comiple project
    QAction *runProg;     //Run program

    QAction *windowSize;        //Set window size and remember it for this project
    QAction *editorText;        //Setup font of editor and remember it for this project
    QAction *terminalText;      //Setup font of terminal/output and remember it for this project
    QAction *customCompileLine; //Setup custom compilation line and remember it for this project
    QAction *customLinkLine;    //Setup custom linker line and remember it for this project

    QAction *contact; //Contact

    QAction *customizeTools; //Toolbar settings

    SyntaxHighlighter *highlighter; //Syntax highlighter for code editor

    void CreateActions();     //Inicializes actions
    void CreateMenu();        //Inicializes menu of program
    void CreateStatusBar();   //Inicializes status bar of program
    void CreateToolBar();     //Inicializes customizable toolbar
    void CreateTreeView();    //Inicializes tree view
    void CreateTextBrowser(); //Inicializes text browser for terminal and IDE output
    void CreateTextEditor();  //Inicializes text editor

public:
    Window();  //Constructor

    ~Window(); //Destructor

    QTreeWidgetItem* AddDir(QString name);            //Adding directory to tree view
    void AddFile(QString name, QTreeWidgetItem *dir); //Adding new file to directory in tree view

private slots:
    void compile();           //Compile slot
    void run();               //Run slot
    void saveCurrFile();      //Save current file slot
    void saveAllFiles();      //Save all files in current project slot
    void saveCurrFileAs();    //Save current file as slot
    void createNewFile();     //Create new file slot
    void createNewProject();  //Create new project slot
    void openCurrFile();      //Open file and set it as current slot
    void openCurrProject();   //Open project and set it as current slot
    void changeCompilerCmd(); //Change compiler command and settings slot
    void changeLinkerCmd();   //Change linker command and settings slot
    void contactSL();         //Contact slot
    void copyText();          //Copy text slot
    void pasteText();         //Paste text slot
    void cutText();           //Cut text slot
    void deleteCurrFile();    //Delete current file slot
    void changeWindowSize();  //Change window size slot
    void changeEditTxt();     //Change font of text editor slot
    void changeTermTxt();     //Change font of terminal slot
    void customize();         //Customize tools toolbar slot
    void undoText();          //Undo slot
    void redoText();          //Redo slot
};
//Basic window class

//==================================================================
//Window class declaration

#endif

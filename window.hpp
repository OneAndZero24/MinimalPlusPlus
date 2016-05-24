//Minimal++ source code
//Jan Miksa

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "includes.hpp"
//Qt Libraries

//{
#include "Libraries/Editor/editor.cpp"
//Custom code editor

#include "Libraries/Highlighter/highlighter.cpp"
//Syntax highlighter
//}
//Minimal++ libraries

//==================================================================
class Window : public QMainWindow
{
Q_OBJECT

private:
    QGridLayout *layout; //Window's grid layout
    QWidget *lhandler;   //Layout's handler widget

    SyntaxHighlighter *highlighter; //Syntax highlighter for code editor

    QAction *customizeTools; //Toolbar settings

    QMenu *fileMenu;
    //File menu of program
    //{
    QAction *save;        //Save current file
    QAction *saveAll;     //Save all files
    QAction *saveAs;      //Save current file as
    QAction *newFile;     //Create new file
    QAction *newProject;  //Create new project
    QAction *openFile;    //Open file and add to current project, if no project popup error
    QAction *openProject; //Open project file
    QAction *deleteFile;  //Delete current file
    //}

    QMenu *editMenu;
    //Menu of text editor
    //{
    QAction *copy;  //Copy text
    QAction *paste; //Paste text
    QAction *cut;   //Cut text
    QAction *undo;  //Undo changes in text
    QAction *redo;  //Redo changes in text
    //}

    QMenu *buildMenu;
    //Build/Compile menu
    //{
    QAction *compileProj; //Comiple project
    QAction *runProg;     //Run program
    //}

    QMenu *settingsMenu;
    //Settings menu
    //{
    QAction *windowSize;        //Set window size and remember it for this project
    QAction *editorText;        //Setup font of editor and remember it for this project
    QAction *terminalText;      //Setup font of terminal/output and remember it for this project
    QAction *customCompileLine; //Setup custom compilation line and remember it for this project
    QAction *customLinkLine;    //Setup custom linker line and remember it for this project
    //}

    QMenu *contactMenu;
    //Contact menu
    //{
    QAction *contact; //Contact
    //}

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

    //Window UI parts
    //{
    QToolBar *tools;      //Customizable toolbar
    QTreeWidget *tree;    //Files tree view
    QTextBrowser *output; //Text browser for terminal and IDE output
    CodeEditor *editor;   //Editor
    //}

    //Important vars
    //{
    QFile *currentfile;                 //Currenly opened file
    QTreeWidgetItem *currentdir = NULL; //Currently opened dir

    QString projectname = "Untitled";        //Important var for handling project name
    QString compileroutput = "setthislater"; //Important var for handling compiler output file
    QString stdfont = "Ubuntu";              //Important var for handling standard font

    int fontsize = 10;                       //Important var for handling standard font size

    bool projectcreated = false;             //Important var for hanfling if project is created
    //}

    QFile* OpenCurrFile();                            //Opens file using file browser
    void SetEditorText(QString value);                //Sets code editor text

    bool CloseFile(QFile *file);                      //Closes file
    bool DeleteFile(QFile *file);                     //Deletes file
    bool SaveFile(QFile *file);                       //Saves specified file

    QTreeWidgetItem* AddDir(QString name);            //Adding directory to tree view
    void AddFile(QString name, QTreeWidgetItem *dir); //Adding new file to current directory in tree view

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
//==================================================================
//Window class declaration

#endif

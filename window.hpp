//Minimal++ source code
//Jan Miksa

#ifndef WINDOW_HPP
#define WINDOW_HPP

//{
#include <string>
//String

#include <QApplication>
//Qt app

#include <QMainWindow>
//Qt main window

#include <QTextCodec>
//Text encoding

#include <QPushButton>
//Buttons

#include <QMenu>
//Qt menu

#include <QMenuBar>
//Qt menu bar

#include <QStatusBar>
//Qt status bar

#include <QToolBar>
//Qt tool bar

#include <QAction>
//Qt action

#include <QtGui>
//Qt GUI

#include <QtCore>
//Qt core

#include <QTreeWidgetItem>
//Qt tree widget

#include <QGridLayout>
//Qt grid layout

#include <QWidget>
//Qt widget

#include <QTextBrowser>
//Qt text browser for terminal output

#include <QPlainTextEdit>
//Plain text editor

#include <QObject>
//Qt object

//{
#include "highlighter.cpp"
//Syntax highlighter for text editor

//}
//Minimal++ libraries

//}
//Libraries

class LineNumberArea;
//Area where line numbers are painted on code editor header

class CodeEditor : public QPlainTextEdit
{
    Q_OBJECT

public:
    CodeEditor(QWidget *parent);
    //Constructor

    void lineNumberAreaPaintEvent(QPaintEvent *event);
    //

    int lineNumberAreaWidth();
    //Getting size of area for displaying line numbers

protected:
    void resizeEvent(QResizeEvent *event);
    //On resize event callback

private slots:
    void updateLineNumberAreaWidth(int newBlockCount);
    //Update line displayment area size

    void updateLineNumberArea(const QRect &, int);
    //Update numbers of lines

private:
    QWidget *lineNumberArea;
    //Area to display lines
};
//Code editor class

class LineNumberArea : public QWidget
{
public:
    LineNumberArea(CodeEditor *ceditor) : QWidget(ceditor)
    {
        editor = ceditor;
        //Setting parameters as "parent" code editor
    }
    //Constructor

    QSize sizeHint() const
    {
        return QSize(editor->lineNumberAreaWidth(), 0);
    }
    //Getting size

protected:
    void paintEvent(QPaintEvent *event)
    {
        editor->lineNumberAreaPaintEvent(event);
    }
    //On paint event callback

private:
    CodeEditor *editor;
    //Code editor on which line numbers are drawn
};
//Area where line numbers are painted on code editor

class Window : public QMainWindow
{
Q_OBJECT

private:
    QGridLayout *layout; //Window grid layout

    QWidget *upwidget;   //Widget for layout
    QWidget *leftwidget; //Widget for layout

    QMenu *fileMenu;     //File menu of program
    QMenu *settingsMenu; //Settings menu of program
    QMenu *contactMenu;  //Contact menu of program
    QMenu *editMenu;     //Menu of text editor
    QMenu *buildMenu;    //Menu of build

    QAction *save;        //Save current file
    QAction *saveAll;     //Save All files
    QAction *saveAs;      //Save current file as
    QAction *newFile;     //Create new file
    QAction *newProject;  //Create new project
    QAction *openFile;    //Open file and add to current project, if no project create one
    QAction *openProject; //Open project file
    QAction *deleteFile;  //Delete current file

    QAction *copy;  //Copy text
    QAction *paste; //Paste text
    QAction *cut;   //Cut text
    QAction *undo;  //Undo text
    QAction *redo;  //Redo text

    QAction *compileProj; //Comiple project
    QAction *runProg;     //Run program

    QAction *windowSize;        //Set window size and remember it for this project
    QAction *editorText;        //Setup font of editor
    QAction *terminalText;      //Setup font of terminal/output
    QAction *customCompileLine; //Setup custom compilation line
    QAction *customLinkLine;    //Setup custom linker line

    QAction *contact; //Contact

    QAction *customizeTools; //Toolbar settings

    QToolBar *tools; //Customizable toolbar

    QTreeWidget *tree; //Files tree

    QTextBrowser *output; //Text browser for terminal and ide output

    QPlainTextEdit *editor; //Editor

    SyntaxHighlighter *highlighter; //Syntax highlighter

    void CreateActions();     //Inicializes actions
    void CreateMenu();        //Inicializes menu of program
    void CreateStatusBar();   //Inicializes status bar of program
    void CreateToolBar();     //Inicializes customizable toolbar
    void CreateTreeView();    //Inicializes tree view
    void CreateTextBrowser(); //Inicializes text browser for terminal and ide output
    void CreateTextEditor();  //Inicializes text editor

public:
    std::string projectname = "Untitled";        //Important var for handling project name
    std::string compileroutput = "setthislater"; //Important var for handling compiler output file
    std::string stdfont = "Ubuntu";              //Important var for handling standard font
    int fontsize = 10;                           //Important var for handling standard font size

    Window();  //Constructor
    ~Window(); //Destructor

    QTreeWidgetItem *AddDir(QString name);                        //Adding directory to tree view
    void AddFile(QString name, QTreeWidgetItem *dir); //Adding new file to directory in tree view

private slots:
    void compile();           //Compile slot
    void run();               //Run slot
    void saveCurrFile();      //Save current file slot
    void saveAllFiles();      //Save all files in current project slot
    void saveCurrFileAs();    //Save current file as slot
    void createNewFile();     //Create new file slot
    void createNewProject();  //Create new project slot
    void openCurrFile();      //Open file and set it as current - handle it slot
    void openCurrProject();   //Open project and set it as current - handle it slot
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

#endif

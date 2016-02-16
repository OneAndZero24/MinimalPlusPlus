//Minimal++ source code
//Jan Miksa

#include "window.hpp"
//Header

Window::Window()
{
    layout = new QGridLayout();
    setLayout(layout);
    //Creating and setting layout

    CreateActions();
    CreateStatusBar();
    CreateMenu();
    CreateToolBar();
    CreateTreeView();
    CreateTextBrowser();
    CreateTextEditor();
    //Inicializing program parts

    setCentralWidget(editor);
    //Setting editor as central widget

    QString title = QString::fromStdString("Minimal++ - "+projectname);
    //Conversion to QString

    setWindowTitle(title);
    //Setting window title

    setMinimumSize(900, 900);
    //Minimal size of Window

}
//Constructor

Window::~Window()
{

}
//Destructor

QTreeWidgetItem *Window::AddDir(QString name)
{
    QTreeWidgetItem *dir = new QTreeWidgetItem(tree);
    //Creating widget item

    dir->setText(0, name);
    //Setting columna and name

    dir->setIcon(0, QIcon(":/Icons/resource_icon.gif"));
    //Setting icon

    tree->addTopLevelItem(dir);
    //Adding directory to tree

    return dir;
}
//Adding directory to tree view

void Window::AddFile(QString name, QTreeWidgetItem *dir)
{
    QTreeWidgetItem *file = new QTreeWidgetItem();
    //Creating widget item

    file->setText(0, name);
    //Setting column and name

    file->setIcon(0, QIcon(":/Icons/resource_icon.gif"));
    //Setting icon

    dir->addChild(file);
    //Adding file to tree
}
//Adding new file to directory in tree view

void Window::compile()
{
    statusBar()->showMessage("Compile project.", 2000);
    //Status bar tip
}
//Compile slot

void Window::run()
{
    statusBar()->showMessage("Run compiled program.", 2000);
    //Status bar tip
}
//Run slot

void Window::saveCurrFile()
{
    statusBar()->showMessage("Save current file.", 2000);
    //Status bar tip
}
//Save current file slot

void Window::saveAllFiles()
{
    statusBar()->showMessage("Save all files in current project.", 2000);
    //Status bar tip
}
//Save all files in current project slot

void Window::saveCurrFileAs()
{
    statusBar()->showMessage("Save current file as.", 2000);
    //Status bar tip
}
//Save current file as slot

void Window::createNewFile()
{
    statusBar()->showMessage("Create new file.", 2000);
    //Status bar tip
}
//Create new file slot

void Window::createNewProject()
{
    statusBar()->showMessage("Create new project.", 2000);
    //Status bar tip
}
//Create new project slot

void Window::openCurrFile()
{
    statusBar()->showMessage("Open file.", 2000);
    //Status bar tip
}
//Open file and set it as current - handle it slot

void Window::openCurrProject()
{
    statusBar()->showMessage("Open project.", 2000);
    //Status bar tip
}
//Open project and set it as current - handle it slot

void Window::changeCompilerCmd()
{
    statusBar()->showMessage("Change compiler command and settings.", 2000);
    //Status bar tip
}
//Change compiler command and settings slot

void Window::changeLinkerCmd()
{
    statusBar()->showMessage("Change linker command and settings.", 2000);
    //Status bar tip
}
//Change linker command and settings slot

void Window::contactSL()
{
    statusBar()->showMessage("Contact of creator and information about project.", 2000);
    //Status bar tip
}
//Contact slot

void Window::copyText()
{
    statusBar()->showMessage("Copy text.", 2000);
    //Status bar tip
}
//Copy text slot

void Window::pasteText()
{
    statusBar()->showMessage("Paste text.", 2000);
    //Status bar tip
}
//Paste text slot

void Window::cutText()
{
    statusBar()->showMessage("Cut text.", 2000);
    //Status bar tip
}
//Cut text slot

void Window::deleteCurrFile()
{
    statusBar()->showMessage("Delete current file.", 2000);
    //Status bar tip
}
//Delete current file slot

void Window::changeWindowSize()
{
    statusBar()->showMessage("Change size of window.", 2000);
    //Status bar tip
}
//Change window size slot

void Window::changeEditTxt()
{
    statusBar()->showMessage("Change font of text editor.", 2000);
    //Status bar tip
}
//Change font of text editor slot

void Window::changeTermTxt()
{
    statusBar()->showMessage("Change font of terminal.", 2000);
    //Status bar tip
}
//Change font of terminal slot

void Window::customize()
{
    statusBar()->showMessage("Customize tools toolbar.", 2000);
    //Status bar tip
}
//Customize tools toolbar slot

void Window::undoText()
{
    statusBar()->showMessage("Undo.", 2000);
    //Status bar tip
}
//Undo slot

void Window::redoText()
{
    statusBar()->showMessage("Redo.", 2000);
    //Status bar tip
}
//Redo slot

void Window::CreateActions()
{
    save = new QAction(QIcon(":/Icons/save_icon.gif"), "Save", this);
    save->setShortcut(Qt::CTRL+Qt::Key_S);
    save->setStatusTip("Save current file.");
    connect(save, SIGNAL(triggered()), this, SLOT(saveCurrFile()));

    saveAll = new QAction(QIcon(":/Icons/save_all_icon.gif"), "Save All", this);
    saveAll->setShortcut(Qt::CTRL+Qt::SHIFT+Qt::Key_S);
    saveAll->setStatusTip("Save all files in current project.");
    connect(saveAll, SIGNAL(triggered()), this, SLOT(saveAllFiles()));

    saveAs = new QAction(QIcon(":/Icons/save_as_icon.gif"), "Save As", this);
    saveAs->setShortcut(Qt::CTRL+Qt::ALT+Qt::Key_S);
    saveAs->setStatusTip("Save current file as.");
    connect(saveAs, SIGNAL(triggered()), this, SLOT(saveCurrFileAs()));

    newFile = new QAction(QIcon(":/Icons/new_file_icon.gif"), "New File", this);
    newFile->setShortcut(Qt::CTRL+Qt::Key_N);
    newFile->setStatusTip("Create new file.");
    connect(newFile, SIGNAL(triggered()), this, SLOT(createNewFile()));

    newProject = new QAction(QIcon(":/Icons/new_project_icon.gif"), "New Project", this);
    newProject->setShortcut(Qt::CTRL+Qt::SHIFT+Qt::Key_N);
    newProject->setStatusTip("Create new project.");
    connect(newProject, SIGNAL(triggered()), this, SLOT(createNewProject()));

    openFile = new QAction(QIcon(":/Icons/open_file_icon.gif"), "Open File", this);
    openFile->setShortcut(Qt::CTRL+Qt::Key_O);
    openFile->setStatusTip("Open file.");
    connect(openFile, SIGNAL(triggered()), this, SLOT(openCurrFile()));

    openProject = new QAction(QIcon(":/Icons/open_project_icon.gif"), "Open Project", this);
    openProject->setShortcut(Qt::CTRL+Qt::SHIFT+Qt::Key_O);
    openProject->setStatusTip("Open project.");
    connect(openProject, SIGNAL(triggered()), this, SLOT(openCurrProject()));

    deleteFile = new QAction(QIcon(":/Icons/delete_icon.gif"), "Delete File", this);
    deleteFile->setShortcut(Qt::CTRL+Qt::SHIFT+Qt::Key_X);
    deleteFile->setStatusTip("Delete current file.");
    connect(deleteFile, SIGNAL(triggered()), this, SLOT(deleteCurrFile()));

    copy = new QAction(QIcon(":/Icons/copy_icon.gif"), "Copy", this);
    copy->setStatusTip("Copy text.");
    copy->setShortcut(Qt::CTRL+Qt::Key_C);
    connect(copy, SIGNAL(triggered()), this, SLOT(copyText()));

    paste = new QAction(QIcon(":/Icons/paste_icon.gif"), "Paste", this);
    paste->setStatusTip("Paste text.");
    paste->setShortcut(Qt::CTRL+Qt::Key_V);
    connect(paste, SIGNAL(triggered()), this, SLOT(pasteText()));

    cut = new QAction(QIcon(":/Icons/cut_icon.gif"), "Cut", this);
    cut->setStatusTip("Cut text.");
    cut->setShortcut(Qt::CTRL+Qt::Key_X);
    connect(cut, SIGNAL(triggered()), this, SLOT(cutText()));

    undo = new QAction(QIcon(":/Icons/undo_icon.gif"), "Undo", this);
    undo->setStatusTip("Undo.");
    undo->setShortcut(Qt::CTRL+Qt::Key_Z);
    connect(undo, SIGNAL(triggered()), this, SLOT(undoText()));

    redo = new QAction(QIcon(":/Icons/redo_icon.gif"), "Redo", this);
    redo->setStatusTip("Redo.");
    redo->setShortcut(Qt::CTRL+Qt::SHIFT+Qt::Key_Z);
    connect(redo, SIGNAL(triggered()), this, SLOT(redoText()));

    compileProj = new QAction(QIcon(":/Icons/compile_icon.gif"), "Compile", this);
    compileProj->setShortcut(Qt::CTRL+Qt::SHIFT+Qt::Key_R);
    compileProj->setStatusTip("Compile project.");
    connect(compileProj, SIGNAL(triggered()), this, SLOT(compile()));

    runProg = new QAction(QIcon(":/Icons/run_icon.gif"), "Run", this);
    runProg->setShortcut(Qt::CTRL+Qt::Key_R);
    runProg->setStatusTip("Run compiled program.");
    connect(runProg, SIGNAL(triggered()), this, SLOT(run()));

    windowSize = new QAction(QIcon(":/Icons/window_size_icon.gif"), "Window Size", this);
    windowSize->setStatusTip("Change size of window.");
    connect(windowSize, SIGNAL(triggered()), this, SLOT(changeWindowSize()));

    editorText = new QAction(QIcon(":/Icons/editor_text_icon.gif"), "Editor Text", this);
    editorText->setStatusTip("Change font of text editor.");
    connect(editorText, SIGNAL(triggered()), this, SLOT(changeEditTxt()));

    terminalText = new QAction(QIcon(":/Icons/terminal_text_icon.gif"), "Terminal Text", this);
    terminalText->setStatusTip("Change font of terminal.");
    connect(terminalText, SIGNAL(triggered()), this, SLOT(changeTermTxt()));

    customCompileLine = new QAction(QIcon(":/Icons/custom_compiler_line_icon.gif"), "Custom Compile Line", this);
    customCompileLine->setStatusTip("Change compiler command and settings.");
    connect(customCompileLine, SIGNAL(triggered()), this, SLOT(changeCompilerCmd()));

    customLinkLine = new QAction(QIcon(":/Icons/custom_linker_line_icon.gif"), "Custom Link Line", this);
    customLinkLine->setStatusTip("Change linker command and settings.");
    connect(customLinkLine, SIGNAL(triggered()), this, SLOT(changeLinkerCmd()));

    contact = new QAction(QIcon(":/Icons/contact_icon.gif"), "Contact", this);
    contact->setShortcut(Qt::CTRL+Qt::Key_H);
    contact->setStatusTip("Contact of creator and information about project.");
    connect(contact, SIGNAL(triggered()), this, SLOT(contactSL()));

    customizeTools = new QAction(QIcon(":/Icons/customize_toolbar_icon.gif"), "", this);
    customizeTools->setStatusTip("Customize tools toolbar.");
    connect(customizeTools, SIGNAL(triggered()), this, SLOT(customize()));
    //Setting up actions
}
//Function for inicializing actions

void Window::CreateMenu()
{
    fileMenu = menuBar()->addMenu("File");
    editMenu = menuBar()->addMenu("Edit");
    buildMenu = menuBar()->addMenu("Build");
    settingsMenu = menuBar()->addMenu("Settings");
    contactMenu = menuBar()->addMenu("Contact");
    //Adding menus to menuBar

    fileMenu->addAction(save);
    fileMenu->addAction(saveAll);
    fileMenu->addAction(saveAs);
    fileMenu->addSeparator();
    fileMenu->addAction(newFile);
    fileMenu->addAction(newProject);
    fileMenu->addSeparator();
    fileMenu->addAction(openFile);
    fileMenu->addAction(openProject);
    fileMenu->addSeparator();
    fileMenu->addAction(deleteFile);
    //File menu

    editMenu->addAction(copy);
    editMenu->addAction(paste);
    editMenu->addSeparator();
    editMenu->addAction(cut);
    editMenu->addSeparator();
    editMenu->addAction(undo);
    editMenu->addAction(redo);
    //Edit menu

    buildMenu->addAction(compileProj);
    buildMenu->addAction(runProg);
    //Build menu

    settingsMenu->addAction(windowSize);
    settingsMenu->addSeparator();
    settingsMenu->addAction(editorText);
    settingsMenu->addAction(terminalText);
    settingsMenu->addSeparator();
    settingsMenu->addAction(customCompileLine);
    settingsMenu->addAction(customLinkLine);
    //Settings menu

    contactMenu->addAction(contact);
    //Contact menu
}
//Function for inicializing menu

void Window::CreateStatusBar()
{
    statusBar()->showMessage("Ready", 10000);
    //Setting startpoint status bar message
}
//Function for inicializing status bar

void Window::CreateToolBar()
{
    upwidget = new QWidget(this);
    //Creating up widget

    tools = new QToolBar(upwidget);
    //Inicializing toolbar - instance

    tools->addAction(customizeTools);
    //Adding cutomizability

    layout->addWidget(upwidget, 0, 0);
    //Adding toolbar to window
}
//Function for inicializing customizable tools toolbar

void Window::CreateTreeView()
{
    leftwidget = new QWidget(this);
    //Creating left widget

    tree = new QTreeWidget(leftwidget);
    //Inicializing tree

    tree->setColumnCount(1);
    //Setting one column

    QTreeWidgetItem *projectdir;
    projectdir = AddDir("Project");
    //Just test delete this

    AddFile("main.cpp", projectdir);
    //Just test delete this

    layout->addWidget(leftwidget, 0, 1, 1, 1);
    //Displaying it
}
//Inicializes tree view

void Window::CreateTextBrowser()
{
    output = new QTextBrowser(this);
    //Inicializing text browser - creating instance

    output->setSource(*new QUrl(QString::fromStdString(compileroutput)));
    //Setting source to compiler output

    output->show();
    //Displaying
}
//Inicializes text browser for terminal and ide output

void Window::CreateTextEditor()
{
    editor =  new QPlainTextEdit;
    //Creating text editor - instance

    QFont font;
    font.setFamily(QString::fromStdString(stdfont));
    font.setFixedPitch(true);
    font.setPointSize(fontsize);
    //Designing font

    editor->setFont(font);
    //Setting up font of text editor

    highlighter = new SyntaxHighlighter(editor->document());
    //Setting up highlighter to highlight current document in text editor

    editor->setPlainText("Placeholder");
    //Just for testing delete this later
}
//Inicializes text editor

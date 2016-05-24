//Minimal++ source code
//Jan Miksa

#include "file_handling.hpp"
//Header

using namespace FlagsAndStatus_Vars;
//Namespace for handling important IDE-wide flags and variables

//==================================================================
QFile* File_Handling::OpenCurrFile(QStatusBar*(*bar)(), QStringList(*openFileBrowser)())
{
    bar()->showMessage("Open file.", 2000);
    //Status bar tip

	if(projectcreated) //Checking if project is created
	{
    	QString filename;
		//Important var    

        filename = openFileBrowser()[0];
    	//Opening file through file browser

        QFile handler(filename);
        currentfile = &handler;
        //Setting currentfile

    	if(!currentfile->open(QFile::ReadWrite)) //Opening file and checking if opened
    	{
        	QMessageBox error;
        	error.critical(0,"Error!","Could not open file!");
        	error.setFixedSize(400,200);
        	//Displaying error message

            QFile handler("Error!");
            currentfile =  &handler;
            return currentfile;
    	}

        bar()->showMessage("Opened file.", 2000);
    	//Status bar tip

        return currentfile;
	}

	QMessageBox error;
    error.critical(0,"Error!","No project created!");
    error.setFixedSize(400,200);
    //Displaying error message

    QFile handler("Error!");
    currentfile = &handler;
    return currentfile;
}
//Opens file using file browser

void File_Handling::setCEditorText(QString value)
{
    editor->setPlainText(value);
    //Opening file in editor

    return;
}
//Sets code editor text

void File_Handling::addFileToTree(QFile *file, void(*addFile)(QString, QTreeWidgetItem*))
{
    if(currentdir != NULL) //If current dir is set
	{
        addFile(file->fileName(), currentdir);
        //Adding file to treeview

        return;
	}

    QMessageBox error;
    error.critical(0,"Error!","No directory selected!");
    error.setFixedSize(400,200);
    //Displaying error message

    return;
}
//Adds file to file tree

void File_Handling::addDirToTree(QString name, QTreeWidgetItem*(*addDir)(QString))
{
    currentdir = addDir(name);
	//Creating dir

	return;
}
//Adds dir to file tree

//==================================================================
//File_Handling namespace definition

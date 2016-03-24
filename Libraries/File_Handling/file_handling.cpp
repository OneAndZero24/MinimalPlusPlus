//Minimal++ source code
//Jan Miksa

#include "file_handling.hpp"
//Header

using namespace FlagsAndStatus_Vars;
//Namespace for handling important IDE-wide flags and variables

using namespace File_Handling;
//Namespace for files displayment and overall handling

//==================================================================

QFile* openCurrFile(Window *window)
{
    window->statusBar()->showMessage("Open file.", 2000);
    //Status bar tip

	if(projectcreated) //Checking if project is created
	{
    	QString filename;
		//Important var    

        filename = QFileDialog::getOpenFileNames(window, "Open File","filename", "All Files (*.*)")[0];
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

        window->statusBar()->showMessage("Opened file.", 2000);
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

void setCEditorText(QString value)
{
    editor->setPlainText(value);
    //Opening file in editor

    return;
}
//Sets code editor text

void addFileToTree(QFile *file, Window *window)
{
    if(currentdir != NULL) //If current dir is set
	{
        window->AddFile(file->fileName(), currentdir);
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

void addDirToTree(QString name, Window *window)
{
    currentdir = window->AddDir(name);
	//Creating dir

	return;
}
//Adds dir to file tree

//==================================================================
//File_Handling namespace definition

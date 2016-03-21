//Minimal++ source code
//Jan Miksa

//{

#include <QTreeWidgetItem>
//Tree widget for tree file view

#include <QFile>
//Files handling

//}
//Libraries

#ifndef FILE_HANDLING_HPP
#define FILE_HANDLING_HPP

//==================================================================
namespace File_Handling
{

	QFile openFile();                  //Opens file using file browser
	void setCEditorText(QString *value); //Sets code editor text
	void addFileToTree(QFile *file);     //Adds file to file tree
	void addDirToTree(QString name);     //Adds dir to file tree
	bool closeFile(QFile *file);         //Closes file
	bool deleteFile(QFile *file);        //Deletes file  
	bool saveFile(QFile *file);          //Saves specified file
};
//Namespace for files displayment and overall handling

//==================================================================
//File_Handling namespace declaration

#endif
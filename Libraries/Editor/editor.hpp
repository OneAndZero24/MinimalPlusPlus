//Minimal++ source code
//Jan Miksa

#ifndef EDITOR_HPP
#define EDITOR_HPP

#include "includes.hpp"
//Qt Libraries

class CodeEditor;
//CodeEditor class header

//==================================================================
class LineNumberArea : public QWidget
{
public:
    LineNumberArea(CodeEditor *ceditor); //Constructor

    QSize sizeHint(); //Getting size

protected:
    void paintEvent(QPaintEvent *event); //On paint event callback

private:
    CodeEditor *editor; //Code editor on which line numbers are drawn
};
//Area where line numbers are painted on code editor

//==================================================================
//LineNumberArea class declaration

//==================================================================
class CodeEditor : public QPlainTextEdit
{
    Q_OBJECT

public:
    CodeEditor(QWidget *parent); //Constructor
    ~CodeEditor();               //Destructor

    void lineNumberAreaPaintEvent(QPaintEvent *event); //Paints widget
    int lineNumberAreaWidth();                         //Getting size of area for displaying line numbers

protected:
    void resizeEvent(QResizeEvent *event); //On resize event callback

private slots:
    void updateLineNumberAreaWidth(); //Update line displayment area size
    void updateLineNumberArea(const QRect &, int); //Update numbers of lines

private:
    QWidget *lineNumberArea; //Area to display lines
};
//Code editor

//==================================================================
//CodeEditor class declaration

#endif

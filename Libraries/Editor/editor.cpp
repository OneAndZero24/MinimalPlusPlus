//Minimal++ source code
//Jan Miksa

#include "editor.hpp"
//Header

//==================================================================
LineNumberArea::LineNumberArea(CodeEditor *ceditor) : QWidget(ceditor)
{
    editor = ceditor;
    //Setting parameters as "parent" code editor
}
//Constructor

QSize LineNumberArea::sizeHint()
{
    return QSize(editor->lineNumberAreaWidth(), 0);
}
//Getting size

void LineNumberArea::paintEvent(QPaintEvent *event)
{
    editor->lineNumberAreaPaintEvent(event);
}
//On paint event callback

//==================================================================
//LineNumberArea class definition

//==================================================================
CodeEditor::CodeEditor(QWidget *parent) : QPlainTextEdit(parent)
{
    lineNumberArea = new LineNumberArea(this);
    //Creating new instance of line counter

    connect(this, SIGNAL(blockCountChanged(int)), this, SLOT(updateLineNumberAreaWidth(int)));
    //Connecting size-change signal to its' slot

    connect(this, SIGNAL(updateRequest(QRect,int)), this, SLOT(updateLineNumberArea(QRect,int)));
    //Conneting update signal to udate line number area slot

    updateLineNumberAreaWidth(0);
    //Standard line counter size
}
//Constructor

int CodeEditor::lineNumberAreaWidth()
{
    int digits = 1;
    //Number of digits in line

    int max = qMax(1, blockCount());
    //Maximum between 1 and number of blocks in text

    while(max >= 10)
    {
        max /= 10;
        //Division

        digits++;
        //Increasing number of digits
    }
    //Loop for counting digits

    int width = 4 + fontMetrics().width(QLatin1Char('9')) * digits;
    //Counting width of line counter

    return width;
}
//Gets size of line counter

void CodeEditor::updateLineNumberAreaWidth(int iDontNeedThisVarButItMustBeHereToMakeSlotCompatibleWithSignal)
{
    setViewportMargins(lineNumberAreaWidth(), 0, 0, 0);
    //Setting margin of editor to fit line counter there
}
//Updates width of line number area

void CodeEditor::updateLineNumberArea(const QRect &rect, int dy)
{
    if (dy)
    {
        lineNumberArea->scroll(0, dy);
        //Scrolling line counter
    }
    else
    {
        lineNumberArea->update(0, rect.y(), lineNumberArea->width(), rect.height());
        //Redrawing line area
    }

    if (rect.contains(viewport()->rect()))
    {
        updateLineNumberAreaWidth(0);
        //Updating line area width
    }
}
//Updating line counter widget

void CodeEditor::resizeEvent(QResizeEvent *e)
{
    QPlainTextEdit::resizeEvent(e);
    //Resizing it

    QRect cr = contentsRect();
    lineNumberArea->setGeometry(QRect(cr.left(), cr.top(), lineNumberAreaWidth(), cr.height()));
    //Updating area for line numbers
}
//On resize event callback

void CodeEditor::lineNumberAreaPaintEvent(QPaintEvent *event)
{
    QPainter painter(lineNumberArea);
    //Creating QPainter

    painter.fillRect(event->rect(), Qt::black);
    //Painting background

    QTextBlock block = firstVisibleBlock();
    int blockNumber = block.blockNumber();
    int top = (int) blockBoundingGeometry(block).translated(contentOffset()).top();
    int bottom = top + (int) blockBoundingRect(block).height();
    //Important vars for paintning line number with loop below

    while (block.isValid() && top <= event->rect().bottom())
    {
        if (block.isVisible() && bottom >= event->rect().top()) //Checking if block is visible
        {
            QString number = QString::number(blockNumber + 1);
            //Setting text to paint

            painter.setPen(Qt::blue);
            //Setting color

            painter.drawText(0, top, lineNumberArea->width(), fontMetrics().height(), Qt::AlignRight, number);
            //Painting line number
        }

        block = block.next();
        top = bottom;
        bottom = top + (int) blockBoundingRect(block).height();
        ++blockNumber;
        //Going to next block
    }
    //Loop for painting line number in each line
}
//Paints widget

//==================================================================
//CodeEditor class definition

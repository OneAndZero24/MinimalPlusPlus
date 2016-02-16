//Minimal++ source code
//Jan Miksa

#ifndef HIGHLIGHTER_HPP
#define HIGHLIGHTER_HPP

//{
#include <QSyntaxHighlighter>
//Qt synatx highlighter - base for ours

#include <QTextCharFormat>
//Qt text format

//}
//Libraries

class SyntaxHighlighter : public QSyntaxHighlighter
{
Q_OBJECT

public:
    inline SyntaxHighlighter(QTextDocument *parent = 0) : QSyntaxHighlighter(parent)
    {

    }
    //Constructor

protected:
    void highlightBlock(const QString &code) Q_DECL_OVERRIDE
    {
    }
    //Highlighting function

private:
    struct Rule
    {
        QRegExp pattern;        //Pattern - what to highlight
        QTextCharFormat format; //Format - how to highlight
    };
    //Rules for syntax highlighting

    QVector<Rule> highlightRules; //Vector of highlighting rules

    QRegExp commentStartExpression; //Start of comment format
    QRegExp commentEndExpression;   //End of comment format

    QTextCharFormat keywordFormat;               //Format of keyword
    QTextCharFormat typeFormat;                  //Format of type
    QTextCharFormat semicolonFormat;             //Format of semicolon
    QTextCharFormat preprocessordirectiveFormat; //Format of preprocessor directive
    QTextCharFormat classFormat;                 //Format of class
    QTextCharFormat singleLineCommentFormat;     //Format of single line comment
    QTextCharFormat multiLineCommentFormat;      //Format of multi line comment
    QTextCharFormat quotationFormat;             //Format of queote
    QTextCharFormat functionFormat;              //Format of function
};
//SyntaxHighlighter class definition

#endif // HIGHLIGHTER_HPP

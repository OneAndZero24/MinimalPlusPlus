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

//==================================================================
class SyntaxHighlighter : public QSyntaxHighlighter
{
Q_OBJECT

public:
    SyntaxHighlighter(QTextDocument *parent = 0); //Constructor

protected:
    void highlightBlock(const QString &code) Q_DECL_OVERRIDE; //Highlighting function

private:
    struct Rule //Rules for syntax highlighting
    {
        QRegExp pattern;        //Pattern - what to highlight
        QTextCharFormat format; //Format - how to highlight
    };

    QVector<Rule> highlightingRules; //Vector of highlighting rules

    QRegExp commentStartExpression; //Start of comment format
    QRegExp commentEndExpression;   //End of comment format

    QTextCharFormat operatorFormat;              //Format of operator
    QTextCharFormat keywordFormat;               //Format of keyword
    QTextCharFormat semicolonFormat;             //Format of semicolon
    QTextCharFormat preprocessordirectiveFormat; //Format of preprocessor directive
    QTextCharFormat singleLineCommentFormat;     //Format of single line comment
    QTextCharFormat multiLineCommentFormat;      //Format of multi line comment
    QTextCharFormat quotationFormat;             //Format of queote
    QTextCharFormat functionFormat;              //Format of function
};
//Syntax highlighter with custom rules for editor

//==================================================================
//SyntaxHighlighter class declaration

#endif

//Minimal++ source code
//Jan Miksa

#include "highlighter.hpp"
//Header

//==================================================================
SyntaxHighlighter::SyntaxHighlighter(QTextDocument *parent) : QSyntaxHighlighter(parent)
{
    Rule rule;
    //Handler

//{
 
    keywordFormat.setForeground(Qt::darkBlue);
    keywordFormat.setFontWeight(QFont::Bold);
    //Settings for keywords

    QStringList keywordPatterns;
    //List of keywords

    keywordPatterns << "\\balignas\\b" << "\\alignof\\b" << "\\band\\b"
                    << "\\basm\\b" << "\\bauto\\b" << "\\bbitand\\b"
                    << "\\bbitor\\b" << "\\bbool\\b" << "\\bbreak\\b"
                    << "\\bcase\\b" << "\\bcatch\\b" << "\\bchar\\b"
                    << "\\bchar16_t\\b" << "\\bchar32_t" << "\\bclass\\b"
                    << "\\bcompl\\b" << "\\bconcept\\b" << "\\bconst\\b"
                    << "\\bconstexpr\\b" << "\\bconst_cast\\b" << "\\bcontinue\\b"
                    << "\\bdecltype\\b" << "\\bdefault\\b" << "\\bdelete\\b"
                    << "\\bdo\\b" << "\\bdouble\\b" << "\\bdynamic_cast\\b"
                    << "\\belse\\b" << "\\benum\\b" << "\\bexplicit\\b"
                    << "\\bexport\\b" << "\\bextern\\b" << "\\bfalse\\b"
                    << "\\bfloat\\b" << "\\bfor\\b" << "\\bfriend\\b"
                    << "\\bgoto\\b" << "\\bif\\b" << "\\binline\\b"
                    << "\\bint\\b" << "\\blong\\b" << "\\bmutable\\b"
                    << "\\bnamespace\\b" << "\\bnew\\b" << "\\bnoexcept\\b"
                    << "\\bnot\\b" << "\\bnot_eq\\b" << "\\bnullptr\\b"
                    << "\\boperator\\b" << "\\bor\\b" << "\\bor_eq\\b"
                    << "\\bprivate\\b" << "\\bprotected\\b" << "\\bpublic\\b"
                    << "\\bregister\\b" << "\\breinterpret_cast\\b" << "\\brequires\\b"
                    << "\\breturn\\b" << "\\bshort\\b" << "\\bsigned\\b"
                    << "\\bsizeof\\b" << "\\bstatic\\b" << "\\bstatic_assert\\b"
                    << "\\bstatic_cast\\b" << "\\bstruct\\b" << "\\bswitch\\b"
                    << "\\btemplate\\b" << "\\bthis\\b" << "\\bthread_local\\b"
                    << "\\bthrow\\b" << "\\btrue\\b" << "\\btry\\b"
                    << "\\btypedef\\b" << "\\btypeid\\b" << "\\btypename\\b"
                    << "\\bunion\\b" << "\\bunsigned\\b" << "\\busing\\b"
                    << "\\bvirtual\\b" << "\\bvoid\\b" << "\\bvolatile\\b"
                    << "\\bwchar_t\\b" << "\\bwhile\\b" << "\\bxor\\b"
                    << "\\bxor_eq\\b" << "\\boverride\\b" << "\\bfinal\\b";

    foreach(const QString &pattern, keywordPatterns) 
    {
        rule.pattern = QRegExp(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }
    //Applying it

//}
//Keywords higlight setup

//{


    operatorFormat.setForeground(Qt::yellow);
    operatorFormat.setFontWeight(QFont::Normal);
    //Settings for operators

    QStringList operatorPatterns;
    //List of operators

    operatorPatterns << "\\b=\\b" << "\\b+\\b" << "\\b-\\b"
                     << "\\b*\\b" << "\\b/\\b" << "\\b%\\b"
                     << "\\b++\\b" << "\\b--\\b" << "\\b==\\b"
                     << "\\b!=\\b" << "\\b>\\b" << "\\b<\\b"
                     << "\\b>=\\b" << "\\b<=\\b" << "\\b!\\b"
                     << "\\b&&\\b" << "\\b||\\b" << "\\b~\\b"
                     << "\\b&\\b" << "\\b|\\b" << "\\b^\\b"
                     << "\\b<<\\b" << "\\b>>\\b" << "\\b+=\\b"
                     << " \\b-=\\b" << "\\b*=\\b" << "\\b/=\\b"
                     << "\\b%=\\b" << "\\b&=\\b" << "\\b|=\\b"
                     << "\\b^=\\b" << "\\b<<=\\b" << "\\b>>=\\b";

    foreach(const QString &pattern, operatorPatterns) 
    {
        rule.pattern = QRegExp(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }
    //Applying it

//}
//Operators highlight setup

    preprocessordirectiveFormat.setForeground(Qt::darkGreen);
    preprocessordirectiveFormat.setFontWeight(4);
    rule.pattern = QRegExp("#[^\n]*");
    rule.format = preprocessordirectiveFormat;
    highlightingRules.append(rule);
//Preprocessor directives highlight setup

    singleLineCommentFormat.setForeground(Qt::green);
    singleLineCommentFormat.setFontItalic(true);
    rule.pattern = QRegExp("//[^\n]*");
    rule.format = singleLineCommentFormat;
    highlightingRules.append(rule);
//Single line comment highlight setup

    multiLineCommentFormat.setForeground(Qt::green);
    multiLineCommentFormat.setFontItalic(true);
    commentStartExpression = QRegExp("/\\*");
    commentEndExpression = QRegExp("\\*/");
//Multi line comment highlight setup

    quotationFormat.setForeground(Qt::magenta);
    rule.pattern = QRegExp("\".*\"");
    rule.format = quotationFormat;
    highlightingRules.append(rule);
//Quotation highlight setup

    functionFormat.setForeground(Qt::blue);
    rule.pattern = QRegExp("\\b[A-Za-z0-9_]+(?=\\()");
    rule.format = functionFormat;
    highlightingRules.append(rule);
//Function name highlight setup

    semicolonFormat.setForeground(Qt::red);
    rule.pattern = QRegExp(";");
    rule.format = semicolonFormat;
    highlightingRules.append(rule);
//Semicolon highlight setup

}
//Constructor


void SyntaxHighlighter::highlightBlock(const QString &code)
{
    foreach(const Rule &rule, highlightingRules)
    {
        QRegExp expression(rule.pattern);
        int index = expression.indexIn(code);
        //Current expresion

        while (index >= 0) 
        {
            int length = expression.matchedLength();
            setFormat(index, length, rule.format);
            index = expression.indexIn(code, index + length);
        }
        //Comparing expression and setting font format if match
    }
    //Loop through all expressions and set them

    setCurrentBlockState(0);
    //Saving state    

    int startIndex = 0;
    if (previousBlockState() != 1)
    {
        startIndex = commentStartExpression.indexIn(code);
    }
    //Setting start index of multi line comment

    while (startIndex >= 0) 
    {
        int endIndex = commentEndExpression.indexIn(code, startIndex);
        int commentLength;
         //Important vars        

        if (endIndex == -1) 
        {
            setCurrentBlockState(1);
            commentLength = code.length() - startIndex;
        }
        else
        {
            commentLength = endIndex - startIndex + commentEndExpression.matchedLength();
        }

        setFormat(startIndex, commentLength, multiLineCommentFormat);
        startIndex = commentStartExpression.indexIn(code, startIndex + commentLength);
        //Formatting font and setting index for next highlight
    }
    //Searching for end of multi line comment and formatting it
}
//Highlighting function

//==================================================================
//SyntaxHighlighter class definition

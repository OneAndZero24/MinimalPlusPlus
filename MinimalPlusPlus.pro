#Minimal++ source code
#Jan Miksa

QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MinimalPlusPlus
TEMPLATE = app

SOURCES += main.cpp\
           window.cpp\
           Libraries/Editor/editor.cpp\
           Libraries/File_Handling/file_handling.cpp\
           Libraries/Highlighter/highlighter.cpp\

HEADERS  += window.hpp\
           Libraries/Editor/editor.hpp\
           Libraries/File_Handling/file_handling.hpp\
           Libraries/Highlighter/highlighter.hpp\
           Libraries/Status_Vars/status_vars.hpp\

RESOURCES += resources.qrc

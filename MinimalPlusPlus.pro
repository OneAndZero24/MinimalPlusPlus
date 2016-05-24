#-------------------------------------------------
#
# Project created by QtCreator 2016-05-20T19:36:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MinimalPlusPlus
TEMPLATE = app


SOURCES += \
    Libraries/Editor/editor.cpp \
    Libraries/Highlighter/highlighter.cpp \
    main.cpp \
    window.cpp

HEADERS  += \
    Libraries/Editor/editor.hpp \
    Libraries/Highlighter/highlighter.hpp \
    includes.hpp \
    window.hpp

FORMS    +=

RESOURCES += \
    resources.qrc

DISTFILES += \
    Icons/compile_icon.gif \
    Icons/contact_icon.gif \
    Icons/copy_icon.gif \
    Icons/custom_compiler_line_icon.gif \
    Icons/custom_linker_line_icon.gif \
    Icons/customize_toolbar_icon.gif \
    Icons/cut_icon.gif \
    Icons/debug_icon.gif \
    Icons/delete_icon.gif \
    Icons/editor_text_icon.gif \
    Icons/new_file_icon.gif \
    Icons/new_project_icon.gif \
    Icons/open_file_icon.gif \
    Icons/open_project_icon.gif \
    Icons/paste_icon.gif \
    Icons/redo_icon.gif \
    Icons/resource_icon.gif \
    Icons/run_icon.gif \
    Icons/save_all_icon.gif \
    Icons/save_as_icon.gif \
    Icons/save_icon.gif \
    Icons/terminal_text_icon.gif \
    Icons/undo_icon.gif \
    Icons/window_size_icon.gif \
    LICENSE \
    README.md

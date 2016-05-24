//Minimal++ source code
//Jan Miksa

#include "includes.hpp"
//Qt Libraries

//{
#include "window.cpp"
//Main window and program parts

//}
//Minimal++ libraries

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    //Creating qapplication

    Window window;
    //Main window

    window.showMaximized();
    //Showing main window of program - maximized default

    return app.exec();
    //Start main program loop
}
//Main

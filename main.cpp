//Minimal++ source code
//Jan Miksa

//{
#include <QApplication>
//Qt application

//{
#include "window.cpp"
//Basic window

//}
//Minimal++ libraries

//}
//Libraries

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    //Creating qapplication

    Window window;
    window.show();
    //Showing main window of program

    return app.exec();
    //Start main program loop
}
//Main

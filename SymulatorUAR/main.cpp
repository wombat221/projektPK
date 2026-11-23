#include "mainwindow.h"

#include <QApplication>


// TU includy:
#include <iostream>
#include <iomanip>
#include "ModelARX.h"
#include "RegulatorPID.h"
#include "ProstyUAR.h"
#include "Generator.h"
#include "Uslugi.h"


#define DEBUG 

#ifdef DEBUG
#include "TestyJednostkowe.h"

int main()
{
	//WszystkieTesty::uruchomWszystkieNasze();
	WszystkieTesty::uruchomWszystkie();
}
#endif


#ifdef MAIN

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	w.show();
	return QApplication::exec();
}


#endif











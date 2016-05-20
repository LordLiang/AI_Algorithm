#include "facerecognicer_bp.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	FaceRecognicer_BP w;
	w.show();
	return a.exec();
}

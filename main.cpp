#include "flyingbox.h"
#include <QtGui/QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	FlyingBox w;
	
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
	QTextCodec::setCodecForTr(QTextCodec::codecForLocale());

	w.show();
	return a.exec();
}

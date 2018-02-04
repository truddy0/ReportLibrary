#include "Printer.h"

Printer::~Printer()
{

}

void Printer::initialize()
{
    _printer.setOutputFormat(QPrinter::PdfFormat);
    _printer.setPaperSize(QPrinter::A4);
}

void Printer::print(QList<QGraphicsView *> parentView, QString name)
{
    _printer.setOutputFileName(name);

    _painter.begin(&_printer);

    QRect rect = _painter.viewport();
    QPixmap picture;
    for(int i = 0; i < parentView.count(); i++) {
        //grab the picture
        picture = parentView.at(i)->grab().scaledToWidth(rect.width(), Qt::SmoothTransformation);
        qDebug() << "pic" << picture.width() << picture.height();
        //get the picture size and scale
        QSize size = picture.size();
        size.scale(rect.size(), Qt::IgnoreAspectRatio);
        //set the painter size and draw picture
        _painter.setViewport(rect.x(), rect.y(), rect.width(), (int)(picture.height() * ((double)rect.width() / picture.width())));
        _painter.setWindow(picture.rect());
        _painter.drawPixmap(8, 0, picture);
        //printer create new page
        if(i < parentView.count() - 1) {
            _printer.newPage();
        }
    }
    _painter.end();
}

Printer::Printer()
{
    initialize();
}

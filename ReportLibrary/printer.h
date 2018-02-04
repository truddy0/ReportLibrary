#ifndef PRINTER_H
#define PRINTER_H

#include <QGraphicsView>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QPainter>

class Printer
{
public:
    static Printer& getInstance()
    {
        static Printer instance;
        return instance;
    }
    ~Printer();

    void initialize();
    void print(QList<QGraphicsView*> parentView, QString name);
private:

    Printer(const Printer &);
    Printer& operator=(const Printer &);

    QPrinter _printer;
    QPainter _painter;
};

#endif // PRINTER_H

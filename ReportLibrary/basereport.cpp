#include "Basereport.h"
#include "Printer.h"

BaseReport::BaseReport(int width, int height, int wordingHieght)
{
    _width = width;
    _height = height;
    _wordingHeight = wordingHieght;
}

BaseReport::~BaseReport()
{

}

QGraphicsView *BaseReport::buildContainer()
{
    QGraphicsView *reportView = new QGraphicsView();
    reportView->resize(_width, _height);
    reportView->setStyleSheet("QGraphicsView { border-style: none; }");
    return reportView;
}

bool BaseReport::isNeedNewPage(int currentY, QGraphicsView *parentView, int &currentPage, QWidget *currentComponet, bool isInTable)
{
    if (currentY <= _wordingHeight) {
        return false;
    } else {
        if (!isInTable) {
            currentComponet->setParent(NULL);
        }
        currentPage++;
        return true;
    }
}

void BaseReport::buildComponentOnNewPage(QWidget *currentComponent, QGraphicsView *newParentView, int currentX, int &currentY)
{
    currentComponent->setParent(newParentView);
    currentComponent->setGeometry(currentX, currentY, currentComponent->width(), currentComponent->height());
    currentY += currentComponent->height();
}

void BaseReport::print(QList<QGraphicsView *> parentView, QString fileName)
{
    Printer::getInstance().print(parentView, fileName);
}

QList<QGraphicsView *> BaseReport::getPages()
{
    return _printPages;
}

void BaseReport::resetPages()
{
    _printPages.clear();
}

void BaseReport::addPage(QGraphicsView *view)
{
    _printPages.append(view);
}

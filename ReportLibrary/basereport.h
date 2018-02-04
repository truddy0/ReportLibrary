#ifndef BASEREPORT_H
#define BASEREPORT_H

#include <QGraphicsView>

class BaseReport
{
public:
    BaseReport(int width, int height, int wordingHieght);
    ~BaseReport();
    QGraphicsView* buildContainer();
    bool isNeedNewPage(int currentY, QGraphicsView* parentView, int &currentPage, QWidget *currentComponet, bool isInTable);
    void buildComponentOnNewPage(QWidget* currentComponent, QGraphicsView* newParentView, int currentX, int &currentY);
    void print(QList<QGraphicsView*> parentView, QString fileName);
    QList<QGraphicsView*> getPages();
    void resetPages();
    void addPage(QGraphicsView* view);
private:
    int _width;
    int _height;
    int _wordingHeight;

    QList<QGraphicsView*> _printPages;

};

#endif // BASEREPORT_H

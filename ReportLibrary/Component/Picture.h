#ifndef PICTURE_H
#define PICTURE_H

#include <QLabel>

class Picture
{
public:
    Picture(QWidget *parentWidget, QString path);
    void setPosition(int x, int y, int width, int height);
    int width();
    int height();

private:
    void setUi();
    QLabel* _label;
};

#endif // PICTURE_H

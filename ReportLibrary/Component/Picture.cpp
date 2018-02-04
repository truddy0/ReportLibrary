#include "Picture.h"
#include <QLabel>

Picture::Picture(QWidget* parentWidget, QString path)
{
    setUi();
    QPixmap pic(path);
    _label->setPixmap(pic);
    int picWidth = pic.width() > parentWidget->width() ? parentWidget->width() : pic.width();
    int picHeight = pic.height() > parentWidget->height() ? parentWidget->height() : pic.height();
    _label->resize(picWidth, picHeight);
    _label->setParent(parentWidget);
}

void Picture::setPosition(int x, int y, int width, int height)
{
    _label->setGeometry(x, y, width, height);
}

int Picture::width()
{
    return _label->width();
}

int Picture::height()
{
    return _label->height();
}

void Picture::setUi()
{
    QLabel* label = new QLabel();
    label->setScaledContents(true);
    label->setAlignment(Qt::AlignCenter);
    _label = label;
}

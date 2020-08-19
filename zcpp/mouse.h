#ifndef MOUSE_H
#define MOUSE_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>

class Mouse : public QGraphicsItem
{
public:
    Mouse();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    void advance(int step);

private:
    qreal speed;
    qreal angle;
    void DoCollision();
};

#endif // MOUSE_H

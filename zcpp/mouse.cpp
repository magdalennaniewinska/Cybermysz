#include "mouse.h"

Mouse::Mouse()
{
    //fixed start position
    int start_x = 50;
    int start_y = 50;

    //set speed
    speed = 5;

    setPos(mapToParent(start_x,start_y));
}

QRectF Mouse::boundingRect() const
{
    return QRect(0,0,10,10);
}

void Mouse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();
    QBrush brush(Qt::gray);

    //colision detection
    if(scene()->collidingItems(this).isEmpty())
    {
        //no collision
    }
    else
    {
        //collision
        brush.setColor(Qt::red);

        //set the position
        DoCollision();
    }
    painter->fillRect(rec,brush);
    painter->drawRect(rec);
}

void Mouse::advance(int step)
{
    if(!step) return;
    QPointF location = this->pos();

    setPos(mapToParent(speed,(speed)));
}

void Mouse::DoCollision()
{

}

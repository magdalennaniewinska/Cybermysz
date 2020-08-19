#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mouse.h"

#include <QDebug>






MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(timer_func()));

    scene = new QGraphicsScene(this);
    ui->main_board->setScene(scene);
    ui->main_board->setRenderHint(QPainter::Antialiasing);
    scene->setSceneRect(0,0,498,498);

    QLineF TopLine(scene->sceneRect().topLeft(), scene->sceneRect().topRight());
    QLineF BottomLine(scene->sceneRect().bottomLeft(), scene->sceneRect().bottomRight());
    QLineF LeftLine(scene->sceneRect().topLeft(), scene->sceneRect().bottomLeft());
    QLineF RightLine(scene->sceneRect().topRight(), scene->sceneRect().bottomRight());

    QPen blashpen(Qt::black);
    blashpen.setWidth(1);

    scene->addLine(TopLine,blashpen);
    scene->addLine(BottomLine,blashpen);
    scene->addLine(LeftLine,blashpen);
    scene->addLine(RightLine,blashpen);

    Mouse *m = new Mouse();
    scene->addItem(m);

    t_move = new QTimer(this);
    connect(t_move, SIGNAL(timeout()), scene, SLOT(advance()));


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_maze_choosing_activated(const QString &arg1)
{
    ui->instructions->setText("Ok great! Now is time to choose your mouse.");
}

void MainWindow::on_mouse_choosing_activated(const QString &arg1)
{
    ui->instructions->setText("Now we are ready to try to go through the maze. Keep fingers crossed, click start button and watch how your mouse are doing ;)");
}

void MainWindow::on_start_pushButton_clicked()
{
    maze_timer.start();
    timer->start(10);

    t_move->start(100);
}

void MainWindow::timer_func()
{
    int time_past = maze_timer.elapsed();
    QString time_past_text = QString("%1:%2:%3").arg( time_past / 60000        , 2, 10, QChar('0'))
                                                .arg((time_past % 60000) / 1000, 2, 10, QChar('0'))
                                                .arg(((time_past % 60000) % 1000) /10, 2, 10, QChar('0'));
    ui->stopwatch->setText(time_past_text);

}

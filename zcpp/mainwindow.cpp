#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QElapsedTimer>


QElapsedTimer maze_timer;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(timer_func()));

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    QBrush redBrush(Qt::red);
    QPen blashpen(Qt::black);
    blashpen.setWidth(6);

    mouse = scene->addRect(10,10,100,100,blashpen, redBrush);

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
}

void MainWindow::timer_func()
{
    int time_past = maze_timer.elapsed();
    QString time_past_text = QString("%1:%2:%3").arg( time_past / 60000        , 2, 10, QChar('0'))
                                                .arg((time_past % 60000) / 1000, 2, 10, QChar('0'))
                                                .arg(((time_past % 60000) % 1000) /10, 2, 10, QChar('0'));
    ui->stopwatch->setText(time_past_text);

}

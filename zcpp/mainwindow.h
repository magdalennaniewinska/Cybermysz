#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QElapsedTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void timer_func();

private slots:

    void on_maze_choosing_activated(const QString &arg1);

    void on_mouse_choosing_activated(const QString &arg1);

    void on_start_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QTimer *t_move;
    QGraphicsScene *scene;
    QGraphicsRectItem *mouse;
    QElapsedTimer maze_timer;
};
#endif // MAINWINDOW_H

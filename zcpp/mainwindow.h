#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsRectItem>

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
    void on_pushButton_clicked();

    void on_label_linkActivated(const QString &link);

    void on_comboBox_activated(const QString &arg1);

    void on_comboBox_2_activated(const QString &arg1);

    void on_maze_choosing_activated(const QString &arg1);

    void on_mouse_choosing_activated(const QString &arg1);

    void on_start_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QGraphicsScene *scene;
    QGraphicsRectItem *mouse;
};
#endif // MAINWINDOW_H

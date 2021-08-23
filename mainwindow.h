#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <string>
#include <vector>
#include <QMainWindow>
#include "astar_search.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void ButtonClickedRestore();
    void ButtonClickedStart();
    void BottonClickShow();
    void BottonClickRandom();

private:
    int speed;
    Ui::MainWindow *ui;
    std::vector<int> steps;
    void show_step_id(int);
    void showstep(std::vector<int>);
    void showinit(std::vector<int>);
    void showtarget(std::vector<int>);
    void show_result(std::vector<int>);
    void show_steps();
    std::vector<int> gettarget();
    std::vector<int> getinit();
};
#endif // MAINWINDOW_H

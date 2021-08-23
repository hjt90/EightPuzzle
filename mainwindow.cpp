#include <QDebug>
#include <string>
#include <time.h>
#include <windows.h>
#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Common_tools.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::BottonClickShow()
{
    QString id_str = ui->Go_Where->text();
    bool ok;
    int id = id_str.toInt(&ok);
    if (ok)
        this->show_step_id(id);
    return;
}

void MainWindow::BottonClickRandom()
{
    std::vector<int> init = create_random();
    std::vector<int> target = create_random();
    this->showinit(init);
    this->showtarget(target);
    return;
}

void MainWindow::showstep(std::vector<int> res)
{
    char str[2] = "0";
    str[0] = res[0] + '0';
    ui->output_1->setText(str);
    str[0] = res[1] + '0';
    ui->output_2->setText(str);
    str[0] = res[2] + '0';
    ui->output_3->setText(str);
    str[0] = res[3] + '0';
    ui->output_4->setText(str);
    str[0] = res[4] + '0';
    ui->output_5->setText(str);
    str[0] = res[5] + '0';
    ui->output_6->setText(str);
    str[0] = res[6] + '0';
    ui->output_7->setText(str);
    str[0] = res[7] + '0';
    ui->output_8->setText(str);
    str[0] = res[8] + '0';
    ui->output_9->setText(str);
    return;
}

void MainWindow::showinit(std::vector<int> res)
{
    char str[2] = "0";
    str[0] = res[0] + '0';
    ui->inti_1->setText(str);
    str[0] = res[1] + '0';
    ui->inti_2->setText(str);
    str[0] = res[2] + '0';
    ui->inti_3->setText(str);
    str[0] = res[3] + '0';
    ui->inti_4->setText(str);
    str[0] = res[4] + '0';
    ui->inti_5->setText(str);
    str[0] = res[5] + '0';
    ui->inti_6->setText(str);
    str[0] = res[6] + '0';
    ui->inti_7->setText(str);
    str[0] = res[7] + '0';
    ui->inti_8->setText(str);
    str[0] = res[8] + '0';
    ui->inti_9->setText(str);
    return;
}

void MainWindow::showtarget(std::vector<int> res)
{
    char str[2] = "0";
    str[0] = res[0] + '0';
    ui->target_1->setText(str);
    str[0] = res[1] + '0';
    ui->target_2->setText(str);
    str[0] = res[2] + '0';
    ui->target_3->setText(str);
    str[0] = res[3] + '0';
    ui->target_4->setText(str);
    str[0] = res[4] + '0';
    ui->target_5->setText(str);
    str[0] = res[5] + '0';
    ui->target_6->setText(str);
    str[0] = res[6] + '0';
    ui->target_7->setText(str);
    str[0] = res[7] + '0';
    ui->target_8->setText(str);
    str[0] = res[8] + '0';
    ui->target_9->setText(str);
    return;
}

void MainWindow::ButtonClickedRestore()
{
    std::vector<int> init_num = {8, 6, 7, 0, 5, 1, 4, 3, 2};
    this->showinit(init_num);

    std::vector<int> target_num = {1, 2, 3, 4, 5, 6, 7, 8, 0};
    this->showtarget(target_num);

    return;
}

std::vector<int> MainWindow::getinit()
{
    std::vector<int> res(9);
    bool ok[9] = {0};
    QString str = ui->inti_1->text();
    res[0] = str.toInt(&ok[0]);
    str = ui->inti_2->text();
    res[1] = str.toInt(&ok[1]);
    str = ui->inti_3->text();
    res[2] = str.toInt(&ok[2]);
    str = ui->inti_4->text();
    res[3] = str.toInt(&ok[3]);
    str = ui->inti_5->text();
    res[4] = str.toInt(&ok[4]);
    str = ui->inti_6->text();
    res[5] = str.toInt(&ok[5]);
    str = ui->inti_7->text();
    res[6] = str.toInt(&ok[6]);
    str = ui->inti_8->text();
    res[7] = str.toInt(&ok[7]);
    str = ui->inti_9->text();
    res[8] = str.toInt(&ok[8]);
    for (int i = 0; i < 9; i++)
        if (!ok[i])
        {
            QMessageBox message(QMessageBox::Warning, "错误", "初始输入含有非数字字符");
            message.exec();
            res[0] = -1;
            return res;
        }
    bool vis[9] = {0};
    for (int i = 0; i < 9; i++)
    {
        if (res[i] >= 0 && res[i] < 9)
            vis[res[i]] = 1;
        else
        {
            QMessageBox message(QMessageBox::Warning, "错误", "初始输入含有只能为0~9");
            message.exec();
            res[0] = -1;
            return res;
        }
    }
    for (int i = 0; i < 9; i++)
        if (!vis[i])
        {
            QMessageBox message(QMessageBox::Warning, "错误", "初始输入含有重复数字");
            message.exec();
            res[0] = -1;
            return res;
        }
    return res;
}

std::vector<int> MainWindow::gettarget()
{
    std::vector<int> res(9);
    bool ok[9] = {0};
    QString str = ui->target_1->text();
    res[0] = str.toInt(&ok[0]);
    str = ui->target_2->text();
    res[1] = str.toInt(&ok[1]);
    str = ui->target_3->text();
    res[2] = str.toInt(&ok[2]);
    str = ui->target_4->text();
    res[3] = str.toInt(&ok[3]);
    str = ui->target_5->text();
    res[4] = str.toInt(&ok[4]);
    str = ui->target_6->text();
    res[5] = str.toInt(&ok[5]);
    str = ui->target_7->text();
    res[6] = str.toInt(&ok[6]);
    str = ui->target_8->text();
    res[7] = str.toInt(&ok[7]);
    str = ui->target_9->text();
    res[8] = str.toInt(&ok[8]);
    for (int i = 0; i < 9; i++)
        if (!ok[i])
        {
            QMessageBox message(QMessageBox::Warning, "错误", "目标输入含有非数字字符");
            message.exec();
            res[0] = -1;
            return res;
        }
    bool vis[9] = {0};
    for (int i = 0; i < 9; i++)
    {
        if (res[i] >= 0 && res[i] < 9)
            vis[res[i]] = 1;
        else
        {
            QMessageBox message(QMessageBox::Warning, "错误", "目标输入含有只能为0~9");
            message.exec();
            res[0] = -1;
            return res;
        }
    }
    for (int i = 0; i < 9; i++)
        if (!vis[i])
        {
            QMessageBox message(QMessageBox::Warning, "错误", "目标输入含有重复数字");
            message.exec();
            res[0] = -1;
            return res;
        }
    return res;
}

void MainWindow::show_step_id(int id)
{
    if (this->steps.empty() || id > this->steps.size())
        return;
    this->showstep(int2vector(this->steps[id]));
    return;
}

void MainWindow::show_result(std::vector<int> res)
{
    std::string res_str;
    res_str = std::string("时间: ") + std::to_string(int(double(res[0]) / CLOCKS_PER_SEC * 1000)) + std::string("ms");
    ui->time_label->setText(res_str.c_str());
    res_str = std::string("解步长: ") + std::to_string(res[1]);
    ui->step_label->setText(res_str.c_str());
    res_str = std::string("已扩展节点: ") + std::to_string(res[2] - res[3]);
    ui->expanded_label->setText(res_str.c_str());
    res_str = std::string("待扩展节点: ") + std::to_string(res[3]);
    ui->to_expand_label->setText(res_str.c_str());
    res_str = std::string("外显率: ") + std::to_string(double(res[1]) / res[2]);
    ui->waixianlv->setText(res_str.c_str());
    res_str = std::string("有效分枝因数: ") + std::to_string(calculate_B(res[2],res[1]));
    ui->fenzhiyinshu->setText(res_str.c_str());
    res_str.clear();
    for (int i = 0; i < this->steps.size(); i++)
    {
        if (this->steps[i] > 99999999)
            res_str += std::to_string(this->steps[i]) + std::string("\n");
        else
            res_str += std::string("0") + std::to_string(this->steps[i]) + std::string("\n");
    }
    ui->out_show->setText(res_str.c_str());
}

void MainWindow::show_steps()
{
    int len = this->steps.size();
    for (int i = 0; i < len; i++)
    {
        //qApp->processEvents();
        QApplication::processEvents();
        int speed = ui->speed->value();
        this->showstep(int2vector(this->steps[i]));
        if (speed > 0 && speed <= 10)
            Sleep(1000 / speed);
        else
            Sleep(1000 / 2);
    }
    return;
}

void MainWindow::ButtonClickedStart()
{
    ui->start->setDisabled(true);
    //ui->speed->setTracking(false);
    std::vector<int> init_vector = this->getinit();
    if (init_vector[0] == -1)
    {
        ui->start->setEnabled(true);
        ui->speed->setTracking(true);
        return;
    }
    int init = vector2int(init_vector);

    std::vector<int> target = this->gettarget();
    if (target[0] == -1)
    {
        ui->start->setEnabled(true);
        ui->speed->setTracking(true);
        return;
    }
    int goal = vector2int(target);
    CountH_Type type = CountH_Type::Euclid;
    int get_type = ui->algorithm_type->currentIndex();
    switch (get_type)
    {
    case 0:
        type = CountH_Type::Euclid;
        break;
    case 1:
        type = CountH_Type::HVdist;
        break;
    case 2:
        type = CountH_Type::Simple;
        break;
    case 3:
        type = CountH_Type::BFS;
        break;
    default:
        break;
    }

    if (!Astar_search::check_ok(init, goal))
    {
        QMessageBox message(QMessageBox::Information, "结果", "  该输入无解  ");
        message.exec();
        ui->start->setEnabled(true);
        ui->speed->setTracking(true);
        return;
    }

    if (type == CountH_Type::BFS)
    {
        QMessageBox message(QMessageBox::Information, "建议", "建议先确定解步长少于15步\n否则关闭该程序");
        message.exec();
    }
    if (type == CountH_Type::Simple)
    {
        QMessageBox message(QMessageBox::Information, "建议", "该算法较慢，请耐心等待\n若出现无响应是正常情况");
        message.exec();
    }

    Astar_search eight_puzzle(init, goal, type);
    std::vector<int> res = eight_puzzle.start_search();
    this->steps = eight_puzzle.show_path();

    this->show_result(res);
    this->show_steps();

    //ui->speed->setTracking(true);
    ui->start->setEnabled(true);
    return;
}

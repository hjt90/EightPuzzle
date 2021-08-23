#include "error_out.h"
#include "ui_error_out.h"

error_out::error_out(QWidget *parent) : QDialog(parent),
                                        ui(new Ui::error_out)
{
    ui->setupUi(this);
}

error_out::~error_out()
{
    delete ui;
}

void error_out::error_out_str(std::string str)
{
    ui->label->setText(str.c_str());
}

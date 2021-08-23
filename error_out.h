#ifndef ERROR_OUT_H
#define ERROR_OUT_H

#include <string>
#include <QDialog>

namespace Ui
{
    class error_out;
}

class error_out : public QDialog
{
    Q_OBJECT

public:
    explicit error_out(QWidget *parent = nullptr);
    void error_out_str(std::string);
    ~error_out();

private:
    Ui::error_out *ui;
};

#endif // ERROR_OUT_H

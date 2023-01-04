#ifndef DATEBOX_H
#define DATEBOX_H

#include <QWidget>

namespace Ui {
class DateBox;
}

class DateBox : public QWidget
{
    Q_OBJECT

public:
    explicit DateBox(QWidget *parent = nullptr);
    ~DateBox();

private:
    Ui::DateBox *ui;
};

#endif // DATEBOX_H

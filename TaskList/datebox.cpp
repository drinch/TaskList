#include "datebox.h"
#include "ui_datebox.h"

DateBox::DateBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DateBox)
{
    ui->setupUi(this);
}

DateBox::~DateBox()
{
    delete ui;
}

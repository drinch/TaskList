#include "taskpage.h"
#include "ui_taskpage.h"
#include <QDate>
#include <QPushButton>

TaskPage::TaskPage(QWidget *parent,Task *task_) :
    QWidget(parent),
    ui(new Ui::TaskPage),
    task(task_)
{
    ui->setupUi(this);
    connect(ui->backButton,&QPushButton::clicked,[=](){emit back();});
}

TaskPage::~TaskPage()
{
    delete ui;
}
void TaskPage::saveTask(){
    task->title=ui->titleLabel->text();
    task->info=ui->infoLabel->text();
    QDate deadline=QDate::fromString(ui->deadlineLabel->text(),"yyyyMMdd");
    task->setDate(deadline);
}
void TaskPage::loadTask(Task *task_){
    task=task_;
    ui->titleLabel->setText(task->title);
    ui->infoLabel->setText(task->info);
    ui->deadlineLabel->setText(task->dateText());
}

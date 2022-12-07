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
    task->title=ui->titleEdit->text();
    task->info=ui->infoEdit->toPlainText();
    QDate deadline=QDate::fromString(ui->deadlineLabel->text(),"yyyyMMdd");
    task->setDate(deadline);
}
void TaskPage::loadTask(Task *task_){
    task=task_;
    ui->titleEdit->setText(task->title);
    ui->infoEdit->setText(task->info);
    ui->deadlineLabel->setText(task->dateText());
}

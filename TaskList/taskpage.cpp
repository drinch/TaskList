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
    //保存任务，将任务信息保存至所选任务中
    task->title=ui->titleEdit->text();
    task->info=ui->infoEdit->toPlainText();
    QDate deadline=ui->dateEdit->date();
    task->setDate(deadline);
}
void TaskPage::loadTask(Task *task_){
    //编辑任务，将任务信息写入编辑页面
    task=task_;
    ui->titleEdit->setText(task->title);
    ui->infoEdit->setText(task->info);
    ui->dateEdit->setDate(QDate::fromString(task->dateText(),"yyyyMMdd"));
}

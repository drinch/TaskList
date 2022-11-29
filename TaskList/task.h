#ifndef TASK_H
#define TASK_H

#include <QString>
#include <QDate>

class Task{
    QDate startdate,enddate;
public:
    QString title,info;

    Task();
    Task(QString title_,QString info_="",QDate startdate_=QDate::currentDate(),QDate enddate_=QDate::currentDate());
    Task(const Task& task);
    void operator = (const Task& task);
    void setTitle(QString title_);
    void setInfo(QString info_);
    void setDate(QDate& startdate_,QDate& enddate_);
    void setDate(QDate& date_);
    void setTask(Task task);
    QString getTitle();
    QString getInfo();
    QDate& getStartDate();
    QDate& getEndDate();
    bool dateType();
    QString dateText();
    QString saveTask();
    void loadTask(QString taskstring);
    bool operator < (const Task& task) const;
};
#endif // TASK_H

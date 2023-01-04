#include "task.h"

Task::Task(){
    this->title=QString();
    this->info=QString();
    this->startdate=QDate::currentDate();
    this->enddate=QDate::currentDate();
}
Task::Task(QString title_,QString info_,QDate startdate_,QDate enddate_){
    this->title=title_;
    this->info=info_;
    this->startdate=startdate_;
    this->enddate=enddate_;
}
Task::Task(const Task& task){
    this->title=task.title;
    this->info=task.info;
    this->startdate=task.startdate;
    this->enddate=task.enddate;
}
void Task::operator = (const Task& task){
    this->title=task.title;
    this->info=task.info;
    this->startdate=task.startdate;
    this->enddate=task.enddate;
}
void Task::setTitle(QString title_){
    this->title=title_;
}
void Task::setInfo(QString info_){
    this->info=info_;
}
void Task::setDate(QDate& startdate_,QDate& enddate_){
    this->startdate=startdate_;
    if(enddate_>=startdate_) this->enddate=enddate_;
    else this->enddate=startdate_;
}
void Task::setDate(QDate& date_){
    setDate(date_,date_);
}
void Task::setTask(Task task){
    this->title=task.title;
    this->info=task.info;
    this->startdate=task.startdate;
    this->enddate=task.enddate;
}
bool Task::dateType(){
    return (this->startdate==this->enddate);
}
QString Task::dateText(){
    if(this->dateType()) return startdate.toString("yyyyMMdd");
    else return startdate.toString("yyyyMMdd")+"-"+enddate.toString("yyyyMMdd");
}
QString Task::saveTask(){
    QString taskstring;
    taskstring+="title:"+this->title+"&";
    taskstring+="info:"+this->info+"&";
    taskstring+="startdate:"+this->startdate.toString("yyyyMMdd")+"&";
    taskstring+="enddate:"+this->enddate.toString("yyyyMMdd")+"&";
    return taskstring;
}
void Task::loadTask(QString taskstring){
    QString name,value;
    int st=0;
    for(int i=st;i<taskstring.length();i++){
        if(taskstring[i]==':'){
            name=taskstring.mid(st,i-st);
            st=i+1;
        }else if(taskstring[i]=='&'){
            value=taskstring.mid(st,i-st);
            st=i+1;
            if(name=="title"){
                this->setTitle(value);
            }else if(name=="info"){
                this->setInfo(value);
            }else if(name=="startdate"){
                this->startdate.fromString(value,"yyyyMMdd");
            }else if(name=="enddate"){
                this->enddate.fromString(value,"yyyyMMdd");
            }
        }
    }
}
bool Task::operator < (const Task& task) const{
    if(this->enddate==task.enddate) {
        if(this->startdate==task.startdate) {
            if(this->title==task.title) return this->info<task.info;
            else return this->title<task.title;
        }else return this->startdate<task.startdate;
    }
    else return this->enddate<task.enddate;
}

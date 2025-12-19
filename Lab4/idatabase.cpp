#include "idatabase.h"
#include <QUuid>

void IDatabase::ininDatabase()
{
    database=QSqlDatabase::addDatabase("QSQLITE");
    QString aFile="F:/Qt/Project/test three/lib4.db";
    database.setDatabaseName(aFile);//设置数据库名称

    if(!database.open()) {//打开数据库
        qDebug() << "failed to open database";
    } else
        qDebug() << "open database is ok" << database.connectionName();
}

bool IDatabase::initPatientModel()
{
    patientTabModel = new QSqlTableModel(this,database);
    patientTabModel->setTable("patient");
    patientTabModel->setEditStrategy(QSqlTableModel::OnManualSubmit);//数据保存方式,OnManualsubmit ,onRowchange
    patientTabModel->setSort(patientTabModel->fieldIndex("name"), Qt::AscendingOrder); //排序
    if(!(patientTabModel->select()))
        return false;

    thePatientSelection = new QItemSelectionModel(patientTabModel);
    return true;
}

int IDatabase::addNewPatient()
{

    patientTabModel->insertRow(patientTabModel->rowCount(),
                               QModelIndex());//在末尾添加一个记录
    QModelIndex curIndex= patientTabModel->index(patientTabModel->rowCount()- 1,
                                                 1);//创建最后一行的ModelIndex
    int curRecNo =curIndex.row();QSqlRecord curRec =patientTabModel->record(curRecNo);//获取当前记录
    curRec.setValue("CREATEDTIMESTAMP", QDateTime::currentDateTime().toString("yyyy-MM-d"));
    curRec.setValue("ID", QUuid::createUuid().toString(QUuid::WithoutBraces));

    patientTabModel->setRecord(curRecNo,curRec);

    return curIndex.row();
}

bool IDatabase::searchPatient(QString filter)
{
    patientTabModel->setFilter(filter);
    return patientTabModel->select();
}

bool IDatabase::deletecurrentPatient()
{
    QModelIndex curIndex = thePatientSelection->currentIndex();
    patientTabModel->removeRow(curIndex.row());
    patientTabModel->submitAll();
    patientTabModel->select();
}

bool IDatabase::submitPatientEdit()
{
    return patientTabModel->submitAll();
}

bool IDatabase::revertPatientEdit()
{
    patientTabModel->revertAll();
}

QString IDatabase::userLogin(QString userName, QString password)
{
    QSqlQuery query;//查询出当前记录的所有字段
    query.prepare("select username,password from user where username = :USER");
    query.bindValue(":USER",userName);
    query.exec();
    qDebug() << query.lastQuery() << query.first();

    if(query.first() && query.value("username").isValid()){
        QString passwd = query.value("password").toString();
        if (passwd == password){
            qDebug() << "loginOK";
            return "loginOK";
        } else{
            qDebug() << "wrongPassword";
            return "wrongPassword";
        }
    }
    else{
        qDebug() << "no such user";
        return "loginFailed";
    }
    query.first();

    return "loginFailed";
}

IDatabase::IDatabase(QObject *parent) : QObject(parent)
{
    ininDatabase();
}

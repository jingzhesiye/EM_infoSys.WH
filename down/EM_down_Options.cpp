#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QSqlQuery"
#include "QDebug"
#include "QSqlRecord"
#include "QSqlError"
#include "QFile"
#include "QDateTime"
#include "QMessageBox"


//通过条形码到MDS下载到的信息
void MainWindow::on_EM_down_insertLocalSql_PsBtn_clicked()
{
    down_MT_METER(ui->EM_down_barCode_LnEdit->text());

}

//清除表格
void MainWindow::on_EM_down_clean_PsBtn_clicked()
{
     remove_TblWdiget_Row(ui->EM_P_CODE_TblWidget);
     remove_TblWdiget_Row(ui->EM_METER_TblWidget);
     remove_TblWdiget_Row(ui->EM_DETECT_TASK_TblWidget);
     remove_TblWdiget_Row(ui->EM_DETECT_OUT_EQUIP_TblWidget);
}

//保存数据到当前数据库
void MainWindow::on_EM_down_saveLocalSql_PsBtn_clicked()
{
    setCursor(QCursor(Qt::WaitCursor));
    QString strExec ,strBarCode;
    strBarCode = ui->EM_down_barCode_LnEdit->text();
    strExec = QString("select * from  MT_DETECT_TASK where BAR_CODE = '%1'").arg(strBarCode);

    if(isLocalBarCodeExist(strExec,strBarCode))
    {
        showInformationBox(QString::fromUtf8("当前条形码数据已存在，请删除原先数据再重新保存"));
        setCursor(QCursor(Qt::ArrowCursor));
        return ;
    }

    save_MT_P_CODE();
    save_MT_METER();
    save_MT_DETECT_TASK();
    save_MT_DETECT_OUT_EQUIP();
    setCursor(QCursor(Qt::ArrowCursor));
}

//查看以往的数据库
void MainWindow::on_EM_down_loadLocalSql_PsBtn_clicked()
{
    QString  strExec,strBarCode;
    setCursor(QCursor(Qt::WaitCursor));
    on_EM_down_clean_PsBtn_clicked();
    strBarCode = ui->EM_down_barCode_LnEdit->text();

    #if 0
    //查看全部
    getDataFromLocalSqlToTblWidget("select * from  MT_P_CODE;",ui->EM_P_CODE_TblWidget,ui->EM_P_CODE_TblWidget->columnCount());
    getDataFromLocalSqlToTblWidget("select * from  MT_METER;",ui->EM_METER_TblWidget,ui->EM_METER_TblWidget->columnCount());
    getDataFromLocalSqlToTblWidget("select * from  MT_DETECT_TASK;",ui->EM_DETECT_TASK_TblWidget,ui->EM_DETECT_TASK_TblWidget->columnCount());
    getDataFromLocalSqlToTblWidget("select * from  MT_DETECT_OUT_EQUIP;",ui->EM_DETECT_OUT_EQUIP_TblWidget,ui->EM_DETECT_OUT_EQUIP_TblWidget->columnCount());
    #endif

    #if 1
    //查看某条记录
    strExec = QString("select * from  MT_P_CODE where BAR_CODE = '%1'").arg(strBarCode);
    getDataFromLocalSqlToTblWidget(strExec,ui->EM_P_CODE_TblWidget,ui->EM_P_CODE_TblWidget->columnCount());

    strExec = QString("select * from  MT_METER where BAR_CODE = '%1'").arg(strBarCode);
    getDataFromLocalSqlToTblWidget(strExec,ui->EM_METER_TblWidget,ui->EM_METER_TblWidget->columnCount());

    strExec = QString("select * from  MT_DETECT_TASK where BAR_CODE = '%1'").arg(strBarCode);
    getDataFromLocalSqlToTblWidget(strExec,ui->EM_DETECT_TASK_TblWidget,ui->EM_DETECT_TASK_TblWidget->columnCount());

    strExec = QString("select * from  MT_DETECT_OUT_EQUIP where BAR_CODE = '%1'").arg(strBarCode);
    getDataFromLocalSqlToTblWidget(strExec,ui->EM_DETECT_OUT_EQUIP_TblWidget,ui->EM_DETECT_OUT_EQUIP_TblWidget->columnCount());
    #endif

    setCursor(QCursor(Qt::ArrowCursor));
}



void MainWindow::on_EM_down_deleteLocalSqlItem_PsBtn_clicked()
{
    QString strExec,strBarCode;
    QByteArray byteArray;
    strBarCode = ui->EM_down_barCode_LnEdit->text();

    strExec=QString("delete  from MT_P_CODE where BAR_CODE ='%1'").arg(strBarCode);
    byteArray = strExec.toLocal8Bit();
    sql_exec(byteArray.data());

    strExec=QString("delete  from MT_METER where BAR_CODE ='%1'").arg(strBarCode);
    byteArray = strExec.toLocal8Bit();
    sql_exec(byteArray.data());

    strExec=QString("delete  from MT_DETECT_TASK where BAR_CODE ='%1'").arg(strBarCode);
    byteArray = strExec.toLocal8Bit();
    sql_exec(byteArray.data());

    strExec=QString("delete from MT_DETECT_OUT_EQUIP where BAR_CODE ='%1'").arg(strBarCode);
    byteArray = strExec.toLocal8Bit();
    sql_exec(byteArray.data());

    showInformationBox(QString::fromUtf8("删除成功，请读查看以确认"));
    //on_EM_down_loadLocalSql_PsBtn_clicked();

}

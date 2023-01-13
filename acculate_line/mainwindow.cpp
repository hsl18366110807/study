#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qdir.h>
#include <qset.h>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), m_target_file_num(0), m_target_source_num(0)
    , m_protect_count(100000), m_dir_path("")
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    m_target_file_num = 0;
    m_target_source_num = 0;
    m_protect_count = 0;
    m_filter_type = "";
    m_dir_path = "";
    m_file_type_set.clear();
}

void MainWindow::analyse_dir(QString dir_path){
    QDir Dir(dir_path);
    if(!Dir.exists()) return;//查看工作路径是否存在

    QStringList dir_list = Dir.entryList(QDir::Dirs);
    //递归查询文件夹
    for(int i=2;i<dir_list.count();++i){
        QString tmp_dir_path = Dir.filePath(dir_list[i]);
        analyse_dir(tmp_dir_path);
    }
    QStringList list = Dir.entryList(QDir::Files);  			//获取所有文件
    foreach (QFileInfo file, list)
    {
        QString file_type = file.fileName().split(".").back();
        if(!m_file_type_set.contains(file_type)) m_file_type_set.insert(file_type);
    }
}

void MainWindow::analyse_file(QString file_path){
    QFile file(file_path);
    if(!file.exists()) return;
    m_dir_path = file_path;
    if (!file.open(QIODevice::ReadOnly))
        return;
    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        ++m_target_source_num;
        if(m_target_source_num>m_protect_count){
            //todo 终止程序
        }
    }
    ui->m_textEdit_files->append(file.fileName());
}

bool MainWindow::isDirExist(QString fullPath){
    QDir dir(fullPath);
    if(dir.exists())
    {
      return true;
    }
    return false;
}

void MainWindow::begin_analyse(QString path){
    ui->m_combox_file_type->clear();
    m_file_type_set.clear();
    m_target_file_num= 0;
    m_target_source_num = 0;
    if(isDirExist(path)) analyse_dir(path);
    else{
        analyse_file(path);
        m_target_file_num = 1;
    }

    foreach (QString type, m_file_type_set) {
        ui->m_combox_file_type->addItem(type);
    }

    ui->m_lineEdit_files_count->setText(QString::number(m_target_file_num, 10));
    ui->m_lineEdit_source_count->setText(QString::number(m_target_source_num, 10));
}

void MainWindow::on_m_button_choose_dir_clicked()
{
    QString str = QFileDialog::getExistingDirectory(
                     this, "选择要打开的文件夹",
                     "./");
    ui->m_lineEdit_dir_path->setText(str);
}


void MainWindow::filter_files(QString file_type){
    QDir Dir(m_dir_path);
    if(!Dir.exists()) return;//查看工作路径是否存在
    QStringList dir_list = Dir.entryList(QDir::Dirs);
    //递归查询文件夹
    for(int i=2;i<dir_list.count();++i){
        QString tmp_dir_path = Dir.filePath(dir_list[i]);
        m_dir_path = tmp_dir_path;
        filter_files(file_type);
    }
    //筛选
    QStringList list = Dir.entryList(QDir::Files);  			//获取所有文件
    foreach (QFileInfo file, list)
    {
        if(file.fileName().split(".").back() == file_type)          //判断进行再次确认是不是目标文件
        {
            QString tmp_file_path = Dir.filePath(file.fileName());
            analyse_file(tmp_file_path);
            ++m_target_file_num;
        }
    }
}

void MainWindow::on_m_button_analyse_clicked()
{
    begin_analyse(m_dir_path);
}

void MainWindow::on_m_lineEdit_dir_path_textChanged(const QString &arg1)
{
    m_dir_path = arg1;
}

void MainWindow::on_m_combox_file_type_activated(const QString &arg1)
{
    ui->m_textEdit_files->clear();
    m_target_file_num = 0;
    m_target_source_num = 0;
    m_dir_path = ui->m_lineEdit_dir_path->text();
    filter_files(arg1);
    ui->m_lineEdit_files_count->setText(QString::number(m_target_file_num, 10));
    ui->m_lineEdit_source_count->setText(QString::number(m_target_source_num, 10));
}

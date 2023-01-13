#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qdir.h>
#include <QFileDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), m_target_file_num(0), m_target_source_num(0)
    , m_protect_count(100000), m_auto_filter_type(true)
{
    ui->setupUi(this);
    init_data();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init_data(){
    ui->m_combox_file_type->addItem("cpp");
    ui->m_combox_file_type->addItem("h");
    m_filter_type = ui->m_combox_file_type->currentText();
}

void MainWindow::analyse_dir(QString dir_path){
    QDir Dir(dir_path);
    if(!Dir.exists()||m_filter_type == "") return;//查看工作路径是否存在

    QStringList dir_list = Dir.entryList(QDir::Dirs);
    //递归查询文件夹
    for(int i=2;i<dir_list.count();++i){
        QString tmp_dir_path = Dir.filePath(dir_list[i]);
        analyse_dir(tmp_dir_path);
    }

    QStringList list = Dir.entryList(QDir::Files);  			//获取所有文件
    foreach (QFileInfo file, list)
    {
        if(file.fileName().split(".").back() == m_filter_type)          //判断进行再次确认是不是目标文件
        {
            QString tmp_file_path = Dir.filePath(file.fileName());
            analyse_file(tmp_file_path);
            ++m_target_file_num;
        }
    }
}

void MainWindow::analyse_file(QString file_path){
    QFile file(file_path);
    if(!file.exists()) return;
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
    ui->m_textEdit_files->clear();
    m_target_file_num = 0;
    m_target_source_num = 0;

    if(isDirExist(path)) analyse_dir(path);
    else{
        analyse_file(path);
        m_target_file_num = 1;
    }

    ui->m_lineEdit_files_count->setText(QString::number(m_target_file_num, 10));
    ui->m_lineEdit_source_count->setText(QString::number(m_target_source_num, 10));
}

void MainWindow::on_m_button_begin_clicked()
{
    QString dir_path = ui->m_lineEdit_dir_path->text();
    this->begin_analyse(dir_path);
}

void MainWindow::on_m_button_choose_dir_clicked()
{
    QString str = QFileDialog::getExistingDirectory(
                     this, "选择要打开的文件夹",
                     "./");
    ui->m_lineEdit_dir_path->setText(str);
}


void MainWindow::on_m_button_manul_filter_clicked()
{
    m_auto_filter_type = !m_auto_filter_type;
    if(m_auto_filter_type){
        ui->m_button_manul_filter->setText("auto filter");
        m_filter_type = ui->m_combox_file_type->currentText();
    }else{
      ui->m_button_manul_filter->setText("manul filter");
      m_filter_type = ui->m_text_input_type->text();
    }
}

void MainWindow::on_m_combox_file_type_currentIndexChanged(const QString &arg1)
{
    if(m_auto_filter_type) m_filter_type = arg1;
}

void MainWindow::on_m_text_input_type_textChanged(const QString &arg1)
{
    if(!m_auto_filter_type) m_filter_type = arg1;
}

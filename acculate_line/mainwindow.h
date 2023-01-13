#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qset.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_m_button_choose_dir_clicked();

    void on_m_button_analyse_clicked();

    void on_m_lineEdit_dir_path_textChanged(const QString &arg1);

    void on_m_combox_file_type_activated(const QString &arg1);

private:
    void begin_analyse(QString dir_path);
    void analyse_dir(QString dir_path);
    void analyse_file(QString file_path);
    void filter_files(QString file_type);
    bool isDirExist(QString fullPath);

private:
    Ui::MainWindow *ui;
    int m_target_file_num;
    int m_target_source_num;
    int m_protect_count;
    QString m_filter_type;
    QString m_dir_path;
    QSet<QString> m_file_type_set;
};
#endif // MAINWINDOW_H

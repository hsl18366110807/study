#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_m_button_begin_clicked();
    void on_m_button_choose_dir_clicked();
    void on_m_button_manul_filter_clicked();
    void on_m_combox_file_type_currentIndexChanged(const QString &arg1);
    void on_m_text_input_type_textChanged(const QString &arg1);

private:
    void init_data();
    void begin_analyse(QString dir_path);
    void analyse_dir(QString dir_path);
    void analyse_file(QString file_path);
    bool isDirExist(QString fullPath);

private:
    Ui::MainWindow *ui;
    int m_target_file_num;
    int m_target_source_num;
    int m_protect_count;
    bool m_auto_filter_type;
    QString m_filter_type;
};
#endif // MAINWINDOW_H

#ifndef TIMEDCONFIRMDIALOG_H
#define TIMEDCONFIRMDIALOG_H

#include <QDialog>

namespace Ui {
class TimedConfirmDialog;
}

class TimedConfirmDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TimedConfirmDialog(QWidget *parent = nullptr, int timeout = 10);
    ~TimedConfirmDialog();

signals:
    void finished();

private slots:
    void update();

private:
    Ui::TimedConfirmDialog *ui;
    int timeout_;
    QTimer* timer_;
};

#endif // TIMEDCONFIRMDIALOG_H

#ifndef SPECIALISTWINDOW_H
#define SPECIALISTWINDOW_H

#include <QDialog>

namespace Ui {
class SpecialistWindow;
}

class SpecialistWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SpecialistWindow(QWidget *parent = nullptr);
    ~SpecialistWindow();

private:
    Ui::SpecialistWindow *ui;
};

#endif // SPECIALISTWINDOW_H

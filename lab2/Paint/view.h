#ifndef VIEW_H
#define VIEW_H

#include <QDialog>
#include <QLabel>


#include "scene.h"

QT_BEGIN_NAMESPACE
namespace Ui { class View; }
QT_END_NAMESPACE

class View : public QDialog
{
    Q_OBJECT

public:
    View(QWidget *parent = nullptr);
    ~View();

    void changeColor(QLabel *label, QColor color);

public slots:
    void addNewFigure();
    void removeFigure();

private slots:
    void on_penSizeSlider_valueChanged(int value);

    void on_figures_currentIndexChanged(int index);

    void on_penColorButton_clicked();

    void on_fillColorButton_clicked();

    void on_undoButton_clicked();

    void on_redoButton_clicked();

    void on_deleteButton_clicked();

    void on_copyButton_clicked();

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::View *ui;
    Scene *scene;

    void resizeEvent(QResizeEvent *event) override;
};
#endif // VIEW_H

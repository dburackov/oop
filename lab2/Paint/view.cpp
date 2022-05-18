#include "view.h"
#include "ui_view.h"

#include <QColor>
#include <QDebug>
#include <QColorDialog>

#include "scene.h"

View::View(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::View)
{
    ui->setupUi(this);

    this->setWindowTitle("Paint");

    this->resize(1600, 900);

    ui->penSizeSlider->setTickInterval(1);
    ui->penSizeSlider->setMinimum(1);
    ui->penSizeSlider->setMaximum(20);

    scene = new Scene();
    scene->setSceneRect(0,0, ui->graphicsView->width() - 20, ui->graphicsView->height() - 20);
    scene->figureType = FigureType(ui->figures->currentIndex());

    ui->penSizeSlider->setSliderPosition(scene->penSize);
    changeColor(ui->penColor, scene->penColor);
    changeColor(ui->fillColor, scene->fillColor);

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setMouseTracking(true);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

    QObject::connect(scene, SIGNAL(addNewFigureSignal()), this, SLOT(addNewFigure()));
    QObject::connect(scene, SIGNAL(removeFigureSignel()), this, SLOT(removeFigure()));
}

View::~View()
{
    delete ui;
}


void View::changeColor(QLabel *label, QColor color) {
    label->setStyleSheet("background-color: " + color.name());
}

void View::addNewFigure()
{
    ui->comboBox->addItem(QString::number(ui->comboBox->count()));
}

void View::removeFigure()
{
    ui->comboBox->removeItem(ui->comboBox->count() - 1);
}


void View::on_penSizeSlider_valueChanged(int value)
{
    ui->penSizeLabel->setText(QString::number(value));
    scene->penSize = value;
}


void View::on_figures_currentIndexChanged(int index)
{
    scene->figureType = FigureType(index);
}


void View::on_penColorButton_clicked()
{
    QColor color = QColorDialog::getColor();
    if (color.isValid()) {
        scene->penColor = color;
        changeColor(ui->penColor, color);
    }
}


void View::on_fillColorButton_clicked()
{
    QColor color = QColorDialog::getColor();
    if (color.isValid()) {
        scene->fillColor = color;
        changeColor(ui->fillColor, color);
     }
}


void View::on_undoButton_clicked()
{
    scene->undo();
}


void View::on_redoButton_clicked()
{
    scene->redo();
}


void View::on_deleteButton_clicked()
{
    scene->deleteFigure();
    ui->comboBox->setCurrentIndex(0);
}


void View::on_copyButton_clicked()
{
    scene->copyCommand();
}

void View::resizeEvent(QResizeEvent *event)
{
    scene->setSceneRect(0,0, ui->graphicsView->width() - 20, ui->graphicsView->height() - 20);
}


void View::on_comboBox_currentIndexChanged(int index)
{
    scene->setActiveItem(index);
}


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "custombutton.h"

#include <QGraphicsDropShadowEffect>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Data for the button: Name and HP values
    QVector<QPair<QString, int>> data = {
        {"Josh", 75},
        {"James", 50},
        {"Adam", 90}
    };

    // Create CustomButton and embed it within crewHealth
    CustomButton* button = new CustomButton(data, ui->crewHealth);

    // Add a layout to crewHealth (if not already set in Designer)
    QVBoxLayout* crewHealthLayout = new QVBoxLayout(ui->crewHealth);
    crewHealthLayout->addWidget(button);

    // Adjust the layout margins to add padding
    crewHealthLayout->setContentsMargins(0, 20, 0, 0); // Top padding of 20px
    crewHealthLayout->setSpacing(10); // Spacing between child widgets

    // Set layout (optional if already set in Designer)
    ui->crewHealth->setLayout(crewHealthLayout);


    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect(this);
    effect->setBlurRadius(10);    // Adjust blur radius
    effect->setOffset(3, 3);      // Set shadow offset

    // Connect the clicked signal to a lambda function (or a custom slot)
    connect(ui->crewHealth, &QPushButton::clicked, this, [=]() {
        // Apply the shadow effect
        ui->crewHealth->setGraphicsEffect(effect);
    });
}

MainWindow::~MainWindow() {
    delete ui;
}

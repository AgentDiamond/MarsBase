#include "customstucturebutton.h"
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QProgressBar>
#include <QStackedWidget>
#include <QPixmap>


CustomStructureButton::CustomStructureButton(QWidget *parent)
    : QWidget(parent), currentIndex(0)
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Icon navigation layout
    QHBoxLayout *iconLayout = new QHBoxLayout();

    // Navigation buttons
    QPushButton *leftArrow = new QPushButton("<", this);
    QPushButton *rightArrow = new QPushButton(">", this);

    // Icon area
    iconStack = new QStackedWidget(this);
    addIcon("Icons/crew_accommodation.png", "Crew Accommodation");
    addIcon("Icons/life_support.png", "Life Support Systems");
    addIcon("Icons/bio_lab.png", "Bio Lab");

    // Connect buttons
    connect(leftArrow, &QPushButton::clicked, this, &CustomStructureButton::showPreviousIcon);
    connect(rightArrow, &QPushButton::clicked, this, &CustomStructureButton::showNextIcon);

    iconLayout->addWidget(leftArrow);
    iconLayout->addWidget(iconStack);
    iconLayout->addWidget(rightArrow);

    // Info area
    hpBar = new QProgressBar(this);
    hpBar->setValue(80); // Example HP value

    label = new QLabel("Crew Accommodation", this);

    // Add components to the layout
    mainLayout->addLayout(iconLayout);
    mainLayout->addWidget(label);
    mainLayout->addWidget(hpBar);
}



void CustomStructureButton::showPreviousIcon()
{
    currentIndex = (currentIndex - 1 + iconStack->count()) % iconStack->count();
    iconStack->setCurrentIndex(currentIndex);
    updateLabelAndHP();
}

void CustomStructureButton::showNextIcon()
{
    currentIndex = (currentIndex + 1) % iconStack->count();
    iconStack->setCurrentIndex(currentIndex);
    updateLabelAndHP();
}


void CustomStructureButton::addIcon(const QString &iconPath, const QString &text)
{
    QWidget *iconWidget = new QWidget(this);
    QVBoxLayout *iconLayout = new QVBoxLayout(iconWidget);

    QLabel *iconLabel = new QLabel(iconWidget);
    QPixmap pixmap(iconPath);
    if (!pixmap.isNull()) {
        iconLabel->setPixmap(pixmap.scaled(64, 64, Qt::KeepAspectRatio));
    } else {
        iconLabel->setText("Image not found");
    }

    iconLayout->addWidget(iconLabel, 0, Qt::AlignCenter);
    iconStack->addWidget(iconWidget);
}

void CustomStructureButton::updateLabelAndHP() {
    label->setText(labels[currentIndex]);
    hpBar->setValue(hpValues[currentIndex]);
};



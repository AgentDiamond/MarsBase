#include "custombutton.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QProgressBar>

CustomButton::CustomButton(QWidget *parent)
    : QWidget (parent) {
    // Default constructor logic (if needed)
}

CustomButton::CustomButton(const QVector<QPair<QString, int>> &data, QWidget *parent)
    : QWidget (parent), m_data(data) {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    for (const auto& entry : m_data) {
        const QString& name = entry.first;
        int hp = entry.second;

        QHBoxLayout* rowLayout = new QHBoxLayout();

        // Add name label
        QLabel* nameLabel = new QLabel(name, this);
        rowLayout->addWidget(nameLabel);

        // Add HP label
        QLabel* hpLabel = new QLabel("HP:", this);
        rowLayout->addWidget(hpLabel);

        // Add progress bar
        QProgressBar* progressBar = new QProgressBar(this);
        progressBar->setValue(hp);
        progressBar->setMaximum(100);  // Assume HP is out of 100
        rowLayout->addWidget(progressBar);

        // Add the row layout to the main layout
        mainLayout->addLayout(rowLayout);
    }

    setLayout(mainLayout);
}

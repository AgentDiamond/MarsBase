#ifndef CUSTOMSTRUCTUREBUTTON_H
#define CUSTOMSTRUCTUREBUTTON_H

#include <QWidget>
#include <QStackedWidget>
#include <QProgressBar>
#include <QLabel>
#include <QStringList>
#include <QList>

class CustomStructureButton : public QWidget {
    Q_OBJECT

public:
    explicit CustomStructureButton(QWidget *parent = nullptr);

private slots:
    void showPreviousIcon();
    void showNextIcon();

private:
    QStackedWidget *iconStack;   // Stacked widget for icons
    QProgressBar *hpBar;        // Progress bar for HP
    QLabel *label;              // Label for descriptions
    int currentIndex;           // Current icon index

    const QStringList labels = {"Crew Accommodation", "Life Support Systems", "Bio Lab"};
    const QList<int> hpValues = {80, 60, 90};

    void addIcon(const QString &iconPath, const QString &text);
    void updateLabelAndHP();
};

#endif // CUSTOMSTRUCTUREBUTTON_H

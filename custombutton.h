#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H

#include <QWidget>
#include <QVector>
#include <QPair>
#include <QString>

class CustomButton : public QWidget
{
    Q_OBJECT
public:
    explicit CustomButton(QWidget *parent = nullptr);
    explicit CustomButton(const QVector<QPair<QString, int>> &data, QWidget *parent = nullptr);

private:
    QVector<QPair<QString, int>> m_data;

signals:

};

#endif // CUSTOMBUTTON_H

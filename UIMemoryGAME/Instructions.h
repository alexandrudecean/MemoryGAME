#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

class Instructions : public QWidget {
    Q_OBJECT

public:
    explicit Instructions(QWidget* parent = nullptr);

signals:
    void nextButtonClicked(); // Semnal pentru a indica trecerea mai departe

private slots:
    void onNextButtonClicked();

private:
    QLabel* titleLabel;
    QLabel* instructionsText;
    QPushButton* nextButton;
};

#endif // INSTRUCTIONS_H

#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QVBoxLayout>
#include <QFormLayout>

class Login : public QWidget {
    Q_OBJECT

public:
    explicit Login(QWidget* parent = nullptr);

signals:
    void startSinglePlayer(const QString& username); 
    void startMultiplayer(const QList<QString>& usernames); 

private slots:
    void onStartClicked();

private:
    QLineEdit* usernameField;
    QList<QLineEdit*> playerFields;
    QComboBox* modeSelector;
    QPushButton* startButton;
    QFormLayout* formLayout;
    QString selectedMode;
};

#endif

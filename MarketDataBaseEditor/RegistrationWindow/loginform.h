#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QObject>

class LoginForm : public QObject
{
    Q_OBJECT
public:
    LoginForm();

    // Аттрибуты
    enum LoginStatus {LOGIN, REGISTRATION};
    LoginStatus loginStatus = LOGIN;

private:


signals:
    void pushButton_login_clicked();


};

#endif // LOGINFORM_H

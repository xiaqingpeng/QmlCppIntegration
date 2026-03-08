#ifndef BACKEND_H
#define BACKEND_H

#pragma once
#include <QObject>
#include <QtQml/qqmlregistration.h>

class Backend : public QObject {
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON // 注册为单例
    Q_PROPERTY(int counter READ counter NOTIFY counterChanged)

public:
    explicit Backend(QObject *parent = nullptr) : QObject(parent), m_counter(0) {}
    int counter() const;
    Q_INVOKABLE void increment() ;
    Q_INVOKABLE void decrement() ;

signals:
    void counterChanged();
private:
    int m_counter;
};


#endif // BACKEND_H

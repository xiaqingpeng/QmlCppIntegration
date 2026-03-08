#ifndef DATAMODEL_H
#define DATAMODEL_H


#pragma once
#include <QAbstractListModel>
#include <QtQml/qqmlregistration.h>

#pragma once
#include <QAbstractListModel>
#include <QtQml/qqmlregistration.h>

class DataModel : public QAbstractListModel {
    Q_OBJECT
    QML_ELEMENT
public:
    enum { NameRole = Qt::UserRole + 1 };

    // 直接在头文件初始化数据
    explicit DataModel(QObject *p = nullptr) : QAbstractListModel(p) { m_items << "A" << "B"; }

    // 极致简化的虚函数实现
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &i, int r) const override ;

    QHash<int, QByteArray> roleNames() const override;

    // 修改方法
    Q_INVOKABLE void addItem(const QString &n) ;

    Q_INVOKABLE void removeItem(int i);

private:
    QStringList m_items;
};


#endif // DATAMODEL_H

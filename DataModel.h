#ifndef DATAMODEL_H
#define DATAMODEL_H


#pragma once
#include <QAbstractListModel>
#include <QtQml/qqmlregistration.h>

class DataModel : public QAbstractListModel {
    Q_OBJECT
    QML_ELEMENT
public:
    enum Roles { NameRole = Qt::UserRole + 1 };
    explicit DataModel(QObject *parent = nullptr) : QAbstractListModel(parent) {
        m_items << "Item 1" << "Item 2";
    }

    int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    QVariant data(const QModelIndex &index, int role) const ;
    QHash<int, QByteArray> roleNames() const ;

    Q_INVOKABLE  void addItem(const QString &name);
    Q_INVOKABLE  void removeItem(int index);

private:
    QStringList m_items;
};


#endif // DATAMODEL_H

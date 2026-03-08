 #include "DataModel.h"


int DataModel::rowCount(const QModelIndex &parent) const
{
    return m_items.size();
}

QVariant DataModel::data(const QModelIndex &i, int r) const
{
    return (i.isValid() && r == NameRole) ? m_items.at(i.row()) : QVariant();
}

QHash<int, QByteArray> DataModel::roleNames() const
{
    return {{NameRole, "itemName"}};
}

void DataModel::addItem(const QString &n)
{
    beginInsertRows({}, m_items.size(), m_items.size());
    m_items << n;
    endInsertRows();
}

void DataModel::removeItem(int i)
{
    if (i < 0 || i >= m_items.size()) return;
    beginRemoveRows({}, i, i);
    m_items.removeAt(i);
    endRemoveRows();
}

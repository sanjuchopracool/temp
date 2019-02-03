#include "treemodel.h"

TreeModel::TreeModel(QObject *parent)
    : QAbstractItemModel(parent)
{
    names.append("Sunil");
    names.append("Sanjay");
    names.append("Satish");
    names.append("Sanjeev");
}

int TreeModel::rowCount(const QModelIndex &parent) const
{
    if(!parent.isValid())
        return names.count();
    return 0;
}

int TreeModel::columnCount(const QModelIndex &parent) const
{
    if(!parent.isValid())
        return 1;
    return 0;
}

QVariant TreeModel::data(const QModelIndex &index, int role) const
{
    if(index.isValid())
    {
        if(role == Qt::DisplayRole)
        {
            int row = index.row();
            int column = index.column();

            if(row >=0 && row < names.count())
            {
                if(column == 0)
                    return names[row];
            }
        }
    }

    return QVariant();
}

QModelIndex TreeModel::parent(const QModelIndex &child) const
{
    return QModelIndex();
}

QModelIndex TreeModel::index(int row, int column, const QModelIndex &parent) const
{
    if(!parent.isValid())
        return createIndex(row, column, row);

    return QModelIndex();
}

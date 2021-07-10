#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <qqml.h>
#include <QAbstractTableModel>
#include <GadgetTest.h>


class TableModel : public QAbstractTableModel{
    Q_OBJECT
    enum TableRoles {
        TableDataRole = Qt::UserRole +1,
        HeadindRole
    };

public:
    explicit TableModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex & = QModelIndex()) const override;

    int columnCount(const QModelIndex & = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role) const override;

    QHash<int, QByteArray> roleNames() const override;

private:

    QVector<QVector<QString>> table;
};

#endif // TABLEMODEL_H

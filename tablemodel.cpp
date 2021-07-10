#include "tablemodel.h"

TableModel::TableModel (QObject *parent) : QAbstractTableModel (parent)

{

    qRegisterMetaType<Player>();
    int idPlayerType = qRegisterMetaType<PlayerType>();

    Player myPlayer;

    QMetaObject metaobject = myPlayer.staticMetaObject;

    int count = metaobject.propertyCount();

    QVector<QString> header;

    for (int i=0; i<count; ++i) {

        QMetaProperty metaproperty = metaobject.property(i);
        const char *name = metaproperty.name();
        QString type = metaproperty.typeName();

        if (type == "float"){
            header.append(name);

        } else if (type == "ushort") {
            header.append(name);

        } else if (type == "uchar") {
            header.append(name);

        } else if (type == "bool") {
            header.append(name);

        } else if (metaproperty.typeId() == idPlayerType){
            header.append(name);

        }
    }

    table.append(header);


    for (int nplayers = 0; nplayers < 25 ; nplayers++){

        QVector<QString> row;
        for (int i=0; i<count; ++i) {

            QMetaProperty metaproperty = metaobject.property(i);
            QString type = metaproperty.typeName();

            if (type == "float"){
                float v = rand() % 1000;
                v = v /100;
                row.append(QString::number(v));

            } else if (type == "ushort") {
                int v = rand() % 50;
                row.append(QString::number(v));

            } else if (type == "uchar") {
                int v = rand() % 10;
                row.append(QString::number(v));

            } else if (type == "bool") {
                int v = rand() % 2;
                if (v == 0){
                    row.append("False");
                } else {
                    row.append("True");
                }

            } else if (metaproperty.typeId() == idPlayerType){

                int v = rand() % 4;

                switch (v) {

                case 0:{
                    row.append("NO_TYPE");
                    break;
                }
                case 1:{
                    row.append("TANK");
                    break;
                }
                case 2 :{
                    row.append("CHARACTER");
                    break;
                }
                case 3: {
                    row.append("SHIP");
                    break;
                }

                }

            }

        }
        table.append(row);
    }

}

int TableModel::rowCount(const QModelIndex &) const
{
    return table.size();
}

int TableModel::columnCount(const QModelIndex &) const
{
    return table.at(0).size();
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    switch (role) {

    case TableDataRole:{
        return table.at(index.row()).at(index.column());
    }

    case HeadindRole: {
        if (index.row() == 0){
            return true;
        } else {
            return false;
        }
    }

    default:
        break;
    }


    return QVariant();
}

QHash<int, QByteArray> TableModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles [TableDataRole] = "tabledata";
    roles [HeadindRole] = "heading";
    return roles;
}




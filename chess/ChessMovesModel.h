#ifndef CHESSMOVESMODEL_H
#define CHESSMOVESMODEL_H


#include "qpainter.h"
#include "qsize.h"
#include <QStyledItemDelegate>
#include <QAbstractTableModel>
#include <QStringList>
#include <vector>
//#include "ChessMove.h"


class ChessMove {
public:
    ChessMove(int from_x, int from_y, int to_x, int to_y) :
        from_x(from_x), from_y(from_y), to_x(to_x), to_y(to_y) {}

    QString toString() const {
        QString result;
        result.append(QChar(from_x + 'a'));
        result.append(QChar(from_y + '1'));
        result.append("-");
        result.append(QChar(to_x + 'a'));
        result.append(QChar(to_y + '1'));
        return result;
    }

private:
    int from_x;
    int from_y;
    int to_x;
    int to_y;
};


class ChessMovesModel : public QAbstractTableModel
{
public:
    //ChessMovesModel(QObject *parent = nullptr) : QAbstractTableModel(parent) {}

    ChessMovesModel(QObject *parent = nullptr) : QAbstractTableModel(parent)
    {
        // Initialisation des en-têtes de colonnes
        headers << tr("Coups blanc") << tr("Coups noir");
    }

    //Nombre de lignes
    int rowCount(const QModelIndex &parent = QModelIndex()) const override {
        Q_UNUSED(parent)
        return qMax(whiteMoves.size(), blackMoves.size());
    }

    //Nombres de colonnes
    int columnCount(const QModelIndex &parent = QModelIndex()) const override {
        Q_UNUSED(parent)
        return 2; // une seule colonne pour les coups
    }

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override {
        if (!index.isValid()) {
            return QVariant();
        }

        if (role == Qt::DisplayRole) {
            // Renvoie la chaîne de caractères représentant le coup
            if (index.column() == 1 && index.row() < whiteMoves.size()) {
                return whiteMoves[index.row()].toString();
            }
            else if (index.column() == 0 && index.row() < blackMoves.size()) {
                return blackMoves[index.row()].toString();
            }
        }

        return QVariant();
    }

    QVariant headerData(int section, Qt::Orientation orientation, int role) const override {
        if (role != Qt::DisplayRole) {
            return QVariant();
        }

        if (orientation == Qt::Horizontal) {
            // En-tête de colonne
            return headers[section];
        } else {
            // En-tête de ligne
            return QString::number(section + 1);
        }
    }

    void addMove(const ChessMove &move, int tour) {
        //int row = moves.size();

        if (tour % 2 == 0){

            insertRows(rowCount(), 1);

            QModelIndex index = createIndex(rowCount()-1, 0);

            setData(index, move.toString(), Qt::DisplayRole);
            whiteMoves.append(move);
        }
        else{

            QModelIndex index = createIndex(rowCount()-1, 1);

            setData(index, move.toString(), Qt::DisplayRole);
            blackMoves.append(move);
        }
        emit layoutChanged();
        QModelIndex topLeft = createIndex(0, 0);
        QModelIndex bottomRight = createIndex(rowCount() - 1, columnCount() - 1);
        emit dataChanged(topLeft, bottomRight);
    }

private:
    QVector<QString> headers;
    QVector<ChessMove> whiteMoves;
    QVector<ChessMove> blackMoves;
};


#endif // CHESSMOVESMODEL_H

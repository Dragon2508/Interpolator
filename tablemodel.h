#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include "QPushButton"
#include "QTableWidget"

class TableModel
{
private:

public:
    TableModel();
    ~TableModel();
    void add_row(QTableWidget*);
    void delete_row(QTableWidget*);
};

#endif // TABLEMODEL_H

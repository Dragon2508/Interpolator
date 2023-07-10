#include "tablemodel.h"

TableModel::TableModel()
{

}

TableModel::~TableModel()
{

}

void TableModel::add_row(QTableWidget* tableWidget)
{
    tableWidget->insertRow( tableWidget->rowCount());
}

void TableModel::delete_row(QTableWidget* tableWidget)
{
    tableWidget->removeRow(tableWidget->rowCount()-1);
}

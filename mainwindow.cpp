#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "QFile"
#include "QTextStream"
#include "QStandardItem"
#include "QTableWidgetItem"
#include "QDebug"

MainWindow::MainWindow(int argc, char *argv[], QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      tableModel (new TableModel)
{
    ui->setupUi(this);
    initWidgits();
    readCSV(argc, argv);
}

MainWindow::~MainWindow()
{
    delete ui;
}

Ui::MainWindow *MainWindow::_ui() const{
    return ui;
}

void MainWindow::readCSV(int argc, char *argv[])
{
    if(argc){
        // Открываем файл
        QFile file("C:\\Users\\tshma\\Desktop\\file.csv");// argv[1]
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            // Обработка ошибки при открытии файла
            return;
        }

        // Создаем текстовый поток для чтения файла
        QTextStream in(&file);

        int rowCount = 1;

        // Читаем файл построчно
        while (!in.atEnd()) {
            QString line = in.readLine();

            // Разделяем строку на поля с разделителем запятая
            QStringList fields = line.split(";");

            // Устанавливаем количество строк в таблице
            if (rowCount == 1) {
                ui->tableWidget->setRowCount(fields.size());
                continue;
            }

            // Заполняем данные в таблице
            for (int column = 0; column < fields.size(); ++column) {
                ui->tableWidget->insertRow(rowCount);
                QTableWidgetItem *item = new QTableWidgetItem(fields.at(column));
                ui->tableWidget->setItem(column, rowCount, item);
            }

            rowCount++;
        }

        file.close();
    }
}

void MainWindow::initWidgits()
{
    ui->tableName_tl->setText("Координаты графика");
    ui->tableName_tl->setAlignment(Qt::AlignCenter);

    ui->graphicsName_tl->setText("График");
    ui->graphicsName_tl->setAlignment((Qt::AlignCenter));

    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels({"X","Y"});
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}




void MainWindow::on_add_pb_clicked()
{
    tableModel->add_row(ui->tableWidget);
}

void MainWindow::on_delete_pb_clicked()
{
    tableModel->delete_row(ui->tableWidget);
}

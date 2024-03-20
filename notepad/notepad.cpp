#include "notepad.h"
#include "./ui_notepad.h"
#include <QMessageBox>
#include <QFileDialog>


notepad::notepad(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::notepad)
{
    ui->setupUi(this);
    connect(ui->plainTextEdit, &QPlainTextEdit::textChanged, this, &notepad::documentModified);
    setWindowTitle("Notepad");
    isModified = false;
}

notepad::~notepad()
{
    delete ui;
}

void notepad::on_actionQuit_triggered()
{
    if (isModified) {
        int result = QMessageBox::warning(this, "Save Changes", "Do you want to save changes?",
                                          QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        if (result == QMessageBox::Save)
            on_actionSave_triggered();
        else if (result == QMessageBox::Cancel)
            return;
    }
    QApplication::quit();
}

void notepad::documentModified()
{
    isModified = true;
    setWindowTitle("Notepad*");
}

void notepad::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save File"), "",
                                                    tr("All Files (*)"));
    if (fileName.isEmpty())
        return;

    QFile file(fileName);

    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::information(this, tr("Unable to open file"),
                                 file.errorString());
        return;
    }

    QTextStream out(&file);
    out << ui->plainTextEdit->toPlainText();
    file.close();

    setWindowTitle("Notepad");
    isModified = false;
}

void notepad::on_actionAbout_qt_triggered()
{
    QMessageBox::aboutQt(this);
}

void notepad::on_actionOpen_triggered()
{
    if (isModified) {
        int result = QMessageBox::warning(this, "Save Changes", "Do you want to save changes?",
                                          QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        if (result == QMessageBox::Save)
            on_actionSave_triggered();
        else if (result == QMessageBox::Cancel)
            return;
    }

    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open File"), "",
                                                    tr("All Files (*)"));
    if (fileName.isEmpty())
        return;

    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(this, tr("Unable to open file"),
                                 file.errorString());
        return;
    }

    QTextStream in(&file);
    ui->plainTextEdit->setPlainText(in.readAll());
    file.close();

    setWindowTitle("Notepad");
    isModified = false;
}

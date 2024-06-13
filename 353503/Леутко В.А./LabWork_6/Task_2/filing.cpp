#include "filing.h"
#include <QInputDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

Filing::Filing() {}

// void Filing::recordTextToFile()
// {
//     QString text = QInputDialog::getText(this, "Write text", "Enter a paragraph of text:");
//     if (!text.isEmpty()) {
//         QFile file("FamilijaLab20.txt");
//         if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
//             QTextStream out(&file);
//             for (QChar c : text) {
//                 out << c;
//             }
//             file.close();
//         } else {
//             QMessageBox::critical(this, "Error", "Failed to open file for writing.");
//         }
//     }
// }

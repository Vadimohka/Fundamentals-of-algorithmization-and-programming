#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
/*
Аккерман получил учёную степень доктора философии в Гёттингенском университете в 1925 году с диссертацией по теме Обоснование «tertium non datur» посредством гильбертовской теории доказательства непротиворечивости (нем. Begründung des "tertium non datur" mittels der Hilbertschen Theorie der Widerspruchsfreiheit), доказательство непротиворечивости арифметики без очевидного использования аксиомы полной индукции Пеано (хотя всё же неявно была использована). С 1929 года по 1948 год он преподаёт в гимназии Штайнфурта, затем до 1961 года в Люденшайде. Он был членом-корреспондентом Академии наук в Гёттингене и почётным профессором Вестфальского университета.

В 1928 году Аккерман помогал Давиду Гильберту подготовить к публикации лекции 1917—1922 гг. по введению в математическую логику — Основы теоретической логики (нем. Grundzüge der theoretischen Logik). В книге содержится первое изложение логики первого порядка и вопросов, которые впоследствии разрешил Гёдель в теореме о полноте и теореме о неполноте.

Несмотря на то, что Аккерман предпочел осуществлять трудовую деятельность скорее в системе школьного образования, чем университетского, он активно занимался наукой и имел множество публикаций. Аккерман работал над доказательством непротиворечивости теории множеств (1937), полной арифметики (1940), свободной логики (1952) и новой аксиоматизацией теории множеств (1956). В теории алгоритмов широко известна функция Аккермана.

В 1956 году Аккерман впервые явным образом рассмотрел проблематику релевантной логики. Хотя впоследствии стало известно, что до Аккермана система релевантной логики была построена И. Е. Орловым (1920-е гг.), а после А. Черчем (1951 г.), логическая система сильной импликации Аккермана была первым явным рассмотрением проблематики релевантной логики.
*/

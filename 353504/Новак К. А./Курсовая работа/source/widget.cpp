#include "widget.h"
#include "ui_widget.h"
#include "graphs.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QCoreApplication>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

int matrix[12][12];
int temp[12][12];
int fileID = 1;
QFile file;
QString fileName;
QTextStream out(&file);
int coords6[] = {225, 75, 525, 75, 675, 200, 525, 325, 225, 325, 75, 200};
Graph graph6(6, coords6);
int coords8[] = {275, 50, 475, 50, 675, 125, 675, 275, 475, 350, 275, 350, 75, 275, 75, 125};
Graph graph8(8, coords8);
int coords10[] = {375, 25, 625, 75, 675, 150, 675, 250, 625, 325, 375, 375, 125, 325, 75, 250, 75, 150, 125, 75};
Graph graph10(10, coords10);
int coords12[] = {275, 25, 475, 25, 625, 75, 675, 150, 675, 250, 625, 325, 475, 375, 275, 375, 125, 325, 75, 250, 75, 150, 125, 75};
Graph graph12(12, coords12);
QString symbol[12] ={"A", "B","C", "D", "E", "F", "G", "H", "I", "J", "K", "L"};
Graph Widget::getGraph()
{
    if(ui->radioButton_6->isChecked()) return graph6;
    if(ui->radioButton_8->isChecked()) return graph8;
    if(ui->radioButton_10->isChecked()) return graph10;
    return graph12;
}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));

    Graph graph = getGraph();
    painter.setBrush(QBrush(Qt::white, Qt::SolidPattern));
    painter.setFont(QFont("times", 22));
    for (int i = 0; i < graph.capacity; ++i)
    {
        for (int j = i + 1; j < graph.capacity; ++j)
            if (matrix[i][j] != 0)
                painter.drawLine(graph.vertexCoord[i].x, graph.vertexCoord[i].y, graph.vertexCoord[j].x, graph.vertexCoord[j].y);
        painter.drawEllipse(graph.vertexCoord[i].x - graph.r / 2, graph.vertexCoord[i].y - graph.r / 2, graph.r, graph.r);
        painter.drawText (graph.vertexCoord[i].x - graph.r / 5, graph.vertexCoord[i].y + graph.r / 5, symbol[i]);
    }
    refresh(graph.capacity);
}

void Widget::on_radioButton_6_clicked()
{
    repaint();
}

void Widget::on_radioButton_8_clicked()
{
    repaint();
}

void Widget::on_radioButton_10_clicked()
{
    repaint();
}

void Widget::on_radioButton_12_clicked()
{
    repaint();
}

void Widget::on_pushButton_add_clicked()
{
    Graph graph = getGraph();
    QString str_vertex1 = ui->lineEdit_vertex_1->text();
    QString str_vertex2 = ui->lineEdit_vertex_2->text();
    QString str_weight = ui->lineEdit_weight->text();
    int weight = str_weight.toInt();
    int vertex1 = -1;
    int vertex2 = -1;
    for (int i = 0; i < graph.capacity; ++i)
    {
        if (str_vertex1 == symbol[i])
        {
            vertex1 = i;
        }
        if (str_vertex2 == symbol[i])
        {
            vertex2 = i;
        }
    }
    if (vertex1 == -1 || vertex2 == -1 || vertex1 == vertex2)
        QMessageBox::critical(this, "Ошибка", "Неверно введены вершины");
    else
    {
        matrix[vertex1][vertex2] = weight;
        matrix[vertex2][vertex1] = weight;
        repaint();
    }
}

void Widget::refresh(int capacity)
{
    QString num;
    if (matrix[0][1] != 0) num.setNum(matrix[0][1]);
    else num = "";
    ui->label_ab->setText(num);
    ui->label_ba->setText(num);
    if (matrix[0][2] != 0) num.setNum(matrix[0][2]);
    else num = "";
    ui->label_ac->setText(num);
    ui->label_ca->setText(num);
    if (matrix[0][3] != 0) num.setNum(matrix[0][3]);
    else num = "";
    ui->label_ad->setText(num);
    ui->label_da->setText(num);
    if (matrix[0][4] != 0) num.setNum(matrix[0][4]);
    else num = "";
    ui->label_ae->setText(num);
    ui->label_ea->setText(num);
    if (matrix[0][5] != 0) num.setNum(matrix[0][5]);
    else num = "";
    ui->label_af->setText(num);
    ui->label_fa->setText(num);
    if (matrix[1][2] != 0) num.setNum(matrix[1][2]);
    else num = "";
    ui->label_bc->setText(num);
    ui->label_cb->setText(num);
    if (matrix[1][3] != 0) num.setNum(matrix[1][3]);
    else num = "";
    ui->label_bd->setText(num);
    ui->label_db->setText(num);
    if (matrix[1][4] != 0) num.setNum(matrix[1][4]);
    else num = "";
    ui->label_be->setText(num);
    ui->label_eb->setText(num);
    if (matrix[1][5] != 0) num.setNum(matrix[1][5]);
    else num = "";
    ui->label_bf->setText(num);
    ui->label_fb->setText(num);
    if (matrix[2][3] != 0) num.setNum(matrix[2][3]);
    else num = "";
    ui->label_cd->setText(num);
    ui->label_dc->setText(num);
    if (matrix[2][4] != 0) num.setNum(matrix[2][4]);
    else num = "";
    ui->label_ce->setText(num);
    ui->label_ec->setText(num);
    if (matrix[2][5] != 0) num.setNum(matrix[2][5]);
    else num = "";
    ui->label_cf->setText(num);
    ui->label_fc->setText(num);
    if (matrix[3][4] != 0) num.setNum(matrix[3][4]);
    else num = "";
    ui->label_de->setText(num);
    ui->label_ed->setText(num);
    if (matrix[3][5] != 0) num.setNum(matrix[3][5]);
    else num = "";
    ui->label_df->setText(num);
    ui->label_fd->setText(num);
    if (matrix[4][5] != 0) num.setNum(matrix[4][5]);
    else num = "";
    ui->label_ef->setText(num);
    ui->label_fe->setText(num);
    if (capacity < 12)
    {
        ui->label_col_k->setText("");
        ui->label_col_l->setText("");
        ui->label_row_k->setText("");
        ui->label_row_l->setText("");
        ui->label_kk->setText("");
        ui->label_ll->setText("");
        for (int i = 0; i < 10; ++i)
            for (int j = 10; j < 12; ++j)
                matrix[i][j] = 0;
        for (int i = 10; i < 12; ++i)
            for (int j = 0; j < 12; ++j)
                matrix[i][j] = 0;
    } else
    {
        ui->label_col_k->setText("K");
        ui->label_col_l->setText("L");
        ui->label_row_k->setText("K");
        ui->label_row_l->setText("L");
        ui->label_kk->setText("-");
        ui->label_ll->setText("-");
    }
    if (capacity < 10)
    {
        ui->label_col_i->setText("");
        ui->label_col_j->setText("");
        ui->label_row_i->setText("");
        ui->label_row_j->setText("");
        ui->label_ii->setText("");
        ui->label_jj->setText("");
        for (int i = 0; i < 8; ++i)
            for (int j = 8; j < 10; ++j)
                matrix[i][j] = 0;
        for (int i = 8; i < 10; ++i)
            for (int j = 0; j < 10; ++j)
                matrix[i][j] = 0;
    } else
    {
        ui->label_col_i->setText("I");
        ui->label_col_j->setText("J");
        ui->label_row_i->setText("I");
        ui->label_row_j->setText("J");
        ui->label_ii->setText("-");
        ui->label_jj->setText("-");
    }
    if (capacity < 8)
    {
        ui->label_row_g->setText("");
        ui->label_row_h->setText("");
        ui->label_col_g->setText("");
        ui->label_col_h->setText("");
        ui->label_gg->setText("");
        ui->label_hh->setText("");
        for (int i = 0; i < 6; ++i)
            for (int j = 6; j < 8; ++j)
                matrix[i][j] = 0;
        for (int i = 6; i < 8; ++i)
            for (int j = 0; j < 8; ++j)
                matrix[i][j] = 0;
    } else
    {
        ui->label_row_g->setText("G");
        ui->label_row_h->setText("H");
        ui->label_col_g->setText("G");
        ui->label_col_h->setText("H");
        ui->label_gg->setText("-");
        ui->label_hh->setText("-");
    }
    if (matrix[0][6] != 0) num.setNum(matrix[0][6]);
    else num = "";
    ui->label_ag->setText(num);
    ui->label_ga->setText(num);
    if (matrix[0][7] != 0) num.setNum(matrix[0][7]);
    else num = "";
    ui->label_ah->setText(num);
    ui->label_ha->setText(num);
    if (matrix[0][8] != 0) num.setNum(matrix[0][8]);
    else num = "";
    ui->label_ai->setText(num);
    ui->label_ia->setText(num);
    if (matrix[0][9] != 0) num.setNum(matrix[0][9]);
    else num = "";
    ui->label_aj->setText(num);
    ui->label_ja->setText(num);
    if (matrix[0][10] != 0) num.setNum(matrix[0][10]);
    else num = "";
    ui->label_ak->setText(num);
    ui->label_ka->setText(num);
    if (matrix[0][11] != 0) num.setNum(matrix[0][11]);
    else num = "";
    ui->label_al->setText(num);
    ui->label_la->setText(num);
    if (matrix[1][6] != 0) num.setNum(matrix[1][6]);
    else num = "";
    ui->label_bg->setText(num);
    ui->label_gb->setText(num);
    if (matrix[1][7] != 0) num.setNum(matrix[1][7]);
    else num = "";
    ui->label_bh->setText(num);
    ui->label_hb->setText(num);
    if (matrix[1][8] != 0) num.setNum(matrix[1][8]);
    else num = "";
    ui->label_bi->setText(num);
    ui->label_ib->setText(num);
    if (matrix[1][9] != 0) num.setNum(matrix[1][9]);
    else num = "";
    ui->label_bj->setText(num);
    ui->label_jb->setText(num);
    if (matrix[1][10] != 0) num.setNum(matrix[1][10]);
    else num = "";
    ui->label_bk->setText(num);
    ui->label_kb->setText(num);
    if (matrix[1][11] != 0) num.setNum(matrix[1][11]);
    else num = "";
    ui->label_bl->setText(num);
    ui->label_lb->setText(num);
    if (matrix[2][6] != 0) num.setNum(matrix[2][6]);
    else num = "";
    ui->label_cg->setText(num);
    ui->label_gc->setText(num);
    if (matrix[2][7] != 0) num.setNum(matrix[2][7]);
    else num = "";
    ui->label_ch->setText(num);
    ui->label_hc->setText(num);
    if (matrix[2][8] != 0) num.setNum(matrix[2][8]);
    else num = "";
    ui->label_ci->setText(num);
    ui->label_ic->setText(num);
    if (matrix[2][9] != 0) num.setNum(matrix[2][9]);
    else num = "";
    ui->label_cj->setText(num);
    ui->label_jc->setText(num);
    if (matrix[2][10] != 0) num.setNum(matrix[2][10]);
    else num = "";
    ui->label_ck->setText(num);
    ui->label_kc->setText(num);
    if (matrix[2][11] != 0) num.setNum(matrix[2][11]);
    else num = "";
    ui->label_cl->setText(num);
    ui->label_lc->setText(num);
    if (matrix[3][6] != 0) num.setNum(matrix[3][6]);
    else num = "";
    ui->label_dg->setText(num);
    ui->label_gd->setText(num);
    if (matrix[3][7] != 0) num.setNum(matrix[3][7]);
    else num = "";
    ui->label_dh->setText(num);
    ui->label_hd->setText(num);
    if (matrix[3][8] != 0) num.setNum(matrix[3][8]);
    else num = "";
    ui->label_di->setText(num);
    ui->label_id->setText(num);
    if (matrix[3][9] != 0) num.setNum(matrix[3][9]);
    else num = "";
    ui->label_dj->setText(num);
    ui->label_jd->setText(num);
    if (matrix[3][10] != 0) num.setNum(matrix[3][10]);
    else num = "";
    ui->label_dk->setText(num);
    ui->label_kd->setText(num);
    if (matrix[3][11] != 0) num.setNum(matrix[3][11]);
    else num = "";
    ui->label_dl->setText(num);
    ui->label_ld->setText(num);
    if (matrix[4][6] != 0) num.setNum(matrix[4][6]);
    else num = "";
    ui->label_eg->setText(num);
    ui->label_ge->setText(num);
    if (matrix[4][7] != 0) num.setNum(matrix[4][7]);
    else num = "";
    ui->label_eh->setText(num);
    ui->label_he->setText(num);
    if (matrix[4][8] != 0) num.setNum(matrix[4][8]);
    else num = "";
    ui->label_ei->setText(num);
    ui->label_ie->setText(num);
    if (matrix[4][9] != 0) num.setNum(matrix[4][9]);
    else num = "";
    ui->label_ej->setText(num);
    ui->label_je->setText(num);
    if (matrix[4][10] != 0) num.setNum(matrix[4][10]);
    else num = "";
    ui->label_ek->setText(num);
    ui->label_ke->setText(num);
    if (matrix[4][11] != 0) num.setNum(matrix[4][11]);
    else num = "";
    ui->label_el->setText(num);
    ui->label_le->setText(num);
    if (matrix[5][6] != 0) num.setNum(matrix[5][6]);
    else num = "";
    ui->label_fg->setText(num);
    ui->label_gf->setText(num);
    if (matrix[5][7] != 0) num.setNum(matrix[5][7]);
    else num = "";
    ui->label_fh->setText(num);
    ui->label_hf->setText(num);
    if (matrix[5][8] != 0) num.setNum(matrix[5][8]);
    else num = "";
    ui->label_fi->setText(num);
    ui->label_if->setText(num);
    if (matrix[5][9] != 0) num.setNum(matrix[5][9]);
    else num = "";
    ui->label_fj->setText(num);
    ui->label_jf->setText(num);
    if (matrix[5][10] != 0) num.setNum(matrix[5][10]);
    else num = "";
    ui->label_fk->setText(num);
    ui->label_kf->setText(num);
    if (matrix[5][11] != 0) num.setNum(matrix[5][11]);
    else num = "";
    ui->label_fl->setText(num);
    ui->label_lf->setText(num);
    if (matrix[6][7] != 0) num.setNum(matrix[6][7]);
    else num = "";
    ui->label_gh->setText(num);
    ui->label_hg->setText(num);
    if (matrix[6][8] != 0) num.setNum(matrix[6][8]);
    else num = "";
    ui->label_gi->setText(num);
    ui->label_ig->setText(num);
    if (matrix[6][9] != 0) num.setNum(matrix[6][9]);
    else num = "";
    ui->label_gj->setText(num);
    ui->label_jg->setText(num);
    if (matrix[6][10] != 0) num.setNum(matrix[6][10]);
    else num = "";
    ui->label_gk->setText(num);
    ui->label_kg->setText(num);
    if (matrix[6][11] != 0) num.setNum(matrix[6][11]);
    else num = "";
    ui->label_gl->setText(num);
    ui->label_lg->setText(num);
    if (matrix[7][8] != 0) num.setNum(matrix[7][8]);
    else num = "";
    ui->label_hi->setText(num);
    ui->label_ih->setText(num);
    if (matrix[7][9] != 0) num.setNum(matrix[7][9]);
    else num = "";
    ui->label_hj->setText(num);
    ui->label_jh->setText(num);
    if (matrix[7][10] != 0) num.setNum(matrix[7][10]);
    else num = "";
    ui->label_hk->setText(num);
    ui->label_kh->setText(num);
    if (matrix[7][11] != 0) num.setNum(matrix[7][11]);
    else num = "";
    ui->label_hl->setText(num);
    ui->label_lh->setText(num);
    if (matrix[8][9] != 0) num.setNum(matrix[8][9]);
    else num = "";
    ui->label_ij->setText(num);
    ui->label_ji->setText(num);
    if (matrix[8][10] != 0) num.setNum(matrix[8][10]);
    else num = "";
    ui->label_ik->setText(num);
    ui->label_ki->setText(num);
    if (matrix[8][11] != 0) num.setNum(matrix[8][11]);
    else num = "";
    ui->label_il->setText(num);
    ui->label_li->setText(num);
    if (matrix[9][10] != 0) num.setNum(matrix[9][10]);
    else num = "";
    ui->label_jk->setText(num);
    ui->label_kj->setText(num);
    if (matrix[9][11] != 0) num.setNum(matrix[9][11]);
    else num = "";
    ui->label_jl->setText(num);
    ui->label_lj->setText(num);
    if (matrix[10][11] != 0) num.setNum(matrix[10][11]);
    else num = "";
    ui->label_kl->setText(num);
    ui->label_lk->setText(num);
}

void Widget::on_pushButton_lounch_clicked()
{
    Graph graph = getGraph();
    int checkLines = 0;
    for (int i = 0; i < graph.capacity; ++i){
        for (int j = 0; j < graph.capacity; ++j) {
            if (matrix[i][j] != 0) {
                ++checkLines;
                break;
            }
        }
    }
    if (checkLines == graph.capacity) calc(graph);
    else QMessageBox::critical(this, "Ошибка", "Граф должен быть связным");
}

void Widget::calc(Graph graph)
{
    for (int i = 0; i < 12; ++i)
        for (int j = 0; j < 12; ++j)
            temp[i][j] = matrix[i][j];
    fileName.setNum(fileID++);

    file.setFileName("./results/" + fileName + ".html");
    file.open(QIODevice::Append | QIODevice::Text);
    out << "<!DOCTYPE html>\n <html>\n  <head>\n   <title>Prim's algorithm</title>\n  </head>\n  <body>\n";
    int step = 1;
    QString str_nums;
    int min;
    int v1, v2;
    bool lightrows[12];

    QString SVGLightLines;
    for (int i = 0; i < 12; ++i) lightrows[i] = false;
    lightrows[0] = true;
    for (int i = 0; i < 12; ++i) temp[i][0] = 0;
    while (!allLinesIsNull())
    {
        str_nums.setNum(step++);
        out << "   <h1>Step ";
        out << str_nums;
        out << "</h1>\n   <svg height=\"400\" width=\"750\">\n";

        out << getSVGLines(graph);
        min = 0;

        for (int i = 0; i < 12; ++i)
        {
            for (int j = 0; j < 12; ++j)
                if (temp[i][j] != 0 && lightrows[i]) min = temp[i][j];
            if (min != 0) break;
        }
        for (int i = 11; i >= 0; --i)
            for (int j = 11; j >= 0; --j)
                if (temp[i][j] != 0 && lightrows[i] && temp[i][j] <= min)
                {
                    min = temp[i][j];
                    v1 = i;
                    v2 = j;
                }

        QTextStream Qcout(stdout);
        Qcout << min << " " << v1 << " " << v2 << "\n";

        SVGLightLines += "    <line x1=\"";
        str_nums.setNum(graph.vertexCoord[v1].x);
        SVGLightLines += str_nums;
        SVGLightLines += "\" y1=\"";
        str_nums.setNum(graph.vertexCoord[v1].y);
        SVGLightLines += str_nums;
        SVGLightLines += "\" x2=\"";
        str_nums.setNum(graph.vertexCoord[v2].x);
        SVGLightLines += str_nums;
        SVGLightLines += "\" y2=\"";
        str_nums.setNum(graph.vertexCoord[v2].y);
        SVGLightLines += str_nums;
        SVGLightLines += "\" style=\"stroke:red;stroke-width:4\"/>\n";
        out << SVGLightLines;
        out << getSVGVertexes(graph);
        out << "   </svg>\n";
        lightrows[v2] = true;

        for (int i = 0; i < 12; ++i) temp[i][v2] = 0;
    }
    out << "  </body>\n </html>";
    file.close();
    QMessageBox::information(this, "Инфо", "Файл " + fileName + ".html с отчетом создан");
}

bool Widget::allLinesIsNull()
{
    for (int i = 0; i < 12; ++i)
        for (int j = 0; j < 12; ++j)
            if (temp[i][j] != 0) return false;
    return true;
}

QString Widget::getSVGLines(Graph graph)
{
    QString svg;
    QString num;
    for (int i = 0; i < graph.capacity; ++i)
        for (int j = i + 1; j < graph.capacity; ++j)
            if (matrix[i][j] != 0)
            {
                svg += "    <line x1=\"";
                num.setNum(graph.vertexCoord[i].x);
                svg += num;
                svg += "\" y1=\"";
                num.setNum(graph.vertexCoord[i].y);
                svg += num;
                svg += "\" x2=\"";
                num.setNum(graph.vertexCoord[j].x);
                svg += num;
                svg += "\" y2=\"";
                num.setNum(graph.vertexCoord[j].y);
                svg += num;
                svg += "\" style=\"stroke:black\"/>\n";
            }
    return svg;
}

QString Widget::getSVGVertexes(Graph graph)
{
    QString svg;
    QString num;
    for (int i = 0; i < graph.capacity; ++i)
    {
        svg += "    <circle cx=\"";
        num.setNum(graph.vertexCoord[i].x);
        svg += num;

        svg += "\" cy=\"";
        num.setNum(graph.vertexCoord[i].y);
        svg += num;
        svg += "\" r=\"";
        num.setNum(graph.r / 2);
        svg += num;
        svg += "\"/>";
        svg += " <text x=\"";
        num.setNum(graph.vertexCoord[i].x - 15);
        svg += num;
        svg += "\" y=\"";
        num.setNum(graph.vertexCoord[i].y + 10);
        svg += num;
        svg += "\" fill=\"white\" font-size=\"40\">" + symbol[i] + "</text>\n";
    }
    return svg;
}

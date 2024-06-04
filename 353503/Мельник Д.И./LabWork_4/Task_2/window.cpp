#include "window.h"
#include "distributor.h"

Window::Window(QWidget* parent, QGraphicsScene* scene, QGraphicsView* view)
    : m_parent(parent),
      m_scene(scene),
      m_view(view),
      m_chooseAlgo(new QComboBox(this)),
      m_chooseOption(new QComboBox(this)),
      m_optmgr(new OptionMgr(m_chooseOption)),
      m_chooseDistrib(new QComboBox(this)),
      m_chooseScramble(new QComboBox(this)),
      m_chooseSize(new QComboBox(this)),
      m_nbCmp(new QLabel(this)),
      m_chooseMenu(new QVBoxLayout()),
      playing(false) {
  setParent(parent);

  show();
  setFixedSize(160, 500);
  move(550, 10);

  m_optmgr->connect(m_chooseAlgo, &QComboBox::currentIndexChanged, m_optmgr,
                    &OptionMgr::updateOptions);

  m_chooseAlgo->addItem("Bubblesort");
  m_chooseAlgo->addItem("Quicksort");
  m_chooseAlgo->addItem("Mergesort");
  m_chooseAlgo->addItem("Heapsort");
  m_chooseAlgo->addItem("Interpolation");
  m_chooseAlgo->setCurrentIndex(1);
  m_chooseAlgo->setCurrentIndex(0);  // To force a refresh

  m_chooseDistrib->addItem("Regular");
  m_chooseDistrib->addItem("Uniform (random)");
  m_chooseDistrib->addItem("Centered (random)");
  m_chooseDistrib->addItem("Split (random)");
  m_chooseDistrib->addItem("High (random)");
  m_chooseDistrib->addItem("Low (random)");

  m_chooseScramble->addItem("Random");
  m_chooseScramble->addItem("Sorted-ish");
  m_chooseScramble->addItem("Reversed-ish");
  m_chooseScramble->addItem("Shuffle");

  m_chooseSize->connect(m_chooseSize, &QComboBox::currentIndexChanged, this,
                        &Window::Resize);
  m_chooseSize->addItem("8");
  m_chooseSize->addItem("16");
  m_chooseSize->addItem("32");
  m_chooseSize->addItem("64");
  m_chooseSize->addItem("128");
  m_chooseSize->addItem("256");
  m_chooseSize->addItem("512");
  m_chooseSize->addItem("1024");

  m_start = new QPushButton("Start", this);
  m_exit = new QPushButton("Exit", this);
  m_abort = new QPushButton("--", this);
  m_playpause = new QPushButton("--", this);
  m_playpause->setEnabled(false);

  m_optmgr->connect(m_exit, &QPushButton::clicked, this, &Window::kill);

  m_chooseMenu->addWidget(new QLabel("Algorithm:", this));
  m_chooseMenu->addWidget(m_chooseAlgo);
  m_chooseMenu->addWidget(new QLabel("Specification:", this));
  m_chooseMenu->addWidget(m_chooseOption);
  m_chooseMenu->addWidget(new QLabel("Size:", this));
  m_chooseMenu->addWidget(m_chooseSize);
  m_chooseMenu->addWidget(new QLabel("Distribution:", this));
  m_chooseMenu->addWidget(m_chooseDistrib);
  m_chooseMenu->addWidget(new QLabel("Scramble:", this));
  m_chooseMenu->addWidget(m_chooseScramble);
  m_chooseMenu->addWidget(new QLabel("Comparisons", this));
  m_chooseMenu->addWidget(m_nbCmp);

  auto buttons = new QGridLayout();
  buttons->addWidget(m_start, 1, 1);
  buttons->addWidget(m_exit, 2, 1);
  buttons->addWidget(m_abort, 1, 2);
  buttons->addWidget(m_playpause, 2, 2);
  m_chooseMenu->addLayout(buttons);
  setLayout(m_chooseMenu);

  setWindowTitle("Sort algo");
  m_optmgr->connect(m_start, &QPushButton::clicked, this, &Window::run);
}

void Window::kill() {
  if (playing) {
    m_sort->stop();
    delete m_link;
    delete m_sort;
    delete[] m_array;
  }
  m_parent->close();
}

void Window::run() {
  m_start->setText("--");
  disconnect(m_start, &QPushButton::clicked, this, &Window::run);
  connect(m_playpause, &QPushButton::clicked, this, &Window::pause);
  m_playpause->setText("Pause");
  m_playpause->setEnabled(true);
  connect(m_abort, &QPushButton::clicked, this, &Window::abort);
  m_abort->setText("Abort");
  m_abort->setEnabled(true);
  m_start->setEnabled(false);
  int size = (1 << (m_chooseSize->currentIndex() + 3));

  m_array = new item[size];
  auto distr = Distributor(size, m_array);
  m_chooseAlgo->setEnabled(false);
  m_chooseOption->setEnabled(false);
  m_chooseSize->setEnabled(false);
  m_chooseDistrib->setEnabled(false);
  m_chooseScramble->setEnabled(false);
  switch (m_chooseDistrib->currentIndex()) {
    case 0:
      distr.Dregular();
      break;
    case 1:
      distr.Duniform();
      break;
    case 2:
      distr.Dcentered();
      break;
    case 3:
      distr.Dsplit();
      break;
    case 4:
      distr.Dhigh();
      break;
    case 5:
      distr.Dlow();
      break;
  }
  switch (m_chooseScramble->currentIndex()) {
    case 0:
      distr.Srandom();
      break;
    case 1:
      distr.Ssorted();
      break;
    case 2:
      distr.Sreversed();
      break;
    case 3:
      distr.Sshuffle();
      break;
  }
  m_link = new Linker(this, m_array, size, m_scene);
  m_link->setSize(size);
  m_sort = new Sorter(m_link);

  switch (m_chooseAlgo->currentIndex()) {
    case 0:  // Bubblesort
      switch (m_chooseOption->currentIndex()) {
        case 0:
          m_sort->Bubble_upwards();
          break;
        case 1:
          m_sort->Bubble_downwards();
          break;
        case 2:
          m_sort->Bubble_shaker();
          break;
      }
      break;
    case 1:  // Quicksort
      switch (m_chooseOption->currentIndex()) {
        case 0:
          m_sort->Quick_naive();
          break;
        case 1:
          m_sort->Quick_middle();
          break;
        case 2:
          m_sort->Quick_optimized();
          break;
        case 3:
          m_sort->Quick_median();
          break;
      }
      break;
    case 2:  // Mergesort
      switch (m_chooseOption->currentIndex()) {
        case 0:
          m_sort->Mergesort_standard();
          break;
        case 1:
          m_sort->Mergesort_pack();
          break;
        case 2:
          m_sort->Mergesort_weave();
          break;
      }
      break;
    case 3:  // Heapsort
      switch (m_chooseOption->currentIndex()) {
        case 0:
          m_sort->Heapsort_max();
          break;
        case 1:
          m_sort->Heapsort_sift();
          break;
        case 2:
          m_sort->Heapsort_min();
          break;
        case 3:
          m_sort->Heapsort_tern();
          break;
      }
      break;
    case 4:  // Interpolation
      switch (m_chooseOption->currentIndex()) {
        case 0:
          m_sort->InterpolationSort();
          break;
      }
  }

  m_start->setText("Clear");
  m_start->setEnabled(true);
  m_playpause->setText("--");
  m_playpause->setEnabled(false);
  disconnect(m_abort, &QPushButton::clicked, this, &Window::abort);
  m_abort->setText("--");
  m_abort->setEnabled(false);

  connect(m_start, &QPushButton::clicked, this, &Window::done);
}

void Window::done() {
  delete[] m_array;
  delete m_link;
  delete m_sort;

  m_chooseAlgo->setEnabled(true);
  m_chooseOption->setEnabled(true);
  m_chooseSize->setEnabled(true);
  m_chooseDistrib->setEnabled(true);
  m_chooseScramble->setEnabled(true);

  m_nbCmp->setText("--");

  m_start->setText("Start");
  m_start->setEnabled(true);
  m_abort->setText("--");
  m_abort->setEnabled(false);

  disconnect(m_start, &QPushButton::clicked, this, &Window::done);
  connect(m_start, &QPushButton::clicked, this, &Window::run);
}

void Window::abort() {
  m_sort->stop();
  play();
  disconnect(m_abort, &QPushButton::clicked, this, &Window::abort);
}

void Window::pause() {
  playing = false;
  disconnect(m_playpause, &QPushButton::clicked, this, &Window::pause);
  connect(m_playpause, &QPushButton::clicked, this, &Window::play);
  m_playpause->setText("Play");
  while (!playing) {
    QApplication::processEvents();
  }
}

void Window::play() {
  playing = true;
  disconnect(m_playpause, &QPushButton::clicked, this, &Window::play);
  connect(m_playpause, &QPushButton::clicked, this, &Window::pause);
  m_playpause->setText("Pause");
}

void Window::INCRCMP() {
  m_nbCmp->setText(QString::number(m_nbCmp->text().toInt() + 1));
}

void Window::Resize(int s) {
  if (s == 7) {
    m_parent->setFixedSize(1310, 620);
    m_view->setFixedSize(1100, 580);
    m_view->setSceneRect(0, 0, 1035, 580);
  } else {
    m_parent->setFixedSize(820, 620);
    m_view->setFixedSize(600, 580);
    m_view->setSceneRect(0, 0, 550, 580);
  }
}

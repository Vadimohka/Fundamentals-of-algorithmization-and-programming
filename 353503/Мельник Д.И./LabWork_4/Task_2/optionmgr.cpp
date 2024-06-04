#include "optionmgr.h"

OptionMgr::OptionMgr(QComboBox* menu) : m_menu(menu) {
  setParent(menu);
}

void OptionMgr::updateOptions(int algorithm) {
  m_menu->clear();
  switch (algorithm) {
    case 0:
      m_menu->addItem("Upwards");
      m_menu->setItemData(0, "Ω(n) | Θ(n²) | O(n²) || O(1)", Qt::ToolTipRole);
      m_menu->addItem("Downwards");
      m_menu->setItemData(1, "Ω(n) | Θ(n²) | O(n²) || O(1)", Qt::ToolTipRole);
      m_menu->addItem("Cocktail Shaker");
      m_menu->setItemData(2, "Ω(n) | Θ(n²) | O(n²) || O(1)", Qt::ToolTipRole);
      break;
    case 1:
      m_menu->addItem("Naive Partition");
      m_menu->setItemData(0, "Ω(n log n) | Θ(n log n) | O(n²) || O(log n)",
                          Qt::ToolTipRole);
      m_menu->addItem("Middle Pivot");
      m_menu->setItemData(1, "Ω(n log n) | Θ(n log n) | O(n²) || O(log n)",
                          Qt::ToolTipRole);
      m_menu->addItem("Best of three");
      m_menu->setItemData(
          2, "Ω(n log n) | Θ(n log n) | O(n log n) (normal cases) || O(log n)",
          Qt::ToolTipRole);
      m_menu->addItem("Median of medians");
      m_menu->setItemData(3, "Ω(n log n) | Θ(n log n) | O(n log n) || O(log n)",
                          Qt::ToolTipRole);
      break;
    case 2:
      m_menu->addItem("Standard");
      m_menu->setItemData(0, "Ω(n log n) | Θ(n log n) | O(n log n) || O(n)",
                          Qt::ToolTipRole);
      m_menu->addItem("Bottom-up");
      m_menu->setItemData(1, "Ω(n log n) | Θ(n log n) | O(n log n) || O(n)",
                          Qt::ToolTipRole);
      m_menu->addItem("Weavesort");
      m_menu->setItemData(2, "Ω(n log n) | ??? | O(n²) || O(n)",
                          Qt::ToolTipRole);
      break;
    case 3:
      m_menu->addItem("Max heap");
      m_menu->setItemData(0, "Ω(n log n) | Θ(n log n) | O(n log n) || O(1)",
                          Qt::ToolTipRole);
      m_menu->addItem("Max heap (variant)");
      m_menu->setItemData(1, "Ω(n log n) | Θ(n log n) | O(n log n) || O(1)",
                          Qt::ToolTipRole);
      m_menu->addItem("Min heap");
      m_menu->setItemData(2, "Ω(n log n) | Θ(n log n) | O(n log n) || O(1)",
                          Qt::ToolTipRole);
      m_menu->addItem("Ternary heap");
      m_menu->setItemData(3, "Ω(n log n) | Θ(n log n) | O(n log n) || O(1)",
                          Qt::ToolTipRole);
      break;
    case 4:
        m_menu->addItem("Interpol");
        m_menu->setItemData(0, "Ω(O(1)) | Θ(1) | O(1) || O(1)",
                            Qt::ToolTipRole);
        break;
  }
}

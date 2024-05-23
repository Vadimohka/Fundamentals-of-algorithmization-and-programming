#ifndef B37AD7AE_FFAB_4874_A12A_14F44517476B
#define B37AD7AE_FFAB_4874_A12A_14F44517476B

#include "Service.h"
#include <qtmetamacros.h>


class Paragraph : public Service {
  Q_OBJECT

    const QString FNAME = FILE_PREF + ".txt";
  virtual QString getInstructions() override;
  virtual void initInput() override;
  virtual void initOutput() override;


  public:
  using Service::Service;

  private slots:
  void textChanged();

  virtual void processOutput() override;
};

#endif /* B37AD7AE_FFAB_4874_A12A_14F44517476B */

#ifndef B37AD7AE_FFAB_4874_A12A_14F44517476B
#define B37AD7AE_FFAB_4874_A12A_14F44517476B

#include "IOService.h"
#include <qtmetamacros.h>


class IOParagraph : public IOService {
  Q_OBJECT

    const QString FNAME = FILE_PREF + ".txt";
  virtual QString getInstructions() override;
  virtual void initInput() override;
  virtual void initOutput() override;


  public:
  using IOService::IOService;

  private slots:
  void textChanged();

  virtual void processOutput() override;
};

#endif /* B37AD7AE_FFAB_4874_A12A_14F44517476B */

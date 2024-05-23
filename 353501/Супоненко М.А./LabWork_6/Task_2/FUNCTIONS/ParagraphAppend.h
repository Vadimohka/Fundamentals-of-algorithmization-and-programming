#ifndef FC74E9D5_D959_47CD_AD50_480B089F8657
#define FC74E9D5_D959_47CD_AD50_480B089F8657

#include "Paragraph.h"
#include "IOService.h"
#include <qtmetamacros.h>
class ParagraphAppend : public Service {
  Q_OBJECT

public:
  using Service::IOService;

  const QString FNAME = FILE_PREF + "_3.txt";

  virtual QString getInstructions() override;

  virtual void initInput() override;
  virtual void initOutput() override;

  void enterInput();

protected slots:
  virtual void processOutput() override;
};

#endif
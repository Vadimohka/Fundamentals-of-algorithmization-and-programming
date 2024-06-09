#ifndef FC74E9D5_D959_47CD_AD50_480B089F8657
#define FC74E9D5_D959_47CD_AD50_480B089F8657

#include "ParagraphW.h"
#include "Service.h"
#include <qtmetamacros.h>
class ParagAppend : public Service {
  Q_OBJECT

public:
  using Service::Service;

  const QString FNAME = FILENAME + "_3.txt";

  virtual QString getInstructions() override;

  virtual void initInput() override;
  virtual void initOutput() override;

  void enterInput();

protected slots:
  virtual void processOutput() override;
};

#endif 

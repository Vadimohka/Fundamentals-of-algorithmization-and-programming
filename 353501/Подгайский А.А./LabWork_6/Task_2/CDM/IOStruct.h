#ifndef E3AEB106_0C4B_456B_A0A0_0627A8C1262B
#define E3AEB106_0C4B_456B_A0A0_0627A8C1262B
#include "IOService.h"
#include <qtmetamacros.h>

class IOStruct : public IOService {
  Q_OBJECT
public:
    using IOService::IOService;

    const QString FNAME = FILE_PREF + "_1.txt";

protected:
  virtual QString getInstructions();
  virtual void initInput();
  virtual void initOutput();
  void enterInput();
protected slots:
  virtual void processOutput();
};

#endif /* E3AEB106_0C4B_456B_A0A0_0627A8C1262B */

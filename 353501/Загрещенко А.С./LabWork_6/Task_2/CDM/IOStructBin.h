#ifndef DC4FB188_A62D_405B_B039_F6631EE1F814
#define DC4FB188_A62D_405B_B039_F6631EE1F814
#include "IOService.h"

class IOStructBin : public IOService {

    const QString FNAME = FILE_PREF + "_2.bin";

  using IOService::IOService;
  virtual QString getInstructions();

  virtual void initInput();
  virtual void initOutput();
  void enterInput();

protected slots:
  virtual void processOutput();
};

#endif /* DC4FB188_A62D_405B_B039_F6631EE1F814 */

#include "IOService.h"
#include <qobject.h>
#include <qplaintextedit.h>

void IOService::init() {
      input->setPlainText({});
  output->setText({});
  
  if (type == BOTH || type == INP) {
    initInput();
  }
  if (type == BOTH || type == OUT) {
    initOutput();
  }

  if(type == OUT){
    input->setEnabled(false);
  } else {
    input->setEnabled(true);
  }

  instruction->setText(getInstructions());
}

IOService::IOService(QPlainTextEdit *inp, QLabel *outp, QLabel *instr,
                     QObject *par, ServiceType _type)
    : input(inp), output(outp), instruction(instr), QObject(par), type(_type) {}

void IOService::clear() { input->setPlainText({}); }
IOService::~IOService() {
    input->disconnect();
}

#include <QValidator>

class LongValidator : public QValidator {
  public:
  QValidator::State validate(QString& input, int& pos) const override;
};
#ifndef F1457040_37D4_45D9_9BF7_8FD3A1E1E315
#define F1457040_37D4_45D9_9BF7_8FD3A1E1E315
#include "coretypes.h"
#include <qaudioformat.h>
#include <QAudioDecoder>
#include <qaudioformat.h>
#include <qcontainerfwd.h>
#include <qobject.h>

class Loader : public QObject {
    Q_OBJECT

    QAudioDecoder* decoder;
    QAudioFormat format;
    StereoAudioBuffer resulting_buffer = {nullptr, nullptr};
    QVector<Sample> tmpBuffer;

public:
    Loader();
    ~Loader();
    void startDecoding(const QString& fname);

    StereoAudioBuffer getResultingBuffer();

    private slots:
        void readBuffer();
        void finishReading();

    signals:
        void onFinish();
        void error(QString err_text);

    

};

#endif /* F1457040_37D4_45D9_9BF7_8FD3A1E1E315 */

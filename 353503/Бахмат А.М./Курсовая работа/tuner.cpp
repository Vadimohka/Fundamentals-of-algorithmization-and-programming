#include "tuner.h"
#include <QFile>
#include <QDataStream>
#include <cmath>

Tuner::Tuner(QObject *parent) : QObject(parent), currentType(SixString) {
    updateFrequencies();
}

void Tuner::setGuitarType(GuitarType type) {
    currentType = type;
    updateFrequencies();
}

double Tuner::getFrequency(int stringNumber) {
    return frequencies.value(stringNumber, 0.0);
}

void Tuner::playFrequency(int stringNumber) {
    double frequency = getFrequency(stringNumber);
    if (frequency > 0) {
        QString soundFile = generateSoundFile(frequency);
        soundEffect.setSource(QUrl::fromLocalFile(soundFile));
        soundEffect.play();
    }
}

void Tuner::updateFrequencies() {
    frequencies.clear();

    switch (currentType) {
    case SixString:
        frequencies[1] = 82.41;  // E2
        frequencies[2] = 110.00; // A2
        frequencies[3] = 146.83; // D3
        frequencies[4] = 196.00; // G3
        frequencies[5] = 246.94; // B3
        frequencies[6] = 329.63; // E4
        break;
    case SevenString:
        frequencies[1] = 65.41;  // B1
        frequencies[2] = 82.41;  // E2
        frequencies[3] = 110.00; // A2
        frequencies[4] = 146.83; // D3
        frequencies[5] = 196.00; // G3
        frequencies[6] = 246.94; // B3
        frequencies[7] = 329.63; // E4
        break;
    case Ukulele:
        frequencies[1] = 261.63; // C4
        frequencies[2] = 293.66; // D4
        frequencies[3] = 329.63; // E4
        frequencies[4] = 392.00; // G4
        break;
    case FourStringBass:
        frequencies[1] = 84.41;  // E2
        frequencies[2] = 110.00;  // A2
        frequencies[3] = 147.83;  // D3
        frequencies[4] = 207.00;  // G3
        break;
    case FiveStringBass:
        frequencies[1] = 61.74;  // B1
        frequencies[2] = 84.41;  // E2
        frequencies[3] = 110.00;  // A2
        frequencies[4] = 147.83;  // D3
        frequencies[5] = 207.00;  // G3
        break;
    }
}

QByteArray Tuner::generateSineWave(double frequency, int sampleRate, int duration) {
    const int amplitude = 32760;
    int numSamples = sampleRate * duration;
    QByteArray byteArray;
    byteArray.resize(numSamples * sizeof(qint16));
    qint16 *data = reinterpret_cast<qint16*>(byteArray.data());

    for (int i = 0; i < numSamples; ++i) {
        double t = static_cast<double>(i) / sampleRate;
        data[i] = static_cast<qint16>(amplitude * std::sin(2 * M_PI * frequency * t));
    }

    return byteArray;
}

QString Tuner::generateSoundFile(double frequency) {
    const int sampleRate = 44100;
    const int duration = 2; // seconds

    QByteArray soundData = generateSineWave(frequency, sampleRate, duration);

    QString fileName = QString("tone_%1.wav").arg(frequency);
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly)) {
        QDataStream out(&file);

        // Write WAV file header
        out.writeRawData("RIFF", 4);
        int chunkSize = 36 + soundData.size();
        out.writeRawData(reinterpret_cast<const char*>(&chunkSize), sizeof(chunkSize));
        out.writeRawData("WAVE", 4);

        // Write fmt subchunk
        out.writeRawData("fmt ", 4);
        int subChunk1Size = 16; // 16 for PCM
        out.writeRawData(reinterpret_cast<const char*>(&subChunk1Size), sizeof(subChunk1Size));
        short audioFormat = 1; // PCM = 1
        out.writeRawData(reinterpret_cast<const char*>(&audioFormat), sizeof(audioFormat));
        short numChannels = 1; // Mono = 1
        out.writeRawData(reinterpret_cast<const char*>(&numChannels), sizeof(numChannels));
        out.writeRawData(reinterpret_cast<const char*>(&sampleRate), sizeof(sampleRate));
        int byteRate = sampleRate * numChannels * sizeof(qint16); // sampleRate * numChannels * bitsPerSample/8
        out.writeRawData(reinterpret_cast<const char*>(&byteRate), sizeof(byteRate));
        short blockAlign = numChannels * sizeof(qint16); // numChannels * bitsPerSample/8
        out.writeRawData(reinterpret_cast<const char*>(&blockAlign), sizeof(blockAlign));
        short bitsPerSample = 16; // 16 bits
        out.writeRawData(reinterpret_cast<const char*>(&bitsPerSample), sizeof(bitsPerSample));

        // Write data subchunk
        out.writeRawData("data", 4);
        int dataSize = soundData.size();
        out.writeRawData(reinterpret_cast<const char*>(&dataSize), sizeof(dataSize));
        out.writeRawData(soundData.data(), soundData.size());

        file.close();
    }

    return fileName;
}


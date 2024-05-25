#include "exporter.h"
#include <algorithm>
#include <stdexcept>
#include "CoreAudio.h"
#include "coretypes.h"
#include <iostream>

using namespace ae;


const int16_t Exporter::KOEF =  std::numeric_limits<int16_t>::max();

void Exporter::exportCoreBuffer(const QString& fname) {
    
        QFile f(fname);
        if(!f.open(QFile::WriteOnly)){
            throw std::runtime_error("Can not open file");
        }
        QDataStream stream (&f);

        auto buf = CoreAudio::getBuffer();

        WAV_HEADER header;

        int num_of_chan = buf.isStereo ? 2 : 1;
        header.Subchunk2Size = num_of_chan * buf.size * 16;
        header.SamplesPerSec = CoreAudio::SamplingFrequency;
        header.bytesPerSec =  num_of_chan * header.SamplesPerSec * 2;
        header.ChunkSize = 4 + (8 + header.Subchunk1Size) + (8 + header.Subchunk2Size);

        stream.writeRawData(reinterpret_cast<const char*>(&header), sizeof(WAV_HEADER));


        auto lgain = 1.0 / *std::max_element(buf.left, buf.left + buf.size);
        auto rgain = 1.0 / *std::max_element(buf.right, buf.right + buf.size);

        for(int i = 0; i < buf.size; ++i){
            int16_t l = std::min((int16_t)(buf.left[i] * lgain * (Sample)KOEF), KOEF);
            int16_t r =  std::min((int16_t)(buf.right[i] * rgain * (Sample)KOEF), KOEF);
            stream.writeRawData( reinterpret_cast<const char*>(&l), 2);
            stream.writeRawData( reinterpret_cast<const char*>(&r), 2);
        }

        f.close();

}

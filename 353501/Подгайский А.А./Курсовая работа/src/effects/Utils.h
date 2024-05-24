#ifndef B6E84D0E_D0A9_4B4E_91F7_3853223A1AE6
#define B6E84D0E_D0A9_4B4E_91F7_3853223A1AE6

#include "CoreAudio.h"
#include "coretypes.h"
#include <cmath>
#include <complex>
#include <valarray>
#include <vector>

class Utils {
  static constexpr double HANNING_A0 = 0.54347826087;

public:
  typedef std::valarray<std::complex<float>> Frequencies;

private:
  static Frequencies _fft(const Frequencies &freqs) {
    auto size = freqs.size();
    auto half_size = size / 2;

    if (size == 1) {
      return {freqs[0]};
    }

    Frequencies odd(half_size), even(half_size);
    for (int i = 0; i < half_size; ++i) {
      even[i] = freqs[i * 2];
      odd[i] = freqs[i * 2 + 1];
    }

    odd = _fft(odd);
    even = _fft(even);

    Frequencies res(size);
    for (int i = 0; i < half_size; ++i) {
      auto a = even[i];
      auto b = std::exp(std::complex<float>(0, -2 * M_PI * i / size)) * odd[i];
      res[i] = a + b;
      res[i + half_size] = a - b;
    }

    return res;
  }

  static void ef_fft(Frequencies &freqs, bool inv = false) {
    auto n = freqs.size();
    auto hf_n = n / 2;

    if (n == 1) {
      return;
    }

    Frequencies odd(hf_n), even(hf_n);
    for (int i = 0; i < hf_n; ++i) {
      even[i] = freqs[i * 2];
      odd[i] = freqs[i * 2 + 1];
    }

    ef_fft(odd);
    ef_fft(even);

    for (int i = 0; i < hf_n; ++i) {
      auto a = even[i];
      auto b =
          std::polar(1.0f, (float)((inv ? 1 : -1) * 2 * M_PI * i / n)) * odd[i];
      freqs[i] = a + b;
      freqs[i + hf_n] = a - b;

      if (inv) {
        freqs[i] /= n;
        freqs[i + hf_n] /= n;
      }
    }
  }

public:
  static double normalise(double x) {
    if(x > 0.0){
      return std::fmod(x + M_PI, 2.0 * M_PI) - M_PI;
    } else {
      return std::fmod(x - M_PI, 2.0 * M_PI) + M_PI;
    }
  }

  static std::vector<double> cosSumWindow(int win_size, int size,
                                          double a0 = HANNING_A0) {
    std::vector<double> window(size);
    auto a1 = 1 - a0;
    for (int i = 0; i < win_size; ++i) {
      window[i] = (a0 - a1 * std::cos(2.0 * M_PI * i / (double)win_size));
    }
    for (int i = win_size; i < size; ++i) {
      window[i] = 0;
    }
    return std::move(window);
  }

  static float sinc(float x, float sf) {
    if (x == 0.f) {
      return 1;
    }
    auto arg = M_PI * sf * x;
    return std::sin(arg) / arg;
  }

  static Frequencies fft(const Sample *buf, int size) {
    Frequencies freqs;

    freqs.resize(size);
    for (int i = 0; i < size; ++i) {
      freqs[i] = buf[i];
    }

    ef_fft(freqs);

    return freqs;
  }

  static void ifft(const Frequencies &freqs, Sample *out, size_t max_len) {
    Frequencies freqs_conj = freqs.apply(std::conj);
    ef_fft(freqs_conj);
    freqs_conj = freqs_conj.apply(std::conj);

    auto size = std::min(freqs_conj.size(), max_len);

    for (int i = 0; i < size; ++i) {
      out[i] = freqs_conj[i].real();
    }
  }

  static double sinc(double x) {
    auto arg = M_PI * ae::CoreAudio::SamplingFrequency * x;
    return std::sin(arg) / arg;
  }

  static void shiftBuf(Sample *buf, size_t beg, size_t end, long long shift) {
    if (shift > 0) {
      for (int i = end - 1; i >= beg; --i) {
        buf[i + shift] = buf[i];
      }
    } else {
      for (int i = beg; i < end; ++i) {
        buf[i + shift] = buf[i];
      }
    }
  }
};

#endif /* B6E84D0E_D0A9_4B4E_91F7_3853223A1AE6 */

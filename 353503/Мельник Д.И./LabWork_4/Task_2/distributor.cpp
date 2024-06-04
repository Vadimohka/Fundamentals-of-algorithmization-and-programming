#include "distributor.h"
#include "allConst.h"

Distributor::Distributor(int size, item* array)
    : m_size(size), m_array(array) {}

void Distributor::flip(int i, int j) {
  item tmp = m_array[i];
  m_array[i] = m_array[j];
  m_array[j] = tmp;
}

// DISTRIBUTIONS

void Distributor::Dregular() {
  if (m_size <= BOUNDARY_SIZE) {
    for (int i = 0; i < m_size; i++) {
      m_array[i] = Item(i);
    }
  } else {
    for (int i = 0; i < m_size; i++) {
      m_array[i] = Item(i / 2);
    }
  }
}

void Distributor::Duniform() {
  for (int i = 0; i < m_size; i++) {
    m_array[i] = Item(
        std::experimental::randint(0, std::min(m_size, BOUNDARY_SIZE) - 1));
  }
  std::sort(m_array, m_array + m_size);
}

void Distributor::Dcentered() {
  std::default_random_engine generator;
  std::normal_distribution<double> distribution(
      std::min(m_size, BOUNDARY_SIZE) / 2.0,
      std::min(m_size, BOUNDARY_SIZE) / 5.0);
  double number = 0;
  for (int i = 0; i < m_size;) {
    number = distribution(generator);
    if ((number >= 0.0) && (number < std::min(m_size, BOUNDARY_SIZE))) {
      m_array[i++] = Item(static_cast<int>(number));
    }
  }
  std::sort(m_array, m_array + m_size);
}

void Distributor::Dsplit() {
  Dcentered();
  for (int i = 0; i < m_size; i++) {
    if (m_array[i].val >= std::min(m_size, BOUNDARY_SIZE) / 2) {
      m_array[i].val -= std::min(m_size, BOUNDARY_SIZE) / 2;
    } else {
      m_array[i].val += std::min(m_size, BOUNDARY_SIZE) / 2;
    }
  }
  std::sort(m_array, m_array + m_size);
}

void Distributor::Dhigh() {
  std::default_random_engine generator;
  std::normal_distribution<double> distribution(
      std::min(m_size, BOUNDARY_SIZE) / 1.0,
      std::min(m_size, BOUNDARY_SIZE) / 3.0);
  double number = 0;
  for (int i = 0; i < m_size;) {
    number = distribution(generator);
    if ((number >= 0.0) && (number < std::min(m_size, BOUNDARY_SIZE))) {
      m_array[i++] = Item(static_cast<int>(number));
    }
  }
  std::sort(m_array, m_array + m_size);
}

void Distributor::Dlow() {
  std::default_random_engine generator;
  std::normal_distribution<double> distribution(
      0.0, std::min(m_size, BOUNDARY_SIZE) / 3.0);
  double number = 0;
  for (int i = 0; i < m_size;) {
    number = distribution(generator);
    if ((number >= 0.0) && (number < std::min(m_size, BOUNDARY_SIZE))) {
      m_array[i++] = Item(static_cast<int>(number));
    }
  }
  std::sort(m_array, m_array + m_size);
}

// SCRAMBLES

void Distributor::Srandom() {
  for (int i = 0; i < m_size; ++i) {
    flip(i, std::experimental::randint(i, m_size - 1));
  }
}

void Distributor::Ssorted() {
  int lg = 0;
  for (int i = 1; i < m_size; i *= 2) {
    lg++;
  }
  for (int i = 0; i < m_size; ++i) {
    flip(i, std::experimental::randint(std::max(0, i - lg),
                                       std::min(m_size - 1, i + lg)));
  }
}

void Distributor::Sreversed() {
  for (int i = 0; i < m_size / 2; i++) {
    flip(i, m_size - 1 - i);
  }
  Ssorted();
}

void Distributor::Sshuffle() {
  Ssorted();
  for (int i = 0; i < m_size / 2; i += 2) {
    flip(i, m_size - 1 - i);
  }
}

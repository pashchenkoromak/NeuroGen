#include <NeuroWeb/NeuroWeb.hpp>

size_t NeuroWeb::getSizeOfFirstLayer() const noexcept {
  if (m_layers.size() > 0)
    return m_layers[0].size();
  else
    return 0;
}

void NeuroWeb::setInputSygnal(const std::vector<double> &inputSygnal) noexcept {
  if (!m_layers.size()) return;
  m_layers[0].setInputSygnal(inputSygnal);
}

Layer NeuroWeb::getFinishLayer() const noexcept {
  if (!m_layers.size()) return Layer::EMPTY_LAYER;
  return *(m_layers.rbegin());
}

void NeuroWeb::run() noexcept {
  for (auto layer : m_layers) {
    layer.activate();
  }
}

std::ostream &operator<<(std::ostream &os, const NeuroWeb &neuroWeb) {}

std::istream &operator>>(std::istream &is, NeuroWeb &neuroWeb) {}

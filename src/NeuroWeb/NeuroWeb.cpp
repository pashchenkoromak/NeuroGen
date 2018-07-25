#include <NeuroWeb/NeuroWeb.hpp>

size_t NeuroWeb::getSizeOfFirstLayer() const noexcept {
  if (m_layers.size() > 0)
    return m_layers[0].getSize();
  else
    return 0;
}

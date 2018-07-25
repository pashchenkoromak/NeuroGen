#pragma once

#include <fstream>
#include <memory>
#include <vector>
#include "NeuroWeb/Neuron.hpp"

/// @class Layer
/// @brief Contain operations with one neuron layer
class Layer {
 public:
  /// @brief default constructor and destructor
  /// @{
  Layer() = default;
  ~Layer() = default;
  /// @}

  /// @brief operator ==
  /// @note It works for O(N) time, where N - size of layer.
  /// @note It doesn`t deep check. Only equality of memory places for each
  /// neuron.
  /// @param[in] other - Layer for checking equality.
  /// @return true, if Layers are the same.
  bool operator==(const Layer &other) const;

  /// @brief See operator == explanation.
  bool operator!=(const Layer &other) const;

  /// @brief Create new Layer at the end
  Layer createNewNextLayer();

  /// @brief activate layer
  void activate();

  /// @brief get Neurons count in layer.
  size_t size() const;

  /// @brief get each neuron activation result
  /// @return vector of doubles - activation values
  std::vector<double> getResults();

  /// @brief set input sygnal
  /// @note if inputSygnal.size is bigger, then Neurons count - extra
  /// sygnals will be ignored.
  /// If inputSygnal.size is less, then Neurons count in  - sygnals
  /// to extra Neurons will be 0.
  void setInputSygnal(const std::vector<double> &inputSygnal) noexcept;

  /// @brief Operators for input and output
  /// @{
  friend std::ostream &operator<<(std::ostream &os, const Layer &layer);
  friend std::istream &operator>>(std::istream &is, Layer &layer);
  /// @}

  /// @brief const empty layer
  static const Layer EMPTY_LAYER = Layer();

 private:
  /// @brief neurons array
  std::vector<std::shared_ptr<Neuron>> m_neurons;

  /// @brief new Layer size
  size_t m_newLayerSize = 9;
};

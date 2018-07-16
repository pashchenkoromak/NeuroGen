#pragma once

#include "NeuroWeb/Neuron.hpp"
#include <fstream>
#include <memory>
#include <vector>

/// @class Layer
/// @brief Contain operations with one neuron layer
class Layer
{
public:
   /// @brief default constructor and destructor
   /// @{
   Layer() = default;
   ~Layer() = default;
   /// @}

   /// @brief operator ==
   /// @note It works for O(N) time, where N - size of layer.
   /// @note It doesn`t deep check. Only equality of memory places for each neuron.
   /// @param[in] other - Layer for checking equality.
   /// @return true, if Layers are the same.
   bool operator==(const Layer &other) const;

   /// @brief See operator == explanation.
   bool operator!=(const Layer &other) const;

   /// @brief Create new Layer at the end
   static Layer createLayer(Layer &previousLayer = EMPTY_LAYER, const Layer &nextLayer = EMPTY_LAYER);

   /// @brief activate layer
   void activate();

   /// @brief get each neuron activation result
   /// @return vector of doubles - activation values
   std::vector<double> getResults();

   /// @brief Operators for input and output
   /// @{
   friend std::ostream &operator<<(std::ostream &os, const Layer &layer);
   friend std::istream &operator>>(std::istream &is, Layer &layer);
   /// @}
private:
   /// @brief neurons array
   std::vector<std::shared_ptr<Neuron>> m_neurons;

   /// @brief const empty layer
   static constexpr Layer EMPTY_LAYER = Layer();
};

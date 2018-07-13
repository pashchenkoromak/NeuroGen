#include "Neuron.hpp"
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

   /// @brief activate layer
   void activate();

   /// @brief get each neuron activation result
   /// @return vector of doubles - activation values
   std::vector<double> getResults();

   /// @brief Operators for input and output
   /// @{
   friend std::ostream &operator<<(std::ostream &os, const NeuroWeb &neuroWeb);
   friend std::istream &operator>>(std::istream &is, NeuroWeb &neuroWeb);
   /// @}
private:
   /// @brief neurons array
   std::vector<std::shared_ptr<Neuron>> m_neurons;
};

#include "Neuron.hpp"
#include <fstream>
#include <memory>
#include <vector>

/// @class NeuroWeb
/// @brief Neuron web, it can study using some samples, after studying it
/// can play the game.
class NeuroWeb
{
public:
   /// @brief contructor and destructor
   /// @{
   NeuroWeb() = default;
   ~NeuroWeb() = default;
   /// @}

   /// @brief studies, using input file.
   /// @param[in] inputFile - file with information for studying.
   /// @param[in] maxEpoch - study iterations count.
   void study(std::ifstream &inputFile, const int maxEpoch = 1000) noexcept;

   /// @brief get the best turn (due to neuron web) using current
   /// state of field.
   int getNextTurn(const std::vector<std::vector<int>> &field) noexcept;

   /// @brief creates a copy of this web with some small change.
   /// @return mutant NeuroWeb
   NeuroWeb mutate();

   /// @brief creates a child of two webs, it contain some parts
   /// of both parents.
   /// @return child NeuroWeb.
   NeuroWeb generate(const NeuroWeb &otherParent);

private:
   /// @enum Mutations
   /// @brief list of possible mutations
   enum Mutations
   {
      AddNeuron,
      DeleteNeuron,
      IncreaseSynapse,
      DecreaseSynapse,
   };

   /// @brief child have some mutation probability
   const static double mutationProbability = 0.1;

   /// @brief sends signal by neuron with number = id to all neurons connected him.
   /// @param[in] id - neuron-sender number.
   void sendSygnal(const int id) noexcept;

   /// @brief vector of neurons.
   std::vector<Neuron> m_neurons;

   /// @brief neuron graph.
   std::vector<std::vector<double>> m_web;
};

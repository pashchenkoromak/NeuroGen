#pragma once

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
   /// @brief Contructor and destructor
   /// @{
   NeuroWeb() = default;
   ~NeuroWeb() = default;
   /// @}

   /// @brief Studies, using input file.
   /// @param[in] inputFile - file with information for studying.
   /// @param[in] maxEpoch - study iterations count.
   void study(std::ifstream &inputFile, const int maxEpoch = 1000) noexcept;

   /// @brief Get the best turn (due to neuron web) using current
   /// state of field.
   int getNextTurn(const std::vector<std::vector<int>> &field) noexcept;

   /// @brief Creates a copy of this web with some small change.
   /// @return Mutant NeuroWeb
   NeuroWeb mutate();

   /// @brief Creates a child of two webs, it contain some parts
   /// of both parents.
   /// @return Child NeuroWeb.
   NeuroWeb generate(const NeuroWeb &otherParent);

   /// @brief Operators for input and output
   /// @{
   friend std::ostream &operator<<(std::ostream &os, const NeuroWeb &neuroWeb);
   friend std::istream &operator>>(std::istream &is, NeuroWeb &neuroWeb);
   /// @}

private:
   /// @enum Mutations
   /// @brief List of possible mutations
   enum Mutations
   {
      AddNeuron,
      AddNeuronToEachLayer,
      AddLayer,
      DeleteNeuron,
      DeleteLayer,
      DeleteNeuronFromEachLayer,
      IncreaseSynapse,
      DecreaseSynapse,
   };

   /// @brief Child have some mutation probability
   const static double mutationProbability = 0.1;

   /// @brief Sends signal by neuron with number = id to all neurons connected him.
   /// @param[in] id - neuron-sender number.
   void sendSygnal(const int id) noexcept;

   /// @brief Vector of neurons.
   std::vector<Neuron> m_neurons;

   /// @brief Neuron graph.
   std::vector<std::vector<double>> m_web;
};

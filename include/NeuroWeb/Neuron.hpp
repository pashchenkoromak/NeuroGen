#pragma once

#include <fstream>
#include <memory>
#include <vector>

class Neuron;

struct Synapse
{
   double weight;
   std::shared_ptr<Neuron> target;
   static constexpr double defaultWeight = 1.0;
};

/// @class Neuron
/// @brief Is a basic unit of neuron web, it can receive sygnals and
/// calculate new signal.
class Neuron
{
public:
   /// @brief Default constructor and destructor
   /// @{
   Neuron() = default;
   ~Neuron() = default;
   /// @}

   /// @brief Creates new Neuron, connected to given neurons Layer
   /// @param[in] connectTo - reference to vector of neurons
   /// @return New neuron
   static Neuron createNewNeuron(const std::vector<std::shared_ptr<Neuron>> &connectTo);

   /// @brief Add synapse from this Neuron to specified
   /// @param[in] neighbor - specified Neuron to create synapse
   void addSynapse(std::shared_ptr<Neuron> neighbor) noexcept;

   /// @brief Increase signal to neuron
   /// @param[in] _signal - value of incoming signal
   void addSignal(const double _signal) noexcept;

   /// @brief Get value that must be sended to other neurons
   /// @return double as a result
   double getResult() const noexcept;

   /// @brief Send signals to all neighbors
   void activate() noexcept;

   /// @brief Set signal to zero
   void nullify() noexcept;

   /// @brief Operators for input and output
   /// @{
   friend std::ostream &operator<<(std::ostream &os, const Neuron &neuroWeb);
   friend std::istream &operator>>(std::istream &is, Neuron &neuroWeb);
   /// @}

private:
   /// @brief Normalize sygnal
   /// @return Value [0, 1].
   double activation() const noexcept;

   /// @brief Sum of received signals
   double m_signal;

   /// @brief connected neurons
   std::vector<Synapse> m_neighbors;
};

#include "NeuroWeb/Neuron.hpp"
#include <math.h>

Neuron Neuron::createNewNeuron(const std::vector<std::shared_ptr<Neuron>> &connectTo)
{
   Neuron newNeuron;
   for (auto neighbor : connectTo)
      newNeuron.addSynapse(neighbor);
}

void Neuron::addSynapse(std::shared_ptr<Neuron> neighbor) noexcept
{
   m_neighbors.push_back({Synapse::defaultWeight, neighbor});
}

void Neuron::addSignal(const double _signal) noexcept
{
   m_signal += _signal;
}

double Neuron::getResult() const noexcept
{
   return activation();
}

void Neuron::activate() noexcept
{
   const double signal = activation();
   for (auto nb : m_neighbors)
   {
      nb.target->addSignal(signal * nb.weight);
   }
}

void Neuron::nullify() noexcept
{
   m_signal = 0;
   m_neighbors.clear();
}

double Neuron::activation() const noexcept
{
   const static double alpha = 1;
   return 1 / (1 + exp(-alpha * m_signal));
}

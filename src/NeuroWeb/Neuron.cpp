#include "NeuroWeb/Neuron.hpp"
#include <math.h>

void Neuron::addNeuron(std::shared_ptr<Neuron> neighbor) noexcept
{
   neighbors.push_back({Synapse::defaultWeight, neighbor});
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
   for (auto nb : neighbors)
   {
      nb.target->addSignal(signal * nb.weight);
   }
}

void Neuron::nullify() noexcept
{
   m_signal = 0;
   neighbors.clear();
}

double Neuron::activation() const noexcept
{
   const static double alpha = 1;
   return 1 / (1 + exp(-alpha * m_signal));
}

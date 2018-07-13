#include <NeuroWeb/Layer.hpp>
void Layer::activate()
{
   for (auto neuron : m_neurons)
   {
      neuron->activate();
   }
}

std::vector<double> Layer::getResults()
{
   std::vector<double> res;
   const size_t N = m_neurons.size();
   res.resize(N);
   for (size_t i = 0; i < N; i++)
      res[i] = m_neurons[i]->getResult();
   return res;
}

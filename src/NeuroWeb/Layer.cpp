#include <NeuroWeb/Layer.hpp>
bool Layer::operator==(const Layer &other) const
{
   size_t N = m_neurons.size(), N_other = other.m_neurons.size();
   bool equal = (N == N_other);
   for (auto i = 0; i < N && equal; i++)
      equal = (m_neurons[i] == other.m_neurons[i]);
   return equal;
}

bool Layer::operator!=(const Layer &other) const
{
   return !(*this == other);
}

Layer Layer::createLayer(const Layer &previousLayer, const Layer &nextLayer)
{
   Layer currentLayerl
}

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

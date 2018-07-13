#include <fstream>

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

   /// @brief Increase signal to neuron
   /// @param[in] _signal - value of incoming signal
   void addSignal(const double _signal) noexcept;

   /// @brief Get value that must be sended to other neurons
   /// @return double as a result
   double getResult() const noexcept;

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
};

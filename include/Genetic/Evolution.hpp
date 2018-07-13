#include "NeuroWeb/NeuroWeb.hpp" l
#include <vector>

/// @brief Main power of evolution.
class Evolution
{
public:
   /// @brief Default constructor and destructor
   /// @{
   Evolution() = default;
   ~Evolution() = default;
   /// @}

   /// @brief Starts an evolution process.
   /// @param[in] populationSize - starting population size
   /// @param[in] epochCount - count of epoches for evolution
   void run(const size_t populationSize, const size_t epochCount) noexcept;


private:
   /// @brief Creates zero generation with <size> elements
   void createZeroGeneration(const std::size_t size) noexcept;

   /// @brief Best individuals will have less numbers
   void sortPopulation() noexcept;

   /// @brief Kill some useless individuals
   /// @param[in] rate - if 0 - don`t kill anyone, 1 - kill all
   void killUseless(const double rate = 0.5) noexcept;

   /// @brief Generates next population from alive individuals
   void generateNextPopulation() noexcept;

   /// @brief Current population for evolution
   std::vector<NeuroWeb> population;
};

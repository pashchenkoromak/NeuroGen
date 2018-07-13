#include "NeuroWeb/NeuroWeb.hpp" l
#include <vector>

/// @brief main power of evolution.
class Evolution
{
public:
   /// @brief default constructor and destructor
   /// @{
   Evolution() = default;
   ~Evolution() = default;
   /// @}

   /// @brief starts an evolution process.
   /// @param[in] populationSize - starting population size
   /// @param[in] epochCount - count of epoches for evolution
   void run(const size_t populationSize, const size_t epochCount) noexcept;


private:
   /// @brief creates zero generation with <size> elements
   void createZeroGeneration(const std::size_t size) noexcept;

   /// @brief best individuals will have less numbers
   void sortPopulation() noexcept;

   /// @brief kill some useless individuals
   /// @param[in] rate - if 0 - don`t kill anyone, 1 - kill all
   void killUseless(const double rate = 0.5) noexcept;

   /// @brief generates next population from alive individuals
   void generateNextPopulation() noexcept;

   /// @brief current population for evolution
   std::vector<NeuroWeb> population;
};

#include "algorithm/sort3elements.h"

#include <stdexcept>
#include <utility>

#include <iostream>

namespace envio 
{
namespace algorithm 
{

void Sort3Elements::Sort(std::vector<uint32_t>& vec) {
  uint32_t low_idx = 0u;
  uint32_t high_idx = vec.size() - 1u;
  uint32_t middle_idx = 0u;

  while(middle_idx <= high_idx) {
    switch (vec[middle_idx])
    {
    case 0:
      // swap middle_idx with low_idx then increment both of them by 1
      std::swap(vec[low_idx++], vec[middle_idx++]);
      break;
    case 1:
      ++middle_idx;
      break;
    case 2:
      std::swap(vec[middle_idx], vec[high_idx--]);
      break;
    
    default:
      throw std::domain_error("Invalid value");
    }
  }
}

}
}
#pragma once

#include <algorithm>
#include <cinttypes>
#include <ostream>
#include <vector>

namespace envio
{
namespace algorithm
{

class Sort3Elements {
public:
  Sort3Elements() = default;
  ~Sort3Elements() = default;

  /// Explicitly Default-Copyable
  Sort3Elements(const Sort3Elements&) = default;
  /// Explicitly Default-Copy-Assignable
  Sort3Elements& operator=(const Sort3Elements&) = default;

  /// Explicitly Default-Movable
  Sort3Elements(Sort3Elements&& msg) = default;
  /// Explicitly Default-Move-Assignable
  Sort3Elements& operator=(Sort3Elements&& msg) = default;

  /// \brief   Sorts an array of 0s, 1s and 2s in linear time complexity.
  /// \details This implementation sorts the \p vec array in-place so the
  ///          space complexity is constant (1).
  ///          Example 1: 
  ///            given array:            {1, 2, 0}
  ///            the expected result is: {0, 1, 2}
  ///          Example 2:
  ///            given array:            {0, 1, 1, 2, 2, 0, 0, 1, 2, 1}
  ///            the expected result is: {0, 0, 0, 1, 1, 1, 1, 2, 2, 2}
  /// \param vec[in,out] The given to be sorted.
  void Sort(std::vector<uint32_t>& vec);
};

} // namespace synchronization
} // namespace triad

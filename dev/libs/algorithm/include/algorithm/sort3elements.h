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

};

} // namespace synchronization
} // namespace triad

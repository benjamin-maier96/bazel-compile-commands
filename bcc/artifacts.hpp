#pragma once

#include <cstdint>
#include <string>

#ifdef environ
#  undef environ  // MSVC CRT defines environ as a macro; conflicts with a proto field name.
#endif
#include "src/main/protobuf/analysis_v2.pb.h"

#include "bcc/path_fragments.hpp"

namespace bcc {
///  Artefacts for lookup.
class artifacts
{
public:
  artifacts(google::protobuf::RepeatedPtrField<analysis::Artifact> const& artifacts, path_fragments fragments);

  std::string path_of_artifact(std::uint32_t artifact_id) const;

private:
  std::unordered_map<std::uint32_t, std::uint32_t> artifacts_;
  path_fragments fragments_;
};
}

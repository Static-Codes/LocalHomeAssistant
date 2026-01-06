#include "status.hpp"

struct Feature {
    FeatureName name;
    FeatureStatus status = FeatureStatus::Available;

    void setStatus(FeatureStatus status) noexcept;
    const FeatureStatus& getStatus() const noexcept;
    volatile FeatureStatus& getStatus() noexcept;
};

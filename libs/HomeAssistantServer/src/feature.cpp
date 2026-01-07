#include "includeall.hpp"

void Feature::setStatus(FeatureStatus status) noexcept {
    this->status = status;
}

const FeatureStatus& Feature::getStatus() const noexcept {
    return this->status;
}

volatile FeatureStatus& Feature::getStatus() noexcept {
    return this->status;
}

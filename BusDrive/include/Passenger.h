#pragma once

#include <array>
#include <glm/glm.hpp>

#include "defs.h"
#include "BidirSegment.h"
#include "Bus.h"
#include "util.h"

class Passenger {
private:

    static constexpr float MIN_SCALE_Y{ 0.5f };
    static constexpr float MAX_SCALE_Y{ 1.4f };
    static constexpr float V{ 0.003f };

    static constexpr std::array<glm::vec3, 5> sharedPathNodes = { {
        {Bus::WIDTH / 2 + 2.0f, 0.0f, -(Bus::REAR_AXLE_TO_FRONT - 1.0f)},
        {Bus::WIDTH / 2 + 0.4f, 0.0f, -(Bus::REAR_AXLE_TO_FRONT - 1.0f)},
        {Bus::WIDTH / 2, Bus::FLOOR_HEIGHT, -(Bus::REAR_AXLE_TO_FRONT - 1.0f)},
        {0.0f, Bus::FLOOR_HEIGHT, -(Bus::REAR_AXLE_TO_FRONT - 1.0f)},
        {0.0f, Bus::FLOOR_HEIGHT, -(Bus::REAR_AXLE_TO_FRONT - 3.0f)}
    } };

    inline static std::array<BidirSegment, 4> buildSharedPath(const std::array<glm::vec3, 5>& points) {
        std::array<BidirSegment, 4> segments = {};

        float totalDist = 0.0f;
        for (size_t i = 0; i < 4; ++i) {
            segments[i].a = points[i];
            segments[i].b = points[i + 1];
            float d = segments[i].getLength();
            segments[i].precedingTotal = totalDist;
            totalDist += d;
        }

        float revTotalDist = 0.0f;
        for (int i = 3; i >= 0; --i) {
            segments[i].reversePrecedingTotal = revTotalDist;
            revTotalDist += segments[i].getLength();
        }

        return segments;
    }

    inline static float getSharedPathLength(const std::array<BidirSegment, 4>& segments) {
        float sum = 0.0f;

        for (const BidirSegment& bs : segments) {
            sum += bs.getLength();
        }

        return sum;
    }

    inline static const std::array<BidirSegment, 4> sharedPath = buildSharedPath(sharedPathNodes);
    inline static const float SHARED_PATH_LENGTH = getSharedPathLength(sharedPath);

    double lastRegisteredTime;
    float dist;

    int _orientation{ DIR_NEG_X };
    int _state{ PASG_UNBOARDED };

    glm::vec3 _pos{ sharedPathNodes.at(0) };

public:

    float scaleY;

    const int& orientation{ _orientation };
    const int& state{ _state };
    const glm::vec3& pos{ _pos };

    bool isControl{ false };

    void doStateStep();

    void startBoarding();

    void startDisembarking();
};
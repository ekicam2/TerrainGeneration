#pragma once

#include <vector>
#include <stdint.h>

class PerlinNoise
{
public:
    PerlinNoise();
    PerlinNoise(uint32_t seed);
    virtual ~PerlinNoise();

    double noise(double x, double y, double z);

protected:
    double fade(double t);
    double grad(int hash, double x, double y, double z);

private:
    std::vector<int32_t> _permutation;
};


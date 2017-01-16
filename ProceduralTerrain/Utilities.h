#pragma once

float clamp(float value, float min, float max) {
    float returner = value;

    if (value > max)
        returner = max;

    if (value < min)
        returner = min;

    return returner;
}

float lerp(float val1, float val2, float weight) {
    float nWeight = clamp(weight, 0.0f, 1.0f);
    return (1 - nWeight) * val1 + nWeight*val2;
}
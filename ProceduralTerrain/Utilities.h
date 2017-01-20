#pragma once

/*
    Keep passed value in range.

    @param value incoming value to be checked
    @param min lower bound of the range
    @param max upper bound of the range
*/
template <typename T>
float clamp(T value, T min, T max)
{
    float returner = value;

    if (value > max)
        returner = max;

    if (value < min)
        returner = min;

    return returner;
}

/*
    Interpolate lineary from val1 to val2 with given weight.
    Passed eight should be in range between 0 and 1.
    Anyway if it's not function will automatically clamp the value!
    
    @param val1 first value
    @param val2 second value
    @param weight used for interpolation
*/
template <typename T>
T lerp(T val1, T val2, T weight)
{
    T nWeight = clamp(weight, 0.0, 1.0);
    return (1.0 - nWeight) * val1 + nWeight * val2;
}

/*
    Re-map any passed number from one range to another

    @param  value  the incoming value to be converted
    @param  start1 lower bound of the value's current range
    @param  stop1  upper bound of the value's current range
    @param  start2 lower bound of the value's target range
    @param  stop2  upper bound of the value's target range
    @return remapped number
*/
template <typename T, typename K, typename V>
V mapValue(T value, K start1, K stop1, V start2, V stop2) 
{
    return ((value - start1) / (stop1 - start1))*(stop2 - start2) + start2;
}
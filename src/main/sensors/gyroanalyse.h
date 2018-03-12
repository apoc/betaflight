/*
 * This file is part of Cleanflight.
 *
 * Cleanflight is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Cleanflight is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Cleanflight.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "common/time.h"
#include "common/filter.h"

#define FFT_SAMPLING_FREQUENCY  4000  // if gyro loop is faster than FFT_SAMPLING_FREQUENCY limit update speed to FFT_SAMPLING_FREQUENCY
#define FFT_SAMPLING_TIME       (1000000 / FFT_SAMPLING_FREQUENCY)

typedef struct gyroFftData_s {
    float maxVal;
    uint16_t centerFreq;
} gyroFftData_t;

void gyroDataAnalyseInit(uint32_t targetLooptime);
const gyroFftData_t *gyroFftData(int axis);
struct gyroDev_s;
void gyroDataAnalyse(const struct gyroDev_s *gyroDev, biquadFilter_t *notchFilterDyn);
void gyroDataAnalyseUpdate(biquadFilter_t *notchFilterDyn);

# eltex-app
This is my humble collection of scripts I wrote during my work and study in BINP

This program calculates the cross-section of the process of electron-positron annihilation into f_2 meson.
This can actually be modified by changing born cross-section in section.cpp

The calculation involves procedures from GSL library, which are implemented in getExperimental.cpp and getCorrections.cpp.
The first calculates the impact of energy distribution in the electron beam on the cross-section, while the latter calculates
radiative corrections to the cross-section. Radiative corrections can be calculated using Fadin-Kuraev-Lipatov radiaton function.
This function is in the radiator.cpp file.

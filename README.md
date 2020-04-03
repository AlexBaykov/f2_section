# eltex-app
This is my humble collection of scripts I wrote during my work and study in BINP

This program calculates the cross-section of the process of electron-positron annihilation into f_2 meson.
This can actually be modified by changing born cross-section in section.cpp

The calculation involves procedures from GSL library, which are implemented in integration.cpp. 
getExperimantal.cpp calculates the impact of energy distribution in the electron beam on the cross-section, while
getCorretions.cpp  calculates radiative corrections to the cross-section. Radiative corrections can be calculated using
Fadin-Kuraev-Lipatov radiaton function. This function is in the radiator.cpp file.

This program uses ROOT CERN to store the output graphs, thus ROOT CERN is required for it compile. I have put the graphs in
pdf for convinience.

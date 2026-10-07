# Traffic Light Controller Using 555 Timer IC

An analog hardware implementation of a sequential traffic signal controller built using NE555 timer ICs operating in astable mode. This project simulates the standard three-phase traffic light sequence (Red → Yellow → Green) using purely analog timing networks without microcontrollers.

##  Project Overview
Modern traffic signals rely heavily on microcontrollers or PLCs. This project demonstrates an accessible, low-cost, and robust alternative using discrete analog components to control vehicular flow and timing delays through cascaded RC networks.

### Key Objectives
1. **Astable Multivibrator Design:** Configure three NE555 timer ICs in astable mode to control phase delays.
2. **Sequential Switching:** Implement automatic, continuous cycling of Red, Yellow, and Green LEDs.
3. **Theoretical & Practical Verification:** Calculate timing parameters using RC equations and validate via Proteus simulation and breadboard implementation.

##  Traffic Signal Timing & Behavior

| Phase | Active LED | Intended Duration | Function |
| :--- | :--- | :--- | :--- |
| **Stop** | Red | ~10 Seconds | Holds vehicular traffic |
| **Ready** | Yellow | ~3 Seconds | Caution/Transition phase |
| **Go** | Green | ~10 Seconds | Allows traffic clearance |

##  Circuit Design & Working Principle

Each signal phase is driven by an independent NE555 timer configured in astable mode. The timing parameters for each phase are determined by:

$$t_H = 0.693 \times (R_1 + R_2) \times C$$

$$t_L = 0.693 \times R_2 \times C$$

$$T = t_H + t_L = 0.693 \times (R_1 + 2R_2) \times C$$

### Operational Sequence:
1. **Power On:** The Red LED illuminates first as Timer 1 completes its timing cycle.
2. **Cascaded Triggering:** As Timer 1's output transitions LOW, it triggers Timer 2 to activate the Yellow LED.
3. **Completion & Reset:** Upon completion of the Yellow phase, Timer 3 triggers the Green LED before automatically resetting the cycle back to Red.

##  Components List

| Component | Specification / Value | Quantity |
| :--- | :--- | :--- |
| **Timer IC** | NE555 / LM555 | 3 |
| **Resistors** | $R_1 = 10\text{ k}\Omega$, $R_2 = 100\text{ k}\Omega$ | 6 |
| **Current Limiting Resistors** | $330\Omega - 1\text{ k}\Omega$ | 3 |
| **Capacitors** | $C = 10\mu\text{F}$ / $100\mu\text{F}$ (Electrolytic), $0.01\mu\text{F}$ (Bypass) | 3 each |
| **LEDs** | Red, Yellow, Green | 3 |
| **Power Supply** | 5V – 12V DC | 1 |
| **Prototyping** | Breadboard & Jumper Wires | — |

##  Simulation & Testing
- **Simulation Environment:** Proteus Design Suite.
- **Hardware Validation:** Constructed on physical breadboard and tested across input voltages ranging from 5V to 12V DC.
- **Output:** Verified square wave outputs on Pin 3 of each IC, showing stable sequential transitions with minor timing variations (~5–8%) attributable to passive component tolerances ($\pm10\%$ for resistors, $\pm20\%$ for electrolytic capacitors).

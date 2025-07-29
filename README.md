# ACC Live Telemetry

ACC Live Telemetry is a software project that extracts **real-time telemetry data** from **Assetto Corsa Competizione**.  
It allows sending this data to external electronic devices, enabling the creation of dashboards, lap timers, or even complete racing simulators.

## Features

- Real-time telemetry extraction from Assetto Corsa Competizione.
- Data transmission to external hardware (microcontrollers, displays, etc.).
- Flexible usage: dashboards, lap timers, physical simulators, or custom projects.
- Easy-to-modify codebase for integration into different systems.

## Example Use Cases

- **Dynamic dashboards**: Display speed, gear, RPM, and more on custom hardware.
- **Lap timers**: Extract live lap times for external displays.
- **Simulators**: Interact with actuators or other hardware to create a realistic racing experience.

## Installation & Build

1. Clone the repository:
    ```bash
    git clone https://github.com/easzyyyyy/acc-live-telemetry.git
    ```
2. Open `ACCLiveTelemetry.vcxproj` in **Visual Studio**.
3. Build the project (ensure proper dependencies and libraries are installed).
4. Run the executable alongside **Assetto Corsa Competizione**.

## Usage

1. Launch **Assetto Corsa Competizione**.
2. Start **ACC Live Telemetry**.
3. Configure the output settings to send data to your desired device or system.
4. Use the data in your custom application (e.g., dashboards, telemetry analyzers, simulators).

## Roadmap

- Add prebuilt modules for popular microcontrollers (Arduino, ESP32).
- Web interface for live telemetry visualization.
- Support for multiple concurrent hardware targets.

## License

This project is distributed under the **MIT License**.

---

**Repository:** [https://github.com/easzyyyyy/acc-live-telemetry](https://github.com/easzyyyyy/acc-live-telemetry)

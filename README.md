# 📡 GPS Tracking System
## 📝 Project Description
The goal of this project is to develop an embedded system using C programming that gathers real-time positional coordinates while the microcontroller (TM4C123G LaunchPad) is in motion, forming a GPS tracking system. The collected data is transferred to a PC for map visualization. The system stops collecting data based on specific conditions:

### 🛑 Stop Conditions:
1- **Distance-based**: Stop when the distance exceeds 100 meters, and mark the final point as the destination.

2- **Push Button**: Stop when a push button is pressed, and the last point added is marked as the destination.

3- **Predefined Destination**: Stop when the system reaches a predefined point in the code.

## ⚙️ Other System Functions:
- When the destination point is reached, the built-in LED on the LaunchPad lights up.
- The system checks for UART commands from the PC. If the PC sends the command 'U', the system sends the stored trajectory data to the PC.
  
## 🛠 Hardware Requirements
- Tiva C Series TM4C123GXL LaunchPad
- GPS Module (e.g., Ublox Neo-6M)
- Push Button
- PC for UART Communication
- Power Supply (USB or Battery)
  
## 💻 Software Requirements
- Keil µVision or ARM GCC Toolchain
- TivaWare™ Peripheral Driver Library
- UART Terminal (e.g., PuTTY, Tera Term)
- C Programming
  
## 🧰 Project Components
1- **GPS Data Collection** 📍

The GPS module transmits NMEA sentences via UART. The system extracts key information like latitude, longitude, and timestamp.

2-**Distance Calculation** 📏

The system continuously calculates the traveled distance from the starting point to the current point using Haversine formula.

3-**Stop Conditions Handling** 🚦

The system stops collecting data when any of the defined stop conditions are met.
LED Indicator 💡
The built-in LED lights up once the destination is reached.

4-**UART Communication** 🔄
The system can send the entire trajectory to a PC via UART when requested with the command 'U'.
## 🔌 Setup Instructions

### Hardware Setup
1. **Connect the GPS Module**:  
   - Connect the **GPS module** to the **Tiva C Series TM4C123GXL LaunchPad** using the UART pins. Typically, you will connect the GPS module's TX pin to the RX pin on the LaunchPad and the GPS module's RX pin to the TX pin on the LaunchPad.
   - Ensure the **power supply** to the GPS module and the LaunchPad is properly connected (USB or Battery).

2. **Add a Push Button** (if using option 2 for stop conditions):  
   - Connect a **push button** to a GPIO pin on the LaunchPad. Configure the button to trigger an interrupt or poll its state in your code.

3. **Optional**: **Add an External Display** or additional sensors if needed for further debugging or data visualization.

### Software Setup
1. **Install Development Tools**:
   - **Keil µVision** or **ARM GCC Toolchain** for compiling and flashing the code.  
     - Download Keil µVision from the [Keil website](https://www.keil.com/download/).
     - For ARM GCC, follow the installation instructions on the [ARM Developer website](https://developer.arm.com/tools-and-software/software-development-tools/gnu-toolchain/gnu-rm).

2. **Install TivaWare™ Peripheral Driver Library**:
   - Download **TivaWare™** from the [Texas Instruments website](https://www.ti.com/tool/SW-TM4C).  
   - Follow the installation guide provided with the TivaWare™ package.

3. **Configure UART Communication**:
   - Use TivaWare™ to initialize UART for communication with the GPS module and the PC.  
   - Configure the UART settings (baud rate, parity, stop bits) to match the GPS module specifications.

4. **Implement GPS Data Collection**:
   - Write or modify the code in `gps_data.c` to parse the NMEA sentences from the GPS module and extract latitude, longitude, and timestamp.

5. **Implement Distance Calculation**:
   - Add the distance calculation logic in `distance_calc.c` using the Haversine formula to track traveled distance.

6. **Handle Stop Conditions**:
   - Implement the logic for stopping data collection based on the defined conditions in `stop_conditions.c`.

7. **Control the LED**:
   - Add the code in `led_control.c` to turn on the built-in LED when the destination is reached.

8. **Setup UART Communication for PC**:
   - Implement the UART communication protocol to handle commands from the PC and send trajectory data as needed.

### Loading and Running
1. **Compile the Project**:
   - Open Keil µVision or use the ARM GCC Toolchain to compile the project code. Ensure there are no compilation errors.

2. **Flash the Firmware**:
   - Connect the TM4C123G LaunchPad to your PC via USB.
   - Use Keil µVision or another flashing tool to upload the compiled firmware to the LaunchPad.

3. **Power On the System**:
   - Ensure the system is powered on and the GPS module is receiving signals.

4. **Monitor the System**:
   - Use a UART terminal (e.g., PuTTY, Tera Term) to monitor real-time data from the GPS module and interact with the system.

## 🗂 Project Structure

```plaintext
├── src
│   ├── main.c               # Main program written in C
│   ├── gps_data.c           # GPS data parsing and handling
│   ├── distance_calc.c      # Distance calculation logic
│   ├── uart_comm.c          # UART communication setup
│   └── led_control.c        # LED indicator logic
├── docs
│   ├── schematics.pdf       # Circuit schematics and wiring diagrams
│   └── README.md            # Project documentation
├── Makefile                 # Build and flashing script (if using GCC)
└── LICENSE                  # License for the project
```

## 🚀 Future Improvements

- 📝 **Data Logging**: Add SD card support to store GPS trajectories for offline access.
- 🛰️ **Improved GPS Parsing**: Handle more NMEA sentences for richer data.
- 🗺️ **Map Visualization**: Automate map plotting of the trajectory using Google Maps API.

## 📜 License

This project is licensed under the **MIT License** - see the [LICENSE](LICENSE) file for details.

## 👤 Contributors

- **[shahd mohamed abdelsalam]**  
  GitHub: [shahed137](https://github.com/shahed137003)
- **[GeorgTawadrous]**  
  GitHub: [GeorgTawadrous3000](https://github.com/GeorgTawadrous3000)
- **[EsraaAtef]**  
  GitHub: [EsraaAtef2101016](https://github.com/EsraaAtef2101016)
- **[Nouran Salah]**  
  GitHub: [Nouran-Salah](https://github.com/Nouran-Salah)
- **[Toqa Gamal]**  
  GitHub: [Toqa-Gamal](https://github.com/Toqa-Gamal)
- **[Alaa Atef]**  
  GitHub: [AlaaAtef2003](https://github.com/AlaaAtef2003)
- **[Mohammad Sameh]**  
  GitHub: [MohammadSameh](https://github.com/MohammadSameh)
- **[youssef osama]**  
  GitHub: [youssefosama](https://github.com/youssefosama0988)
- **[Mariam Hany]**  
  GitHub: [MariamHany4 · she/her](https://github.com/MariamHany4)

/*
 * name:        ADXL345
 * description: Small, thin, ultralow power, 3-axis accelerometer with high resolution (13-bit) measurement at up to ±16 g.
 * manuf:       Analog Devices Inc.
 * version:     0.1
 * url:         http://www.analog.com/media/en/technical-documentation/data-sheets/ADXL345.pdf
 * date:        2016-08-01
 * author       https://chisl.io/
 * file:        ADXL345.hpp
 */

#include <cinttypes>

/* Derive from class ADXL345_Base and implement the read and write functions! */

/* ADXL345: Small, thin, ultralow power, 3-axis accelerometer with high resolution (13-bit) measurement at up to ±16 g. */
class ADXL345_Base
{
public:
	/* Pure virtual functions that need to be implemented in derived class: */
	virtual uint8_t read8(uint16_t address, uint16_t n=8) = 0;  // 8 bit read
	virtual void write(uint16_t address, uint8_t value, uint16_t n=8) = 0;  // 8 bit write
	virtual uint16_t read16(uint16_t address, uint16_t n=16) = 0;  // 16 bit read
	virtual void write(uint16_t address, uint16_t value, uint16_t n=16) = 0;  // 16 bit write
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                            REG DEVID                                             *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG DEVID:
	 * Fixed device ID
	 */
	struct DEVID
	{
		static const uint16_t __address = 0;
		
		/* Bits DEVID: */
		struct DEVID_
		{
			/* Mode:r */
			static const uint8_t dflt = 0b11100101; // 8'b11100101
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register DEVID */
	void setDEVID(uint8_t value)
	{
		write(DEVID::__address, value, 8);
	}
	
	/* Get register DEVID */
	uint8_t getDEVID()
	{
		return read8(DEVID::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                          REG THRESH_TAP                                           *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG THRESH_TAP:
	 * Threshold value for tap interrupts. The data format is unsigned, therefore, the magnitude of the tap event is
	 * compared with the value in THRESH_TAP for normal tap detection. The scale factor is 62.5 mg/LSB
	 * (that is, 0xFF = 16 g). A value of 0 may result in undesirable behavior if single tap/double tap interrupts are
	 * enabled.
	 */
	struct THRESH_TAP
	{
		static const uint16_t __address = 29;
		
		/* Bits THRESH_TAP: */
		struct THRESH_TAP_
		{
			/* Mode:rw */
			static const uint8_t dflt = 0b00000000; // 8'h0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register THRESH_TAP */
	void setTHRESH_TAP(uint8_t value)
	{
		write(THRESH_TAP::__address, value, 8);
	}
	
	/* Get register THRESH_TAP */
	uint8_t getTHRESH_TAP()
	{
		return read8(THRESH_TAP::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                             REG OFSX                                              *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG OFSX:
	 * The OFSX, OFSY, and OFSZ registers are each eight bits and offer user-set offset adjustments in twos complement
	 * format with a scale factor of 15.6 mg/LSB (that is, 0x7F = 2 g). The value stored in the offset registers is
	 * automatically added to the acceleration data, and the resulting value is stored in the output data registers.
	 * For additional information regarding offset calibration and the use of the offset registers, refer to the
	 * Offset Calibration section.
	 */
	struct OFSX
	{
		static const uint16_t __address = 30;
		
		/* Bits OFSX: */
		struct OFSX_
		{
			/* Mode:rw */
			static const uint8_t dflt = 0b00000000; // 8'h0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register OFSX */
	void setOFSX(uint8_t value)
	{
		write(OFSX::__address, value, 8);
	}
	
	/* Get register OFSX */
	uint8_t getOFSX()
	{
		return read8(OFSX::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                             REG OFSY                                              *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG OFSY:
	 * Y-axis offset
	 */
	struct OFSY
	{
		static const uint16_t __address = 31;
		
		/* Bits OFSY: */
		struct OFSY_
		{
			/* Mode:rw */
			static const uint8_t dflt = 0b00000000; // 8'h0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register OFSY */
	void setOFSY(uint8_t value)
	{
		write(OFSY::__address, value, 8);
	}
	
	/* Get register OFSY */
	uint8_t getOFSY()
	{
		return read8(OFSY::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                             REG OFSZ                                              *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG OFSZ:
	 * Z-axis offset
	 */
	struct OFSZ
	{
		static const uint16_t __address = 32;
		
		/* Bits OFSZ: */
		struct OFSZ_
		{
			/* Mode:rw */
			static const uint8_t dflt = 0b00000000; // 8'h0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register OFSZ */
	void setOFSZ(uint8_t value)
	{
		write(OFSZ::__address, value, 8);
	}
	
	/* Get register OFSZ */
	uint8_t getOFSZ()
	{
		return read8(OFSZ::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                             REG DUR                                              *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG DUR:
	 * Tap duration: Unsigned time value representing the maximum time that an event must be above the THRESH_TAP threshold to
	 * qualify as a tap event. The scale factor is 625 μs/LSB. A value of 0 disables the single tap/ double tap functions.
	 */
	struct DUR
	{
		static const uint16_t __address = 33;
		
		/* Bits DUR: */
		struct DUR_
		{
			/* Mode: */
			static const uint8_t dflt = 0b00000000; // 8'h0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register DUR */
	void setDUR(uint8_t value)
	{
		write(DUR::__address, value, 8);
	}
	
	/* Get register DUR */
	uint8_t getDUR()
	{
		return read8(DUR::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                            REG Latent                                             *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG Latent:
	 * Tap latency: Unsigned time value representing the wait time from the detection of a tap event to the start of the time window (defined by the window register) during which a possible second tap event can be detected. The scale factor is 1.25 ms/LSB. A value of 0 disables the double tap function.
	 */
	struct Latent
	{
		static const uint16_t __address = 34;
		
		/* Bits Latent: */
		struct Latent_
		{
			/* Mode:rw */
			static const uint8_t dflt = 0b00000000; // 8'h0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register Latent */
	void setLatent(uint8_t value)
	{
		write(Latent::__address, value, 8);
	}
	
	/* Get register Latent */
	uint8_t getLatent()
	{
		return read8(Latent::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                            REG Window                                             *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG Window:
	 * Tap window: Unsigned time value representing the amount of time after the expiration of the latency time (determined by the latent register) during which a second valid tap can begin. The scale factor is 1.25 ms/LSB. A value of 0 disables the double tap function.
	 */
	struct Window
	{
		static const uint16_t __address = 35;
		
		/* Bits Window: */
		struct Window_
		{
			/* Mode:rw */
			static const uint8_t dflt = 0b00000000; // 8'h0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register Window */
	void setWindow(uint8_t value)
	{
		write(Window::__address, value, 8);
	}
	
	/* Get register Window */
	uint8_t getWindow()
	{
		return read8(Window::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                          REG THRESH_ACT                                           *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG THRESH_ACT:
	 * Threshold value for detecting activity. The data format is unsigned, so the magnitude of the activity event is compared with the value in the THRESH_ACT register. The scale factor is 62.5 mg/LSB. A value of 0 may result in undesirable behavior if the activity interrupt is enabled.
	 */
	struct THRESH_ACT
	{
		static const uint16_t __address = 36;
		
		/* Bits THRESH_ACT: */
		struct THRESH_ACT_
		{
			/* Mode:rw */
			static const uint8_t dflt = 0b00000000; // 8'h0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register THRESH_ACT */
	void setTHRESH_ACT(uint8_t value)
	{
		write(THRESH_ACT::__address, value, 8);
	}
	
	/* Get register THRESH_ACT */
	uint8_t getTHRESH_ACT()
	{
		return read8(THRESH_ACT::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                         REG THRESH_INACT                                          *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG THRESH_INACT:
	 * Inactivity threshold: threshold value for detecting inactivity. The data format is unsigned, so the magnitude of the inactivity event is compared with the value in the THRESH_INACT register. The scale factor is 62.5 mg/LSB. A value of 0 may result in undesirable behavior if the inactivity interrupt is enabled.
	 */
	struct THRESH_INACT
	{
		static const uint16_t __address = 37;
		
		/* Bits THRESH_INACT: */
		struct THRESH_INACT_
		{
			/* Mode:rw */
			static const uint8_t dflt = 0b00000000; // 8'h0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register THRESH_INACT */
	void setTHRESH_INACT(uint8_t value)
	{
		write(THRESH_INACT::__address, value, 8);
	}
	
	/* Get register THRESH_INACT */
	uint8_t getTHRESH_INACT()
	{
		return read8(THRESH_INACT::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                          REG TIME_INACT                                           *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG TIME_INACT:
	 * Inactivity time: unsigned time value representing the amount of time that acceleration must be less than the value in the THRESH_INACT register for inactivity to be declared. The scale factor is 1 sec/LSB. Unlike the other interrupt functions, which use unfiltered data (see the Threshold section), the inactivity function uses filtered output data. At least one output sample must be generated for the inactivity interrupt to be triggered. This results in the function appearing unresponsive if the TIME_INACT register is set to a value less than the time constant of the output data rate. A value of 0 results in an interrupt when the output data is less than the value in the THRESH_INACT register.
	 */
	struct TIME_INACT
	{
		static const uint16_t __address = 38;
		
		/* Bits TIME_INACT: */
		struct TIME_INACT_
		{
			/* Mode:rw */
			static const uint8_t dflt = 0b00000000; // 8'h0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register TIME_INACT */
	void setTIME_INACT(uint8_t value)
	{
		write(TIME_INACT::__address, value, 8);
	}
	
	/* Get register TIME_INACT */
	uint8_t getTIME_INACT()
	{
		return read8(TIME_INACT::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                        REG ACT_INACT_CTL                                         *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG ACT_INACT_CTL:
	 * Axis enable control for activity and inactivity detection
	 */
	struct ACT_INACT_CTL
	{
		static const uint16_t __address = 39;
		
		/* Bits ACT: */
		struct ACT
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b10000000; // [7]
			static const uint8_t DC = 0b0; // Dc-coupled operation: The current acceleration magnitude is compared directly with THRESH_ACT and THRESH_INACT to determine whether activity or inactivity is detected.<br>
			static const uint8_t AC = 0b1; // Ac-coupled operation: The acceleration value at the start of activity detection is taken as a reference value. New samples of acceleration are then compared to this reference value, and if the magnitude of the difference exceeds the THRESH_ACT value, the device triggers an activity interrupt.
		};
		/* Bits ACT_X: */
		/*
		 * Enable axis participation in detecting activity or inactivity.
		 * If all axes are excluded, the function is disabled. For activity detection, all participating axes are logically OR'ed, causing the activity function to trigger when any of the partici- pating axes exceeds the threshold. For inactivity detection, all participating axes are logically AND'ed, causing the inactivity function to trigger only if all participating axes are below the threshold for the specified time.
		 */
		struct ACT_X
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b01000000; // [6]
		};
		/* Bits ACT_Y: */
		/* Enable axis participation in detecting activity or inactivity.  */
		struct ACT_Y
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00100000; // [5]
		};
		/* Bits ACT_Z: */
		/* Enable axis participation in detecting activity or inactivity.  */
		struct ACT_Z
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00010000; // [4]
		};
		/* Bits INACT: */
		struct INACT
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00001000; // [3]
		};
		/* Bits INACT_X: */
		struct INACT_X
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000100; // [2]
		};
		/* Bits INACT_Y: */
		struct INACT_Y
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000010; // [1]
		};
		/* Bits INACT_Z: */
		struct INACT_Z
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000001; // [0]
		};
	};
	
	/* Set register ACT_INACT_CTL */
	void setACT_INACT_CTL(uint8_t value)
	{
		write(ACT_INACT_CTL::__address, value, 8);
	}
	
	/* Get register ACT_INACT_CTL */
	uint8_t getACT_INACT_CTL()
	{
		return read8(ACT_INACT_CTL::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                          REG THRESH_FF                                           *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG THRESH_FF:
	 * Free-fall threshold: threshold value, in unsigned format, for free-fall detection. The acceleration on all axes is compared with the value in THRESH_FF to determine if a free-fall event occurred. The scale factor is 62.5 mg/LSB. Note that a value of 0 mg may result in undesirable behavior if the free- fall interrupt is enabled. Values between 300 mg and 600 mg (0x05 to 0x09) are recommended.threshold value, in unsigned format, for free-fall detection. The acceleration on all axes is compared with the value in THRESH_FF to determine if a free-fall event occurred. The scale factor is 62.5 mg/LSB. Note that a value of 0 mg may result in undesirable behavior if the free- fall interrupt is enabled. Values between 300 mg and 600 mg (0x05 to 0x09) are recommended.
	 */
	struct THRESH_FF
	{
		static const uint16_t __address = 40;
		
		/* Bits THRESH_FF: */
		struct THRESH_FF_
		{
			/* Mode:rw */
			static const uint8_t dflt = 0b00000000; // 8'h0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register THRESH_FF */
	void setTHRESH_FF(uint8_t value)
	{
		write(THRESH_FF::__address, value, 8);
	}
	
	/* Get register THRESH_FF */
	uint8_t getTHRESH_FF()
	{
		return read8(THRESH_FF::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                           REG TIME_FF                                            *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG TIME_FF:
	 * Free-fall time: unsigned time value representing the minimum time that the value of all axes must be less than THRESH_FF to generate a free-fall interrupt. The scale factor is 5 ms/LSB. A value of 0 may result in undesirable behavior if the free-fall interrupt is enabled. Values between 100 ms and 350 ms (0x14 to 0x46) are recommended.
	 */
	struct TIME_FF
	{
		static const uint16_t __address = 41;
		
		/* Bits TIME_FF: */
		struct TIME_FF_
		{
			/* Mode:rw */
			static const uint8_t dflt = 0b00000000; // 8'h0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register TIME_FF */
	void setTIME_FF(uint8_t value)
	{
		write(TIME_FF::__address, value, 8);
	}
	
	/* Get register TIME_FF */
	uint8_t getTIME_FF()
	{
		return read8(TIME_FF::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                           REG TAP_AXES                                            *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG TAP_AXES:
	 * Axis control for single tap/double tap
	 */
	struct TAP_AXES
	{
		static const uint16_t __address = 42;
		
		/* Bits TAP_AXES: */
		struct TAP_AXES_
		{
			/* Mode:rw */
			static const uint8_t dflt = 0b00000000; // 8'h0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register TAP_AXES */
	void setTAP_AXES(uint8_t value)
	{
		write(TAP_AXES::__address, value, 8);
	}
	
	/* Get register TAP_AXES */
	uint8_t getTAP_AXES()
	{
		return read8(TAP_AXES::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                        REG ACT_TAP_STATUS                                         *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG ACT_TAP_STATUS:
	 * Source of single tap/double tap
	 */
	struct ACT_TAP_STATUS
	{
		static const uint16_t __address = 43;
		
		/* Bits unused_0: */
		struct unused_0
		{
			static const uint8_t dflt = 0b0000; // 4'b0
			static const uint8_t mask = 0b11110000; // [4,5,6,7]
		};
		/* Bits Suppress: */
		/*
		 * Setting the suppress bit suppresses double tap detection if acceleration greater than the value in THRESH_TAP
		 * is present between taps. See the Tap Detection section for more details.
		 */
		struct Suppress
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00001000; // [3]
		};
		/* Bits TAP_X: */
		/* Enable x-axis participation in tap detection. A setting of 0 excludes the selected axis from participation in tap detection. */
		struct TAP_X
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000100; // [2]
		};
		/* Bits TAP_Y: */
		/* Dto. for y-axis */
		struct TAP_Y
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000010; // [1]
		};
		/* Bits TAP_Z: */
		/* Dto. for z-axis */
		struct TAP_Z
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000001; // [0]
		};
	};
	
	/* Set register ACT_TAP_STATUS */
	void setACT_TAP_STATUS(uint8_t value)
	{
		write(ACT_TAP_STATUS::__address, value, 8);
	}
	
	/* Get register ACT_TAP_STATUS */
	uint8_t getACT_TAP_STATUS()
	{
		return read8(ACT_TAP_STATUS::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                           REG BW_RATE                                            *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG BW_RATE:
	 * Data rate and power mode control:
	 * The ACT_X/Y/Z TAP_X/Y/Z bits indicate the first axis involved in a tap or activity event.
	 * When new data is available, these bits are not cleared but are overwritten by the new data. The ACT_TAP_STATUS
	 * register should be read before clearing the interrupt. Disabling an axis from participation clears the
	 * corresponding source bit when the next activity or single tap/double tap event occurs.
	 */
	struct BW_RATE
	{
		static const uint16_t __address = 44;
		
		/* Bits unused_0: */
		struct unused_0
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b10000000; // [7]
		};
		/* Bits ACT_X: */
		/* A setting of 1 corresponds to involvement in the event */
		struct ACT_X
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b01000000; // [6]
		};
		/* Bits ACT_Y: */
		struct ACT_Y
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00100000; // [5]
		};
		/* Bits ACT_Z: */
		struct ACT_Z
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00010000; // [4]
		};
		/* Bits Asleep: */
		/* Indicates that the part is asleep, and a setting of 0 indicates that the part is not asleep. This bit toggles only if the device is configured for auto sleep. See the AUTO_SLEEP Bit section for more information on autosleep mode. */
		struct Asleep
		{
			static const uint8_t dflt = 0b1; // 1'b1
			static const uint8_t mask = 0b00001000; // [3]
		};
		/* Bits TAP_X: */
		struct TAP_X
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000100; // [2]
		};
		/* Bits TAP_Y: */
		struct TAP_Y
		{
			static const uint8_t dflt = 0b1; // 1'b1
			static const uint8_t mask = 0b00000010; // [1]
		};
		/* Bits TAP_Z: */
		struct TAP_Z
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000001; // [0]
		};
	};
	
	/* Set register BW_RATE */
	void setBW_RATE(uint8_t value)
	{
		write(BW_RATE::__address, value, 8);
	}
	
	/* Get register BW_RATE */
	uint8_t getBW_RATE()
	{
		return read8(BW_RATE::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                          REG POWER_CTL                                           *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG POWER_CTL:
	 * Power-saving features control
	 */
	struct POWER_CTL
	{
		static const uint16_t __address = 45;
		
		/* Bits reserved_0: */
		struct reserved_0
		{
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b11000000; // [6,7]
		};
		/* Bits LINK: */
		/*
		 * A 1 with both the activity and inactivity functions enabled delays the start of the activity function until inactivity is detected. After activity is detected, inactivity detection begins, preventing the detection of activity. This bit serially links the activity and inactivity functions. When this bit is set to 0, the inactivity and activity functions are concurrent. Additional information can be found in the Link Mode section.
		 * When clearing the link bit, it is recommended that the part be placed into standby mode and then set back to measurement mode with a subsequent write. This is done to ensure that the device is properly biased if sleep mode is manually disabled; otherwise, the first few samples of data after the link bit is cleared may have additional noise, especially if the device was asleep when the bit was cleared.
		 */
		struct LINK
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00100000; // [5]
		};
		/* Bits AUTO_SLEEP: */
		/*
		 * If the link bit is set, a setting of 1 in the AUTO_SLEEP bit enables the auto-sleep functionality. In this mode, the ADXL345 auto- matically switches to sleep mode if the inactivity function is enabled and inactivity is detected (that is, when acceleration is below the THRESH_INACT value for at least the time indicated by TIME_INACT). If activity is also enabled, the ADXL345 automatically wakes up from sleep after detecting activity and returns to operation at the output data rate set in the BW_RATE register. A setting of 0 in the AUTO_SLEEP bit disables automatic switching to sleep mode. See the description of the Sleep Bit in this section for more information on sleep mode.
		 * If the link bit is not set, the AUTO_SLEEP feature is disabled and setting the AUTO_SLEEP bit does not have an impact on device operation. Refer to the Link Bit section or the Link Mode section for more information on utilization of the link feature.<br>
		 * When clearing the AUTO_SLEEP bit, it is recommended that the part be placed into standby mode and then set back to measure- ment mode with a subsequent write. This is done to ensure that the device is properly biased if sleep mode is manually disabled; otherwise, the first few samples of data after the AUTO_SLEEP bit is cleared may have additional noise, especially if the device was asleep when the bit was cleared.
		 */
		struct AUTO_SLEEP
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00010000; // [4]
		};
		/* Bits Measure: */
		/* The ADXL345 powers up in standby mode with minimum power consumption.  */
		struct Measure
		{
			static const uint8_t dflt = 0b1; // 1'b1
			static const uint8_t mask = 0b00001000; // [3]
			static const uint8_t STDBY = 0b0; // place the part into standby mode
			static const uint8_t MEASURE = 0b1; // place the part into measurement mode
		};
		/* Bits Sleep: */
		/*
		 * Sleep mode suppresses DATA_READY, stops transmission of data to FIFO, and switches the sampling rate to one specified by the wakeup bits. In sleep mode, only the activity function can be used. When the DATA_READY interrupt is suppressed, the output data registers (Register 0x32 to Register 0x37) are still updated at the sampling rate set by the wakeup bits (D1:D0).<br>
		 * When clearing the sleep bit, it is recommended that the part be placed into standby mode and then set back to measurement mode with a subsequent write. This is done to ensure that the device is properly biased if sleep mode is manually disabled; otherwise, the first few samples of data after the sleep bit is cleared may have additional noise, especially if the device was asleep when the bit was cleared.
		 */
		struct Sleep
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000100; // [2]
			static const uint8_t NORMAL = 0b0; // places the part into normal mode
			static const uint8_t SLEEP = 0b1; // places the part into sleep mode
		};
		/* Bits Wakeup: */
		/* control the frequency of readings in sleep mode  */
		struct Wakeup
		{
			static const uint8_t dflt = 0b10; // 2'b10
			static const uint8_t mask = 0b00000011; // [0,1]
			static const uint8_t FREQ_8 = 0b00; // 8 Hz
			static const uint8_t FREQ_4 = 0b01; // 4 Hz
			static const uint8_t FREQ_2 = 0b10; // 2 Hz
			static const uint8_t FREQ_1 = 0b11; // 1 Hz
		};
	};
	
	/* Set register POWER_CTL */
	void setPOWER_CTL(uint8_t value)
	{
		write(POWER_CTL::__address, value, 8);
	}
	
	/* Get register POWER_CTL */
	uint8_t getPOWER_CTL()
	{
		return read8(POWER_CTL::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                          REG INT_ENABLE                                           *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG INT_ENABLE:
	 * Interrupt enable control: A value of 1 enables their respective functions to generate interrupts, whereas
	 * a value of 0 prevents the functions from generating interrupts. The functions are always enabled. It is
	 * recommended that interrupts be configured before enabling their outputs.
	 */
	struct INT_ENABLE
	{
		static const uint16_t __address = 46;
		
		/* Bits DATA_READY: */
		/* enables only the interrupt output */
		struct DATA_READY
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b10000000; // [7]
		};
		/* Bits SINGLE_TAP: */
		struct SINGLE_TAP
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b01000000; // [6]
		};
		/* Bits DOUBLE_TAP: */
		struct DOUBLE_TAP
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00100000; // [5]
		};
		/* Bits Activity: */
		struct Activity
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00010000; // [4]
		};
		/* Bits Inactivity: */
		struct Inactivity
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00001000; // [3]
		};
		/* Bits FREE_FALL: */
		struct FREE_FALL
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000100; // [2]
		};
		/* Bits Watermark: */
		/* enables only the interrupt output */
		struct Watermark
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000010; // [1]
		};
		/* Bits Overrun: */
		/* enables only the interrupt output */
		struct Overrun
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000001; // [0]
		};
	};
	
	/* Set register INT_ENABLE */
	void setINT_ENABLE(uint8_t value)
	{
		write(INT_ENABLE::__address, value, 8);
	}
	
	/* Get register INT_ENABLE */
	uint8_t getINT_ENABLE()
	{
		return read8(INT_ENABLE::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                           REG INT_MAP                                            *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG INT_MAP:
	 * Interrupt mapping control: Any bits set to 0 in this register send their respective interrupts to the INT1 pin,
	 * whereas bits set to 1 send their respective interrupts to the INT2 pin. All selected interrupts for a given pin are OR'ed.
	 */
	struct INT_MAP
	{
		static const uint16_t __address = 47;
		
		/* Bits DATA_READY: */
		struct DATA_READY
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b10000000; // [7]
		};
		/* Bits SINGLE_TAP: */
		struct SINGLE_TAP
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b01000000; // [6]
		};
		/* Bits DOUBLE_TAP: */
		struct DOUBLE_TAP
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00100000; // [5]
		};
		/* Bits Activity: */
		struct Activity
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00010000; // [4]
		};
		/* Bits Inactivity: */
		struct Inactivity
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00001000; // [3]
		};
		/* Bits FREE_FALL: */
		struct FREE_FALL
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000100; // [2]
		};
		/* Bits Watermark: */
		struct Watermark
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000010; // [1]
		};
		/* Bits Overrun: */
		struct Overrun
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000001; // [0]
		};
	};
	
	/* Set register INT_MAP */
	void setINT_MAP(uint8_t value)
	{
		write(INT_MAP::__address, value, 8);
	}
	
	/* Get register INT_MAP */
	uint8_t getINT_MAP()
	{
		return read8(INT_MAP::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                          REG INT_SOURCE                                           *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG INT_SOURCE:
	 * Source of interrupts: Bits set to 1 in this register indicate that their respective functions have triggered an
	 * event, whereas a value of 0 indicates that the corresponding event has not occurred.
	 */
	struct INT_SOURCE
	{
		static const uint16_t __address = 48;
		
		/* Bits DATA_READY: */
		/* may require multiple reads, as indicated in the FIFO mode descriptions; <br>always set if the corresponding events occur, regardless of the INT_ENABLE register settings, and are cleared by reading data from the DATAX, DATAY, and DATAZ registers */
		struct DATA_READY
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b10000000; // [7]
		};
		/* Bits SINGLE_TAP: */
		struct SINGLE_TAP
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b01000000; // [6]
		};
		/* Bits DOUBLE_TAP: */
		struct DOUBLE_TAP
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00100000; // [5]
		};
		/* Bits Activity: */
		struct Activity
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00010000; // [4]
		};
		/* Bits Inactivity: */
		struct Inactivity
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00001000; // [3]
		};
		/* Bits FREE_FALL: */
		struct FREE_FALL
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000100; // [2]
		};
		/* Bits Watermark: */
		/* may require multiple reads, as indicated in the FIFO mode descriptions; <br>always set if the corresponding events occur, regardless of the INT_ENABLE register settings, and are cleared by reading data from the DATAX, DATAY, and DATAZ registers */
		struct Watermark
		{
			static const uint8_t dflt = 0b1; // 1'b1
			static const uint8_t mask = 0b00000010; // [1]
		};
		/* Bits Overrun: */
		/* always set if the corresponding events occur, regardless of the INT_ENABLE register settings, and are cleared by reading data from the DATAX, DATAY, and DATAZ registers */
		struct Overrun
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000001; // [0]
		};
	};
	
	/* Set register INT_SOURCE */
	void setINT_SOURCE(uint8_t value)
	{
		write(INT_SOURCE::__address, value, 8);
	}
	
	/* Get register INT_SOURCE */
	uint8_t getINT_SOURCE()
	{
		return read8(INT_SOURCE::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                         REG DATA_FORMAT                                          *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG DATA_FORMAT:
	 * Control the presentation of data to Register 0x32 through Register 0x37. All data, except that for the +/-16 g range,
	 * must be clipped to avoid rollover.
	 */
	struct DATA_FORMAT
	{
		static const uint16_t __address = 49;
		
		/* Bits SELF_TEST: */
		/*
		 * 1 in the SELF_TEST bit applies a self-test force to the sensor,
		 * causing a shift in the output data. A value of 0 disables the self-test force.
		 */
		struct SELF_TEST
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b10000000; // [7]
		};
		/* Bits SPI: */
		/* 1 in the SPI bit sets the device to 3-wire SPI mode, and a value of 0 sets the device to 4-wire SPI mode. */
		struct SPI
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b01000000; // [6]
		};
		/* Bits INT_INVERT: */
		/* 0 in the INT_INVERT bit sets the interrupts to active high, and a value of 1 sets the interrupts to active low. */
		struct INT_INVERT
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00100000; // [5]
		};
		/* Bits reserved_0: */
		struct reserved_0
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00010000; // [4]
		};
		/* Bits FULL_RES: */
		/* 1, the device is in full resolution mode, where the output resolution increases with the g range set by the range bits to maintain a 4 mg/LSB scale factor. When the FULL_RES bit is set to 0, the device is in 10-bit mode, and the range bits determine the maximum g range and scale factor. */
		struct FULL_RES
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00001000; // [3]
		};
		/* Bits Justify: */
		/* A setting of 1 in the justify bit selects left-justified (MSB) mode, and a setting of 0 selects right-justified mode with sign extension. */
		struct Justify
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000100; // [2]
		};
		/* Bits Range: */
		/* set the g range  */
		struct Range
		{
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b00000011; // [0,1]
			static const uint8_t RANGE_2G = 0b00; // +/- 2g
			static const uint8_t RANGE_4G = 0b01; // +/- 4g
			static const uint8_t RANGE_8G = 0b10; // +/- 8g
			static const uint8_t RANGE_16G = 0b11; // +/- 16g
		};
	};
	
	/* Set register DATA_FORMAT */
	void setDATA_FORMAT(uint8_t value)
	{
		write(DATA_FORMAT::__address, value, 8);
	}
	
	/* Get register DATA_FORMAT */
	uint8_t getDATA_FORMAT()
	{
		return read8(DATA_FORMAT::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                            REG DATAX                                             *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG DATAX:
	 * X-Axis output data is twos complement,
	 * The DATA_FORMAT register controls the format of the data. It is recommended that a multiple-byte read of all
	 * registers be performed to prevent a change in data between reads of sequential registers.
	 */
	struct DATAX
	{
		static const uint16_t __address = 50;
		
		/* Bits DATAX: */
		struct DATAX_
		{
			/* Mode:r */
			static const uint16_t dflt = 0b0000000000000000; // 16'h0
			static const uint16_t mask = 0b1111111111111111; // [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]
		};
	};
	
	/* Set register DATAX */
	void setDATAX(uint16_t value)
	{
		write(DATAX::__address, value, 16);
	}
	
	/* Get register DATAX */
	uint16_t getDATAX()
	{
		return read16(DATAX::__address, 16);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                            REG DATAY                                             *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG DATAY:
	 * Y-Axis output data is twos complement,
	 * The DATA_FORMAT register controls the format of the data. It is recommended that a multiple-byte read of all
	 * registers be performed to prevent a change in data between reads of sequential registers.
	 */
	struct DATAY
	{
		static const uint16_t __address = 52;
		
		/* Bits DATAY: */
		struct DATAY_
		{
			/* Mode:r */
			static const uint16_t dflt = 0b0000000000000000; // 16'h0
			static const uint16_t mask = 0b1111111111111111; // [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]
		};
	};
	
	/* Set register DATAY */
	void setDATAY(uint16_t value)
	{
		write(DATAY::__address, value, 16);
	}
	
	/* Get register DATAY */
	uint16_t getDATAY()
	{
		return read16(DATAY::__address, 16);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                            REG DATAZ                                             *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG DATAZ:
	 * Z-Axis output data is twos complement,
	 * The DATA_FORMAT register controls the format of the data. It is recommended that a multiple-byte read of all
	 * registers be performed to prevent a change in data between reads of sequential registers.
	 */
	struct DATAZ
	{
		static const uint16_t __address = 54;
		
		/* Bits DATAZ: */
		struct DATAZ_
		{
			/* Mode:r */
			static const uint16_t dflt = 0b0000000000000000; // 16'h0
			static const uint16_t mask = 0b1111111111111111; // [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]
		};
	};
	
	/* Set register DATAZ */
	void setDATAZ(uint16_t value)
	{
		write(DATAZ::__address, value, 16);
	}
	
	/* Get register DATAZ */
	uint16_t getDATAZ()
	{
		return read16(DATAZ::__address, 16);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                           REG FIFO_CTL                                            *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG FIFO_CTL:
	 * FIFO control
	 */
	struct FIFO_CTL
	{
		static const uint16_t __address = 56;
		
		/* Bits FIFO_MODE: */
		struct FIFO_MODE
		{
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b11000000; // [6,7]
			static const uint8_t Bypass = 0b00; // FIFO is bypassed.
			static const uint8_t FIFO = 0b01; // FIFO collects up to 32 values and then stops collecting data, collecting new data only when FIFO is not full.
			static const uint8_t Stream = 0b10; // FIFO holds the last 32 data values. When FIFO is full, the oldest data is overwritten with newer data.
			static const uint8_t Trigger = 0b11; // 1 When triggered by the trigger bit, FIFO holds the last data samples before the trigger event and then continues to collect data until full. New data is collected only when FIFO is not full.
		};
		/* Bits Trigger: */
		struct Trigger
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00100000; // [5]
			static const uint8_t INT1 = 0b0; // link the trigger event of trigger mode to INT1
			static const uint8_t INT2 = 0b1; // link the trigger event to INT2.
		};
		/* Bits Samples: */
		/* The function of these bits depends on the FIFO mode selected (see Table 23). Entering a value of 0 in the samples bits immediately sets the watermark status bit in the INT_SOURCE register, regardless of which FIFO mode is selected. Undesirable operation may occur if a value of 0 is used for the samples bits when trigger mode is used.  */
		struct Samples
		{
			static const uint8_t dflt = 0b00000; // 5'b0
			static const uint8_t mask = 0b00011111; // [0,1,2,3,4]
		};
	};
	
	/* Set register FIFO_CTL */
	void setFIFO_CTL(uint8_t value)
	{
		write(FIFO_CTL::__address, value, 8);
	}
	
	/* Get register FIFO_CTL */
	uint8_t getFIFO_CTL()
	{
		return read8(FIFO_CTL::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                         REG FIFO_STATUS                                          *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG FIFO_STATUS:
	 * FIFO status
	 */
	struct FIFO_STATUS
	{
		static const uint16_t __address = 57;
		
		/* Bits FIFO_TRIG: */
		/* A 1 corresponds to a trigger event occurring, and a 0 means that a FIFO trigger event has not occurred. */
		struct FIFO_TRIG
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b10000000; // [7]
		};
		/* Bits unused_0: */
		struct unused_0
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b01000000; // [6]
		};
		/* Bits Entries: */
		/* How many data values are stored in FIFO. Access to collect the data from FIFO is provided through the DATAX, DATAY, and DATAZ registers. FIFO reads must be done in burst or multiple-byte mode because each FIFO level is cleared after any read (single- or multiple-byte) of FIFO. FIFO stores a maximum of 32 entries, which equates to a maximum of 33 entries available at any given time because an additional entry is available at the output filter of the device. */
		struct Entries
		{
			static const uint8_t dflt = 0b000000; // 6'b0
			static const uint8_t mask = 0b00111111; // [0,1,2,3,4,5]
		};
	};
	
	/* Set register FIFO_STATUS */
	void setFIFO_STATUS(uint8_t value)
	{
		write(FIFO_STATUS::__address, value, 8);
	}
	
	/* Get register FIFO_STATUS */
	uint8_t getFIFO_STATUS()
	{
		return read8(FIFO_STATUS::__address, 8);
	}
	
};
